/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:26:41 by jules             #+#    #+#             */
/*   Updated: 2023/03/24 15:38:26 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->arg_cmd[i])
	{
		free(pipex->arg_cmd[i]);
		i++;
	}
	free(pipex->arg_cmd);
	free(pipex->cmd);
}

char	*cmd(char **path, char *command)
{
	int		i;
	char	*cmd;

	i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], command);
		if (access(cmd, 0) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

void	child_prog(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->tube[1], STDOUT_FILENO);
	dup2(pipex->file_input, STDIN_FILENO);
	pipex->arg_cmd = ft_split(argv[2], ' ');
	close(pipex->tube[0]);
	pipex->cmd = cmd(pipex->tab_path, pipex->arg_cmd[0]);
	if (!pipex->cmd)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close_pipes(pipex);
		child_free(pipex);
		free_all(pipex);
		free(pipex);
		msg_write_error("Error first cmd");
		exit(1);
	}
	execve(pipex->cmd, pipex->arg_cmd, envp);
}

void	second_child_prog(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->tube[0], STDIN_FILENO);
	dup2(pipex->file_output, STDOUT_FILENO);
	pipex->arg_cmd = ft_split(argv[3], ' ');
	close(pipex->tube[1]);
	pipex->cmd = cmd(pipex->tab_path, pipex->arg_cmd[0]);
	if (!pipex->cmd)
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close_pipes(pipex);
		child_free(pipex);	
		free_all(pipex);
		free(pipex);
		msg_write_error("Error second cmd");
		exit(1);
	}
	execve(pipex->cmd, pipex->arg_cmd, envp);
}
