a.out	: blankservice.o main.o
	g++ blankservice.o main.o -o a.out

main.o	: blankservice.h main.cpp
	g++ -std=c++11 -Wall -Werror main.cpp -c -o main.o

blankservice.o	: blankservice.h blankservice.cpp
	g++ -std=c++11 -Wall -Werror blankservice.cpp -c 

clean	:
	rm *.o a.out -f
run-inLinux	:
	./a.out | grep leave | sort -k2 -n | less
