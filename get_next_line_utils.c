/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:00 by lyie              #+#    #+#             */
/*   Updated: 2021/08/25 17:18:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "pipex.h"

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_get_strjoin(char const *s1, char const *s2, int store)
{
	char	*cat;
	int		i;
	int		j;

	j = -1;
	if (s1 == NULL)
	{
		cat = malloc(sizeof(char) * store + 1);
		if (!cat)
			return (NULL);
		ft_strlcpy(cat, s2, store + 1);
		return (cat);
	}
	i = (ft_strlen((char *)s1)) + store;
	cat = malloc(sizeof(char) * i + 1);
	if (!cat)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		cat[i] = s1[i];
	while (++j < store)
		cat[i + j] = s2[j];
	cat[i + j] = '\0';
	free((void *)s1);
	return (cat);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*finalstr;
	int		i;

	if (!(s))
		return (NULL);
	if (start >= (unsigned int)ft_strlen((char *)s))
		len = 0;
	else if (ft_strlen((char *)&s[start]) < len)
		len = ft_strlen((char *)&s[start]);
	finalstr = malloc(sizeof(char) * len + 1);
	if (!(finalstr))
		return (NULL);
	i = 0;
	while (i < len && (s[start + i] != '\0'))
	{
		finalstr[i] = s[start + i];
		i++;
	}
	free((void *)s);
	finalstr[i] = '\0';
	return (finalstr);
}
