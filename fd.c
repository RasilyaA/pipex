/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:04:58 by tandrea           #+#    #+#             */
/*   Updated: 2022/02/24 10:07:36 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_file(char **argv, int argc, int i, int **multip)
{
	int	fd;

	if (ft_strcmp(argv[1], "here_doc") == 0)
		fd = open(argv[argc], O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
		fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_mistake();
	if (dup2(multip[i - 1][0], 0) == -1 || dup2(fd, 1) == -1
		|| close(fd) == -1)
		exit (write(2, "pipex: error\n", 13));
}

void	close_file( int *pip, int **multip, int argc)
{
	if ((close(pip[0]) == -1) && close (pip[1] == -1))
		ft_mistake();
	free_pipe(multip, argc);
	ft_free_child(multip, argc - 5);
}

void	fd(int i, int pid, char **argv, char **e)
{
	waitpid(pid, 0, 0);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		ft_find_cmd(e, argv[i + 4]);
	ft_find_cmd(e, argv[i + 3]);
}
