#include <iostream>
#include <fstream>

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

	if (input.is_open() && output.is_open()) {
		std::streambuf* inbuf = input.rdbuf();
		std::streambuf* outbuf = output.rdbuf();

		std::streamsize length = inbuf->pubseekoff(0, input.end);
		inbuf->pubseekoff(0, input.beg);

		char buf[1024];
		std::streamsize cnt;
		int count = 0;

		while ((cnt = inbuf->sgetn(buf, sizeof(buf))) > 0) {
			outbuf->sputn(buf, cnt);
			count += cnt;
		}

		if (length == count) {
			std::cout << "COPY SUCCESSFUL." << std::endl;
		}
		else {
			std::cout << "WTF COPY." << std::endl;
		}
	}
	else {
		std::cout << "FILE OPEN FAILED!!" << std::endl;
	}

}