<h1 align="center">push_swap</h1>

***push_swap*** is a simple project in which you have to sort data. You are given two empty piles: _a_ and _b_.
You have top put the integers in _a_ after the parsing. Therefore with the _Push swap instructions_ you have to sort the _a_ pile using the _b_ pile.

The difficulty of this project comes from the number of instruction that you'll use. You have to sort the data using as few instruction as possible.

## Push_swap instructions 🔨

| instructions | description |
| --- | --- |
| ***sa (swap a)*** | switches the first 2 elements at the top of the stack a. Does nothing if there is only one or none. |
| ***sb (swap b)*** | switches the first 2 elements at the top of the stack b. Does nothing if there is only one or none. |
| ***ss *** | sa + sb but I personally don't use it |
| ***pa (push a)*** | takes the first element on top of b and puts it on a. Does nothing if b is empty. |
| ***pb (push b)*** | takes the first element on top of a and puts it on b. Does nothing if a is empty. |
| ***ra (rotate a)*** | shifts all the elements of the stack a one position upwards. The first element becomes the last. |
| ***rb (rotate b)*** | shifts all the elements in the stack up by one position b. The first element becomes the last. |
| ***rr*** | ra + rb |
| ***rra (reverse rotate a)*** | shifts all elements of the stack down one position the stack a. The last element becomes the first. |
| ***rrb (reverse rotate b)*** | shifts all the elements in the stack down by one position the stack b. The last element becomes the first. |
| ***rrr*** | rra + rrb |

## Personal approach

> At first, I was really scared of this project but I ended up liking it !

### First step: parsing

For the parsing, you have to check several things:
- no duplicates
- no other input than **integers**
- it should be able to read ```bash ./push_swap 2 3 "1 4  "```

Else, it should exit the program with *"Error\n"* in the error output.

### Second step: int arrays or chained lists / Push_swap instructions

I personally went for chained lists as I was really scared of it when I was doing the [libft](https://github.com/Nonino42/libft).

I had no difficulty coding the Push_swap instructions.

### Third step: Choose an algorithm (or find out yourself 👀)

I went for the **insertion sort** with some optimization.

You will also need another algorithm for smaller data.

## Grading scale

| number of data | given points | number of instructions to sort |
| :--------: | :-------: | :-------: |
| 3 | need it to pass | not more than 3 instructions |
| 5 | need it to pass | not more than 12 instructions |
| 100 | 1 | less than 1500 |
| | 2 | less than 1300 |
| | 3 | less than 1100 |
| | 4 | less than 900 |
| | 5 | less than 700 |
| 500 | 1 | less than 11 500 |
| | 2 | less than 10 000 |
| | 3 | less than 8 500 |
| | 4 | less than 7 000 |
| | 5 | less than 5 500 |

Mine does for an average of 5000 instructions to sort a pile of 500 numbers.

PS: I don't recommend you to try and make your own algorithm (you will loose a lot of time).
