#include "pch.h"
#include <iostream>
#include <locale>

int main() {
#if defined __linux__ || defined __CYGWIN__
	// For Linux
	setlocale(LC_ALL, "ko_KR.utf8");
	std::wcout << L"setlocale(LC_ALL, ko_KR.utf8);" << std::endl;
#elif defined(WIN32)
	// For Window
	std::wcout.imbue(std::locale("kor"));
	std::wcin.imbue(std::locale("kor"));
	std::cout << "imbue(setlocale(kor));" << std::endl;
#endif

	wchar_t en[] = L"HelloWorld!";
	
	// 화면에 출력 할때는 std::wcout 사용 한다.
	std::wcout << "wchar_t " << en << ", 크기 : " << sizeof(en) << std::endl;

	// 입력을 받을때는 std::wcin 사용.
	std::wcin >> en;

	std::cout << "=-=-=-=-= std::cout 을 사용한 출력 =-=-=-=-=-=" << std::endl;
	for (int i = 0; en[i]; ++i) {
		std::cout << (char)en[i];
	}
	std::cout << std::endl << std::endl;

	wchar_t wc[] = L"안녕 친구들 해결사가 왔어!";
	std::cout << "=-=-=-=-= std::wcout 을 사용한 출력 =-=-=-=-=-=" << std::endl;
	std::wcout << wc << std::endl;

	
	std::cout << "=-=-=-=-= std::cout 을 사용한 출력 =-=-=-=-=-=" << std::endl;
	int i = 0;
	while (wc[i]) {
		std::cout << (char)wc[i++];
	}
}