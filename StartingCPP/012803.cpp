#include <iostream>
#include <string>

class MyString {
public:
	MyString(const char* n) {
		SetString(n);
	}

	MyString(const MyString& other) {
		SetString(other.data.get());
	}

	MyString& operator=(const MyString& other) {
		if (this != &other) {
			data.reset();
			SetString(other.data.get());
		}
	}

	~MyString() {
		if (data != nullptr) {
			data.reset(nullptr);
		}
	}

	void SetString(const char* n) {
		if (n != nullptr) {
			data = std::make_unique<char[]>(strlen(n) + 1);
			strcpy(data.get(), n);
		}
	}

	const char* GetString() {
		return data.get();
	}

	int GetLength() {
		return strlen(data.get());
	}

private:
	std::unique_ptr<char[]> data;
};

int main() {
	MyString str1 = "Hello world!";
	MyString str2(str1);

	std::cout << str1.GetString() << std::endl;
	std::cout << str2.GetString() << std::endl;
}