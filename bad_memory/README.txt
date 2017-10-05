These code samples provide simple demostrations of memory errors that may be present in C code but may not reliably cause crashes.

bad_access.c is a program that uses memory outside of an allocated region.
leaky.c is a program that leaks memory on the heap.

Import the gcc and valgrind modules. The compile the code with the debugging symbols. Then run valgrind with the compiled binary as the first argument.


