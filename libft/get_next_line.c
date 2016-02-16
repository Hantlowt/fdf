/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 12:21:00 by alhote            #+#    #+#             */
/*   Updated: 2016/02/08 10:14:34 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strlenchr(const char *s1)
{
	int	i;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
		++i;
	return (i);
}

static char		*ft_strdupchr(const char *s1)
{
	char	*ans;
	int		len;
	int		i;

	len = ft_strlenchr(s1);
	ans = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!len)
		return (ft_strdup(""));
	if (ans)
	{
		while (i < len)
		{
			ans[i] = s1[i];
			i++;
		}
		ans[i] = '\0';
	}
	return (ans);
}

int				get_next_line(int const fd, char **line)
{
	static char	*buffer[256];
	int			ret;
	char		*l_buffer;

	if (!buffer[fd % 256])
		buffer[fd % 256] = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	l_buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	while (!ft_strchr(buffer[fd % 256], '\n') && ret > 0)
	{
		ret = read(fd, l_buffer, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		l_buffer[ret] = '\0';
		buffer[fd % 256] = ft_strjoin(buffer[fd % 256], l_buffer);
	}
	*line = ft_strdupchr(buffer[fd % 256]);
	if (ret)
		buffer[fd % 256] = ft_strdup(&ft_strchr(buffer[fd % 256], '\n')[1]);
	else
		buffer[fd % 256] = ft_strdup("");
	free(l_buffer);
	return (*line[0] || buffer[fd % 256][0] || ret ? 1 : 0);
}
