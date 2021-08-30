/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:43:27 by user42            #+#    #+#             */
/*   Updated: 2021/08/26 09:32:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_error(char *error, int ret)
{
	write(2, error, ft_strlen(error));
	return (ret);
}

void	ft_cmd_error(char **cmd)
{
	int	i;

	i = 0;
	write(2, "command not found: ", 19);
	while (cmd[i])
	{
		write(2, cmd[i], ft_strlen(cmd[i]));
		i++;
	}
	write(2, "\n", 1);
}

void	close_both(int pipefd[2])
{
	if (pipefd[0])
		close(pipefd[0]);
	if (pipefd[1])
		close(pipefd[1]);
}

int	**ft_make_pipefds(int no_cmds, int **pipefd)
{
	int	i;

	i = 0;
	pipefd = malloc((sizeof(int *)) * no_cmds + 1);
	if (!pipefd)
	{
		write(2, "Error: malloc failed\n", 21);
		exit (1);
	}
	while (i < no_cmds)
	{
		pipefd[i] = malloc(sizeof(int) * 2);
		if (!pipefd[i])
		{
			write(2, "Error: malloc failed\n", 21);
			ft_free_pipes(pipefd);
			exit(1);
		}
		i++;
	}
	pipefd[i] = 0;
	return (pipefd);
}

void	ft_parenting(int counter, int **pipefd, int no_cmds)
{
	if (counter != 0)
		close_both(pipefd[counter - 1]);
	if (counter == no_cmds - 1)
		close_both(pipefd[counter]);
}
