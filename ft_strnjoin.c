/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kferterb <kferterb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 18:26:13 by kferterb          #+#    #+#             */
/*   Updated: 2022/02/01 16:23:30 by kferterb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*first_step(char *str)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char *) * ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	*ft_strnjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (first_step(s2));
	res = malloc(sizeof(*res) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '\n';
	j = 0;
	while (s2[++j - 1])
		res[i + j] = s2[j - 1];
	res[i + j] = '\0';
	free(s1);
	return (res);
}
