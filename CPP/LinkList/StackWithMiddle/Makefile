OBJS = BasicStack.o MiddleSupportedStack.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
RM = rm -f

myStack : $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o myStack

BasicStack.o : common.h BasicStack.h BasicStack.cpp
    $(CC) $(CFLAGS) BasicStack.cpp

MiddleSupportedStack.o : common.h MiddleSupportedStack.h MiddleSupportedStack.cpp
    $(CC) $(CFLAGS) MiddleSupportedStack.cpp

clean:

    $(RM) $(OBJS) *~ myStack

tar:

    tar cfv p1.tar Movie.h Movie.cpp Name.h Name.cpp NameList.h \
            NameList.cpp  Iterator.cpp Iterator.h
