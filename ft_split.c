/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:24:33 by tandrea           #+#    #+#             */
/*   Updated: 2021/10/17 18:31:37 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	k;
	int	f;

	k = 0;
	i = 0;
	f = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && f == 0)
		{
			f = 1;
			k++;
		}
		else if (s[i] == c)
			f = 0;
		i++;
	}
	return (k);
}

static char	**ft_clean(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free (s);
	return (NULL);
}

int	ft_wordlen(char *w, char c, unsigned int i)
{
	int	d;

	d = 0;
	while (w[i] != '\0' && w[i] != c)
	{
		d++;
		i++;
	}
	return (d);
}

char	**reet(char *s, char c, char **s1)
{
	int				k;
	unsigned int	i;
	char			*word;

	k = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			word = ft_substr(s, i, ft_wordlen(s, c, i));
			if (!word)
				return (ft_clean(s1));
			s1[k++] = word;
			i = i + ft_wordlen(s, c, i);
		}
	}
	s1[k] = NULL;
	return (s1);
}

char	**ft_split(char *s, char c)
{
	char			**s1;

	if (!s)
		return (NULL);
	s1 = (char **)malloc((count_words (s, c) + 1) * sizeof(char *));
	if (s1 == NULL)
		return (NULL);
	if (reet (s, c, s1) == NULL)
		return (NULL);
	return (s1);
}
