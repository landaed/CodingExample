assignment5.exe:	arraymap.o main.o linkedmap.o
	g++ -std=c++11 -Wall -g -o ./bin/assignment5.exe ./build/arraymap.o ./build/main.o ./build/linkedmap.o

arraymap.o: ./include/collection.h ./src/arraymap.cpp ./include/keyvalue.h ./include/map.h
	g++ -std=c++11 -Wall -g -c -o ./build/arraymap.o ./src/arraymap.cpp

linkedmap.o: ./include/collection.h ./src/linkedmap.cpp ./include/keyvalue.h ./include/map.h
	g++ -std=c++11 -Wall -g -c -o ./build/linkedmap.o ./src/linkedmap.cpp

main.o: ./src/main.cpp ./include/collection.h ./include/keyvalue.h ./include/map.h ./src/linkedmap.cpp ./src/arraymap.cpp
	g++ -std=c++11 -Wall -g -c -o ./build/main.o ./src/main.cpp

clean:
	rm ../build/*
	rm ../bin/*
