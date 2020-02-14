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
	
	// ȭ�鿡 ��� �Ҷ��� std::wcout ��� �Ѵ�.
	std::wcout << "wchar_t " << en << ", ũ�� : " << sizeof(en) << std::endl;

	// �Է��� �������� std::wcin ���.
	std::wcin >> en;

	std::cout << "=-=-=-=-= std::cout �� ����� ��� =-=-=-=-=-=" << std::endl;
	for (int i = 0; en[i]; ++i) {
		std::cout << (char)en[i];
	}
	std::cout << std::endl << std::endl;

	wchar_t wc[] = L"�ȳ� ģ���� �ذ�簡 �Ծ�!";
	std::cout << "=-=-=-=-= std::wcout �� ����� ��� =-=-=-=-=-=" << std::endl;
	std::wcout << wc << std::endl;

	
	std::cout << "=-=-=-=-= std::cout �� ����� ��� =-=-=-=-=-=" << std::endl;
	int i = 0;
	while (wc[i]) {
		std::cout << (char)wc[i++];
	}
}