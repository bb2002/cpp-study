#include <iostream>
#include <string>
#include <cstring>

class MyString {
public:
	MyString(const char* n) {
		CopyString(n);
		std::cout << "MyString::MyString(const char*)" << std::endl;
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

		return *this;
	}

	~MyString() {
		std::cout << "MyString::~MyString() " << data << std::endl;
		if (data != nullptr) {
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

void display(MyString other) {
	std::cout << "display : " << other.GetString() << std::endl;
}

int main() {
	MyString a("Hello world!");
	MyString b("sisigami leona");

	a = b;
	std::cout << "a : " << a.GetString() << std::endl;
}