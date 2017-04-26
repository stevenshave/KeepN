CXX = g++
ccopt = -Wall -O3 -std=c++1y -lz

all: keepn-example
keepn-example: keepn-example.cpp
	$(CXX) -o $@ $^ $(libs) $(ccopt)

.PHONY: clean
clean:
	/bin/rm -f *.o  keepn-example
