#include <iostream>
#include <vector>

enum Days {
	Sunday = 0,
	Monday = Sunday + 1,
	Tuesday,
	WendesDay,
	Thursday,
	Friday,
	Saturday = Sunday + 6
};

enum class Month : short {
	Jan = 1,
	Feb,
	March,
	Apr,
	May,
	Jun,
	Jul,
	Aug,
	Sep,
	Oct,
	Nov,
	Dec
};

const char *DayNames[] = {
	"Sunday", "Monday", "Tuesady", "Wednesday", "Thusrcay", "금요일", "토요일"
};

const char* getDayName(Days day) {
	if (day < Sunday || day > Saturday) {
		return "Unknwon";
	}
	else {
		return DayNames[day];
	}
}

int main() {
	/*int n = 100;
	void* nv = &n;
	long* n01 = static_cast<long*>(nv);
	int* n02 = static_cast<int*>(&n);

	std::cout << "n = " << n << ", n01 = " << *n01 << ", n02 = " << *n02 << std::endl;

	std::vector<long> e = { 1,23,10 };
	void* voidp = &e;
	std::vector<int> *vec = static_cast<std::vector<int>*>(voidp);

	std::vector<int> vr = *vec;
	for (int a : vr) {
		std::cout << " a = " << a;
	}

	std::cout << std::endl;*/

	Month thisMonth = Month::Dec;
	Days today = static_cast<Days>(thisMonth);
	std::cout << getDayName(today) << "주는" << today + 1 << "번째 요일" << std::endl;
}