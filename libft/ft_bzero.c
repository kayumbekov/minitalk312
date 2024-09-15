/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:32:40 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 03:35:51 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//bzero: Zero out a block of memory.*
//This function sets the first 'n'
//bytes of the memory block pointed to by 's' to zero (0).
// Parameters:
// s : Pointer to the memory block to be zeroed out.
// n : Number of bytes to zero out.
// Return:
// None
// Note:
// This function is equivalent to memset(s, 0, n).
// It's commonly used to clear memory buffers before use.

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char buffer[10] = "Hello";
// 	printf("Before ft_bzero: %s\n", buffer);
// 	ft_bzero(buffer, sizeof(buffer));
// 	printf("after bzero: %s\n", buffer);
// 	return (0);
// }
