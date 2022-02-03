CC = gcc
FLAGS = -Wall -Wextra -g

# TODO: add binaries here
STENCILS = exercises swap findtok
SOLS = $(addsuffix -sol,$(STENCILS))
BINS = $(STENCILS) $(SOLS)

.phony: clean all

clean:
	rm -f $(BINS) *.o

all: $(BINS)

%: %.c
	$(CC) $(FLAGS) $@.c -o $@
