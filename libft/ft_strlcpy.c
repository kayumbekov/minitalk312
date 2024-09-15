/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:42:02 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 20:05:03 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

// {
// 	size_t	src_len;

// 	src_len = ft_strlen(src);
// 	if(src_len + 1< dstsize)
// 		ft_memcpy(dst, src, src_len + 1);
// 	else if(dstsize)
// 	{
// 		ft_memcpy(dst, src, dstsize - 1);
// 		dst[dstsize - 1] = '\0';
// 	}
// 	return (src_len);
// }
