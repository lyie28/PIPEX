/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:37:24 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 17:05:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_ending(int **pipefd, int pid)
{
	int	status;

	ft_free_pipes(pipefd);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

int	ft_piperr(int **pipefd, char *error, int ret)
{
	ft_free_pipes(pipefd);
	write(2, error, ft_strlen(error));
	return (ret);
}
