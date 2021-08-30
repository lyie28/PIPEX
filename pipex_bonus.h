/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:42:06 by user42            #+#    #+#             */
/*   Updated: 2021/08/26 09:32:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/errno.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_exetrio
{
	const char	*path;
	char *const	*command;
}		t_exetrio;

char	*ft_getpath(char **all_paths, char *command);
void	failed_dup(int **pipes);
void	ft_free_exe(t_exetrio *exe, int **pipes);
int		ft_free_pipes(int **pipes);
void	ft_free_exit_exe(int exit_code, int **pipes, t_exetrio exe);
int		ft_herecmp(char *str);
void	ft_cmd_error(char **cmd);
void	close_both(int pipefd[2]);
void	ft_parenting(int counter, int **pipefd, int no_cmds);
int		**ft_make_pipefds(int no_cmds, int **pipefd);
int		here_doc(char *del, char *file, int **pipefd);
int		ft_error(char *error, int ret);
char	*ft_pathfinder(char *command);
int		ft_init_first(const char *file, int **pipes);
int		ft_init_last(const char *file, char *argv[], int **pipes);
int		ft_free_onetrio(t_exetrio *one);
int		ft_error(char *error, int ret);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strdup(char *src);
char	**ft_split(const char *s, char c);
int		ft_strlcpy(char *dest, const char *src, int size);
int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_strjoin(char const *s1, char const *s2, int store);
char	*ft_substr(char const *s, unsigned int start, int len);
void	*ft_memmove(void *dst, const void *src, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memccpy(void *dest, const void *src, int c, int n);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		get_next_line(int fd, char **line, int BS);
int		ft_ending(int **pipefd, int pid);
int		ft_piperr(int **pipefd, char *error, int ret);
int		ft_strchr(char *s, char c);
int		ft_strlcpy(char *dest, const char *src, int size);

#endif
