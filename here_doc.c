/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:07:35 by tandrea           #+#    #+#             */
/*   Updated: 2022/02/21 17:15:52 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tmp(char *tmp, char *tmp2, char *tmp3)
{
	free(tmp);
	free(tmp2);
	free(tmp3);
}

void	here_doc(char **argv, char **e, int pip[2])
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	int		here_pip[2];

	tmp1 = NULL;
	tmp2 = NULL;
	while (ft_strcmp(tmp2, argv[2]) != 0)
	{
		tmp1 = ft_strnjoin(tmp1, tmp2);
		free(tmp2);
		write (1, "pipe heredoc> ", 15);
		tmp2 = get_next_line();
	}
	tmp3 = ft_strjoin(tmp1, "\n");
	if (pipe(here_pip) == -1)
		exit(1);
	write (here_pip[1], tmp3, ft_strlen(tmp3));
	ft_free_tmp(tmp1, tmp2, tmp3);
	if (dup2(here_pip[0], 0) == -1 || dup2(pip[1], 1) == -1
		|| close(here_pip[0]) == -1 || close(here_pip[1]) == -1
		|| close(pip[0]) == -1 || close(pip[1]) == -1)
		exit (write(2, "pipex: error\n", 13));
	ft_find_cmd (e, argv[3]);
}
