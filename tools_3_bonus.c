/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:43:08 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 17:43:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
