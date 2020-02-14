#include <iostream>
#include <string>

class Shape {
public:
	Shape(std::string n) : name(n) {

	}

	virtual void echo() const {
		std::cout << "Shape �̸� : " << getName() << ", ũ�� : " << getArea() << std::endl;
	}

	virtual double getArea() const {
		return 0;
	}

	std::string getName() const {
		return name;
	}

private:
	std::string name;
};

class Rect : public Shape {
public:
	Rect(std::string n, double w = 0, double h = 0) : Shape(n), width(w), height(h) {

	}

	void echo() const {
		std::cout << "RECT �̸� : " << getName() << ", ũ�� : " << getArea() << std::endl;
	}

	double getArea() const {
		return width * height;
	}

private:
	double width;
	double height;
};

class Triangle : public Rect {
public:
	Triangle(float w, float h) : Rect("�ﰢ��", w, h) {

	}

	// ���̻� ��� X
	virtual double getArea() const final {
		return Rect::getArea() / 2;
	}
};

class Circle : public Shape {
public:
	Circle(double r = 0) : Shape("��"), rad(r) {

	}

	// Override ������ �߰�. C++ 11 ~
	double getArea() const override {
		return rad * rad * 3.141592;
	}

private:
	double rad;
};

int main() {
	Shape *shape[] = {
		new Rect("���簢��", 10, 5),
		new Triangle(10, 5),
		new Circle(10)
	};

	for (Shape *s : shape) {
		s->Shape::echo();
	}
	
	std::cout << std::endl << std::endl;


	Triangle* tri = (Triangle*)shape[1];
	tri->Rect::echo();


	// �����ͳ� ���������� ��� ����.
	// �Ϲ� �������� �Ұ���.

	std::cout << std::endl << std::endl;


	Rect r("�������", 10, 5);
	Shape s = r;

	s.echo();

	for (Shape *s : shape) {
		delete s;
	}
}