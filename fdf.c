/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:34:21 by alhote            #+#    #+#             */
/*   Updated: 2016/03/05 17:39:05 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

/*static int				count_char(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c && *(str + 1) != c)
			++i;
		str++;
	}
	return (i);
}

static int				get_nbr(char *str, int id)
{
	char	*ptr;
	int		size;
	char	*result;

	size = 0;
	result = 0;
	while (id > 0)
	{
		while ((*str != ' ' || *(str + 1) == ' ') && *str)
			str++;
		str++;
		id--;
	}
	ptr = str;
	while ((*str != ' ' || *(str + 1) == ' ') && *str)
	{
		++size;
		str++;
	}
	result = (char*)malloc(sizeof(char) * size + 1);
	result = ft_strncpy(result, ptr, size);
	size = ft_atoi(result);
	ft_memdel((void**)&result);
	return (size);
}*/

static int				make_grille(t_map *m, t_world *w)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!w || !m)
		return (0);
	while (y < m->sizey)
	{
		while (x < m->sizex)
		{
			if (x < m->dots[y][0])
				w->seg = init_segment(m->p[y][x], m->p[y][x + 1], w->seg);
			if (y < m->sizey - 1 && m->dots[y + 1][0] >= m->dots[y][0])
				w->seg = init_segment(m->p[y][x], m->p[y + 1][x], w->seg);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int						map_to_world(t_map *m, t_world *w)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!w || !m)
		return (0);
	m->p = (t_point***)ft_memalloc(sizeof(t_point**) * m->sizey);
	while (y < m->sizey)
	{
		m->p[y] = (t_point**)ft_memalloc(sizeof(t_point*) * m->sizex);
		while (x < m->dots[y][0])
		{
			m->sizez = (m->dots[y][x + 1] > m->sizez ? m->dots[y][x + 1] : m->sizez);
			add_point(w, (double)x, (double)m->dots[y][x + 1], (double)y);
			w->p->color += (m->dots[y][x + 1] * 5) % 255;
			m->p[y][x] = (t_point*)ft_memalloc(sizeof(t_point));
			m->p[y][x] = w->p;
			++x;
		}
		x = 0;
		y++;
	}
	make_grille(m, w);
	return (1);
}

static int	ft_wordnbr(char const *s, char c)
{
	int	words;

	words = 0;
	while (*++s)
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			words++;
	return (words);
}

t_map					*init_map(char *path, t_world *w)
{
	int		fd;
	t_map	*map;
	char	*temp;
	int		i;

	fd = open(path, O_RDONLY);
	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->sizex = 0;
	map->sizey = 0;
	map->sizez = 0;
	while ((i = get_next_line(fd, &temp)))
	{
		if (i < 0)
			return (0);
		i = -1;
		temp = ft_strtrim(temp);
		while (++i <= ft_wordnbr(temp, ' '))
			add_point(w, (double)i, (double)ft_atoi(ft_strsplit(temp, ' ')[i]), (double)map->sizey);
		map->sizey++;
	}
	return (map->sizey - 1 ? map : 0);
}
