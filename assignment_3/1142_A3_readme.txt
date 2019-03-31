Data structures used:
doubly linked list, node, state.
A state represents the state of the system at some point of time. It has three domain specific variables, eightV, fiveV, threeV, which represent the volume in 8 litre jug, 5 litre jug, and 3 litre jug respectively. It also contains an implementation specific variable fn_index which indicates the next function transition this state should try.
Each node consists of a state variable as data and a pointer to next node.
The list is comprised of nodes, and is used to track the solution states via nodes (if any solution is found).

I've used the freopen function to redirect output to the file as mentioned in the email.