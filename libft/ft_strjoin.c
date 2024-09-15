/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:50:59 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 07:16:28 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;
	char	*ptr;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1 = len1 + 1;
	while (s2[len2])
		len2 = len2 + 1;
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ptr = result;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (result);
}

// while (*s1)
// 	{
// 		*ptr = *s1;
// 		ptr = ptr + 1;
// 		s1 = s1 + 1;
// 	}
// 	while (*s2)
// 	{
// 		*ptr = *s2;
// 		ptr = ptr + 1;
// 		s2 = s2 + 1;
// 	}

// char	*join;
// size_t	i;
// size_t	j;
// join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// if (join == NULL)
// 	return (NULL);
// i = 0;
// j = 0;
// while (s1[j])
// 	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// if (join == NULL)
// 	return (NULL);
// i = 0;
// j = 0;
// while (s2[j])
// 	join[i++] = s2[j++];
// join[i] = '\0';
// return (join);
