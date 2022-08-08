/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:49:06 by tandrea           #+#    #+#             */
/*   Updated: 2022/01/29 16:26:46 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (!src && !dst)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)s;
	if (n != 0)
	{
		while (i < n)
		{
			c[i] = '\0';
			i++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	s = malloc(count * size);
	if (s)
	{
		ft_bzero (s, count * size);
		return (s);
	}
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	size_t			i;
	int				len1;

	i = 0;
	if (s == NULL)
		return (NULL);
	len1 = len;
	if (ft_strlen(s) - start < len)
		len1 = ft_strlen(s) - start;
	else if ((int)(ft_strlen(s) - start) < 0)
		len1 = 0;
	s1 = (char *) ft_calloc((len1 + 1), sizeof(char));
	if (s1 == NULL)
		return (NULL);
	if ((int)ft_strlen(s) >= (int)(start + len1))
		ft_memcpy(s1, &s[start], len1);
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1)
		return (first_step(s2));
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}
