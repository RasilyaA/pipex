/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_parent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:48:29 by tandrea           #+#    #+#             */
/*   Updated: 2022/02/21 15:48:31 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc_parent(char **argv, char **e, int pip[2])
{
	int	fd;

	fd = open(argv[5], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		ft_mistake();
	if (dup2(pip[0], 0) == -1 || dup2(fd, 1) == -1
		|| close(fd) == -1 || close(pip[0]) == -1
		|| close(pip[1]) == -1)
		exit (write(2, "pipex: error\n", 13));
	ft_find_cmd (e, argv[4]);
}
