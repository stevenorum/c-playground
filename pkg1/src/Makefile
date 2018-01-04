# This is slightly changed from the one in the source tutorial in order to create the obj/ directory automatically.
# It's possible(/likely) that this isn't done in the preferred way.
# I mostly just followed https://stackoverflow.com/questions/1950926/create-directories-using-make-file

IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)
MKDIR=mkdir -p

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: hellomake

$(ODIR):
	$(MKDIR) $(ODIR)

$(ODIR)/%.o: %.c $(DEPS) $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
