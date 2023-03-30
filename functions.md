> Recoding UNIX pipes behavior in C

## Code Vault - Youtube

### The fork() function in C

```c
int	main(int argc, char **argv) {
	fork(); // return an integer (id)
	// => forking the execution line
	printf("Hello world\n");
	return 0;
}
```

The child process' id is 0. If it is not 0 that means that you are in the main process.
Everything before the fork line is going to be executed once then after it it's gonna be executed twice in two different processes.

If we have two fork() functions: 4 processes in total. We will always have 2 to the power of *n* processes.

If you want to create only 3 processes you can do like so:

```c
int	main(int argc, char **argv) {
	int	id = fork();
	if (id != 0) {
		fork(); // We should only get 3 processes out of this
	}
	printf("Hello world\n");
	return 0;
}
```

### The wait() function in C

> Waiting for the processes to finish

```c
int	main(int argc, char **argv) {
	int	id = fork();
	int	n;
	if (id == 0) {
		n = 1;
	} else {
		n = 6;
	}

	int	i;
	for(i = n; i < n + 5; i++) {
		printf("%d ", i);
		fflush(stdout);
	}
	printf("\n");
	return 0;
}
```

The numbers are not printed in order because the processes work more or less at the same time.

**wait()**: stop the execution until a child process has finished executing.

```c
int	main(int argc, char **argv) {
	int	id = fork();
	int	n;
	if (id == 0) {
		n = 1;
	} else {
		n = 6;
	}
	if (id != 0) {
		wait(NULL);
	}
	int	i;
	for (i = n; i < n + 5; i++) {
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0) {
		printf("\n");
	}
	return 0;
}
```

### Calling fork() multiple times

```c
int	main(int argc, char **argv) {
	int	id1 = fork();
	int	id2 = fork();
	if (id1 == 0) {
		if (id2 == 0) {
			printf("We are process y\n");
		} else {
			printf("We are process x\n");
		}
	} else {
		if (id2 == 0) {
			printf("We are process z\n");
		} else {
			printf("We are the parent process\n");
		}
	}
	wait(NULL);
	return 0;
}
```

What is a pipe ? It's like a memory file. It's a file that only has a buffer, you can write and read from it. It takes an array of 2 integers. File descriptors for the file.

If you close a file descriptor in a process, it will not close it in the other process. They are inherited.

- **fd[0] = read**
- **fd[1] = write**

```c
int	main(int argc, char **argv) {
	int	fd[2]; // A pipe should have two ends.
	if (pipe(fd) == -1) {
		printf(“An error ocurred with opening the pipe\n”);
		return 1;
	}
	int	id = fork(); // when you fork here the file descriptors are getting copied over.
	if (id == -1) {
		printf(“An error ocurred with fork\n”);
		return 4;
	}
	if (id == 0) { // child process to the parent process.
		close(fd[0]);
		int	x;
		printf(“Input a number: “);
		scanf(%d”, &x);
		if (write(fd[1], &x, sizeof(int)) == -1) {
			printf(“An error ocurred with writing to the pipe\n”);
			return 2;
		}
		close(fd[1]);
	} else {
		close(fd[1]);
		int	y;
		if (read(fd[0], &y, sizeof(int)) == -1) {
			printf(“An error ocurred with reading from the pipe\n”);
			return 3;
		}
		y = y * 10;
		close(fd[0]);
		printf(“Got from child process %d\n”, y);
	}
	return 0;
}
```

### Practical use case for fork() and pipe() in C

```c
int	main(int argc, char **argv) {
	int	arr[] = { 1, 2, 3, 4, 1, 2};
	int	arrSize = sizeof(arr) / sizeof(int);
	int	start, end;
	int	fd[2];
	if (pipe(fd) == -1) {
		return 1;
	}
	int	id = fork();
	if (id == -1) {
		return 2;
	}

	if (id == 0) {
		start = 0;
		end = arrSize / 2;
	} else {
		start = arrSize / 2;
		end = arrSize;
	}

	int sum = 0;
	int	i;
	for (i = start; i < end; i++) {
		sum += arr[i];
	}

	printf(“Calculated partial sum: %d\n”, sum);

	if (id == 0) {
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return 3;
		close(fd[1]);
	} else {
		int	sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
			return 4;
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf(“Total sum is %d\n”, totalSum);
		wait(NULL);
	}

	return 0;
}
```

### Two way communication between processes (using pipes) in C

```c
int	main(int argc, char **argv) {
	// 5 => 5 * 4 = 20 => 20
	int	p1[2]; // C => P
	int	p2[2]; // P => C

	if (pipe(p1) == -1) { return 1; } // 4 file descriptors, 2 for the child process and 2 for the parent process and they both are opened. 
	int pid = fork();
	if (pid == -1) { return 2; }
	if (pid ==  0) {
		close(p1[0]);
		close(p2[1]);
		// Child process
		int	x;
		if (read(p2[0], &x, sizeof(x)) == -1) { return 3; } // it will wait to read something
		printf(“Received %d\n”, x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1) { return 4; }
		printf(“Wrote %d\n”, x);
		close(p1[1]);
		close(p2[0]);
	} else {
		close(p1[1]);
		close(p2[0]);
		// Parent process
		srand(time(NULL));
		int	y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1) { return 5; }
		printf(“Wrote %d\n”, y); // If we comment this line, the program will not finish because it will write and read at the same time.
		if (read(p1[0], &y, sizeof(y)) == -1) { return 6; }
		printf(“Result is %d\n”, y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	return 0;
}
```

```sh
-- OUTPUT --
Wrote 9
Received 9
Wrote 36
Result is 36
```

We don't do both reading and writing on the same pipe. You have to create 2 pipes.

