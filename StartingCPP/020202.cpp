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

	char* buf = new char[len];
	input.read(buf, len);
	output.write(buf, len);
	output.write(buf, len);
	delete[] buf;

	if (input.good()) {
		std::cout << "FILE WRITE SUCCESS!!" << std::endl;
	}
	else {
		std::cout << "FILE WRITE FAILED" << std::endl;
	}

	input.close();
	output.close();

	return 0;
}