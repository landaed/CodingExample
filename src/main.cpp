#include <iostream>
#include <string>
#include "../include/keyvalue.h"
#include "../include/collection.h"
#include "../include/map.h"
#include "arraymap.cpp"
#include "linkedmap.cpp"

using namespace std;

int main() {
	ArrayMap<string, string> arrayMap;
	LinkedMap<string, string> linkedMap;


	string countries[5] = {"United States of America", "United Kingdom", "Canada", "Australia", "Mexico"};
	string capitals[5] = {"Washington", "London", "Ottawa", "Canberra", "Mexico City"};

	string brazil("Brazil");
	string brazil_capital("Brasilia");


	//Testing ArrayMap using Map ADT reference
	cout<<"Testing ArrayMap using Map ADT reference................."<<endl;
	Map<string, string>& mapRef1 = arrayMap;

	for(int i=0; i<5; i++) {
		mapRef1.put(countries[i], capitals[i]);
	}

	for (int i=0; i<5; i++) {
		cout<<"The capital of "<< countries[i]<<" is "<<mapRef1.get(countries[i])<<"."<<endl;
	}

	cout<<"Before adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef1.containsValue(brazil_capital)? "true":"false")<<endl;

	mapRef1.put(brazil, brazil_capital);
	cout<<"Adding adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef1.containsValue(brazil_capital)? "true": "false")<<endl;

	mapRef1.remove(brazil);
	cout<<"After removing "<<brazil<<" and its capital "<<brazil_capital<<" from the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef1.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef1.containsValue(brazil_capital)? "true": "false")<<endl;

	Collection<string>* keys = mapRef1.keys();
	int keySize = keys->getSize();
	cout<<"Keys size: "<<keySize<<endl;
	cout<<"Keys in the map are: "<<endl;
	for(int i=0; i<keySize-1; i++) {
		cout<<keys->get(i)<<", ";
	}
	cout<<keys->get(keySize-1)<<endl;

	Collection<string>* values = mapRef1.values();
	int valueSize = values->getSize();
	cout<<"Values size: "<<valueSize<<endl;
	cout<<"Values in the map are: "<<endl;
	for(int i=0; i<valueSize-1; i++) {
		cout<<values->get(i)<<", ";
	}
	cout<<values->get(valueSize-1)<<endl;

	delete values;

	//Testing LinkedMap using Map ADT reference
	cout<<"Testing LinkedMap using Map ADT reference................."<<endl;
	Map<string, string>& mapRef2 = linkedMap;

	for(int i=0; i<5; i++) {
		mapRef2.put(countries[i], capitals[i]);
	}

	for (int i=0; i<5; i++) {
		cout<<"The capital of "<< countries[i]<<" is "<<mapRef2.get(countries[i])<<"."<<endl;
	}


	cout<<"Before adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;
	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2.containsValue(brazil_capital)? "true":"false")<<endl;

	mapRef2.put(brazil, brazil_capital);
	cout<<"Adding adding "<<brazil<<" and its capital "<<brazil_capital<<" into the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2.containsValue(brazil_capital)? "true": "false")<<endl;

	mapRef2.remove(brazil);
	cout<<"After removing "<<brazil<<" and its capital "<<brazil_capital<<" from the map"<<endl;

	cout<<"Contains Key: "<<brazil<<" : "<<(mapRef2.containsKey(brazil)? "true": "false")<<endl;
	cout<<"Contains Value: "<<brazil_capital<<" : "<<(mapRef2.containsValue(brazil_capital)? "true": "false")<<endl;

	Collection<string>* linkedMapKeys = mapRef2.keys();
	int linkedMapKeySize = linkedMapKeys->getSize();
	cout<<"Keys size: "<<linkedMapKeySize<<endl;
	cout<<"Keys in the map are: "<<endl;
	for(int i=0; i<linkedMapKeySize-1; i++) {
		cout<<linkedMapKeys->get(i)<<", ";
	}
	cout<<linkedMapKeys->get(linkedMapKeySize-1)<<endl;

	Collection<string>* linkedMapValues = mapRef2.values();
	int linkedMapValueSize = linkedMapValues->getSize();
	cout<<"Values size: "<<linkedMapValueSize<<endl;
	cout<<"Values in the map are: "<<endl;
	for(int i=0; i<linkedMapValueSize-1; i++) {
		cout<<linkedMapValues->get(i)<<", ";
	}
	cout<<linkedMapValues->get(linkedMapValueSize-1)<<endl;

	delete linkedMapValues;

	return 0;
}
