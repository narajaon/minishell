/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:39:44 by narajaon          #+#    #+#             */
/*   Updated: 2017/11/05 21:39:30 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

# define EMJ_ARRW 0x27A1

# define PRC_LEN 9
# define MAX_CMD_NAME 10

# define SCHAR_NB 11

# define NBR(x) printf(#x "= %d\n", x)
# define STR(x) printf(#x "= %s\n", x)
# define CHAR(x) printf(#x "= %c\n", x)
# define EX exit(1);
# define ICI printf("ICI\n");

#endif
