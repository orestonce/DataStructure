a.out	: main.o convert.o
	g++ main.o convert.o -std=c++11 -Wall -Werror -o a.out

main.o	: main.cpp convert.h
	g++ -c main.cpp -std=c++11 -Wall -Werror 

convert.o	: convert.cpp convert.h
	g++ -c convert.cpp -std=c++11 -Wall -Werror

clean	:
	rm *.o a.out -f
