/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:07:57 by tandrea           #+#    #+#             */
/*   Updated: 2022/02/24 10:14:17 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_child(int **multip, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free (multip[j++]);
	free (multip);
}

void	free_pipe(int **multi, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 5)
	{
		if (close(multi[i][0]) == -1 || close(multi[i][1]) == -1)
			exit (write(2, "pipex: error\n", 13));
		i++;
	}
}

void	my_dup(int i, int *pip, int **multi, int argc)
{
	if (i == 0)
	{
		if (dup2(pip[0], 0) == -1 || dup2(multi[i][1], 1) == -1
			|| close(pip[0]) == -1 || close(pip[1]) == -1)
			exit (write(2, "pipex: error\n", 13));
		free_pipe(multi, argc);
	}
	else
	{
		if (dup2(multi[i - 1][0], 0) == -1 || dup2(multi[i][1], 1) == -1
			|| close(pip[0]) == -1 || close(pip[1]) == -1)
			exit (write(2, "pipex: error\n", 13));
		free_pipe(multi, argc);
	}
}

int	**ft_init(int argc)
{
	int	**tmp;
	int	i;

	i = 0;
	tmp = malloc (sizeof(int *) * (argc - 5));
	if (!tmp)
		exit(1);
	while (i < argc - 5)
	{
		tmp[i] = malloc(sizeof(int) * 2);
		if (!tmp)
			exit(1);
		if (pipe(tmp[i]) == -1)
			exit(1);
		i++;
	}
	return (tmp);
}

void	mult(int argc, char **argv, char **e, int pip[2])
{
	int	**multip;
	int	i;
	int	pid;

	i = -1;
	multip = ft_init(argc);
	while (++i < argc - 5)
	{
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
		{
			my_dup(i, pip, multip, argc);
			ft_free_child(multip, argc - 5);
			if (ft_strcmp(argv[1], "here_doc") == 0)
				ft_find_cmd(e, argv[i + 4]);
			ft_find_cmd(e, argv[i + 3]);
		}
	}
	open_file(argv, argc, i, multip);
	close_file(pip, multip, argc);
	fd(i, pid, argv, e);
}
