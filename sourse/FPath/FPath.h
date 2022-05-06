
#pragma once

#include <exception>
#include <filesystem>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <stdarg.h>
#include <fstream>

namespace fs = std::filesystem;

class FExceptions
{

public:
	enum class Type
	{
		Compilation,
		Files
	};

	enum class Level
	{
		Skip,
		Rebuild,
		Crash,
		ambiguity
	};

	std::string what();

	Type type;
	Level level;

	FExceptions() = default;
	FExceptions(Type&& _type, Level&& level) : type(_type), level(level) {};
};

class FPath : public FExceptions
{


public:

	enum class Find_mode
	{
		Classic,
		Root
	};

private:

	Find_mode mode;

	std::string_view files_path;

	std::multimap < std::string, fs::path > unique_files;

	std::string print_files(const std::string& way, const std::vector<std::string>& list_args = {});

	void analys_files();

	std::vector <std::string> split_path(const std::string& file);

	bool find_unique_pathes(const std::string& file, const std::vector <std::string>& list);

	bool find_root_pathes(const std::string& file, const std::vector <std::string>& list);

public:

	template <typename T>
	FPath(T&& _path_files)
	{
		if constexpr (std::is_same_v<std::remove_reference_t<T>, std::string_view> ||
			std::is_same_v<std::remove_reference_t<T>, std::string> ||
			std::is_same_v<std::remove_reference_t<T>, const char[sizeof(_path_files)] >
			)
			files_path = std::forward<std::string_view>(_path_files);
		else
		 	throw std::exception("Uncorrect type of path");

		analys_files();
	}
	//FPath() = delete;
	FPath(){}

	std::string operator()(const std::string& way, const std::vector<std::string>& list_args = {}
	, Find_mode&& mode = Find_mode::Classic);

};

