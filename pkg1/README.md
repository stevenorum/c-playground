# pkg1: Basic compilation

pkg1 is a slight rewrite of this [Colby College Makefile tutorial](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/).  All credit should go to them.  Mostly just rewritten to get it into a form that's a bit clearer to me, and also to better understand exactly what each part does.

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
# This is stored as Makefile.1 in this directory.
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
### Makefile #3:
### Makefile #4:
### Makefile #5:
