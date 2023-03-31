/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:51:13 by jules             #+#    #+#             */
/*   Updated: 2023/03/31 18:38:55 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	char	**tab_paths;
	char	**tab_cmd;
	char	*cmd;
	char	*cmd_two;
	char	*env_path;
}		t_pipex;

				/*OPEN_FILES_BONUS.C*/

void	get_fd_infile(char **argv, t_pipex *pipex);
void	get_fd_outfile(char *argv, t_pipex *pipex);
int		verif_all_and_get_file(int argc, t_pipex *pipex);

				/*PIPEX_BONUS.C*/

void	close_all_pipes(t_pipex	*pipex);
char	*find_path(char **envp);

				/*CHILD_BONUS.C*/

void	child(t_pipex *pipex, char **argv, char **envp);

				/*FREE_BONUS.C*/

void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	pipe_free(t_pipex *pipex);
void	close_before(t_pipex *pipex);
void	free_error_execve(t_pipex *pipex);

				/*MSG_ERROR_BONUS.C*/

void	msg_send_error(char *err);
void	msg_pipe(void);
int		msg(char *err);

				/*GET_PATH.C*/

char	*find_path(char **envp);
void	add_cmd_slash(char **paths, t_pipex *pipex);

				/*HELP_FREE.C*/

void	close_all_pipes(t_pipex *pipex);
void	free_malloc_error(void);
void	free_error_malloc(t_pipex *pipex);
void	free_error_malloc_two(t_pipex *pipex);
void	free_error_cmd(t_pipex *pipex);

				/*UTILS.C*/	

int		verif_argv(char *argv);		
int		verif_all_and_get_file(int argc, t_pipex *pipex);
void	double_dup2(int zero, int first);

#endif
