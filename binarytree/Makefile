a.out	: main.cpp binarytree.h binarytree.hpp
	g++ main.cpp -Wall -Werror -std=c++11 -o a.out

clean	:
	rm a.out -f

run	:	a.out	data
	./a.out < data
