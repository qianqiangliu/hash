EXE = a.out
SRC = $(shell ls *.c)
CFLAGS = -Wall

all: $(EXE)

$(EXE): $(SRC)
	ctags -R *
	gcc -o $@ $^ $(CFLAGS)

clean:
	-rm -f tags $(EXE)
