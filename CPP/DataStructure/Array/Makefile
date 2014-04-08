#This is an easier to use and modify makefile, but it is slightly more difficult to read than the simple one:

#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = gcc
CPP = g++
PLATFORM = $(shell uname -s)

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
#
INCLUDES = -I/home/ravi/LapiMyProg/C++Faq/SampleTest/include  -I./include

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L/home/ravi/LapiMyProg/C++Faq/SampleTest/lib  -L./lib

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lmylib -lm

# define the C source files
SRCDIR = /home/ravi/LapiMyProg/C++Faq/SampleTest/src/
SRCS = $(SRCDIR)main.cpp $(SRCDIR)hello.cpp $(SRCDIR)factorial.cpp 

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
TARGET = $(shell mkdir $(SRCDIR)$(PLATFORM))
OBJS = $(SRCS:.c=.o)
OBJSCPP = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = main

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN)
	@echo  Simple compiler named main has been compiled
	@echo  Platform is $(PLATFORM)

$(MAIN): $(OBJSCPP) 
#	$(CPP) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJSCPP) $(LFLAGS) $(LIBS)
	$(TARGET)
	$(CPP) $(CFLAGS) $(INCLUDES) -o $(SRCDIR)$(PLATFORM)/$(MAIN) $(OBJSCPP) 

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CPP) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) $(SRCDIR)*.o *~ $(SRCDIR)$(PLATFORM)/$(MAIN) 
	$(RM) -r $(SRCDIR)$(PLATFORM)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

