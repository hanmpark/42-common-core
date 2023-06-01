# Pipex

> Recoding UNIX pipes behavior in C

The goal of *pipex* is to **execute a series of commands** provided as arguments and ***redirect the output of one command as input to the next command***, similar to the behavior of the pipe operator in a shell. It allows for the sequential execution of commands, with the output of one command serving as the input for the next.

The *pipex* utility uses file redirection and process execution to achieve this behavior. It creates pipes to establish communication channels between the commands, redirects standard input and output to files, and uses the fork and exec functions to execute the commands as child processes.

## Compiling

### Mandatory
After running `make all` you will have to execute the program like so:
```zsh
./pipex file1 cmd1 cmd2 file2
```
It should behave similarly as:
```zsh
< file1 cmd1 | cmd2 > file2
```

### Bonus
After running `make bonus` you will have to execute the program like so:
```zsh
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
It should behave similarly as:
```zsh
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
OR like so:
```zsh
./pipex here_doc LIMITER cmd cmd1 file
```
It should behave similarly as:
```zsh
cmd << LIMITER | cmd1 >> file
```