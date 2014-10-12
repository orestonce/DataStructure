a.out	: main.o bitarea.o
	g++ main.o bitarea.o -o a.out

main.o	: main.cpp bitarea.h
	g++ -std=c++11 -Wall -Werror -c main.cpp

bitarea.o	: bitarea.cpp bitarea.h
	g++ -std=c++11 -Wall -Werror -c bitarea.cpp

clean	:
	rm a.out *.o -f
