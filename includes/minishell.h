/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 12:18:04 by narajaon          #+#    #+#             */
/*   Updated: 2017/10/19 16:00:34 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "sh_structs.h"

pid_t					g_cur_pid;
volatile t_bool			g_loop;

int						g_errno;
int						g_cmd_ret;

int						g_fd_ou;
int						g_fd_in;
int						g_fd_err;

t_sh					*g_env_ptr;

extern const t_shcmd	g_sh_struct[PRC_NB + 1];
extern const t_sherror	g_sh_error[NB_ERR + 1];
extern const t_schar	g_spec_char[SCHAR_NB];
extern const t_sighand	g_sig_msg[NB_SIG + 1];

void					exec_sh(t_sh *sh_env);

int						echo_cmd(t_sh *sh_env, char **env);
int						cd_cmd(t_sh *sh_env, char **env);
int						setenv_cmd(t_sh *sh_env, char **env);
int						unsetenv_cmd(t_sh *sh_env, char **bin_path);
int						env_cmd(t_sh *sh_env, char **env);
int						exit_cmd(t_sh *sh_env, char **env);
int						exec_cmd(t_sh *sh_env, char **env);

int						export_cmd(t_sh *sh_env, char **bin_path);

void					parse_input(t_in *input);
int						is_esc_char(char *str);
int						get_proc_index(char *cmd, const t_shcmd *cmd_tab);
void					get_input(int fd, t_in *input);
int						get_cmd_name(char *cmd_name, char *user_in);
char					**ft_arg_split(char *str, t_list **list);
char					*check_bin(char **paths, t_prc *proc, t_in *input);
void					format_input(char **str);
char					**ft_format_tab_content(char **tab, void (*fmt)());
char					*replace_spec_char(char *user_in, int size);
t_bool					export_valid_arg(char *str, char ***arg);
t_bool					is_valid_setenv_arg(char *str, int *pos);
char					*get_str_in_quotes(char *str, int *pos);
void					fork_process(int proc_id, int (*cmd)(),
		t_sh *sh_env, char **bin_path);
void					apply_env_opt(char **arg, char **bin_path, t_sh *env);

t_bool					is_env_var(char *str, char *var);
void					add_var_to_env(char **arg, t_list **env);
t_bool					setenv_has_args(char *str);
void					init_env(t_sh *sh_env, char **env);
void					ft_usage(int ac, char **av);

void					update_path(t_sh *sh_env, char *cur_dir);
void					remove_from_path(char *path);
void					add_to_path(char *path, char *file_name);
char					*get_var_val(t_shenv *cmd_env, char *var);
char					**fill_env_var(char *var_name, char *var_value);

t_bool					is_valid_path(char *path_bin);
int						exit_error(int error, char *bad_input,
		char *cmd_name, int ret);
void					sighandler(int sigval);
t_bool					jump_loop(void);
void					sig_intercepter(void);
void					flush_sh_env(t_sh *env);
void					update_env_tab(t_sh *sh_env);

t_list					*ft_tab_to_list(char **str);
char					**ft_list_to_tab(t_list **list);
char					*get_cur_dir(char *cur_dir_buff);
char					**get_env_path(char **env);
void					del_list(void *content, size_t size);
void					ft_lstpop(t_list **list, t_bool (*cmp)(), void *to_cmp);
#endif
