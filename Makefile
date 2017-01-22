CC=g++
CFLAGS=-W -Wall -std=c++11 -pedantic
LDFLAGS=
EXEC=elections
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)

all: $(EXEC)

elections: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o:$(wildcard *.hh)

%.o: %.cc
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)

