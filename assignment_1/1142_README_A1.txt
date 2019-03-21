1) Allocation policy: bestfit
2) For bookkeeping, I've used a bookkeeping structure called blockinfo, which has fields: next (pointer to next blockinfo node), size (the size of block this blockinfo points to), occupied (to indicate whether its occupied or not)
It takes 16 bytes of space (on my computer). Once the user asks for memory, my code checks for free blocks, and if found, it allocates the memory to the user, and creates a new blockinfo node after the current one if there's space left to create. 
The bestfit part comes into picture when I'm finding the free node; I find that node which has the tightest fit for the size the user wants (by taking the min difference: block free size - user size).
3) Before compilation, the client should call the allocate function, with enough input n, such that it could allocate my bookkeeping structures as well. I'm not assigning extra space myself in the memory array, just directly assigning based on input n.

My code takes care of the corner conditions as well:
Suppose when you have allocated blocks something like: (16+30) (16+40) (16+50)
then suppose the user frees 40, and then tries to call malloc again with say 35, then it returns the proper pointer back, 
but the point to note is, I can't insert another blockinfo node after 35 because there wouldn't be any space after that. If I did insert it, it would corrupt the subsequent blocks.

It also takes care that when the above 35 block is freed, the free memory size for that block again becomes the original size (40) that it was supposed to be and not just 35.


There's also a commented out piece of code in the end that explains the above mechanism.