### Executing commands in C

- **execl =** *put the list of args*
- **execv =** *set the list of args through a variable*
- **exec?e =** *put an environment*
- **exec?p =** *set the path to the command*

```c
#include <unistd.h>

int	main(int argc, char **argv) {
	execl("file_path", "file_path", "argument", NULL); // Taking a file name to a executable with certain arguments
	// This is gonna execute the command
	printf("Program finished executing\n"); // We will not see it tho
	// All the exec functions replace the process to the program
	// It takes the new program process and put it on top of the current process
	// Unless it does not work properly
	return 0;
}
```

But whenever you would use the exec() function, not only your program would stop executing, your process would also be replaced with whatever you have called.

```c
int	main(int argc, char **argv) {
	execlp("ping", "ping", "-c", "3", "google.com", NULL);
	printf("Success!\n"); // It will not print out
	return 0;
}
```
All the memory is going to be replaced by its own memory, the execution line is going to be replaced by its own line...

Now that we know how to create new processes it should be fine.
You cannot call exec in the parent process and expect for it to work. The child process is going to be a zombie process.

```c
int	main(int argc, char **argv) {
	int	pid = fork();
	if (pid == -1) {
		return 1;
	}

	if (pid == 0) {
		// Child process
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
		printf("THIS SHOULD NOT PRINT ON THE TERMINAL!\n");
	} else {
		// Parent process
		wait(NULL); // Wait for a child process to finish
		printf("Success!\n");
		printf("Some post processing goes here!\n");
	}

	return 0;
}
```

### Redirecting standard output in C

***dup()*** -> takes in a single file descriptor. It returns another fd. It duplicates the fd and points to the same file.
***dup2()*** -> this one takes 2 parameters. The first one being the fd you want to duplicate, and the second one being the value that we want the new fd to actually have. It will close the new fd first if it already open.
***exec()*** overwrites the code/memory but it doesn't change the process id nor does it change the fd that are already opened.

```c
int	main(int argc, char **argv) {
	...
	if (pid == 0) {
		// Child process
		int	file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1) {
			return 2;
		}
		printf("The fd to pingResults: %d\n", file);
		dup2(file, STDOUT_FILENO); // fd 1
		close(file); // We can close the original id
	}
	return 0;
}
```

### How to send an array through a pipe

```c
#include <time.h>

// 2 processes
// 1) Child process should generate random numbers and send them to the parent
// 2) Parent is going to sum all the numbers and print the result

int	main(int argc, char **argv) {
	int	fd[2];
	if (pipe(fd) == -1) {
		return 2;
	}
	int	pid = fork();
	if (pid == -1) {
		return 1;
	}
	if (pid == 0) {
		// Child process
		close(fd[0]); // read fd
		int	n, i;
		int	arr[10];
		srand(time(NULL));
		n = rand() % 10 + 1; // anything between 1 and 10
		printf("Generated: ");
		for (i = 0; i < n; i++) {
			arr[i] = rand() % 11; // anything from 0 to 10
			printf("%d ", arr[i]);
		}
		printf("\n")

		if (write(fd[1], &n, sizeof(int)) < 0) {
			return 4;
		}
		printf("Sent n = %d\n", n);

		if (write(fd[1], arr, sizeof(int) * n) < 0) {
			return 3;
		}
		printf("Sent array\n");

		close(fd[1]);
	} else {
		// Parent process
		close(fd[1]); // write fd
		int	arr[10];
		int	n, i, sum = 0;
		if (read(fd[0], &n, sizeof(int)) < 0) {
			return 5;
		}
		printf("Received n = %d\n", n);
		if (read(fd[0], arr, sizeof(int) * n) < 0) {
			return 6;
		}
		printf("Received array\n");
		close(fd[0]);
		for (i = 0; i < n; i++) {
			sum += arr[i];
		}
		printf("Result is: %d\n", sum);
		wait(NULL);
	}
	return 0;
}
```
```sh
Generated: 5 3 8 3 10 0 1 9
Sent n = 8
Received n = 8
Received array
Result is: 39
```

### How to send a string through a pipe

```c
int	main(int argc, char **argv) {
	int	fd[2];
	if (pipe(fd) < 0) {
		return 1;
	}

	int	pid = fork();
	if (pid < 0) {
		return 2;
	}

	if (pid == 0) {
		// Child process
		close(fd[0]);
		char	str[200];
		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = 0;

		int	n = strlen(str) + 1;
		if (write(fd[1], &n, sizeof(int)) < 0) {
			return 4;
		}

		if (write(fd[1], str, sizeof(char) * n) < 0) {
			return 3;
		}
		close(fd[1]);
	} else {
		// Parent process
		close(fd[1]);
		char	str[200];
		int		n;

		if (read(fd[0], &n, sizeof(int)) < 0) {
			return 5;
		}
		if (read(fd[0], str, sizeof(char) * n) < 0) {
			return 6;
		}
		printf("Received: %s\n", str);
		close(fd[0]);
		wait(NULL);
	}

	return 0;
}
```

You could technically do a while loop instead of another read but it will add more lines for nothing.

### Simulating the pipe operator in C

Move the output to the input of the next command is the goal here.
```c
int	main(int argc, char **argv) {
	int	fd[2];
	if (pipe(fd) == -1) {
		return 1;
	}

	int	pid1 = fork();
	if (pid1 < 0) {
		return 2;
	}

	if (pid1 == 0) {
		// Child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]); // Because it remains open even if we have duplicated it
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
		// It replaces everything inside the executing process
		// That's why we don't need an else
	}

	int pid2 = fork();
	if (pid2 < 0) {
		return 3;
	}

	if (pid2 == 0) {
		// Child process (grep)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return 0;
}
```
