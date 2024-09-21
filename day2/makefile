CC = g++
CXXFLAGS = -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -pedantic \
			  -pedantic-errors -std=c++14 -Og -g
INCLUDES = -I../helper

TARGET ?= day2

all : ${TARGET}.cpp ../helper/helper.cpp
	${CC} ${CXXFLAGS} ${INCLUDES} $^ -o ${TARGET}

clean :
	-rm ${TARGET} output.cpp output *.out *.o *.map
