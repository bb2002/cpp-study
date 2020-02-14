#include <iostream>

class Ours;

class Friends {
public:
	int Fun1(Ours& a);

private:
	int Fun2(Ours& a);
};

class Ours {
private:
	int _b;

	friend int Friends::Fun1(Ours&);
};

int main() {

}

int Friends::Fun1(Ours & a)
{
	return a._b;
}

int Friends::Fun2(Ours & a)
{
	//return a._b;
	return 0;
}
