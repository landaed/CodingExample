#include <iostream>
#include "../include/map.h"
#include "../include/keyvalue.h"
#include "../include/node.h"

using namespace std;
template <typename K, typename V>
class LinkedMap: public Map<K,V>{
private:
  Node<K,V> *data;
  public:
    LinkedMap():data(new Node<K,V>){}
    //Returns the number of entries that have been put into the map.
    int getSize(){
      int size = 0;
      Node<K,V> *current = this->data;
      while(current->next != NULL){
        current = current->next;
        size++;
      }
      return size;
    }

    //Puts an entry with a key of type K and a value of type V into the map
    //only if there exists no other entry in the map with the same key.
    //Returns true if the put is successful.
    //Returns false, otherwise.
    bool put(K key, V value){
      if(!this->containsKey(key)){
        KeyValue<K,V> newItem(key, value);
        Node<K,V> *current = this->data;
        while(current->next != NULL){
          current = current->next;
        }
        current->next = new Node<K,V>(newItem);
        return true;
      }
      return false;

    }

    Node<K,V>* getNode(int index){
      Node<K,V> *current = this->data;
      for(int i = 0; i < index; i++){
        current = current->next;
      }
      return current;
    }

    //Returns the value of an entry from the map whose key matches with a given key.
    //Returns NULL if there is no entry in the map with the given key.
    V get(K key){
      for(int i = 0; i < this->getSize() + 1; i++){
        if(key == this->getNode(i)->data.key){
          return this->getNode(i)->data.value;
        }
      }
      return NULL;
    }

    //Removes an entry from the map, if there is any whose key matches with a given key.
    //Returns the value of the removed entry, if the remove is successful.
    //Returns NULL, if the remove fails.
    V remove(K key){

      for(int i = 0; i < this->getSize(); i++){
        if(key == this->getNode(i)->next->data.key){
          V temp = this->getNode(i)->next->data.value;
          this->getNode(i)->next = this->getNode(i)->next->next;

          return temp;
        }
      }
      return NULL;
    }

    //Returns true, if there is an entry in the map whose key matches with a given key.
    //Returns false, otherwise.
    bool containsKey(K key){
      Node<K,V> *current = this->data;
      while(current->next != NULL){
        current = current->next;
        if(key == current->data.key){
          return true;
        }
      }
      return false;
    }

    //Returns true, if there is at least one entry in the map whose value matches with a given value.
    //Returns false, otherwise.
    bool containsValue(V val){
      Node<K,V> *current = this->data;
      while(current->next != NULL){
        current = current->next;
        if(val == current->data.value){
          return true;
        }
      }
      return false;
    }

    //Returns all the keys in the map in a  Collection pointer.
    //Use Collection class from 'include/collection.h'
    Collection<K>* keys(){
      Collection<K> *keyCollection = new Collection<K>(this->getSize());
      Node<K,V> *current = this->data;
      for(int i = 0; i < this->getSize(); i++){
        current = current->next;
        keyCollection->add(current->data.key);
      }
      return keyCollection;
    }

    //Returns all the values of the map in a Collection pointers.
    //Use Collection class from 'include/collection.h'
    Collection<V>* values(){
      Collection<V> *valueCollection = new Collection<V>(this->getSize());
      Node<K,V> *current = this->data;
      for(int i = 0; i < this->getSize(); i++){
        current = current->next;
        valueCollection->add(current->data.value);
      }
      return valueCollection;
    }
};
