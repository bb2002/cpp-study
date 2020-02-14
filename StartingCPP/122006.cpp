#include <iostream>

class Box {
private:
	char* BoxName;
	int volume;

public:
	Box(const char* BoxName, int vol) : BoxName(new char[strlen(BoxName) + 1]), volume(vol) {

	}

	void echo() {
		std::cout << BoxName << "Àº " << volume << std::endl;
	}

	virtual ~Box() {
		std::cout << "Box DESTROY" << std::endl;
		delete[] BoxName;
	}
};

class Cloud : public Box {
public:
	using Box::Box;

	~Cloud() {
		std::cout << "CLOUD DESTROY" << std::endl;
	}
};

int main() {
	Box* MyCloud = new Cloud("OneDrive", 5000);
	delete MyCloud;
}