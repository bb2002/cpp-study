#include <iostream>

enum Days {
	Sunday = 0,
	Monday,
	Tue,
	Wens = Sunday + 3
};

enum class Months : short {
	Jan = 1,
	Feb = Jan + 1,
	Mar, Apr, May, Dec
};

int main() {
	Days today = Tue;
	Days asita = (Days)(Tue + 1);

	Months mon = Months::Apr;
}