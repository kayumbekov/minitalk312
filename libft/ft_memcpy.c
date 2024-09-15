/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:26 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/21 05:31:27 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdst;
	unsigned char	*csrc;

	i = 0;
	if (dst == NULL && src == NULL && n)
		return (NULL);
	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (i < n)
	{
		*cdst = *csrc;
		cdst++;
		csrc++;
		i++;
	}
	return (dst);
}
