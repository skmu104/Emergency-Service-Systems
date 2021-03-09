CXX = g++
CXXFLAGS = -Wall -g

all: ems_test

ems_test: test.cpp Emergency_Services/*.cpp Emergency_Services/*.hpp
	$(CXX) $(CXXFLAGS) -o ems_test $^

test: ems_test
	./ems_test

clean:
	rm -f ems_test
