#include <iostream>
#include <vector>

class MyString {
public:
	MyString(const char* n) {
		CopyString(n);
		std::cout << "MyString::MyString(const char*) " << n << std::endl;
	}

	MyString(const MyString& other) : data(nullptr), length(0) {
		CopyString(other.data);
		std::cout << "MyString::MyString(const MyString&)" << std::endl;
	}

	MyString& operator= (const MyString& other) {
		if (this != &other) {
			delete[] this->data;
			this->length = 0;
			CopyString(other.data);
		}

		std::cout << "MyString& operator= (const MyString&)" << other.data << std::endl;

		return *this;
	}

	MyString& operator=(MyString&& other) noexcept {
		if (this != &other) {
			if (this->data != nullptr) {
				delete[] data;
			}

			data = other.data;
			length = other.length;
			other.data = nullptr;
			other.length = 0;
		}

		std::cout << "MyString& operator=(MyString&& other) 이동대입연산자" << std::endl;
		return *this;
	}

	MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
		std::cout << "MyString(MyString&& other) 이동대입생성자" << std::endl;
		other.data = nullptr;
		other.length = 0;
	}

	~MyString() {
		if (data != nullptr) {
			std::cout << "MyString::~MyString() 소멸자 호출" << data << std::endl;
			delete[] data;
			data = nullptr;
			length = 0;
		}
	}

	const char* GetString() const {
		return data;
	}

	int GetLength() {
		return length;
	}

private:
	char* data;
	int length;

	void CopyString(const char* n) {
		if (n == nullptr || strlen(n) == 0) {
			data = nullptr;
			length = 0;
			return;
		}

		data = new char[strlen(n) + 1];
		strcpy_s(data, strlen(n) + 1, n);
		length = strlen(n);
	}
};

void Display(MyString a) {
	std::cout << "cout :: " << a.GetString() << std::endl;
}

int main() {
	MyString a(MyString(MyString(MyString(MyString(MyString(MyString(MyString("Hello World!"))))))));
	Display(a);
}