<div align="center">
    <img src="https://github.com/hanmpark/42-project-badges/blob/main/badges/philosophersm.png"/>
</div>

<h1 align="center">Philosophers</h1>

<p align="center">
    <b><i>An introduction to threads, processes, and concurrency in C.</i></b>
</p></br>

<div align="center">
    <img alt="Repository created at" src="https://img.shields.io/github/created-at/hanmpark/philosophers"/>
    <img alt="Repository code size" src="https://img.shields.io/github/languages/code-size/hanmpark/philosophers"/>
    <img alt="Mostly used language" src="https://img.shields.io/github/languages/top/hanmpark/philosophers"/>
</div>

## 📖 Description
> The **Philosophers** project explores multithreading, synchronization, and concurrent programming in C.
> It is based on the **Dining Philosophers Problem**, a classical concurrency challenge where philosophers alternate between eating, sleeping, and thinking.
> The goal is to implement a solution that avoids **deadlocks** and **race conditions**, ensuring all philosophers can eat without blocking each other.

## 🛠️ Features
- Two implementations:
    - **Mandatory**: threads + mutexes
    - **Bonus**: processes + semaphores
- Correct handling of:
    - Shared memory
    - Resource allocation
    - Synchronization problems (deadlocks, race conditions)
- Simulation of philosophers’ life cycle: **eating**, **sleeping**, **thinking**

## 🧩 Code Structure
`./philo` (**threads** + **mutexes**)
<div align="center">
    <img src="https://github.com/hanmpark/philosophers/blob/master/code_struct/philo.png" alt="philo structure"/>
</div>

`./philo_bonus` (**processes** + **semaphores**)
<div align="center">
    <img src="https://github.com/hanmpark/philosophers/blob/master/code_struct/philo_bonus.png" alt="philo_bonus structure"/>
</div>

## 🧠 Key Concepts
### Threads
> A thread is an independent sequence of execution within a process.</br>
> Threads share the same memory and resources, making them lightweight but requiring careful synchronization.

### Race Conditions 🏎
> A race condition occurs when multiple threads/processes access or modify shared data simultaneously, leading to unpredictable outcomes.</br>
> **Mutexes** (locks) can prevent simultaneous access and ensure safe operations.

### Deadlocks 🔒
> A deadlock happens when two or more threads wait indefinitely for resources locked by each other.</br>
> Proper resource ordering and synchronization design prevent deadlocks.

## 📦 Installation
Clone the repository and compile:
```bash
git clone https://github.com/hanmpark/philosophers.git
cd philosophers
make
```

## 🚀 Usage
### Mandatory (threads + mutexes)
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_slee [number_of_times_each_philosopher_must_eat]
```
### Bonus (processes + semaphores)
```bash
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

## 👤 Authors
- [hanmpark](https://github.com/hanmpark)
