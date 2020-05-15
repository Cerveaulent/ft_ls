/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eschnell <eschnell@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 14:46:04 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 09:04:30 by eschnell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <uuid/uuid.h>
# include <stdlib.h>
# include <stdio.h>
# include "colours.h"
# include "../libft/includes/libft.h"

# define _EXEC          "ft_ls"
# define _LS_OPTS       "@1ARalrt"
# define _DIR_BUF       1024
# define __USE_XOPEN
# define C_OFFSET		(2599000 + 43200 - 25000) * 6
# ifdef true
#  undef true
# endif
# ifdef false
#  undef false
# endif

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef enum			e_bool
{
	false,
	true
}						t_bool;

typedef struct			s_linfo
{
	unsigned int		link_spacing;
	unsigned int		user_spacing;
	unsigned int		group_spacing;
	unsigned int		size_spacing;
	unsigned int		minor_spacing;
	unsigned int		major_spacing;
}						t_linfo;

typedef struct			s_fdir
{
	char				*name;
	size_t				namlen;
	char				*path;
	t_stat				*stats;
	char				*sl;
	char				*mode;
	t_linfo				*info;
	int					expli;
}						t_fdir;

/*
** main.c
*/
void					ls_print_total(u_int64_t total);
/*
** opts.c
*/
t_bool					opts_has_l(char *opts);
int						check_prm(char *prm);
int						isopt(char *s, char *opts);
int						parse_opts(char **opts, int prmrange, char **prms);

/*
** ls_filedirs.c
*/
void					get_file_link(t_fdir *fdir);
t_fdir					*fdir(char *given_path);
t_fdir					*direct_fdir(char *given_path, char *opts);
t_fdir					*init_fdir(char *given_path, int state);
t_arraylist				*get_fdirs_list(int lsize, char **list, char *opts);

/*
** ls_usergroup_id.c
*/
char					*conv_uid(uid_t uid);
char					*conv_gid(uid_t gid);

/*
** ls_utils1.c
*/
void					ls_loop(char *opts, t_arraylist *fdirs, char dots);
int						ls_isdir(char *path);
void					ls_buckle(char *opts, t_arraylist *fdirs);

/*
** ls_utils2.c
*/
t_arraylist				*ls_dirs(char *opts, t_arraylist *fdirs);
void					ls_gen_fdirs_sort(char *opts, t_arraylist *fdirs);
t_arraylist				*ls_populate_fdirs(char *opts, t_fdir *tmp_fdir);

/*
** ls_utils3.c
*/
void					ls_get_info(t_fdir **fdir);
void					ls_l_prepare(char *opts, t_arraylist *fdirs,
										t_bool state);
void					extract_linfo(t_fdir *fdir);
/*
** ls_utils4.c
*/
void					ls_first(char *opts, t_arraylist *fdirs);
void					del_fdir(t_fdir *filedir);
void					del_fdir_arlst(t_arraylist *fdirs);
unsigned int			count_dozen(unsigned int n);

/*
** ls_utils5.c
*/
void					ls_print_fdir_struct(t_fdir *fdirs);
int						getacl(char *s);

/*
** utils.c
*/
void					*lsperror(char *ret);
void					*check_malloc(void *ret);
void					checkopts(char *opts, char *to_free);
int						isdots(char *s);
int						grab_entry(char *opts, char *s);

/*
** ls_print1.c
*/
unsigned int			ls_get_max_size(t_arraylist *fdirs);
void					ls_prtparent(char *s);
void					ls_print(char *opts, t_arraylist *fdirs, t_bool state);

/*
** ls_print2.c
*/
char					*ls_print_permissions(int mode, char *link, \
												char *path);
void					ls_print_l(char *opts, t_fdir *fdir, t_linfo *tmp_info);

/*
** ls_print3.c
*/
void					ls_print_sp_left(char *s, size_t sp);
void					ls_print_sp_right(char *s, size_t sp);
void					ls_print_left(char *s, size_t sp);
void					ls_print_right(char *s, size_t sp);

/*
** ls_cmp_fdir.c
*/
int						ls_fdir_cmp(t_fdir *fd1, t_fdir *fd2);
int						ls_fdir_t_cmp(t_fdir *fd1, t_fdir *fd2);

/*
** free_t_fdir.c
*/
void					free_t_fdir(t_fdir *fdir);

/*
** ls_filedirs_re.c
*/
t_fdir					*direct_fdir_extended_sl(t_fdir *curr_fdir, char *opts);
t_linfo					*ls_stock_sp_max(t_fdir *curr_fdir);

/*
** ls_print_sl.c
*/
void					ls_print_sl(char *opts, t_fdir *curr_sl);

void					ls_print_extended(char *opts, t_fdir *tmp_fdir,
											t_linfo *tmp_info);

/*
** ls_colours.c
*/
char					*get_parent_path(char *path);
t_fdir					*get_sl_path(char *full_path, char *fn);
void					ls_format_name_c(char *opts, t_fdir *fdir);
#endif
