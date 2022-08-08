/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:03:39 by tandrea           #+#    #+#             */
/*   Updated: 2022/02/24 10:15:00 by tandrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strnstr(const char *h, const char *n, size_t len);
void	ft_find_cmd(char **env, char *ar);
char	*get_path(char **str, char *cmd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	for_child(char **argv, char **e, int pip[2]);
void	for_parent(int argc, char **argv, char **e, int pip[2]);
char	**ft_clear(char **s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_mistake(void);
char	*get_next_line(void);
void	here_doc(char **argv, char **e, int pip[2]);
char	*ft_strnjoin(char *s1, char *s2);
char	*first_step(char *str);
void	here_doc_parent(char **argv, char **e, int pip[2]);
void	mult(int argc, char **argv, char **e, int pip[2]);
void	fd(int i, int pid, char **argv, char **e);
void	open_file(char **argv, int argc, int i, int **multip);
void	close_file( int *pip, int **multip, int argc);
void	ft_free_child(int **multip, int i);
void	free_pipe(int **multi, int argc);

#endif
