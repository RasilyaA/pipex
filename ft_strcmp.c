/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:00:46 by tandrea           #+#    #+#             */
/*   Updated: 2021/10/17 18:39:29 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (ss1 == NULL || ss2 == NULL)
		return (1);
	if (*ss1 == 0 || *ss2 == 0)
		return (1);
	while (*ss1 || *ss2)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (0);
}
