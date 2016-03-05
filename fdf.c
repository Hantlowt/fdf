/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:34:21 by alhote            #+#    #+#             */
/*   Updated: 2016/03/05 22:23:49 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

static int					ft_wordnbr(char const *s, char c)
{
	int	words;

	words = 0;
	while (*++s)
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			words++;
	return (words);
}

static void					seg(t_world *w, int x, int sizex, int sizey)
{
	int		i;
	t_point	*p;

	i = 0;
	p = w->p;
	if (x)
		add_segment_with_last_pts(w);
	if (sizey && x < sizex)
	{
		while (i < sizex)
		{
			p = p->prev;
			i++;
		}
		w->seg = init_segment(w->p, p, (w->seg ? w->seg : 0));
	}
}

t_map						*init_map(char *path, t_world *w)
{
	int		fd;
	t_map	*m;
	char	*temp;
	int		i;

	fd = open(path, O_RDONLY);
	m = (t_map*)malloc(sizeof(t_map));
	m->sizex = 0;
	m->sizey = 0;
	while ((i = get_next_line(fd, &temp)))
	{
		if (i < 0)
			return (0);
		temp = ft_strtrim(temp);
		i = (ft_wordnbr(temp, ' ') && temp[0] != ' ' ? -1 : 0);
		while (++i <= ft_wordnbr(temp, ' '))
		{
			add_point(w, i, ft_atoi(ft_strsplit(temp, ' ')[i]), m->sizey);
			w->p->color += ft_atoi(ft_strsplit(temp, ' ')[i]) * 5;
			seg(w, i, m->sizex, m->sizey);
		}
		m->sizey += (ft_wordnbr(temp, ' ') && temp[0] != ' ' ? 1 : 0);
		m->sizex = (ft_wordnbr(temp, ' ') && temp[0] != ' ' ? i : m->sizex);
	}
	return (m->sizey - 1 ? m : 0);
}
