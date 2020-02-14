#include <iostream>
#include <string>
#include <vector>

class Track {
public:
	Track(std::string name, std::string artist, int level) : _name(name), _artist(artist), _level(level) {
		std::cout << "Create Track() : " << _name << std::endl;
	}

	const char* GetTitle() {
		return _name.data();
	}

	const char* GetArtist() {
		return _artist.data();
	}

	int GetLevel() {
		return _level;
	}

	~Track() {
		std::cout << "Delete ~Track()" << _name << std::endl;
	}

private:
	std::string _name;
	std::string _artist;
	int _level;
};

int main() {
	std::shared_ptr<Track> losthogok(new Track("�ν�Ʈ�� �� ȣ��", "IA", 12));
	std::cout << losthogok->GetTitle() << "�� count : " << losthogok.use_count() << std::endl;

	auto happysync = std::make_shared<Track>("���ǽŹ�������", "DECO*27", 11);
	std::shared_ptr<Track> happysync2(happysync);
	std::cout << happysync2->GetTitle() << " �� count : " << happysync.use_count() << std::endl;

	happysync2.reset(new Track("��Ÿ����Ʈ", "������ ��", 13));
	auto lobs = std::make_shared<Track>("�κ�", "ȣ�ó�޾�", 10);

	std::shared_ptr<Track> sp4;
	sp4 = std::make_shared<Track>("�峭�� ���", "����í", 13);

	std::vector<std::shared_ptr<Track>> playlist;
	playlist.push_back(std::move(losthogok));
	playlist.push_back(std::move(happysync));
	playlist.push_back(std::move(happysync2));
	playlist.push_back(lobs);
	playlist.push_back(sp4);

	for (auto& sp : playlist) {
		std::cout << "Playing : " << sp->GetTitle() << ", By " << sp->GetArtist() << ", level : " << sp->GetLevel() << " -> count : " << sp.use_count() << std::endl;
	}
}