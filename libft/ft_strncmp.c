/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:42:18 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 06:57:02 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (i < n)
	{
		if (*c1 != *c2)
		{
			return (*c1 - *c2);
		}
		if (*c1 == '\0' || *c2 == '\0')
		{
			return (0);
		}
		i++;
		c1++;
		c2++;
	}
	return (0);
}

// int main ()
// {
//     char *str1 = "hdfsfs";
//     char *str2 = "lekss";
//     int m = 4;
//     printf("compared first string to second string %d \n", ft_strncmp(str1,
// str2, m));
// }
