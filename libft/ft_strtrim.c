/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:51:46 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 12:15:00 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;
	size_t	start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && in_set(s1[start], set))
		start++;
	len = ft_strlen(s1 + start);
	while (len > 0 && in_set(s1[start + len - 1], set))
		len--;
	trim = malloc(len + 1);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1 + start, len + 1);
	return (trim);
}

// int main(void)
// {
//     const char *s1 = "   Hello, world!   ";
//     const char *set = " ";

//     char *trimmed = ft_strtrim(s1, set);

//     if (trimmed)
//     {
//         printf("Original string: \"%s\"\n", s1);
//         printf("Trimmed string : \"%s\"\n", trimmed);
//         free(trimmed); // Remember to free the allocated memory
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     return (0);
// }
// This program uses ft_strtrim to remove leading and trailing characters
//  specified in the set string from the s1 string.
//   It then prints both the original and trimmed strings.
// Finally, it frees the memory allocated for the trimmed string.
