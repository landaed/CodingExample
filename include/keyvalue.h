#ifndef KEYVALUE_H
#define KEYVALUE_H

template <typename K, typename V> class ArrayMap;
template <typename K, typename V> class LinkedMap;

template <typename K, typename V>
class KeyValue {
	private:
		K key;
		V value;
	public:
		KeyValue(){};
		KeyValue(K key, V value): key(key), value(value) {}
		friend class ArrayMap<K,V>;
		friend class LinkedMap<K,V>;

};

#endif
