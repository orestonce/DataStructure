a.out	: suitpair.o main.o
	g++ suitpair.o main.o -o a.out

main.o	: suitpair.h main.cpp
	g++ -std=c++11 -Wall -Werror main.cpp -c -o main.o

suitpair.o	: suitpair.h suitpair.cpp
	g++ -std=c++11 -Wall -Werror suitpair.cpp -c -o suitpair.o

clean	:
	rm main.o suitpair.o a.out -f
