target = text_query

#path=/home/ming/project
path := $(shell pwd)

GG = g++
FLAGS = -std=c++11 -Werror
GCC = gcc -Werror -c

HeadPath := $(path)/../h

queryobj = text_query.o
querysrc = text_query.cpp

queryhead := $(HeadPath)/text_query.h

all:$(queryobj)
	$(GG) $(queryobj) -o $(target)

$(queryobj):$(querysrc) $(queryhead)
	$(GG) $(FLAGS) -I $(HeadPath) -c $(querysrc) -o $(queryobj) 

.PHONY:clean
clean:
	-rm -f $(queryobj) $(target)

