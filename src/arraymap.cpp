#include <iostream>
#include "../include/map.h"
#include "../include/keyvalue.h"
#include "../include/node.h"

using namespace std;
template <typename K, typename V>
class ArrayMap: public Map<K,V>{
private:
  Collection<KeyValue<K,V>> data;
  public:
    ArrayMap():data(Collection<KeyValue<K,V>>(10)){}
    //Returns the number of entries that have been put into the map.
    int getSize(){
      return this->data.getSize();
    }

    //Puts an entry with a key of type K and a value of type V into the map
    //only if there exists no other entry in the map with the same key.
    //Returns true if the put is successful.
    //Returns false, otherwise.
    bool put(K key, V value){
      if(!this->containsKey(key)){
        KeyValue<K,V> newItem(key, value);
        this->data.add(newItem);
        return true;
      }
      return false;

    }

    //Returns the value of an entry from the map whose key matches with a given key.
    //Returns NULL if there is no entry in the map with the given key.
    V get(K key){
      for(int i = 0; i < this->getSize(); i++){
        if(key == this->data.get(i).key){
          return this->data.get(i).value;
        }
      }
      return NULL;
    }

    //Removes an entry from the map, if there is any whose key matches with a given key.
    //Returns the value of the removed entry, if the remove is successful.
    //Returns NULL, if the remove fails.
    V remove(K key){
      Collection<KeyValue<K,V>> tempCol(this->data.getCapacity());

      for(int i = 0; i < this->getSize(); i++){
        if(key == this->data.get(i).key){
          V temp = this->data.get(i).value;

          for(int x = i+1; x < this->getSize(); x++){
            tempCol.add(this->data.get(x));
          }

          this->data = tempCol;
          return temp;
        }
        else{
          tempCol.add(this->data.get(i));
        }
      }
      return NULL;
    }

    //Returns true, if there is an entry in the map whose key matches with a given key.
    //Returns false, otherwise.
    bool containsKey(K key){
      for(int i = 0; i < this->getSize(); i++){
        if(key == this->data.get(i).key){
          return true;
        }
      }
      return false;
    }

    //Returns true, if there is at least one entry in the map whose value matches with a given value.
    //Returns false, otherwise.
    bool containsValue(V val){
      for(int i = 0; i < this->getSize(); i++){
        if(val == this->data.get(i).value){
          return true;
        }
      }
      return false;
    }

    //Returns all the keys in the map in a  Collection pointer.
    //Use Collection class from 'include/collection.h'
    Collection<K>* keys(){
      Collection<K> *keyCollection = new Collection<K>(this->getSize());
      for(int i = 0; i < this->getSize(); i++){
        keyCollection->add(this->data.get(i).key);
      }
      return keyCollection;
    }

    //Returns all the values of the map in a Collection pointers.
    //Use Collection class from 'include/collection.h'
    Collection<V>* values(){
      Collection<V> *valueCollection = new Collection<V>(this->getSize());
      for(int i = 0; i < this->getSize(); i++){
        valueCollection->add(this->data.get(i).value);
      }
      return valueCollection;
    }
};
