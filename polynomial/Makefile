a.out	: main.cpp polynomial.h
	g++ main.cpp -std=c++11 -Wall -Werror -o a.out

run	: a.out
	./a.out < data >/dev/null 

clean	:
	rm -f a.out
