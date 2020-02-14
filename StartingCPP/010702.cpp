#include <iostream>
#include <iterator>
#include <string>
#include "Array.h"


int main() {
	Array<std::string> youtuber(3);
	Array<std::string> names{ "sisigami leona", "domyozi kokoa", "hochino mea" };

	typedef Array<std::string>::Iterator Iter;

	std::copy(std::move_iterator<Iter>(names.begin()), std::move_iterator<Iter>(names.end()), youtuber.begin());

	for (auto& n : youtuber) {
		std::cout << n << std::endl;
	}
}