OBJS = main.o LibKarlos.o
CC = g++

main : $(OBJS)
	$(CC)  $(OBJS) -o main

main.o : main.cpp
	$(CC) -c main.cpp

funcoes.o : LibKarlos.h LibKarlos.cpp
	$(CC) -c LibKarlos.cpp

clean:
	\rm *.o *~ main

tar:
	tar cfv main.tar main.h main.cpp LibKarlos.h LibKarlos.cpp 
