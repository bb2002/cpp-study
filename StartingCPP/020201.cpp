#include <iostream>
#include <fstream>
#include <string>

void make_file(const char* input, const char* output) {
	std::ifstream input_file(input);
	if (!input_file.is_open()) {
		std::cout << "파일을 열 수 없습니다. >> input" << std::endl;
		return;
	}

	std::ofstream output_file(output);
	if (!output_file.is_open()) {
		std::cout << "파일을 열 수 없습니다. >> output" << std::endl;
		return;
	}

	char data[100];
	while (input_file.get(data, 100)) {
		output_file << data;
	}

	input_file.close();
	output_file.close();
}

void read_file(const char* input) {
	std::ifstream input_file(input);
	if (!input_file.is_open()) {
		std::cout << "파일을 읽을 수 없습니다." << std::endl;
		return;
	}

	std::string data;
	while (input_file >> data) {
		std::cout << data << std::endl;
	}

	input_file.close();
}

int main() {
	char in[1000];
	char out[1000];
	std::cout << "input file: ";
	std::cin >> in;

	std::cout << "output file: ";
	std::cin >> out;

	make_file(in, out);
	std::cout << "COPY OK!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	read_file(out);
}