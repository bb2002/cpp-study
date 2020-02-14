#include <iostream>

class Sample {
public:

	Sample(int content = 0) : _content(content) {
		std::cout << "Construct Sample()" << std::endl;
	}

	~Sample() {
		std::cout << "~Sample()" << std::endl;
	}

	int getContent() {
		return _content;
	}

	void operator<<(std::ostream& os) {
		os << _content;
	}

private:
	int _content;
};

static std::ostream& operator<<(std::ostream& os, Sample& data) {
	os << data.getContent();
	return os;
}

class Deleter {
public:
	Deleter() {
		std::cout << "Deleter()" << std::endl;
	}

	void operator()(Sample* p) const {
		std::cout << "Sample(" << p->getContent() << ") is deleted" << std::endl;
		delete p;
	}
};

int main() {
	{
		std::unique_ptr<Sample, Deleter> ptr1(new Sample(16));
		std::unique_ptr<Sample> ptr2 = std::make_unique<Sample>(3);
		std::unique_ptr<int> ptr3(new int(10), std::default_delete<int>());

		*ptr2 = 10000;

		std::cout << "ptr1 = " << *ptr1 << std::endl;
		std::cout << "ptr2 = " << *ptr2 << std::endl;
		std::cout << "ptr3 = " << *ptr3 << std::endl;

		auto ptr4(std::move(ptr1));
		std::cout << "ptr4 = " << *ptr4 << std::endl;


		Sample* sample2 = ptr2.get();
		std::cout << "sample2 : " << sample2->getContent() << std::endl;
	}

	std::cout << "±¸¿ª ³¡" << std::endl;
}