#include <iostream>
#include <string>
#include <vector>


int n;
bool areFriend[10][10] = {false, };

int countParings(bool taken[10]) {
	bool finished = true;

	for (int i = 0; i < n; ++i) {
		if (!taken[i]) finished = false;
	}
	if (finished) {
		return 1;
	}
	int ret = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!taken[i] && !taken[j] && areFriend[i][j]) {
				taken[i] = taken[j] = true;
				ret += countParings(taken);
				taken[i] = taken[j] = false;
			}
		}
	}

	return ret;

}

int main() {
	int testCount = 0;
	std::cin >> testCount;

	for (int i = 0; i < testCount; ++i) {
		int students = 0;
		int couples = 0;

		scanf("%d %d", &students, &couples);
		n = students;

		for (int i = 0; i < couples; ++i) {
			int a = 0;
			int b = 0;
			scanf("%d %d", &a, &b);
			areFriend[a][b] = true;
		}

		bool taken[10] = {false, };
		std::cout << "cout : " << countParings(taken) << std::endl;
	}


}