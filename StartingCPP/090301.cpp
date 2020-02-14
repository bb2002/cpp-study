#include <iostream>
#include <stdexcept>

void CopyObject(const char* orig) {
	if (orig == nullptr) {
		throw -1;
	}

	std::cout << orig << std::endl;
}

void SmartCopyObject(const char* orig) {
	if (orig == nullptr) {
		throw std::runtime_error("인수가 null 인데요???");
	}

	std::cout << orig << std::endl;
}

int MyArrayAccess(int idx) {
	if (idx > 5) {
		throw std::out_of_range("Index OutOfRange!!");
	}

	int a[] = { 1,2,3,4,5 };
	return a[idx];
}

int main() {
	/*try {
		char *name = nullptr;
		SmartCopyObject(name);
	}
	catch (std::runtime_error& RuntimeError) {
		std::cerr << RuntimeError.what() << std::endl;
	}
	catch (...) {
		std::cerr << "몰라 이게 뭐야" << std::endl;
	}*/

	try {
		std::cout << MyArrayAccess(99) << std::endl;
	}
	catch (std::out_of_range& OutError) {
		std::cout << OutError.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown Error" << std::endl;
	}
}