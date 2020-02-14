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

		std::cout << "���ڳ� ������ �Է��ϼ���. : ";
		std::cin >> s;

		// �Է°��� �������� Ȯ�� �Ѵ�.
		long l = strtol(s, &p, 10);
		if (*p == NULL) {
			// ���� �Դϴ�.
			type = INTEGER;
			value.v_int = l;
			return;
		}

		// �Է°��� �Ǽ����� Ȯ�� �Ѵ�.
		float f = strtof(s, &p);
		if (*p == NULL) {
			// �÷� �Դϴ�.
			type = FLOAT;
			value.v_float = f;
			return;
		}

		// �ƹ��͵� �ƴ�. ������
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

	std::cout << "���� ������ : " << *(*app) << std::endl;
}