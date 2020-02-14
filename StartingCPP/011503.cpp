#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <tuple>
#include "Array.h"

typedef std::pair<std::string, double> MyPair;

bool compare(const MyPair& i, const MyPair& j) {
	return i.second < j.second;
}

int main() {
	MyPair prod1;
	MyPair prod2("Sisigami", 3.141592);
	MyPair prod3(prod2);
	MyPair prod4;

	prod1 = std::make_pair("Mea", 2.718);
	prod4.first = "Kokoa";
	prod4.second = 3.141592 / 2.718;

	Array<MyPair> prods(5);
	prods[0] = prod1;
	prods[1] = prod2;
	prods[2] = prod3;
	prods[3] = prod4;
	prods[4] = std::make_pair<std::string, double>("YuNi", 3.141592 * 2.718);

	std::sort(prods.begin(), prods.end(), compare);

	for (int i = 0; i < 5; ++i) {
		std::cout << i << ". " << prods[i].first << " 쨩의 무리수는 : " << prods[i].second << " desu." << std::endl;
	}
}