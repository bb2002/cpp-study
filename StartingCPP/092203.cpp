#include <iostream>

enum PoppinParty {
	Kasumi = 0,
	Arisa = 1,
	Saaya = 2,
	Rimi = 3,
	Tae = 4
};

const char* Names[] = {
	"Toyama Kasumi",
	"Ichigaya Arisa",
	"Yamabuki Saya",
	"Rimiring",
	"Hanazono Tae"
};

template <PoppinParty P>
class Select {
public:
	const char* GetName() {
		return Names[P];
	}
};

int main() {
	Select<Rimi> Char;
	std::cout << Char.GetName() << std::endl;
}