a.out	: main.o
	g++ main.o -o a.out

main.o	: meragelist.h main.cpp
	g++ -std=c++11 -Wall -Werror main.cpp -c -o main.o

clean	:
	rm *.o a.out -f
