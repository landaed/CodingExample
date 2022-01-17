#ifndef MAP_H
#define MAP_H

#include "collection.h"


//This is the specification of Map Abstract Data Type (ADT).
//The specification specifies only the expected behaviours or operations of Map ADT.
//This specification does not tell what data or data structure should be used.
//The choice of data structure is left to the implementor.
//Map ADT can be implemented using either an Array or a Linked List.
//If Map ADT is implemented using an Array data structure, it might impose a maximum capacity on the ADT.
//If Map ADT is implemented using Linked List, there will be no such limitation on ADT capacity.
//To encapsulate an entry or key-value pair you can use KeyValue class from 'include/keyvalue.h'.
//To encapsulate a Node for the Linked List you can use Node class from 'include/node.h'.
//Collection is another ADT, however, an implementation of Collection ADT is given in 'include/collection.h'.
//You can use Collection ADT implementation from 'include/collection.h'.
template <typename K, typename V>
class Map {
	public:
		//Returns the number of entries that have been put into the map.
		virtual int getSize() = 0;

		//Puts an entry with a key of type K and a value of type V into the map
		//only if there exists no other entry in the map with the same key.
		//Returns true if the put is successful.
		//Returns false, otherwise.
		virtual bool put(K, V) = 0;

		//Returns the value of an entry from the map whose key matches with a given key.
		//Returns NULL if there is no entry in the map with the given key.
		virtual V get(K) = 0;

		//Removes an entry from the map, if there is any whose key matches with a given key.
		//Returns the value of the removed entry, if the remove is successful.
		//Returns NULL, if the remove fails.
		virtual V remove(K) = 0;

		//Returns true, if there is an entry in the map whose key matches with a given key.
		//Returns false, otherwise.
		virtual bool containsKey(K) = 0;

		//Returns true, if there is at least one entry in the map whose value matches with a given value.
		//Returns false, otherwise.
		virtual bool containsValue(V) = 0;

		//Returns all the keys in the map in a  Collection pointer.
		//Use Collection class from 'include/collection.h'
		virtual Collection<K>* keys() = 0;

		//Returns all the values of the map in a Collection pointers.
		//Use Collection class from 'include/collection.h'
		virtual Collection<V>* values() = 0;
};

#endif
