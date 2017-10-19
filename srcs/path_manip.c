/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:13:38 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/18 12:14:52 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void		add_to_path(char *path, char *file_name)
{
	if (*path != 0)
		ft_strcat(path, "/");
	ft_strcat(path, file_name);
}

void		remove_from_path(char *path)
{
	int		stop;

	stop = ft_strlen(path);
	while (path[stop] != '/' && stop > 0)
		stop--;
	path[stop] = '\0';
}

char		**get_env_path(char **env)
{
	char		*path;
	char		**tab;

	tab = NULL;
	path = NULL;
	while (*env && (ft_strncmp(*env, "PATH", 4) != 0) != 0)
		env++;
	if (*env != NULL)
		path = *env + 5;
	if (path != NULL)
		tab = ft_strsplit(path, ':');
	return (tab);
}

char		*get_cur_dir(char *cur_dir_buff)
{
	char		*tmp;
	int			len;

	tmp = getcwd(cur_dir_buff, PATH_MAX + 1);
	len = ft_strlen(tmp);
	while (len > 0 && tmp[len] != '/')
		len--;
	if (tmp[len] == '/' && ft_strcmp(tmp, "/") != 0)
		len++;
	tmp = &tmp[len];
	return (tmp);
}
