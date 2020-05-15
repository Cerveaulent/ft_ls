/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccantin <ccantin@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/09 14:49:50 by eschnell     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/30 17:41:21 by ccantin     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static char			*g_opts = NULL;
static t_fdir		*g_tmp_dir = NULL;

static void			final_cleanup(void)
{
	if (g_opts)
		ft_strdel(&g_opts);
}

static void			post_cleanup(t_arraylist *fdirs)
{
	del_fdir_arlst(fdirs);
}

static void			post_main(t_fdir *tmp_dir)
{
	t_arraylist		*fdirs;

	if (tmp_dir == NULL)
		return ;
	if (opts_has_l(g_opts) && tmp_dir->sl)
		return (ls_print_sl(g_opts, tmp_dir));
	if ((ls_isdir(tmp_dir->path) && !opts_has_l(g_opts)) ||
			S_ISDIR(tmp_dir->stats->st_mode))
		fdirs = ls_populate_fdirs(g_opts, tmp_dir);
	else
	{
		fdirs = check_malloc(arraylist(tmp_dir, 1));
		ft_strchr(g_opts, 'l') ? (*(ft_strchr(g_opts, 'l')) = 'F') : 0;
	}
	if (tmp_dir->sl && ft_strchr(g_opts, 'R'))
	{
		ft_strdel(&(tmp_dir->path));
		tmp_dir->path = (char *)check_malloc(ft_strdup(tmp_dir->sl));
	}
	ft_strchr(g_opts, 'R') ? \
		ls_buckle(g_opts, fdirs) : ls_print(g_opts, fdirs, true);
	post_cleanup(fdirs);
}

int					main(int ac, char **av)
{
	int				i;
	t_arraylist		*fdirs;

	fdirs = NULL;
	g_opts = check_malloc(ft_strnew(0));
	i = parse_opts(&g_opts, ac, av);
	av += i;
	ac -= i;
	if (ac <= 1)
	{
		g_tmp_dir = ac < 1 ? \
			direct_fdir(".", g_opts) : direct_fdir(*av, g_opts);
		post_main(g_tmp_dir);
		if (ac < 1)
			del_fdir(g_tmp_dir);
	}
	else if ((fdirs = get_fdirs_list(ac, av, g_opts)) != NULL)
	{
		ls_first(g_opts, fdirs);
		del_fdir_arlst(fdirs);
	}
	final_cleanup();
	return (0);
}
