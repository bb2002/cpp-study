#include <iostream>

class MyString {
public:
	MyString(const char* data);
	MyString(const MyString& other) = default;

	const char* GetString() const;
	int GetLength() const;

	~MyString();

private:
	std::shared_ptr<char> data;
	int length;
};

template<typename T>
std::shared_ptr<T> make_shared_array(size_t size) {
	return std::shared_ptr<T>(new T[size], std::default_delete<T[]>());
}

MyString::MyString(const char* data)
{
	if (data != nullptr) {
		this->length = strlen(data);
		this->data = make_shared_array<char>(length + 1);
		strcpy(this->data.get(), data);

		std::cout << "MyString() :: " << data << std::endl;
	}
}

MyString::~MyString()
{
	if (this->data != nullptr) {
		std::cout << "~MyString() :: " << data.get() << "count : " << data.use_count() << std::endl;
		data.reset();
		length = 0;
	}
}

const char* MyString::GetString() const {
	return data.get();
}

int MyString::GetLength() const
{
	return length;
}

void echo(const MyString& data) {
	std::cout << data.GetString() << std::endl;
}

int main() {
	MyString s1("¾û¸ÁÁøÃ¢ÀÌ¶ó »ý°¢ÀÌ »ý°¢ÀÌ ¹½½Ã±â..");
	echo(s1);

	MyString s2(s1);
	echo(s2);

}