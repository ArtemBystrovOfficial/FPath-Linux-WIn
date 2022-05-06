
#include "FPath.h"
#include <iostream>

int main()
{
 FPath s = "/home/artem";
try
{
	std::cout << s("CMakeLists.txt",{"FPath"});
}
catch(FExceptions & ex)
{
	std::cout << ex.what();
}
}
