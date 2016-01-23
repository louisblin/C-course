CC     = gcc
CFLAGS = -Wall -Werror -pedantic 

SRC    = $(wildcard *.c)
OBJ    = $(patsubst %.c, %.o, $(SRC))
EXE    = stack

.PHONY: clean

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(EXE) $(OBJ)
