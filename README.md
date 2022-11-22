# push_swap

push_swap is a 42 school algorithm project where we must sort a given list of random numbers with a limited set of instructions, using the lowest possible number of actions.

The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

    pa (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
    pb (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
    sa (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
    sb (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
    ss: sa and sb at the same time.
    ra (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
    rb (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
    rr: ra and rb at the same time.
    rra (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
    rrb (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
    rrr : rra and rrb at the same time.
