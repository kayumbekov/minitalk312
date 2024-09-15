/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:57 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 15:22:31 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	offset;

	s_len = (unsigned int)ft_strlen(src);
	if (dstsize == 0 && dst == NULL)
		return (s_len);
	d_len = (unsigned int)ft_strlen(dst);
	offset = d_len;
	if (dstsize <= d_len)
		return (dstsize + s_len);
	while (*src && offset < dstsize - 1)
	{
		dst[offset] = *src;
		src++;
		offset++;
	}
	if (offset < dstsize)
		dst[offset] = '\0';
	return ((unsigned int)(d_len + s_len));
}

// int	main(void)
// {
// 	int	x;
// 	int	*ptr;

// 	x = 10;
// 	ptr = &x;
// 	printf("Address of ptr variable: %p\n", (void *)&ptr);
// 	printf("Value of ptr: %p\n", (void *)ptr);
// 	printf("Address of x: %p\n", (void *)&x);
// 	return (0);
// }
