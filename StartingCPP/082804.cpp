#include "pch.h"
#include <iostream>

union Data1 {
	float	v_int;
	float	v_float;
	char	v_string[4];
};

int main() {
	Data1 d1;
	d1.v_int = 3.14;

	std::cout << d1.v_float << std::endl;
}