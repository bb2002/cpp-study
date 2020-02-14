#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	char in_path[100];
	char out_path[100];

	std::cout << "입력 파일 : ";
	std::cin >> in_path;
	std::cout << "출력 파일 : ";
	std::cin >> out_path;

	std::ifstream input;
	input.open(in_path, std::ios::binary | std::ios::in);

	std::ofstream output;
	output.open(out_path, std::ios::binary | std::ios::out);

	std::stringstream ss;
	ss << input.rdbuf();
	std::cout << ss.rdbuf() << std::endl;

	input.seekg(0, input.beg);
	char buf[1024];
	std::streamsize cnt;

	while ((cnt = input.readsome(buf, sizeof(buf)) > 0)) {
		ss << buf;
	}

	output << ss.str();

	input.close();
	output.close();
}