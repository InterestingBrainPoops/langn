CC = gcc

ODIR = obj

LIBS = -lm

_OBJ = main.o lexer.o token.o parser.o ast.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

DEPS = lexer.h token.h parser.h ast.h

$(ODIR)/%.o : %.c 
	$(CC) -g -c -o $@ $^ $(CFLAGS)

gran: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

debug: $(OBJ) 
	$(CC) -g -o gran_d -O0 $^ $(CFLAGS)

.PHONY : run 
run: $(OBJ) 
	$(CC) -o -v $@ $^ $(CFLAGS) ./gran

.PHONY : clean 
clean: 
	rm -f $(ODIR)/*.o