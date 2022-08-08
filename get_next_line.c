/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:49:27 by tandrea           #+#    #+#             */
/*   Updated: 2022/02/21 13:49:34 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_next_line(void)
{
	int		j;
	char	*buf;
	char	*line;
	char	*tmp;

	line = NULL;
	while (1)
	{
		buf = malloc(sizeof(char) + 1);
		j = read(0, buf, 1);
		if (buf[0] == '\n' || buf[0] == '\0')
			break ;
		buf[1] = '\0';
		tmp = ft_strjoin(line, buf);
		free(line);
		line = tmp;
		free(buf);
	}
	free(buf);
	return (line);
}
