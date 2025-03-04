#include "../pipex.h"

extern char **environ;

int	main(void)
{
	char	*cmd = "ls";

	char	*cmd_path = get_cmd_path(cmd, environ);
	printf("%s", cmd_path);

	return (0);
}