
#include "../include/pipex_bonus.h"

void	get_fd_infile(char **argv, t_pipex *pipex)
{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			msg_error("ERR_INFILE");
}

void	get_fd_outfile(char *argv, t_pipex *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		pipex->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex->outfile < 0)
		msg_error("ERR_OUTFILE");
}
