/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:42:28 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 12:14:45 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*result;
	const unsigned char	*us;
	unsigned char		uc;

	us = (unsigned char *)s;
	uc = (unsigned char)c;
	result = NULL;
	if (ft_strlen(s) == 0 && c == 0)
		return ((char *)s);
	if (uc == '\0')
		return ((char *)s + ft_strlen(s));
	while (*us != '\0')
	{
		if (*us == uc)
			result = us;
		us++;
	}
	return ((char *)result);
}

// int main(void)
// {
//     const char *str = "Hello, world!";
//     int c = 'o';

//     char *result = ft_strrchr(str, c);

//     if (result)
//         printf("Last occurrence of '%c' in \"%s\" is at position: %ld\n", c,
// str, result - str);
//     else
//         printf("'%c' not found in \"%s\"\n", c, str);

//     return (0);
// }
// int main() {
//    const char *str = "Hello, Wrld!";
//    int character = 'o';
//    //using ft_strrchr to find the last occurence of 'o' in the string
//    char *last_occurrence = ft_strrchr(str, character);
//       if(last_occurrence != NULL)
//       {
//printf("Last occurence of '%c' in \"%s\" is at position:
// %ld\n", character, str, last_occurrence - str);
//       }else {
//          printf("'%c'not found \"%s\"\n", character, str);
//       }
//    return (0);
// }
// int main()
// {
//     char* s = "kofla";
//     int k = 'l';
//     printf("integer s[0] = %i\n", s[0]);
//     printf("character s[0] = %c\n", s[0]);
//     printf("the first occurence of f is: %s ", ft_strrchr(s, k));
//     // printf("the first occurence of f is: %s\n", strrchr(s, k));
//     // printf("the first occurence of f is: %p\n", strrchr(s, k));
// }
// int main(){
//     char a = 'A';
//     printf("%c",a);
// }
// #include <stdio.h>
// int main() {
//     int num = 10;       // Declare an integer variable
//     int* ptr;
// Declare a pointer variable to store the address of an integer
//     ptr = &num;
// Store the address of 'num' in the pointer variable 'ptr'
//     printf("Value of num: %d\n", num);          // Output the value of 'num'
//     printf("Address of num: %p\n", (void*)&num); //
//Output the address of 'num'
//     printf("Value of num using pointer: %d\n", *ptr);
// Output the value of 'num' using the pointer
//     return (0);
// }
// ft_strrchr(const char *s, int c)
// {
// int i;
// int *a;
// int *b;
// i = 0;
// *i
// }
// #include <stdio.h>
// // Pass by value
// void swap_pbv(int a, int b) {
//     int temp = a;
//     a = b;
//     b = temp;

//     printf("When swapping: a = %d, b = %d\n", a, b);
// }

// // Pass by reference
// void swap(int* a,   b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;

//     printf("When swapping: a = %d, b = %d\n", *a, *b);
// }

// int main() {
//     int x = 5, y = 10;

//     printf("Before swapping: x = %d, y = %d\n", x, y);

//     swap_pbv(x, y);

//     printf("After 1 swapping: x = %d, y = %d\n", x, y);

//     swap(&x, &y);

//     printf("After 2 swapping: x = %d, y = %d\n", x, y);

//     return (0);
// }
