CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS=llrec-test.o llrec.o 

all: llrec-test stack-test

llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

stack-test: stack-test.o
	$(CXX) $(CXXFLAGS) -o $@ stack-test.o

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test.o: llrec-test.cpp llrec.h 
	$(CXX) $(CXXFLAGS) -o $@ -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -o $@ -c llrec.cpp

stack-test.o: stack-test.cpp stack.h
	$(CXX) $(CXXFLAGS) -o $@ -c stack-test.cpp



valgrind: 
	$(VALGRIND) ./llrec-test llrec-test1.in

clean:
	rm -f *.o rh llrec-test stack-test *~

.PHONY: clean, valgrind