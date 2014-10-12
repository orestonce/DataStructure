obj=mazepath

a.out	: main.o
	g++ main.o

main.o	: main.cpp ${obj}.h 
	g++ -std=c++11 -Wall $< -c 


clean	:
	rm *.o a.out -f
