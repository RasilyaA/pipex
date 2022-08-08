/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                             :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:59:54 by tandrea           #+#    #+#             */
/*   Updated: 2022/02/21 17:07:01 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_mistake(void)
{
	perror("pipex");
	exit(1);
}

void	for_parent(int argc, char **argv, char **e, int pip[2])
{
	int	fd;

	if (ft_strcmp(argv[1], "here_doc") != 0 && argc > 5)
		mult(argc, argv, e, pip);
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc > 6)
		mult(argc - 1, argv, e, pip);
	if (ft_strcmp(argv[1], "here_doc") == 0 && argc)
		here_doc_parent(argv, e, pip);
	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_mistake();
	if (dup2(pip[0], 0) == -1 || dup2(fd, 1) == -1
		|| close(fd) == -1 || close(pip[0]) == -1
		|| close(pip[1]) == -1)
		exit (write(2, "pipex: error\n", 13));
	ft_find_cmd (e, argv[3]);
}

void	for_child(char **argv, char **e, int pip[2])
{
	int	fd;

	if (ft_strcmp(argv[1], "here_doc") == 0)
		here_doc(argv, e, pip);
	else
	{
		if (access(argv[1], F_OK) == -1)
			ft_mistake();
		else if (access(argv[1], R_OK) == -1)
			ft_mistake();
		if (ft_strcmp(argv[1], argv[4]) == 0)
			fd = open(argv[1], O_RDONLY | O_TRUNC);
		else
			fd = open(argv[1], O_RDONLY);
		if (dup2(fd, 0) == -1 || dup2(pip[1], 1) == -1
			|| close(fd) == -1 || close(pip[0]) == -1
			|| close(pip[1]) == -1)
			exit (write(2, "pipex: error\n", 13));
		ft_find_cmd (e, argv[2]);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		mypipe[2];
	int		i;
	pid_t	pid;

	i = 0;
	while ((ft_strnstr(env[i], "PATH=", 5)) == NULL)
	{
		i++;
		if (env[i] == NULL)
			exit(write (2, "pat pipex!!!", 13));
	}
	if ((ft_strcmp(argv[1], "here_doc") == 0 && argc < 6) || argc < 5)
		exit(1);
	if (pipe(mypipe) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		for_child(argv, env, mypipe);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		waitpid(pid, 0, 0);
	for_parent(argc, argv, env, mypipe);
}
