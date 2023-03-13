<h1 align="center">push_swap</h1>
***push_swap*** is an Algorithmic project in which you have to sort data. You are given two piles: _a_ and _b_.
In the _a_ pile, you have a random list of integers (+/-) and you are given the _b_ empty pile to help you sort with the given instructions (in the **language of Push swap**)
the integers stacked in _a_.

The difficulty of this project comes from the number of instruction that you'll use. You have to sort the data using as few instruction as possible.

## The given instructions (Push swap language)

| instructions | description |
| --- | --- |
| ***sa (swap a)*** | switches the first 2 elements at the top of the stack a. Does nothing if there is only one or none. |
| ***sb (swap b)*** | switches the first 2 elements at the top of the stack b. Does nothing if there is only one or none. |
| ***ss *** | sa + sb |
| ***pa (push a)*** | takes the first element on top of b and puts it on a. Does nothing if b is empty. |
| ***pb (push b)*** | takes the first element on top of a and puts it on b. Does nothing if a is empty. |
| ***ra (rotate a)*** | shifts all the elements of the stack a one position upwards. The first element becomes the last. |
| ***rb (rotate b)*** | shifts all the elements in the stack up by one position b. The first element becomes the last. |
| ***rr*** | ra + rb |
| ***rra (reverse rotate a)*** | shifts all elements of the stack down one position the stack a. The last element becomes the first. |
| ***rrb (reverse rotate b)*** | shifts all the elements in the stack down by one position the stack b. The last element becomes the first. |
| ***rrr*** | rra + rrb |
