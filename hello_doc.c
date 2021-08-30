/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_doc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:10:45 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 17:19:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>

static int	ft_setup(char *file, int *count, int fd[2])
{
	fd[1] = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	fd[0] = open(file, O_RDONLY, 0644);
	if (!fd[1] || !fd[0])
		return (-1);
	(*count) = 0;
	return (0);
}

static int	close_all_good(int fd, char *line)
{
	close(fd);
	free(line);
	return (0);
}

static int	close_free_error(int fd, char *line, int **pipefd, char *error)
{
	ft_error(error, 1);
	ft_free_pipes(pipefd);
	close(fd);
	free(line);
	exit (-1);
}

int	here_doc(char *del, char *file, int **pipefd)
{
	int		fd[2];
	char	*line;
	int		count;

	line = NULL;
	if (ft_setup(file, &count, fd) == -1)
		return (-1);
	while (get_next_line(0, &line, 2) > 0)
	{
		if (ft_strncmp(line, del, sizeof(del)) == 0)
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) == 0)
				close_free_error(fd[0], line, pipefd, "dup2 failed\n");
			return (close_all_good(fd[0], line));
		}
		if (count != 0)
			write(fd[1], "\n", 1);
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = NULL;
		count++;
	}
	return (close_free_error(fd[0], line, pipefd, "Malloc failed\n"));
}
