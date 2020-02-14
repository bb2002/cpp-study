#include <iostream>

class MyString {
public:
	MyString() {
		std::cout << "MyString ������ ȣ��" << std::endl;
	}

	char* mData;
	size_t mLength;

	const char* getData() const {
		return mData;
	}
};

int main() {
	const char* mString = "Hello Ballbot World!";
	unsigned short len = strlen(mString) + 1;

	MyString* s1 = new MyString();		// New �� �Ҵ� �ޱ�.
	s1->mData = new char[len];
	strcpy_s(s1->mData, len, mString);

	printf("s1 ������ : 0x%p, s1->mData ������ : 0x%p, ������ : %s\n", s1, s1->getData(), s1->getData());

	delete[] s1->mData;
	delete s1;

	size_t n = sizeof(MyString);
	std::cout << "MyString Ŭ������ ũ�� : " << n << std::endl;
	MyString* s2 = (MyString*) malloc(n);
	s2->mData = (char*)malloc(len);
	strcpy_s(s2->mData, len, mString);

	printf("s2 ������ : 0x%p, s2->mData ������ : 0x%p, ������ : %s\n", s2, s2->getData(), s2->getData());

	free(s2->mData);
	free(s2);
}