#include <iostream>
#include <cstring>

template <int i>
class A {
	int arr[i];
	const int length = i;

public:
	A() {
		memset(arr, 0, i * sizeof(int));
	}
};

struct Y {
	
};

template <const Y& b>
struct Z {

};

Y y;
Z<y> b;

int main() {
	A<100> a;
}