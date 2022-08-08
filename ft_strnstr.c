/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:19:29 by tandrea           #+#    #+#             */
/*   Updated: 2021/10/19 10:56:30 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	j;
	size_t	i;
	char	*hc;

	hc = (char *)h;
	i = 0;
	if (!*n)
		return (hc);
	while (h[i] != '\0' && i < len)
	{	
		j = 0;
		if (h[i] == n[j])
		{
			while (n[j] != '\0' && i + j < len && h[i + j] == n[j])
			{
				if (n[j + 1] == '\0')
					return (hc + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
