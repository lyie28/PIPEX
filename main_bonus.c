/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:41:45 by user42            #+#    #+#             */
/*   Updated: 2021/08/26 09:24:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	init_exetrio(const char*command, t_exetrio *exec)
{
	char	**split;
	char	*path;
	int		i;

	i = -1;
	split = ft_split(command, ' ');
	if (access(split[0], X_OK) == 0)
		path = ft_strdup((char *)split[0]);
	else
	{
		path = ft_pathfinder(split[0]);
		if (path == NULL)
		{
			ft_cmd_error(split);
			while (split[++i])
				free(split[i]);
			free((void *)split);
			return (-1);
		}
	}
	exec->path = (const char *)path;
	exec->command = (char *const *)split;
	return (0);
}

static int	ft_cmd(char *argv[], int counter, char *envp[], int **p)
{
	t_exetrio	cmd;

	if (ft_herecmp(argv[1]) == 0)
		counter++;
	if (init_exetrio(argv[counter + 2], &cmd) == 0)
	{
		if (execve(cmd.path, cmd.command, envp) == -1)
		{
			perror("Error: ");
			ft_free_exit_exe(127, p, cmd);
		}
		return (0);
	}
	ft_free_pipes(p);
	exit (127);
}

static void	ft_child_loop(int counter, int no_cmds, int **pipefd, char *argv[])
{
	if (counter == 0)
	{
		if (ft_herecmp(argv[1]) == 0)
			here_doc(argv[2], ".here_doc", pipefd);
		else
			ft_init_first(argv[1], pipefd);
	}
	else
	{
		if (dup2(pipefd[counter - 1][0], 0) == -1)
			failed_dup(pipefd);
		close_both(pipefd[counter - 1]);
	}
	if (counter < no_cmds - 1)
	{
		close(pipefd[counter][0]);
		if (dup2(pipefd[counter][1], 1) == -1)
			failed_dup(pipefd);
		close(pipefd[counter][1]);
	}
	else if (ft_herecmp(argv[1]) == 0)
		ft_init_last(argv[no_cmds + 3], argv, pipefd);
	else
		ft_init_last(argv[no_cmds + 2], argv, pipefd);
}

static int	ft_piping(char *argv[], char *envp[], int no_cmds)
{
	int	pid;
	int	**pipefd;
	int	counter;

	counter = -1;
	pipefd = NULL;
	pipefd = ft_make_pipefds(no_cmds, pipefd);
	while (++counter < no_cmds)
	{
		if (counter < (no_cmds - 1))
		{
			if (pipe(pipefd[counter]) == -1)
				return (ft_piperr(pipefd, "Failed to create pipe\n", 1));
		}
		pid = fork();
		if (pid == 0)
		{
			ft_child_loop(counter, no_cmds, pipefd, argv);
			ft_cmd(argv, counter, envp, pipefd);
		}
		else
			ft_parenting(counter, pipefd, no_cmds);
	}
	return (ft_ending(pipefd, pid));
}

int	main(int argc, char *argv[], char *envp[])
{
	int	no_cmds;
	int	ret;

	ret = 0;
	if (ft_herecmp(argv[1]) == 0)
	{
		no_cmds = argc - 4;
		if (argc < 6)
			return (ft_error("Wrong number of arguments\n", 1));
	}
	else
		no_cmds = argc - 3;
	if (argc < 5)
		return (ft_error("Wrong number of arguments\n", 1));
	exit(ft_piping(argv, envp, no_cmds));
}
