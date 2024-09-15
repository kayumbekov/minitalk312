/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:42:11 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 06:01:18 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

// int main()
// {
//     char *c = "Hell are you sure";

//     printf("lenght of strinc c is: %d\n", ft_strlen(c));
// }

// #include <stdlib.h>
// size_t ft_strlen(const char* str)
// {
//     int i;

//     i = 0;
//     while (str[i] != '\0')
//     {

//         i++;
//     }
//     return (i);
// }
// void baskafunc(char *str){
//     write(1, str, ft_strlen(str));
//     printf("%zu", ft_strlen(str));
// }

// strlen does not do a NULL check (NULL edge case), results in seg fault
// -> if (str == NULL) return (0)

//  int main (void)
//  {
//     baskafunc("kaka");
//     // char *str = "food";
//     // printf("%lu", ft_strlen(str));
//     // printf("\n");
//     // printf("%lu", strlen (str));
//     // printf("\n");
//     // // str = NULL;
//     // printf("%lu", ft_strlen(str));
//     // printf("\n");
//     // printf("%lu", strlen (str));
//     return (0);
//  }

// #include <stdio.h>

// int main() {
//     int num = 10;       // Declare an integer variable
//     int *ptr;
// Declare a pointer variable to store the address of an integer
//     ptr = &num;         /
// Store the address of 'num' in the pointer variable 'ptr'
//     printf("Value of num: %d\n", num);          // Output the value of 'num'
//     printf("Address of num: %p\n", (void*)&num);
// Output the address of 'num'
//     printf("Value of num using pointer: %d\n", *ptr);
// Output the value of 'num' using the pointer
//     return (0);
// }
