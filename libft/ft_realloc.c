/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhote <alhote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 12:59:40 by alhote            #+#    #+#             */
/*   Updated: 2016/02/18 13:00:08 by alhote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_realloc(void *ptr, size_t size)
{
	void			*dup;

	dup = ft_memalloc(size);
	if (ptr)
	{
		if (dup)
			ft_memcpy(dup, ptr, size);
		ft_memdel(&ptr);
	}
	return (dup);
}
