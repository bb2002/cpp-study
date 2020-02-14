#include <iostream>

class Box {
public:
	Box(int w = 0, int l = 0, int h = 0) {
		SetBox(w, l, h);
	}

	inline int Volume() {
		return _width * _left * _height;
	}

	void SetBox(int w = 0, int l = 0, int h = 0) {
		_width = w;
		_height = h;
		_left = l;
	}

	std::ostream& operator<<(std::ostream& os) {
		os << _width << ", " << _left << ", " << _height << " : " << Volume();
		return os;
	}

	friend static std::ostream& operator<<(std::ostream& os, Box& box);

private:
	int _width;
	int _height;
	int _left;
};

static std::ostream& operator<<(std::ostream& os, Box& box) {
	os << box._width << ", " << box._left << ", " << box._height << " : " << box.Volume();
	return os;
}

int main() {
	std::unique_ptr<Box> v1 = std::make_unique<Box>();
	std::unique_ptr<Box> v2 = std::make_unique<Box>(5, 10, 15);
	std::unique_ptr<Box[]> v3 = std::make_unique<Box[]>(5);

	std::cout << "v1 : " << *v1 << std::endl;
	std::cout << "v2 : " << *v2 << std::endl;

	v3[0].SetBox(2, 2, 2);
	v3[4].SetBox(rand(), rand(), rand());

	for (int i = 0; i < 5; ++i) {
		std::cout << v3[i] << std::endl;
	}
}