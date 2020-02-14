#include <iostream>
#include <fstream>

int main() {
	char in[100];
	char out[100];
	std::cin >> in;
	std::cin >> out;

	std::ifstream input(in, std::ios::binary | std::ios::in);
	std::ofstream output(out, std::ios::binary | std::ios::out);

	if (!input.is_open() || !output.is_open()) {
		std::cout << "파일을 열지 못했습니다." << std::endl;
		return 0;
	}

	input.seekg(0, input.end);
	int len = input.tellg();
	input.seekg(0, input.beg);
	char buf[1024];
	int count = 0;

	while (input.read(buf, sizeof(buf))) {
		output.write(buf, sizeof(buf));
		count += input.gcount();
	}

	int cnt = input.gcount();
	output.write(buf, cnt);
	count += cnt;

	std::cout << "full size :: " << count << std::endl;
}