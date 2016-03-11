CC=gcc

LIB_FLAGS=

CFLAGS=$(LIB_FLAGS)

EXE=recs
DEPS=list.h
OBJ_DEPS=list.o recs.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE): $(OBJ_DEPS)
	$(CC) -o $@ $^

clean:
	rm -f $(EXE) *.o *~
