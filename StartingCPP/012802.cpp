#include <iostream>

class Youtuber {
public:
	Youtuber(std::string name = "undefined", int subs = 0) {
		this->_name = name;
		this->_subs = subs;
	}

	const std::string& getName() const {
		return this->_name;
	}

	int getSubs() const {
		return this->_subs;
	}

	std::ostream& operator<<(std::ostream& os) {
		std::cout << "name : " << _name.data() << ", subs : " << _subs;
		return os;
	}

	~Youtuber() {
		std::cout << _name.data() << " is deleted" << std::endl;
	}

private:
	std::string _name;
	int _subs;
};

static std::ostream& operator<<(std::ostream& os, Youtuber& youtuber) {
	std::cout << "name : " << youtuber.getName().data() << ", subs : " << youtuber.getSubs();
	return os;
}

int main() {
	std::unique_ptr<Youtuber> leona = std::make_unique<Youtuber>(Youtuber("�ýð��� ������", 133000));
	std::unique_ptr<Youtuber> mea(new Youtuber("ȣ�ó� �޾�", 78000));
	std::unique_ptr<Youtuber> cocoa(new Youtuber("������ ���ھ�", 330000));

	Youtuber* cocoa_ptr = cocoa.release();
	if (cocoa == nullptr) {
		std::cout << "���ھ�»�� ��������ϴ�." << std::endl;
	}
	else {
		std::cout << *cocoa << std::endl;
	}

	std::cout << *leona << std::endl;
	std::cout << *mea << std::endl;
	std::cout << *cocoa_ptr << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
	
}