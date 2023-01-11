CC=gcc

ODIR=obj

LIBS=-lm

_OBJ = main.o lexer.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

DEPS = lexer.h token.h

$(ODIR)/%.o: %.c 
	$(CC) -c -o $@ $^ $(CFLAGS)

gran: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
run:$(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	./gran
clean:
	rm -f $(ODIR)/*.o