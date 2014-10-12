LINK=g++
LF=
OBJ=indexkmp
CC=g++
CF=-std=c++11 -Wall -Werror

a.out	: main.o ${OBJ}.o
	${LINK} ${LF} $^ -o $@

${OBJ}.o	: ${OBJ}.cpp ${OBJ}.h
	${CC} -c ${CF} $< -o $@

main.o	: main.cpp ${OBJ}.h
	${CC} -c ${CF} $< -o $@

clean	:
	rm -f a.out *.o
