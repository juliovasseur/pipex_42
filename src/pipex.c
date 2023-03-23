/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvasseur <jvasseur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 04:32:59 by jules             #+#    #+#             */
/*   Updated: 2023/03/23 15:09:10 by jvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	add_cmd_slash(char **paths)
{
	int		i;
	char	*tmp;

	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		i++;
	}
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t		pid1;
	pid_t		pid2;
	t_pipex		*pipex;

	if (argc != 5)
		return (msg_write_error("Error input, number arguments invalid"));
	pipex = malloc(sizeof(t_pipex));
	if (open_file_and_verif(pipex, argv) == 0)
		return (2);
	if (pipe(pipex->tube) == -1)
		msg_send_error("Error pipe");
	pipex->path = find_path(envp);
	pipex->tab_path = ft_split(pipex->path, ':');
	add_cmd_slash(pipex->tab_path);
	pid1 = fork();
	if (pid1 == 0)
		child_prog(pipex, argv, envp);
	pid2 = fork();
	if (pid2 == 0)
		second_child_prog(pipex, argv, envp);
	close_pipes(pipex);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_all(pipex);
	return (0);
}
