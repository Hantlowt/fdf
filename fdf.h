/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:09:54 by alhote            #+#    #+#             */
/*   Updated: 2016/03/05 20:29:40 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "draw.h"

typedef struct	s_map
{
	int			sizex;
	int			sizey;
	int			sizez;
	int			**dots;
	t_point		***p;
}				t_map;

t_map			*init_map(char *path, t_world *w);
t_point			*find_pt(t_world *w, int x, int y);
int				make_grid(t_world *w, t_map *m);
int				mouse_motion(int x, int y, void *param);
int				key(int keycode, void *param);

#endif
