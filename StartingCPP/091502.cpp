#include <iostream>

class Object {
public:
	virtual bool Equals(Object& other) {
		std::cout << "Object -> Equals()" << std::endl;
		return this == &other;
	}

	std::string name;
};

class Rect : virtual public Object {
public:
	Rect() : Object() {

	}

	virtual bool Equals(Rect& other) {
		std::cout << "Rect -> Equals()" << std::endl;
		return this == &other;
	}
};

class Clickable : virtual public Object {
public:
	Clickable() : Object() {

	}

	virtual bool Equals(Clickable& other) {
		std::cout << "Clickable -> Equals()" << std::endl;
		return this == &other;
	}
};

class Button : public Clickable, public Rect {
public:
	Button() : Clickable(), Rect() {

	}
};

int main() {
	Button btn;
	btn.name = "Button";

	std::cout << std::boolalpha;
	std::cout << "button.equals(button) = " << btn.Clickable::Equals(btn) << std::endl;

	Button btn2;
	std::cout << "button.equals(btn2) = " << btn.Rect::Equals(btn2) << std::endl;
}