#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void) {
	int		arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int		arrSize = sizeof(arr) / sizeof(int);
	int		totalSum = 0;
	int		start;
	int		end;
	int		fd[2];
	if (pipe(fd) == -1) {
		printf("An error ocurred with pipe\n");
		return 1;
	}

	pid_t	id1;
	id1 = fork();
	if (id1 == -1) {
		printf("An error ocurred with fork\n");
		return 2;
	}

	if (id1 == 0) {
		close(fd[0]);
		start = 0;
		end = arrSize / 2;
		int	sum = 0;
		int	i;
		for (i = start; i < end; i++) {
			sum += arr[i];
		}
		printf("From child = %d\n", sum);
		if (write(fd[1], &sum, sizeof(sum)) == -1) {
			printf("An error ocurred with writing to the pipe\n");
			return 3;
		}
		close(fd[1]);
	} else {
		close(fd[1]);
		start = arrSize / 2;
		end = arrSize;
		if (read(fd[0], &totalSum, sizeof(totalSum)) == -1) {
			printf("An error ocurred with reading from the pipe\n");
			return 4;
		}
		close(fd[0]);
		int	i;
		for (i = start; i < end; i++) {
			totalSum += arr[i];
		}
		printf("From parent = %d\n", totalSum);
		wait(NULL);
	}
	if (id1 != 0) {
		printf("Total is %d\n", totalSum);
	}
	return 0;
}
