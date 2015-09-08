CC = clang
EXE = a.out
SRC = $(shell ls *.c)
CFLAGS = -Wall

all: $(EXE)

$(EXE): $(SRC)
	ctags -R *
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	-rm -f tags $(EXE)
