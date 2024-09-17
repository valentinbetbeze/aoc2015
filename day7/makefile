TARGET=day7
CC=g++
CXXFLAGS=-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic \
			  -pedantic-errors -std=c++14 -Og -g
INCLUDES=-I../helper

all : ${TARGET}.cpp ../helper/helper.cpp
	${CC} ${CXXFLAGS} ${INCLUDES} $^ -o ${TARGET}

clean :
	-rm ${TARGET} *.out *.o *.map
