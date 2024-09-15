/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:31 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 15:36:32 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copy `src_len` length string from `src` to `dst`
void	*ft_memmove(void *dst, const void *src, size_t copy_len)
{
	unsigned char	*cdst;
	unsigned char	*csrc;
	size_t			i;

	if (dst == NULL && src == NULL && copy_len)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	if (cdst < csrc)
	{
		i = 0;
		while (i++ < copy_len)
			*cdst++ = *csrc++;
	}
	else
	{
		i = copy_len;
		while (i > 0)
		{
			cdst[i - 1] = csrc[i - 1];
			i--;
		}
	}
	return (dst);
}
