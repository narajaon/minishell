/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_bin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:52:20 by narajaon          #+#    #+#             */
/*   Updated: 2017/11/05 21:42:24 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int			get_cmd_name(char **cmd_name, char *user_in)
{
	int		i;

	i = 0;
	while (user_in[i] != '\0' && ft_isspace(user_in[i]) == FALSE)
		i++;
	*cmd_name = ft_strndup(user_in, i);
	return (i);
}

int			get_input(int fd, t_in *input)
{
	int		arg_index;
	char	*tmp_gnl;
	char	*tmp_to_free;

	input->input_lst = NULL;
	tmp_gnl = NULL;
	if (get_next_line(fd, &tmp_gnl) == -1)
		return (-1);
	tmp_to_free = tmp_gnl;
	while (ft_isspace(*tmp_gnl))
		tmp_gnl++;
	input->user_in = ft_strdup(tmp_gnl);
	free_str(&tmp_to_free);
	arg_index = get_cmd_name(&input->cmd_name, input->user_in);
	return (arg_index);
}

int			get_proc_index(char *cmd, const t_shcmd *cmd_tab)
{
	int		i;
	int		ret;

	i = 0;
	if (cmd == NULL)
		return (-1);
	while (cmd_tab[i].fun_ptr != NULL)
	{
		if ((ret = ft_strcmp(cmd, cmd_tab[i].name)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

t_bool		is_valid_path(char *path_bin)
{
	if (access(path_bin, X_OK) == 0)
		return (TRUE);
	return (FALSE);
}

char		*check_bin(char **paths, t_prc *proc, t_in *input)
{
	const char		*path;
	char			*slashed;
	char			*tmp;

	if (paths == NULL)
		return (NULL);
	path = input->cmd_name;
	while (*paths != NULL)
	{
		slashed = ft_strjoin(*paths, "/");
		if (is_valid_path((tmp = ft_strjoin(slashed, path))) == TRUE)
			return (tmp);
		free_str(&tmp);
		free_str(&slashed);
		paths++;
	}
	return (NULL);
}
