
HEADERS_AND_MAKE := Common.h Makefile

all: libThreadPool.so main
libThreadPool.so: ThreadPool.cpp Mutex.cpp Makefile Common.h
	$(CXX) -fPIC -shared -g -Wl,-soname=libThreadPool.so $(filter-out $(HEADERS_AND_MAKE), $(^)) -lpthread -o $(@)

main: main.cpp
	$(CXX) -g $(<) -o $(@) -Wl,-rpath=$(PWD) -L $(PWD) -lThreadPool

.PHONY: clean 

clean:
	-rm -f libThreadPool.so main
