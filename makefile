IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm 

_DEPS = pilha.hpp 
DEPS = $(patsubst % , $(IDIR)/% , $(_DEPS))

_OBJ = pilha.o teste_pilha.o 
OBJ = $(patsubst % , $(ODIR)/% , $(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

pilha: $(OBJ)
	$(CC) -g -o  $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~