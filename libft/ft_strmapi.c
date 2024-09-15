/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:51:38 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 06:52:39 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*cpy;

	i = 0;
	if (s == NULL || (*f) == NULL)
		return (NULL);
	cpy = malloc(ft_strlen(s) + 1);
	if (cpy == NULL)
		return (NULL);
	while (s[i])
	{
		cpy[i] = (*f)(i, s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

// char map_func(unsigned int index, char c)
// {
//     if (c >= 'a' && c <= 'z')
//         return (c - 32); // Convert lowercase to uppercase
//     return (c); // Leave other characters unchanged
// }

// int main(void)
// {
//     char input[] = "Hello, world!";

//     // Apply the mapping function to each character of the input string
//     char *result = ft_strmapi(input, &map_func);

//     if (result)
//     {
//         printf("Original string: %s\n", input);
//         printf("Mapped string  : %s\n", result);
//         free(result); // Free the memory allocated by ft_strmapi
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     return (0);
// }

// Comman to run: cc ft_strlen.c ft_strmapi.c -o program_name
