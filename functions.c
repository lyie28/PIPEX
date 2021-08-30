/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:08:54 by user42            #+#    #+#             */
/*   Updated: 2021/08/26 09:26:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	ft_free_paths(char **all_paths)
{
	int	i;

	i = -1;
	while (all_paths[++i])
		free(all_paths[i]);
	free((void *)all_paths);
}

char	*ft_getpath(char **all_paths, char *command)
{
	int		i;
	char	*base;
	char	*path;

	base = NULL;
	path = NULL;
	i = -1;
	while (all_paths[++i])
	{
		base = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(base, command);
		free(base);
		if (access(path, X_OK) == 0)
		{
			ft_free_paths(all_paths);
			return (path);
		}
		free(path);
	}
	ft_free_paths(all_paths);
	return (NULL);
}

char	*ft_pathfinder(char *command)
{
	int		i;
	int		check;
	char	**all_paths;
	char	*copy;

	check = 0;
	i = -1;
	all_paths = NULL;
	while (__environ[++i])
	{
		if (ft_strncmp(__environ[i], "PATH", 4) == 0)
		{
			copy = ft_strdup(__environ[i] + 5);
			all_paths = ft_split(copy, ':');
			free(copy);
			return (ft_getpath(all_paths, command));
		}
	}
	return (NULL);
}

int	ft_init_first(const char *file, int **pipes)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		ft_free_pipes(pipes);
		exit (1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		failed_dup(pipes);
	}
	close(fd);
	return (0);
}

int	ft_init_last(const char *file, int **pipes)
{	
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		ft_free_pipes(pipes);
		exit (1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		failed_dup(pipes);
	}
	close(fd);
	return (0);
}
