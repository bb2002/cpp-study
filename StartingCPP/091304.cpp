#include <iostream>

#define unsafe(i) ( (i) >= 0 ? (i) : -(i) )

inline int safe(int i) {
	return i >= 0 ? i : -i;
}

constexpr int expr(int i) {
	return i >= 0 ? i : -i;
}

int main() {
	int ans, x = 0;
	ans = unsafe(x++);
	std::cout << "unsafe : " << ans << ", " << x << std::endl;

	x = 0;
	ans = safe(x++);
	std::cout << "safe : " << ans << ", " << x << std::endl;

	x = 0;
	ans = expr(x++);
	std::cout << "expr : " << ans << ", " << x << std::endl;
}