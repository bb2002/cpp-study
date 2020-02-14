#include <iostream>

class Song;

class Album {
public:
	Album(std::string name, Song* newsong) : _name(name) {
		_song.reset(newsong);
		_song->SetAlbum(this);
		std::cout << "Song()" << std::endl;
	}

	void release() {
		if (_song != nullptr) {
			std::cout << "Album::release()" << std::endl;
			_song.reset();
		}
	}

	~Album() {
		if (_song != nullptr) {
			std::cout << "~Album()" << std::endl;
			_song->release();
			_song.reset();
		}
	}

private:
	std::string _name;
	std::shared_ptr<Song> _song;
};

class Song {
public:
	Song(std::string name, std::string artist = "undefined") : _title(name), _artist(artist) {
		std::cout << "Song() :: " << name.data() << std::endl;
	}

	void SetAlbum(Album* newalbum) {
		_album.reset(newalbum);
	}

	const char* GetTitle() const {
		return _title.data();
	}

	const char* GetArtist() const {
		return _artist.data();
	}

	void release() {
		if (_album != nullptr) {
			std::cout << "Delete album " << std::endl;
			_album.reset();
		}
	}

	~Song() {
		if (_album != nullptr) {
			std::cout << "~Song() :: " << _title.data() << std::endl;
			_album->release();
			_album.reset();
		}
	}

private:
	std::string _title;
	std::string _artist;
	std::shared_ptr<Album> _album;
};

int main() {

}