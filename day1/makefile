TARGET=day1
CC=g++
CXXFLAGS=-Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic \
			  -pedantic-errors -std=c++14 -Og -g -Wl,-Map=${TARGET}.map

all :
	${CC} ${CXXFLAGS} -o ${TARGET} ${TARGET}.cpp

clean:
	-rm ${TARGET} *.out *.o *.map
