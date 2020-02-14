#include <iostream>
#include <ctime>

int main() {
	time_t now = time(0);
	std::cout << "unix time : " << now << std::endl;
	char* dt = ctime(&now);
	std::cout << dt << std::endl;

	tm* localtm = localtime(&now);
	std::cout << "¿ÃÇØ´Â : " << localtm->tm_year << std::endl;
}