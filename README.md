# PIPEX
input and output redirection and pipes program for Linux

Pipex notes:

Key concepts:

When you launch a command, it will generally take its input from STDIN and send its out to STDOUT.

For each | , you need to create a pipe by launching the command pipe(pipefd), where pipefd is an int[2] that you create in advance (without assigning values- they are assigned by pipe function).

For each command that you want to launch, you’ll need to use pid = fork() to create a child process, to work within the child process do if (pid == 0) and put your code here! You need to use child processes for each command because if not, when you execve your command, your command will replace the whole program process!

Pipefd[0] & [1] is a file fd! You can imagine it is a file fd that has already been opened and is ready to be used. You also close them using close(pipefd[0]) just like a file!

The next key thing to understand is dup2. Dup2 adjusts the newfd (second argument) so it actually refers to the oldfd (first fd). So if you do dup2(pipefd[0], STDIN_FILENO), stdin wil actually be the contents of pipefd[0]. Therefore, when you launch a command after doing this, instead of taking in “real” stdin, it will be pointed to your pipefd[0] file and take the info from there.

So, what does pipefd[0] and pipefd[1] actually refer to? Well, 0 is considered the “read” end of the pipe and 1 is the “write” end of the pipe, BUT, that is when you consider them in relation to the commands, pipefd[0] is what will be READ by the NEXT command, pipefd[1] is what is WRITTEN by the PREVIOUS command.... I like to picture it like this:

This command: ls | cat Would look like this: ls <[1] [0]> cat

For pipex, there are four cases to consider and code:

THE FIRST COMMAND ONLY: Since we want to redirect the input from a file (argv[1]), we need to use dup2 to get stdin to point to the fd of this file.

ALL COMMANDS EXCEPT FIRST: All commands after the first one need to read input from the previous commands output… so that is pipefd[0], so you need to set the STDIN which will be used by the current command to point towards the pipefd[0] of the previous command!

ALL COMMANDS EXCEPT LAST Commands usually send their output to STOUT, but we don’t want our output to go to be printed out, we want to stock in the pipe to be used by the next command. So, we need to set stdout to instead point to the pipefd[1] of our current pipe.

ls <1 0 > cat

THE LAST COMMAND ONLY: Since we want to redirect the output to a file, we need to use dup2 to redirect stdout to the file.

It can get a bit confusing about which pipe and fd number you should be using so I try to visualise which command and pipe I am by writing it out:

ls <[1] [0]> cat <[1] [0] > wc -l <[1] [0] > grep 1 <[1] [0] > ls

(as you can see you need a pipe for every command except the last!)

KEY RULES:

    Your commands (except for the first) read from [0] of the previous pipe!
    Your commands write to [1] of current pipe!

It took me a while to get the concepts and there is one article that REALLY helped in particular! http://www.rozmichelle.com/pipes-forks-dups/

Another good article by a student: https://aurelienabrabant.fr/posts/an-introduction-to-unix-pipes
