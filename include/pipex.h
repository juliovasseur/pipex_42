/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:51:13 by jules             #+#    #+#             */
/*   Updated: 2023/03/23 15:22:49 by jvasseur         ###   ########.fr       */
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

typedef struct s_pipex {
	int		file_input;
	int		file_output;
	char	*path;
	int		tube[2];
	char	**tab_path;
	char	*cmd;
	char	**arg_cmd;
}				t_pipex;

void	msg_send_error(char *err);
int		msg_write_error(char *err);
void	child_prog(t_pipex *pipex, char **argv, char **envp);
void	second_child_prog(t_pipex *pipex, char **argv, char **envp);
void	free_all(t_pipex *pipex);
int		open_file_and_verif(t_pipex *pipex, char **argv);

#endif