/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:23:08 by jvasseur          #+#    #+#             */
/*   Updated: 2023/03/31 15:36:59 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include"../Libft/libft.h"

# include<string.h>
# include<stdlib.h>
# include<sys/wait.h>
# include<unistd.h>
# include<stddef.h>
# include<limits.h>
# include<fcntl.h>
# include<stdio.h>

typedef struct s_pipex
{
	pid_t	pid;
	int		nb_cmd;
	int		idx;
	int		pipe[2][2];
	int		tube[2];
	int		idx_path;
	int 	*tab_wait;
	int 	tmp_tab;
	int		infile;
	int		outfile;
	int		here_doc;
	char	**tab_paths;
	char	**tab_cmd;
	char	*cmd;
	char	*env_path;
}		t_pipex;

				/*OPEN_FILES_BONUS.C*/

void	get_fd_infile(char **argv, t_pipex *pipex);
void	get_fd_outfile(char *argv, t_pipex *pipex);
int		verif_all_and_get_file(int argc, char **argv, t_pipex *pipex);

				/*PIPEX_BONUS.C*/

void	close_all_pipes(t_pipex	*pipex);
char	*find_path(char **envp);

				/*CHILD_BONUS.C*/

void	child(t_pipex *pipex, char **argv, char **envp);

				/*FREE_BONUS.C*/

void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	pipe_free(t_pipex *pipex);

				/*HERE_DOC_BONUS.C*/

int		here_doc_or_not(char *arg, t_pipex *pipex);
void	here_doc(t_pipex *pipex, char *argv);

				/*MSG_ERROR_BONUS.C*/

void	msg_send_error(char *err);
void	msg_pipe(void);
int		msg(char *err);

#endif
