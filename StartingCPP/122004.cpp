#include <iostream>

class Box {
private:
	int width = 0;
	int height = 0;
	int length = 0;

public:
	Box(int width = 0, int length = 0, int height = 0) : width(width), height(height), length(length) {

	}

	virtual inline int Volume() {
		return width * height * length;
	}
};

class WoodBox : public Box {
public:
	/*WoodBox(int w, int l, int h) : Box(w,l,h) {

	}*/

	using Box::Box;
};

class UnShapedBox : public Box {
private:
	int x, y, z, t;

public:
	UnShapedBox(std::initializer_list<int> nums) {
		std::cout << "UnShapedBox(std::initializer_list<int> nums) called" << std::endl;

		auto it = nums.begin();
		x = *it++;
		y = *it++;
		z = *it++;
		t = *it;
	}

	virtual inline int Volume() {
		return x * y * z * t;
	}
};

int main() {
	WoodBox* MyWoodBox = new WoodBox(10,20,30);
	std::cout << "woodbox vol : " << MyWoodBox->Volume() << std::endl;

	UnShapedBox unBox{ 10,20,30,40 };
	std::cout << "unbox vol : " << unBox.Volume() << std::endl;
}