#include "pch.h"
#include <iostream>

union DataValue1 {
	int		v_int;			// 4Byte 크기
	float	v_float;		// 4Byte 크기
	char	v_string[4];	// 4Byte 크기
};

struct DataValue2 {
	int		v_int;			// 4Byte 크기
	float	v_float;		// 4Byte 크기
	char	v_string[4];	// 4Byte 크기
};

int main() {
	std::cout << "공유체 크기 : " << sizeof(DataValue1) << std::endl;
	std::cout << "구조체 크기 : " << sizeof(DataValue2) << std::endl;
}