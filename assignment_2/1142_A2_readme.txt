Data structures used:
Binary counter and Adjacency list concept using node structure.
I've made an array of pointers to nodes (which become linked lists of size 1, 2 and so on) called bcarr (binary counter array) which mimics the binary counter technique for finding the second largest number.


To take care of cases when n is not a perfect power of 2, I've made sure I took ceil of log n while creating the bcarr and adding a compare merge snippet after the original input array has been read.

Compilation instructions:
Make sure to link the math library (with -lm) while compiling.