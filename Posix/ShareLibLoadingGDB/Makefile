SRC_FILES=initapi.c randapi.c test.c
OBJ_FILES=$(patsubst %.c, %.o, ${SRC_FILES})

VPATH=/home/ravi/MyProg/Posix/ShareLibLoadingGDB
CFLAGS=-c -g -Wall
LDFLAGS=-g -Wall
FPIC=-fPIC

all:
	gcc ${FPIC} ${CFLAGS} initapi.c
	gcc ${FPIC} ${CFLAGS} randapi.c
	gcc -shared ${LDFLAGS} initapi.o randapi.o -o libmyrand.so
	gcc ${LDFLAGS}  test.c -L. -lmyrand -o test


%.o:%.c
	gcc ${CFLAGS} -o $@ $ 

clean:
	rm *.o *.so 

