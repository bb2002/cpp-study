#include <iostream>

class Distance {
private:
	int meters;
	int centimeters;

public:
	Distance(int f = 0, int i = 0) {
		SetDistance(f, i);
	}

	void SetDistance(int i, int f) {
		f += (i / 100);
		i %= 100;

		meters = f;
		centimeters = i;
	}

	int GetMeters() const {
		return meters;
	}

	int GetCentimeters() const {
		return centimeters;
	}

	friend std::ostream& operator<<(std::ostream& os, const Distance& d) {
		os << d.GetMeters() << "m " << d.GetCentimeters() << "cm";
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Distance &d) {
		int m, cm;
		std::cout << "m : ";
		in >> m;
		std::cout << "cm : ";
		in >> cm;
		d.SetDistance(m, cm);
		return in;
	}
};

int main() {
	Distance d1(16, 22), d2(33, 48), d3;
	std::cin >> d3;

	std::cout << d1 << std::endl;
	std::cout << d2 << std::endl;
	std::cout << d3 << std::endl;
}