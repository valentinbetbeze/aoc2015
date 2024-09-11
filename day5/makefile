TARGET=day5
CC=g++
CXXFLAGS=-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic \
			  -pedantic-errors -std=c++14 -Og -g

all : ${TARGET}.cpp
	${CC} ${CXXFLAGS} $^ -o ${TARGET} -lcrypto -lssl

clean :
	-rm ${TARGET} *.out *.o *.map
