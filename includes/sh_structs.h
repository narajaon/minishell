/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:17:33 by narajaon          #+#    #+#             */
/*   Updated: 2017/11/05 17:14:01 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_STRUCTS_H
# define SH_STRUCTS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <signal.h>
# include <dirent.h>
# include "macros.h"

typedef struct			s_2link
{
	void				*content;
	int					position;
	struct s_2link		*prev;
	struct s_2link		*next;
}						t_2link;

typedef struct			s_schar
{
	char				sequ[3];
	char				asc;
}						t_schar;

typedef enum			e_fd
{
	STDI,
	STDO,
	STDE
}						t_fd;

typedef enum			e_name
{
	ECHO,
	CD,
	SET,
	USET,
	ENV,
	EXT,
	EXP,
	PRC_NB
}						t_name;

typedef enum			e_sig
{
	MYSIG_INT,
	NB_SIG
}						t_sig;

typedef struct			s_sighand
{
	char				err_str[100];
	int					sig_id;
}						t_sighand;

typedef enum			e_errno
{
	NOT_A_CMD,
	ERRDIR,
	PID,
	WRONG_TYPE,
	INVALID_CMD,
	SETENV_INVAL,
	CD_INVAL,
	EX_ARG,
	LES_ARG,
	USAGE,
	NO_PERM,
	VAR_UNSET,
	NB_ERR
}						t_errno;

typedef struct			s_sherror
{
	char				err_str[100];
	int					errno;
}						t_sherror;

typedef struct			s_in
{
	char				*user_in;
	char				**split_in;
	t_list				*input_lst;
	t_list				*history;
	char				*cmd_name;
}						t_in;

typedef struct			s_prc
{
	char				**prc_tab;
	void				*prc_funs[PRC_NB];
	int					proc_id;
}						t_prc;

typedef struct			s_shcmd
{
	char				name[PRC_LEN];
	int					index;
	void				*fun_ptr;
}						t_shcmd;

typedef struct			s_local
{
	char				*name;
	char				*val;
	t_bool				has_equ;
}						t_local;

typedef struct			s_shenv
{
	char				*cur_dir;
	char				**bin_path;
	t_list				*env_list;
	char				**env_tab;
}						t_shenv;

typedef struct			s_sh
{
	t_in				input;
	t_prc				proc;
	t_shenv				cmd_env;
	t_local				*lst_local;
	char				cur_dir[PATH_MAX + 1];
	char				prev_dir[PATH_MAX + 1];
	char				*exec_path;
}						t_sh;

#endif
