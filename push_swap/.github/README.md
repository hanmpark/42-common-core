<div align="center">
    <img src="https://github.com/hanmpark/42-project-badges/blob/main/badges/push_swapm.png"/>
</div>

<h1 align="center">push_swap</h1>

<p align="center">
    <b><i>A sorting algorithm project focusing on efficiency and instruction minimization.</i></b>
</p></br>

<div align="center">
    <img alt="Repository created at" src="https://img.shields.io/github/created-at/hanmpark/push_swap"/>
    <img alt="Repository code size" src="https://img.shields.io/github/languages/code-size/hanmpark/push_swap"/>
    <img alt="Mostly used language" src="https://img.shields.io/github/languages/top/hanmpark/push_swap"/>
</div>

## 📖 Description
> The push_swap project challenges you to sort a stack of integers using two stacks (a and b) and a set of restricted operations.
>
> The goal is to sort the stack with the fewest possible instructions, introducing concepts of algorithmic complexity, optimization, and data structure manipulation.
>
> You’ll need to implement both the sorting algorithm and the official instructions, then optimize your solution for efficiency.

## 🛠️ Features

### 🔨 Push_swap Instructions
| Instruction | Description |
| --- | --- |
| `sa` | Swap the first 2 elements of stack a. |
| `sb` | Swap the first 2 elements of stack b. |
| `ss` | `sa` and `sb` simultaneously. |
| `pa` | Push the top element of **b** onto **a**. |
| `pb` | Push the top element of **a** onto **b**. |
| `ra` | Rotate stack **a** (first element becomes last). |
| `rb` | Rotate stack **b** (first element becomes last). |
| `rr` | `ra` and `rb` simultaneously. |
| `rra` | Reverse rotate stack **a** (last element becomes first). |
| `rrb` | Reverse rotate stack **b** (last element becomes first). |
| `rrr` | `rra` and `rrb` simultaneously. |

## 📦 Installation
Clone the repository and compile:
```bash
git clone https://github.com/hanmpark/push_swap.git
cd push_swap
make
```

## 🚀 Usage
Run the program with a list of integers:
```bash
./push_swap 2 3 1 4
```

For the **bonus checker**:
```bash
make bonus
./checker "2 3 1 4"
```

## 📊 Grading Scale
| Number of integers | Points | Instruction limit |
| --- | --- | --- |
| 3 | Pass required | <= 3 |
| 5 | Pass required | <= 12 |
| 100 | 1 → ≤ 1500 | 2 → ≤ 1300 |
| 500 | 1 → ≤ 11500 | 2 → ≤ 10000 |

## 👤 Authors
- [hanmpark](https://github.com/hanmpark)
