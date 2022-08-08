/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:39:31 by tandrea           #+#    #+#             */
/*   Updated: 2022/01/29 17:36:58 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_clear(char **s)
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

char	*get_path(char **str, char *cmd)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		path = ft_strjoin(str[i], "/");
		tmp = ft_strjoin(path, cmd);
		free(path);
		if (access(tmp, F_OK) == 0)
		{
			ft_clear(str);
			return (tmp);
		}
		else
			free(tmp);
		i++;
	}
	return (NULL);
}

void	ft_comanda(char *e, char **cmd, char **env)
{
	char	*comd;
	char	**paths;

	paths = ft_split(e + 5, ':');
	if (!paths)
		ft_mistake();
	comd = get_path(paths, cmd[0]);
	if (!comd)
	{
		ft_clear(paths);
		ft_clear(cmd);
		write (1, "bad pipex!!!", 13);
		exit(1);
	}
	if (execve(comd, cmd, env) == -1)
	{
		free(comd);
		ft_clear(cmd);
		ft_mistake();
	}
}

void	ft_find_cmd(char **env, char *ar)
{
	char	**cmd;
	int		i;

	i = 0;
	cmd = ft_split(ar, ' ');
	if (!cmd)
		ft_mistake();
	while ((ft_strnstr(env[i], "PATH=", 5)) == NULL)
		i++;
	ft_comanda(env[i], cmd, env);
}
