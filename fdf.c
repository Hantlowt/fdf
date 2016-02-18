/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:34:21 by alhote            #+#    #+#             */
/*   Updated: 2016/02/18 16:11:53 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

static int				count_char(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
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
		while (*str != ' ' && *str)
			str++;
		str++;
		id--;
	}
	ptr = str;
	while (*str != ' ' && *str)
	{
		++size;
		str++;
	}
	result = (char*)malloc(sizeof(char) * size + 1);
	result = ft_strncpy(result, ptr, size);
	size = ft_atoi(result);
	ft_memdel((void**)&result);
	return (size);
}

t_map					*init_map(char *path)
{
	int		fd;
	t_map	*map;
	char	*temp;
	int		i;

	fd = open(path, O_RDONLY);
	map = (t_map*)ft_memalloc(sizeof(t_map));
	map->sizex = 0;
	map->sizey = 0;
	while ((i = get_next_line(fd, &temp)))
	{
		if (i < 0 || (map->sizex && (count_char(temp, ' ') + 1) != map->sizex))
			return (0);
		else
			map->sizex = (count_char(temp, ' ') + 1);
		map->sizey++;
		i = -1;
		map->dots = (int**)ft_realloc(map->dots, (sizeof(int*) * map->sizey));
		map->dots[map->sizey - 1] = (int*)ft_memalloc(sizeof(int) * map->sizex);
		while (++i < map->sizex)
			map->dots[map->sizey - 1][i] = get_nbr(temp, i);
	}
	return (map);
}