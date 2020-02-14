#include <iostream>

template <typename T, typename D>
class MyMap {
	MyMap(T a, D b) : data(a), source(b) {

	}

private:
	T data;
	D source;
};

template <typename K, typename V, template <typename T, typename D> typename C>
class Map {
public:
	Map(K k, V v) : key(k), value(v) {
	
	}

private:
	C<K, K> key;
	C<V, V> value;
};

int main() {
	Map<int, std::string, MyMap> map(100, "ÅÆÅÆ ÀÎ¼ö");

}