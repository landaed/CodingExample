#ifndef NODE_H
#define NODE_H
#include "keyvalue.h"

template <typename K, typename V> class LinkedMap;

template <typename K, typename V>
class Node {
	private:
		KeyValue<K,V> data;
		Node* next;
	public:
		Node(): next(NULL) {}
		Node(KeyValue<K,V> data): data(data), next(NULL) {}
		friend class LinkedMap<K,V>;

};

#endif
