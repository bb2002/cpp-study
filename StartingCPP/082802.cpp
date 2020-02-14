#include "pch.h"
#include <iostream>

union DataValue1 {
	int		v_int;			// 4Byte ũ��
	float	v_float;		// 4Byte ũ��
	char	v_string[4];	// 4Byte ũ��
};

struct DataValue2 {
	int		v_int;			// 4Byte ũ��
	float	v_float;		// 4Byte ũ��
	char	v_string[4];	// 4Byte ũ��
};

int main() {
	std::cout << "����ü ũ�� : " << sizeof(DataValue1) << std::endl;
	std::cout << "����ü ũ�� : " << sizeof(DataValue2) << std::endl;
}