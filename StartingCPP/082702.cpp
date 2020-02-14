#include "pch.h"
#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char sent[] = "Hello Kasumi!";
	std::cout << "TEXT : " << sent << endl;

	std::cin >> sent;
	for (int i = 0; sent[i]; ++i) {
		std::cout << (char)sent[i];
	}

	std::cout << endl;
	std::cout << endl;
	std::cout << endl;

	char wc1[] = "한글화 작업!";
	std::cout << wc1 << endl;

	int i = 0;
	while (wc1[i]) {
		std::cout << (char)wc1[i];
		++i;
	}

	std::cout << endl << endl;

	const char *wc2 = "한글화 작업2";
	std::cout << wc2 << ", 문자크기 : " << strlen(wc2) << endl;


	std::cout << endl << endl << endl;

	const char *wc3 = "全身全力一生懸命魅惑噎せ返る鐘が鳴り響く";
	std::cout << wc3 << endl;

}