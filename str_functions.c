/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:10:07 by user42            #+#    #+#             */
/*   Updated: 2021/08/25 16:10:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

int	ft_strlcpy(char *dest, const char *src, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((!(dest)) || (!(src)))
		return (0);
	while (src[i])
	{
		i++;
	}
	if (size == 0)
		return (i);
	while (src[j] && j < (size - 1))
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*dest;
	int		i;

	i = 0;
	size = ft_strlen(src);
	dest = malloc(sizeof(char) * (ft_strlen(src)) + 1);
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1 && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		size;
	int		i;
	int		j;

	if ((!(s1)) || (!(s2)))
		return (NULL);
	i = -1;
	j = -1;
	size = (ft_strlen((char *)s1)) + (ft_strlen((char *)s2));
	cat = malloc(sizeof(char) * size + 1);
	if (!cat)
		return (NULL);
	while (s1[++i])
		cat[i] = s1[i];
	while (s2[++j])
		cat[i + j] = s2[j];
	cat[i + j] = '\0';
	return (cat);
}
