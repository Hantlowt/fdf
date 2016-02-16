/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:34:21 by alhote            #+#    #+#             */
/*   Updated: 2016/02/16 17:36:22 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_map			*init_map(char *path)
{
	int		fd;
	t_map	*map;
	char	*temp;

	fd = open(path, 1);
	while (get_next_line(fd, &temp))
	{
		return (0);
	}
	map = (t_map*)malloc(sizeof(t_map));
	return (map);
}
