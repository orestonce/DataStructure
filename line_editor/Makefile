obj=lineeditor

a.out	: ${obj}.o main.o
	g++ ${obj}.o main.o

main.o	: main.cpp ${obj}.h 
	g++ -std=c++11 -Wall -Werror $< -c 

${obj}.o	: ${obj}.cpp ${obj}.h 
	g++ -std=c++11 -Wall -Werror $< -c

clean	:
	rm *.o a.out -f
