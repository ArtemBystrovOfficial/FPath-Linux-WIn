#include "FPath.h"﻿

std::string FExceptions::what()
	{
		std::string msg = "Error: ";
		switch (type)
		{
			case(Type::Compilation):
			{

			}
			break;
			case(Type::Files):
			{
				switch (level)
				{
					case(Level::Skip):
					{
						msg += "UNKNOWN, you can skip, maybe you try open security folder";
					}
					break;
					case(Level::Rebuild):
					{
						msg += "file does'nt exist, check path or file name";
					}
					break;
					case(Level::ambiguity):
					{
						msg += "you have some ambiguity files, set args for correct path";
					}
					break;
				}

			}
			break;
		}
		return msg;
}

	std::string FPath::print_files(const std::string& way, const std::vector<std::string>& list_args)
	{

		switch (mode)
		{
			case(Find_mode::Classic):
			{
				const auto test = unique_files.find(way);

				if (test == unique_files.end())
					throw FExceptions(Type::Files, Level::Rebuild);

				const auto it = unique_files.equal_range(way);

				decltype(it.first->second) final_path;

				int filter = 0;

				if (it.first == it.second)
				{
					return it.first->second.u8string();
				}

				for (decltype(it.first) i = it.first; i != it.second && i != unique_files.end(); i++)
				{
					if (find_unique_pathes(i->second.parent_path().string(), list_args))
					{
						final_path = i->second;
						filter++;
					}
				}

				if (filter == 1)
				{
					return final_path.u8string();
				}

			}
			break;
			case(Find_mode::Root):
			{
				const auto test = unique_files.find(way);

				if (test == unique_files.end())
					throw FExceptions(Type::Files, Level::Rebuild);

				const auto it = unique_files.equal_range(way);

				decltype(it.first->second) final_path;

				int filter = 0;

				if (it.first == it.second)
				{
					return it.first->second.u8string();
				}

				for (decltype(it.first) i = it.first; i != it.second && i != unique_files.end(); i++)
				{
					if (find_root_pathes(i->second.parent_path().string(), list_args))
					{
						final_path = i->second;
						filter++;
					}
				}

				if (filter == 1)
				{
					return final_path.u8string();
				}
			}
		}
		throw FExceptions(Type::Files, Level::ambiguity);
	}


	void FPath::analys_files()
	{
		for (const auto& dir_entry : fs::recursive_directory_iterator(files_path,
			fs::directory_options::follow_directory_symlink |
			std::filesystem::directory_options::skip_permission_denied))
		{
			if (!fs::is_directory(dir_entry))
			{
				unique_files.insert(std::pair{ dir_entry.path().filename().u8string(),dir_entry.path() });
			}
		}
	}


	std::vector <std::string> FPath::split_path(const std::string& file)
	{
		// NRVO
		std::vector<std::string> vec;
		std::string s = "";
		for (auto i : file)
		{
			if (i == '\\' || i == '/')
			{
				vec.push_back(s);
				s = "";
			}
			else
			{
				s += i;
			}
		}
		if (s.size() > 0)
			vec.push_back(s);

		return vec;
	}

	bool FPath::find_unique_pathes(const std::string& file, const std::vector <std::string>& list)
	{
		auto list_pathes = split_path(file);
		bool is_find = true;
		for (auto j : list)
		{
			bool is = false;
			for (auto i : list_pathes)
			{
				if (j == i)
				{
					is = true;
				}
			}
			if (!is) is_find = false;
		}
		return is_find;
	}


	bool FPath::find_root_pathes(const std::string& file, const std::vector <std::string>& list)
	{
		auto list_pathes = split_path(file);

		int k = list.size()-1;

		bool is = true;

		std::for_each(list_pathes.crbegin(), list_pathes.crend(), [&](std::string path)
			{
				if (k >= 0)
				{
					if (list[k] != path)
					{
						is = false;
					}
				}
				k--;
			});
		return is;
	}


	std::string  FPath::operator()(const std::string& way, const std::vector<std::string>& list_args
	, Find_mode&& mode)
	{
		this->mode = mode;
		return print_files(way, list_args);
	}
	
