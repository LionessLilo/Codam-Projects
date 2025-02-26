/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_cmd_path.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: llourens <llourens@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 14:13:34 by llourens      #+#    #+#                 */
/*   Updated: 2025/02/26 18:07:12 by llourens      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	*search_directories(char **directories, char *cmd);
char	*find_path_in_env(char **env, char *key);

char	*get_cmd_path(char *cmd, char **env)
{
	char	*path;
	char	**directories;
	char	*cmd_directory;
	char	**cmd_with_args;

	path = find_path_in_env(env, "PATH");
	if (!path)
		custom_error_and_exit("Error: PATH not found", 127);
	directories = ft_split(path, ':');
	ft_free(&path);
	cmd_directory = search_directories(&directories, cmd);
	if (!cmd_directory)
		custom_error_and_exit("Error: Failed to access directory", 127);
	return (cmd_directory);
}

char	*find_path_in_env(char **env, char *key)
{
	int		i;
	int		key_len;

	i = 0;
	key_len = ft_strlen(key);
	while (env[i])
	{
		if ((ft_strncmp(env[i], key, key_len) == 0)
			&& (env[i][key_len] == '='))
			return (ft_strdup(env[i] + key_len + 1));
		i++;
	}
	return (NULL);
}

char	*search_directories(char **directories, char *cmd)
{
	int		i;
	int		full_path_len;
	char	*full_path;
	char	*path_join;
	char	*temp_path;

	i = 0;
	while (directories[i])
	{
		full_path_len = ((ft_strlen(directories[i]))
				+ (ft_strlen(cmd)) + 2);
		full_path = malloc(sizeof(char) * full_path_len);
		if (!full_path)
			return (NULL);
		ft_strlcpy(temp_path, directories[i], full_path_len);
		path_join = ft_strjoin(temp_path, "/");
		full_path = ft_strjoin(path_join, cmd[0]);
		free_variables(&temp_path, &path_join);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		i++;
	}
	ft_putendl_fd("Error: Command not found", STDERR_FILENO);
	return (NULL);
}
