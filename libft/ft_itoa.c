/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:40:51 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 05:58:12 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int			len;
	long long	nb;

	len = 1;
	nb = n;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			len;
	long long	nb;

	nb = n;
	len = ft_itoa_len(n);
	num = malloc(len + 1);
	if (num == NULL)
		return (NULL);
	num[len] = '\0';
	if (nb < 0)
	{
		num[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		num[0] = '0';
	while (nb > 0)
	{
		num[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (num);
}
// int count_digits(int n) {
//     int digits = 0;
//     int temp_n = abs(n); // Geçici değişken, n'nin bir kopyasıdır
//     while (temp_n != 0) {
//         digits = digits + 1; // Basamak sayısını artır
//         temp_n = temp_n / 10; // Sayıyı 10'a böler ve son basamağı kaldırır
//     }
//     return (digits);
// }

// char *ft_itoa(int n) {
//     // Negatif sayı ise işareti ve pozitif yap
//     int negative = 0;
//     if (n < 0) {
// 			if (n == INT_MIN) // Eğer n INT_MIN ise, direk sonucu döndür
//             return (ft_st("-2147483648"));;
//         negative = 1;
//         n = -n;
//     }
// 	int digits = count_digits(n);
//     // Sayının basamak sayısını bul
//     int total_digits = digits + negative;

//
// ASCII karakterlerini tutmak için yeterli boyutta bir karakter dizisi oluştur
//     char *buffer = (char *)malloc((total_digits + 1) * sizeof(char)); //
// +1 for '\0'
//     if (buffer == NULL) {
//         return (NULL); // Bellek ayrılamadı
//     }

//     // Sayıyı sağdan sola dönüştür ve karakter dizisine yerleştir
//     char *ptr = buffer + total_digits;
// Pointer'i karakter dizisinin sonuna ayarla
//     *ptr = '\0'; // Son karakteri null-terminate et
//     while (n != 0) {
//         ptr = ptr - 1; // Pointer'i bir pozisyon sola kaydır
//         *ptr = n % 10 + '0';
//         n = n / 10; // Sayıyı 10'a böler ve son basamağı kaldırır
//     }

//     // Negatifse '-' karakterini başa ekle
//     if (negative) {
//         ptr = ptr - 1; // Pointer'i bir pozisyon sola kaydır
//         *ptr = '-';
//     }

//     return (buffer);
// }

// int main() {
//     int myInt = 12345;
//     char *ch = ft_itoa(myInt);
//     if (ch == NULL) {
//         printf("Memory allocation failed\n");
//         return (1); // Bellek ayrılamadı, hata durumunda sonlandır
//     }

//     printf("integer %d converted to ascii: %s\n", myInt, ch);

//     // Belleği serbest bırak
//     free(ch);

//     return (0);
// }

// char *ft_itoa(int n)
// {

// // i = 0;

// while(n >= 0 && n <= 9)
// {
// 	n = n + '0';
// 	return (n);
// }

// // }
// int main ()
// {
// 	int myInt = -9 ;
// 	int negative = 0;

// 	if(myInt < 0)
// 	{
// 		negative = 1;
// 		myInt = myInt * (-1);

// 	}

// 	if(negative == 0)
// 	{
// 	return (printf("%d int converted to ascii %c", myInt, myInt + '0'));

// 	}else
// 	{
// 		return (printf("%d int converted to ascii %c", myInt, (myInt + '0')));

// 	}

// }

// static int ft_itoa_length(int n)
// {
//     int length;

//     length = 0;
//     if (n == 0)
//         return (1);
//     if (n < 0)
//     {
//         length = 1;
//         if (n != -2147483648) // Special handling for -2147483648
//             n = -n;
//     }
//     while (n > 0)
//     {
//         length++;
//         n /= 10;
//     }
//     return (length);
// }

// char *ft_itoa(int n)
// {
//     char *string;
//     int nb;
//     int length;

//     length = ft_itoa_length(n);
//     string = (char *)malloc(sizeof(char) * (length + 1));
//     if (string == NULL)
//         return (NULL);
//     string[length] = '\0';
//     if (n == 0)
//         string[0] = '0';
//     else if (n == -2147483648) // Special handling for -2147483648
//     {
//         ft_memcpy(string, "-2147483648", 12); // Copy "-2147483648" to string
//         return (string);
//     }
//     else if (n < 0)
//     {
//         string[0] = '-';
//         nb = -n;
//     }
//     else
//         nb = n;
//     while (nb > 0)
//     {
//         string[--length] = (nb % 10) + '0';
//         nb /= 10;
//     }
//     return (string);
// }

// static int	ft_itoa_length(int n)
// {
// 	int	length;

// 	length = 0;
// 	if (n < 0)
// 	{
// 		length = 1;
// 		n = -n;
// 	}
// 	while (n > 0)
// 	{
// 		length++;
// 		n /= 10;
// 	}
// 	return (length);
// }

// char	*ft_itoa(int n)
// {
// 	char			*string;
// 	unsigned int	nb;
// 	unsigned int	length;

// 	length = ft_itoa_length(n);
// 	string = (char *)malloc(sizeof(char) * (length + 1));
// 	if (string == NULL)
// 		return (NULL);
// 	string[length] = '\0';
// 	if (nb < 0)
// 	{
// 		string[0] = '-';
// 		nb = -n;
// 	}
// 	else
// 		nb = n;
// 	if (nb == 0)
// 		string[0] = '0';
// 	while (nb != 0)
// 	{
// 		string[--length] = (nb % 10) + '0';
// 		nb /= 10;
// 	}
// 	return (string);
// }

// int	main(void)
// {
// 	int		string1;
// 	int		string2;
// 	int		string3;
// 	int		string4;
// 	int		string5;
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;
// 	char	*str4;
// 	char	*str5;

// 	string1 = 123;
// 	string2 = -456;
// 	string3 = 0;
// 	string4 = 987654321;
// 	string5 = -2147483648;
// 	str1 = ft_itoa(string1);
// 	str2 = ft_itoa(string2);
// 	str3 = ft_itoa(string3);
// 	str4 = ft_itoa(string4);
// 	str5 = ft_itoa(string5);
// 	if (str1 && str2 && str3 && str4 && str5)
// 	{
// 		printf("Integer: %d, String: %s\n", string1, str1);
// 		printf("Integer: %d, String: %s\n", string2, str2);
// 		printf("Integer: %d, String: %s\n", string3, str3);
// 		printf("Integer: %d, String: %s\n", string4, str4);
// 		printf("Integer: %d, String: %s\n", string5, str5);
// 	}
// 	else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     free(str1);
//     free(str2);
//     free(str3);
//     free(str4);
//     free(str5);
//     return (0);
// }
