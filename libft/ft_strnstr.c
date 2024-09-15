/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:42:23 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 12:13:58 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		length;
	char	*large;
	char	*small;

	if (*little == '\0')
		return ((char *)big);
	large = (char *)big;
	small = (char *)little;
	i = 0;
	length = ft_strlen(small);
	while (large[i] != '\0' && (i + length) <= len)
	{
		if (ft_strncmp((large + i), small, length) == 0)
		{
			return (large + i);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     const char *big = "Hello, world! This is a test string.";
//     const char *little = "world";
//     size_t len = ft_strlen(big);

//     char *result = ft_strnstr(big, little, len);

//     if (result != NULL)
//     {
//         printf("Substring \"%s\" found at position %ld in \"%s\"\n", little,
// (result - big), big);
//     }
//     else
//     {
//         printf("Substring \"%s\" not found in \"%s\"\n", little, big);
//     }

//     return (0);
// }
