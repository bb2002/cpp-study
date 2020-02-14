#include <iostream>
#include <vector>

class Group;

class Youtuber {
public:
	Youtuber(std::string name);

	void echo() const;

	void set_group(std::shared_ptr<Group> group) {
		this->currentGroup = group;
	}

	~Youtuber();

private:
	std::string _name;
	std::shared_ptr<Group> currentGroup;
};

class Group {
public:
	Group(std::string name, std::vector<std::weak_ptr<Youtuber>> youtubers);

	void show_youtubers();

	~Group();

private:
	std::string _name;
	std::vector<std::weak_ptr<Youtuber>> _youtubers;
};

int main() {
	{
		std::shared_ptr<Youtuber> kotone = std::make_shared<Youtuber>("텐진 코토네");
		std::shared_ptr<Youtuber> leona = std::make_shared<Youtuber>("시시가미 레오나");
		std::shared_ptr<Youtuber> mea = std::make_shared<Youtuber>("호시노 메아");
		std::vector<std::weak_ptr<Youtuber>> youtubers;
		youtubers.push_back(kotone);
		youtubers.push_back(leona);
		youtubers.push_back(mea);

		std::shared_ptr<Group> cms = std::make_shared<Group>("CMS", youtubers);

		kotone->set_group(cms);
		leona->set_group(cms);
		mea->set_group(cms);

		cms->show_youtubers();
	}

	std::cout << "exec ok." << std::endl;
}

Youtuber::Youtuber(std::string name)
{
	std::cout << "Youtuber() : " << name.data() << std::endl;
	this->_name = name;
}

void Youtuber::echo() const
{
	std::cout << "유튜버 : " << _name.data() << std::endl;
}

Youtuber::~Youtuber() {
	std::cout << "~Youtuber() : " << _name.data() << std::endl;
}

Group::Group(std::string name, std::vector<std::weak_ptr<Youtuber>> youtubers)
{
	std::cout << "Group() : " << name.data() << std::endl;
	this->_name = name;
	this->_youtubers = youtubers;
}

void Group::show_youtubers()
{
	for (auto& y : _youtubers) {
		std::shared_ptr<Youtuber> a = y.lock();
		a->echo();
	}
}

Group::~Group()
{
	std::cout << "~Group() : " << _name.data() << std::endl;
}
