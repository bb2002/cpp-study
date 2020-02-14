#include <iostream>

class Shape {
public:
	
	virtual void Draw() {};

	static Shape* create(std::string type);
};

class Circle : public Shape {
public:
	void Draw() {
		std::cout << "�̰Ž� ���̴�" << std::endl;
	}
};

class Square : public Shape {
public:
	void Draw() {
		std::cout << "�̰Ž� �׸��" << std::endl;
	}
};

int main() {
	Shape();

	Shape* circle = Shape::create("circle");
	Shape* square = Shape::create("square");
	circle->Draw();
	square->Draw();
}

Shape * Shape::create(std::string type)
{
	if (type == "circle") return new Circle();
	if (type == "square") return new Square();
	return nullptr;
}
