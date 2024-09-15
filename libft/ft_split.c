/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:50:46 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 15:27:53 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_word_len(char const *s, char delim, int current_pos)
{
	int	start;

	start = current_pos;
	while (s[current_pos] != '\0' && s[current_pos] != delim)
		current_pos++;
	return (current_pos - start);
}

char	**ft_splits(char const *s, char delim, int word_count, char **str_arr)
{
	int	word_nb;
	int	main_pos;
	int	word_len;

	word_nb = 0;
	main_pos = 0;
	while (word_nb < word_count)
	{
		while (s[main_pos] != '\0' && s[main_pos] == delim)
		{
			main_pos++;
		}
		word_len = ft_word_len(s, delim, main_pos);
		str_arr[word_nb] = ft_substr(s, main_pos, word_len);
		if (!str_arr[word_nb])
		{
			free_str_arr(str_arr);
			return (0);
		}
		main_pos = main_pos + word_len;
		word_nb++;
	}
	str_arr[word_nb] = NULL;
	return (str_arr);
}

static int	ft_word_count(char const *s, char delim)
{
	int	i;
	int	word_count;

	if (s == NULL)
		return (0);
	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == delim)
			i++;
		else
		{
			word_count++;
			while (s[i] != '\0' && s[i] != delim)
				i++;
		}
	}
	return (word_count);
}

char	**ft_split(char const *s, char delim)
{
	int		word_count;
	char	**strings;

	if (!s)
		return (0);
	word_count = ft_word_count(s, delim);
	strings = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!strings)
		return (0);
	return (ft_splits(s, delim, word_count, strings));
}

// int main(void)
// {
//     char const *s = "Hello,world,this,is,a,test";
//     char delim = ',';

//     char **result = ft_split(s, delim);

//     if (result)
//     {
//         printf("Original string: \"%s\"\n", s);
//         printf("Split result:\n");
//         for (int i = 0; result[i] != NULL; i++)
//         {
//             printf("[%d]: \"%s\"\n", i, result[i]);
//             free(result[i]); // Free each individual string
//         }
//         free(result); // Free the array itself
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }

//     return (0);
// }
