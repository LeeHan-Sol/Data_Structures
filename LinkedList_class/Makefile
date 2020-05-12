CC = gcc
OBJS = Node.o List.o main.o
TARGET = linkedList

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

clean :
	rm -f *.o $(TARGET)

Node.o : Node.h Node.c
List.o : List.h List.c
main.o : main.c
