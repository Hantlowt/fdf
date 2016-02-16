/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 12:09:54 by alhote            #+#    #+#             */
/*   Updated: 2016/02/16 16:21:41 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "draw.h"

typedef struct	s_map
{
	int		size_x;
	int		size_y;
	int		dots;
	t_world	*w;
}				t_map;

t_map			*init_map(char *path);

#endif
