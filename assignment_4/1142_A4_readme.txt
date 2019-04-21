This code implements binary search tree on hard disk. 
The free nodes are added to the free list wherein, the right offset of a node indicates the next free node if any otherwise -1.
I've used freopen function to redirect output as mentioned in the e-mail.
This code also ignores the key if a duplicate key is trying to be inserted and takes care of the necessary conditions.