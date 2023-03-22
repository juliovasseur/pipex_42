
#include "../include/pipex_bonus.h"


void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	while (pipex->tab_paths[i])
	{
		free(pipex->tab_paths[i]);
		i++;
	}
	free(pipex->tab_paths);
	free(pipex);
}

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->tab_cmd[i])
	{
		free(pipex->tab_cmd[i]);
		i++;
	}
	free(pipex->tab_cmd);
	free(pipex->cmd);
}

void	pipe_free(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	free(pipex->pipe);
	msg("ERR_ENVP");
	exit(1);
}
