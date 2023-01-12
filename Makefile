CC = gcc

ODIR = obj
SRCDIR = src
LIBS = -lm
IDIR = include
_OBJ = main.o lexer.o token.o parser.o ast.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

_DEPS = lexer.h token.h parser.h ast.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o : $(SRCDIR)/%.c
	mkdir $(ODIR)
	$(CC) -g -c -o $@ $^ -I $(IDIR)/ $(CFLAGS)

gran: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

debug: $(OBJ) 
	$(CC) -g -o gran_d -O0 $^ $(CFLAGS)

.PHONY : run 
run: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) ./gran

.PHONY : clean 
clean: 
	rm -f $(ODIR)/*.o