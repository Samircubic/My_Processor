CXXFLAGS ?= -std=c++17 -O0 -g -Wall -Wextra
STACK := $(addprefix My_Stack/sources/,c_d_tor.cpp general_func.cpp push_pop.cpp safety.cpp)
STACK_HEADERS := $(wildcard My_Stack/headers/*.h)

.PHONY: all clean
all: assembler machine

assembler: processor/my_assembler/my_assembler.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $< $(LDLIBS) -o $@

machine: processor/processor/processor.cpp $(STACK) $(STACK_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -IMy_Stack/headers $(LDFLAGS) $< $(STACK) $(LDLIBS) -o $@

clean:
	$(RM) assembler machine
