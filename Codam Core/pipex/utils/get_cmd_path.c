/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cmd_path.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 14:13:34 by llourens      #+#    #+#                 */
/*   Updated: 2025/03/03 20:01:21 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_get_env(char **envp);

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path_from_env;
	char	**directories;
	char	*cmd_directory;

	path_from_env = ft_get_env(env);
	if (!path_from_env)
		custom_error_and_exit("failed to find PATH", 127);
	directories = ft_split(path_from_env, ':');
	cmd_directory = find_cmd_directory(directories, cmd);
}

char	*ft_get_env(char **envp)
{
	int		pos_in_list;
	char	*path_directories;
	char	*start_copying;

	pos_in_list = 0;
	while (envp[pos_in_list])
	{
		if (ft_strncmp(envp[pos_in_list], "PATH", 4) == 0)
		{
			start_copying = ft_strchr(envp[pos_in_list], '=');
			path_directories = ft_strdup(start_copying + 1);
			return (path_directories);
		}
		pos_in_list++;
	}
	return (NULL);
}

char	*find_cmd_directory(char **directories, char *cmd)
{
	char	*directory_and_slash;
	char	*full_directory;
	int		pos_in_directories;

	while (directories[pos_in_directories])
	{
		directory_and_slash = malloc(sizeof(char)
				* ft_strlen(directories[pos_in_directories]) + 1);
		if (!directory_and_slash)
			return (NULL);
		directory_and_slash = 
		
	}
}
