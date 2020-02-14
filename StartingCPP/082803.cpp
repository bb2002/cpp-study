#include "pch.h"
#include <iostream>

#define NONE		0
#define INTEGER		1
#define FLOAT		2
#define STRING		3

union DataValue {
	int		v_int;
	float	v_float;
	char	*v_char;
};

struct DataNode {
	void ReadSomeInput() {
		char *p;
		char s[100];

		std::cout << "문자나 정수를 입력하세요. : ";
		std::cin >> s;

		// 입력값이 숫자인지 확인 한다.
		long l = strtol(s, &p, 10);
		if (*p == NULL) {
			// 숫자 입니다.
			type = INTEGER;
			value.v_int = l;
			return;
		}

		// 입력값이 실수인지 확인 한다.
		float f = strtof(s, &p);
		if (*p == NULL) {
			// 플롯 입니다.
			type = FLOAT;
			value.v_float = f;
			return;
		}

		// 아무것도 아님. 문자임
		type = STRING;
		value.v_char = (char*) malloc(strlen(s) + 1);
		strcpy_s(value.v_char, strlen(s) + 1, s);
	}

	void FreeString() {
		if (type == STRING) {
			free(value.v_char);
		}
	}

	int type;
	DataValue value;
};

int main() {
	DataNode Node;
	Node.ReadSomeInput();

	switch (Node.type)
	{
	case INTEGER:
		std::cout << "INT : " << Node.value.v_int << std::endl;
		break;

	case FLOAT:
		std::cout << "FLOAT : " << Node.value.v_float << std::endl;
		break;

	case STRING:
		std::cout << "STRING : " << Node.value.v_char << std::endl;
		break;
	}

	Node.FreeString();




	int a = 10;
	int *ap = &a;
	int **app = &ap;

	std::cout << "이중 포인터 : " << *(*app) << std::endl;
}