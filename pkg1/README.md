# pkg1: Basic compilation

(from http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)

Here's a list of ways to compile the code in this package, from most basic to most complex (also, generally speaking, from worst to best).
Important note: Makefiles require explicit tabs (\t), not spaces.

Makefile #0 (not a Makefile, just a command-line call):

gcc -o hellomake hellomake.c hellofunc.c -I.

Makefile #1:

hellomake: hellomake.c hellofunc.c
	gcc -o hellomake hellomake.c hellofunc.c -I.

