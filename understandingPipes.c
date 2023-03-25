#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void) {
	int	fd[2];
	if (pipe(fd) == -1) {
		return 1;
	}
	int	x = 0;
	int	pid1 = fork();
	if (pid1 < 0) {
		return 2;
	}
	if (pid1 == 0) {
		// Child process
		close(fd[0]);
		x += 5;
		printf("First Child process x = %d\n", x);
		if (write(fd[1], &x, sizeof(int)) < 0) {
			return 3;
		}
		close(fd[1]);
	}

	waitpid(pid1, NULL, 0);

	return 0;
}
