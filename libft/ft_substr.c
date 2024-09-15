/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:51:53 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 12:15:37 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen || len == 0)
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	slen = slen - start;
	if (slen < len)
		len = slen;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

// int main(void)
// {
//     const char *s = "Hello, world!";
//     unsigned int start = 7;
//     size_t len = 5;
//     char *substring = ft_substr(s, start, len);
//     if (substring)
//     {
//         printf("Original string: \"%s\"\n", s);
//         printf("Substring      : \"%s\"\n", substring);
//         free(substring); // Remember to free the allocated memory
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return (0);
// }
// This program uses ft_substr to extract a
// substring from the original string s,
// starting from index start and with a length of len.
// It then prints both the original string and
// the extracted substring.
// Finally, it frees the memory allocated for the substring.
