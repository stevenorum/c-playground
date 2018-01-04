# makefiles_intro: Basic Makefile intro

This is a slight rewrite of this [Colby College Makefile tutorial](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/).  All credit should go to them.  Mostly just rewritten to get it into a form that's a bit clearer to me, and also to better understand exactly what each part does.

## Methods of compilation

Here's a list of ways to compile the code in this package, from most basic to most complex (also, generally speaking, from worst to best).

Important note: Makefiles require explicit tabs (\t), not spaces.

### Makefile #0
Not technically a Makefile, just a command-line call:

```Shell
% gcc -o hellomake hellomake.c hellofunc.c -I.
%
```

This won't print any output, it'll just (assuming gcc and whatnot are correctly installed) create the executable ```hellomake``` in the current directory.  Run this to check that it works:

```Shell
% ./hellomake
Hello makefiles!
%
```

If you're going through these in order, after each one you'll want to delete the ```hellomake``` executable so that the next method can create it:

```Shell
% ls hellomake
hellomake
% rm hellomake
% ls hellomake
ls: hellomake: No such file or directory
%
```

### Makefile #1:

This is the most basic Makefile.  It does exactly the same thing as the command-line call above.

```Makefile
# This is how you put a comment in a Makefile.
# This is stored as Makefile.1
hellomake: hellomake.c hellofunc.c
	gcc -o hellomake hellomake.c hellofunc.c -I.
```

The default Makefile name is just "Makefile", and if no alternative is specified, that's what the make command will use.  Normally that's what you want.  However, in this package there are several Makefiles, named Makefile.1, Makefile.2, etc., so we need to explicitly provide the Makefile with the --file option.

When make runs, it prints out the underlying commands it's calling, so unlike option #0 it'll have a bit of output.

```Shell
% make --file Makefile.1
gcc -o hellomake hellomake.c hellofunc.c -I.
%
```

This'll create the exact same ```hellomake``` file as above, and it can be tested in the same way:

```Shell
% ./hellomake
Hello makefiles!
%
```

### Makefile #2:

This is similar to #1, but a bit better.  First, it specifies its compiler and default flags in variables at the top, so that if more things get added and then you want to change these, you only need to chenge them in one place.  Second, it's compiling the source code into object files first, then generating the actual executable.  I don't think this makes any real difference for a tiny project like this, but it probably adds efficiency for larger projects when you don't always want to have to recompile every piece because another one changed.

```Makefile
# This is stored as Makefile.2
CC=gcc
CFLAGS=-I.

hellomake: hellomake.o hellofunc.o
	$(CC) -o hellomake hellomake.o hellofunc.o -I.
```

You can test this in the same way as the previous makefile (and you can test #3 and #4 in this way, as well, so I'll skip this part for them).  Also, remember that this won't do anything if the ```hellomake``` file from a previous compilation exists, so get rid of that.

```Shell
% make --file Makefile.2
gcc -I.   -c -o hellomake.o hellomake.c
gcc -I.   -c -o hellofunc.o hellofunc.c
gcc -o hellomake hellomake.o hellofunc.o -I.
% ./hellomake
Hello makefiles!
%
```

In order to clean up from this, you need to remove both ```hellomake``` and the .o files. (Likewise, this also applies to #3 and #4, so I'll skip it in their descriptions.)

One thing to notice: Once the executable has been created, the .o files aren't required for it to run.

```Shell
% ls *.o
hellofunc.o	hellomake.o
% ls hellomake
hellomake
% rm *.o
% ls *.o
zsh: no matches found: *.o
% ./hellomake
Hello makefiles!
% rm hellomake
% ls hellomake
ls: hellomake: No such file or directory
% 
```

### Makefile #3:

See [Colby's tutorial](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) for an explanation of how this differs from the above.

```Makefile
# This is stored as Makefile.3
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o 
	gcc -o hellomake hellomake.o hellofunc.o -I.
```

### Makefile #4:

See [Colby's tutorial](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) for an explanation of how this differs from the above.

```Makefile
# This is stored as Makefile.4
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
```

### Makefile #5:

For this final version, we've split the files.  The .c source files are in [src/](src/) and the .h files are in [include/](include/).  This Makefile is stored in (and make is called from) the [src/](src/) directory.

```Makefile
# This is stored as src/Makefile
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
```

Here's what it looks like when it gets used:

```Shell
% ls
Makefile	hellofunc.c	hellomake.c	obj
% ls obj
% make
gcc -c -o obj/hellomake.o hellomake.c -I../include
gcc -c -o obj/hellofunc.o hellofunc.c -I../include
gcc -o hellomake obj/hellomake.o obj/hellofunc.o -I../include -lm
% ls
Makefile	hellofunc.c	hellomake	hellomake.c	obj
% ls obj
hellofunc.o	hellomake.o
% ./hellomake
Hello makefiles!
% make clean
rm -f obj/*.o *~ core /*~
% ls
Makefile	hellofunc.c	hellomake	hellomake.c	obj
% ls obj
% ./hellomake
Hello makefiles!
```
