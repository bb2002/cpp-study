// StartingCPP.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[], char* const envp[])
{
	for (int i = 0; i < argc; ++i) {
		std::cout << i << " : " << argv[i] << std::endl;
	}

	while (*envp) {
		std::cout << *envp++ << std::endl;
	}

	std::cerr << "삑사리가 발생했습니다." << std::endl;
}
