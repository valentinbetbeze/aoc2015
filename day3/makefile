TARGET=day3
CC=g++
CXXFLAGS=-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic \
			  -pedantic-errors -std=c++14 -Og -g 

all : day3.cpp santa.cpp street.cpp
	${CC} ${CXXFLAGS} -o ${TARGET} $^

clean :
	-rm ${TARGET} *.out *.o *.map
