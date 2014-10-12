a.out	: evaluateexpression.o main.o
	g++ evaluateexpression.o main.o -o a.out

main.o	: evaluateexpression.h main.cpp
	g++ -std=c++11 -Wall -Werror main.cpp -c -o main.o

evaluateexpression.o	: evaluateexpression.h evaluateexpression.cpp
	g++ -std=c++11 -Wall -Werror evaluateexpression.cpp -c 

clean	:
	rm main.o evaluateexpression.o a.out -f
