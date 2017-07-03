// ConsoleApplication1.cpp: определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#include <iostream>
extern "C++" __declspec(dllexport) void LetterList()
{
std::cout << "This function was called from LetterList() " << std::endl;
}
extern "C++" __declspec(dllexport) int PutInt(int param)
{
return param;
}


