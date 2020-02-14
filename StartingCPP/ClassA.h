#pragma once
#include <iostream>

class BBB;

class AAA {
	inline void AAAAA() {
		std::cout << "AAA CALL" << std::endl;
	}

	BBB* getBBB() {
		return nullptr;
	}
};

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
	// Support C Functions...
	void MyCFunction();

	int open(const char *pathname, int flags);

#ifdef __cplusplus
}
#endif // __cplusplus

