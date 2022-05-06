
#include "FPath.h"
#include <iostream>

int main(int argc, char *argv[])
{

FPath::Find_mode mode = FPath::Find_mode::Classic;

std::vector<std::string> Purpose_files;
int k  = 0;
std::string root_path;
std::string file_search;

if(argc==1)
{
std::cout <<"-+-+ | FPATH | -+-+-\n"
	    "-h for help\n";
return 0;
}
for(int i=1;i<argc;i++)
{
	std::string command = argv[i];
	if(command[0]=='-' && i == 1)
	{
		 if(command.size()>1)
			{
				if(command[1] == 'h')
					{
						std::cout <<"specify--> fpath [Flag -h or -s or NONE] [root_directory] [file_search] [Arguments...]\n";
						std::cout <<" -h -> help\n"
							    " -s -> strong mode\n";
						return 0;
					}
				if(command[1] == 's')
					{
					   mode = FPath::Find_mode::Root;

					}
			}
			else
			{
				std::cout << "UNKNOWN FLAG\n";
				return 0;
			}

	}
	else
	{
		if(k==0) root_path = command;
		if(k==1) file_search = command;
		if(k>1) Purpose_files.push_back(command);
		k++;
	}
}

if(root_path.size()==0 || file_search.size()==0)
{
	std::cout <<"-+-+ | FPATH | -+-+-\n";
	std::cout <<"specify--> fpath [Flag -h or -s or NONE] [root_directory] [file_search] [Arguments...]\n";
	return 0;
}

FPath s = root_path;

try
{
	std::cout << s(file_search,Purpose_files,std::move(mode));
}
catch(FExceptions & ex)
{
	std::cout <<"-+-+ | FPATH | -+-+-\n";
	std::cout << ex.what()<<"\n";
}

}
