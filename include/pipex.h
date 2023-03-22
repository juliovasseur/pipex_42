/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jules <jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:51:13 by jules             #+#    #+#             */
/*   Updated: 2023/03/11 03:26:25 by jules            ###   ########.fr       */
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
	int file_input;
    int file_output;
    char *path;
    int tube[2];
    char **tab_path;
    char *cmd;
    char **arg_cmd;
}				t_pipex;


void	msg_send_error(char *err);
int     msg_write_error(char *err);
void    child_prog(t_pipex *pipex, char **argv, char **envp);
void	second_child_prog(t_pipex *pipex, char **argv, char **envp);
#endif