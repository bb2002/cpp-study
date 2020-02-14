#include <iostream>
#include <fstream>
#include <string>

void make_file(const char* input, const char* output) {
	std::ifstream input_file(input);
	if (!input_file.is_open()) {
		std::cout << "������ �� �� �����ϴ�. >> input" << std::endl;
		return;
	}

	std::ofstream output_file(output);
	if (!output_file.is_open()) {
		std::cout << "������ �� �� �����ϴ�. >> output" << std::endl;
		return;
	}

	std::filebuf* inbuf = input_file.rdbuf();
	std::filebuf* outbuf = output_file.rdbuf();

	char c;
	while ((c = inbuf->sbumpc()) != EOF) {
		outbuf->sputc(c);
	}

	input_file.close();
	output_file.close();
}

void read_file(const char* input) {
	std::ifstream input_file(input);
	if (!input_file.is_open()) {
		std::cout << "������ ���� �� �����ϴ�." << std::endl;
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