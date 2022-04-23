CXX = g++
O = -O0
CXXFLAGS = -std=gnu++17 -W -Wall -Wshadow -Wno-unused-result -Wno-unused-parameter -Wno-unused-variable -Werror $(O) -g

SAMPLES = $(patsubst %.cc, %, $(wildcard sample*.cc))
PRIMES = $(patsubst %.cc, %, $(wildcard primefinder*.cc))
EXECS = $(SAMPLES) $(PRIMES) transactions-deadlock

all: $(EXECS)

%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $^ -lpthread

clean:
	rm -f $(EXECS)

.PHONY: all clean
