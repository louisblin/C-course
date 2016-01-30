CC     = gcc
CFLAGS = -g -Wall -Werror -pedantic

SRC    = $(wildcard *.c)
OBJ    = $(patsubst %.c, %.o, $(SRC))
EXE    = matcher

.PHONY: clean

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(EXE) $(OBJ)
