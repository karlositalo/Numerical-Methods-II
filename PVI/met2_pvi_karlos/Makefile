OBJS = main.o PVILib.o
CC = g++

main : $(OBJS)
	$(CC)  $(OBJS) -o main

main.o : main.cpp
	$(CC) -c main.cpp

PVILab.o : PVILib.h PVILib.cpp
	$(CC) -c PVILib.cpp

clean:
	\rm *.o *~ main

tar:
	tar cfv main.tar main.h main.cpp PVILib.h PVILib.cpp 
