#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Collection {
	private:
		static const int DEFAULT_CAPACITY = 1;
		int capacity;
		int size;
		T* elements;
	public:
		Collection(): capacity(DEFAULT_CAPACITY), size(0), elements(new T[DEFAULT_CAPACITY]) {}
		Collection(int capacity): capacity(capacity), size(0), elements(new T[capacity]) {}
		~Collection() {delete [] elements;}

		//Copy constructor
		Collection(const Collection& other): capacity(other.capacity), size(other.size), elements(new T[other.capacity]) {
			for(int i =0; i<size; i++) {
				elements[i] = other.elements[i];
			}
		}

		//Move constructor
		Collection(Collection&& temp): capacity(temp.capacity), size(temp.size), elements(temp.elements) { }

		//Copy assignment
		Collection& operator = (const Collection& other) {
			capacity = other.capacity;
			size = other.size;
			delete [] elements;
			elements = new T[other.capacity];
			for(int i=0; i<size; i++ ) {
				elements[i] = other.elements[i];
			}
			return (*this);
		}

		//Move assignment
		Collection& operator = (Collection&& temp) {
			capacity = temp.capacity;
			size = temp.size;
			delete []  elements;
			elements = temp.elemennts;
			temp.elements = NULL;
			return *this;
		}

		int getCapacity() { return capacity;}

		int getSize() { return size; }

		bool add(T element) {
			if(size<capacity) {
				elements[size++] = element;
				return true;
			}
			else {
				return false;
			}
		}

		T get(int index) {
			if(index>=size || index<0) {
				throw string("Out of Index");
			}

			return elements[index];
		}
};

#endif
