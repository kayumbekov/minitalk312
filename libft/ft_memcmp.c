/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:41:19 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 02:57:13 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (*cs1 != *cs2)
		{
			return (*cs1 - *cs2);
		}
		cs1++;
		cs2++;
		n--;
	}
	return (0);
}
// int main()
// {
// 	// Karsilastirilacak iki dizgi
// 	char str1[] = "abcdef";
// 	char str2[] = "abcdEF";
// 	// Ilk 4 karakter karsilastirilir
// 	int result = ft_memcmp(str1, str2, 4);
// 	if(result == 0)
// 	{
// printf("Ilk 5 karakter aynidir.\n");
// 	} else if (result < 0)
// 	{
//printf("Ilk 5 karakterde %d, '%d' buyuktur '%d'.\n", result,
// (int *)str1[-result], (int *)str2[-result]);
//}else
//{
//printf("Ilk 5 karakterde %d, '%d' kucuktur '%d'.\n",
//result,
//(int *)str1[result], (int *)str2[result]);
//}
//return (0);
//}
//memcmp: İki bellek bloğunu karşılaştırır.
//Bu fonksiyon,
//'s1' ile işaret edilen bellek bloğunu 's2' ile işaret edilen
//bellek bloğuyla karşılaştırır. Karşılaştırma,
//ilk 'n' bayt boyunca yapılır.
//Parametreler:
//s1 : Karşılaştırılacak birinci bellek bloğunun işaretçisi.
//s2 : Karşılaştırılacak ikinci bellek bloğunun işaretçisi.
//n  : Karşılaştırılacak bayt sayısı.
//Dönüş:
//Eğer 's1', 's2'den küçükse, negatif bir değer döndürülür.
//Eğer 's1', 's2'ye eşitse, 0 döndürülür.
//   Eğer 's1', 's2'den büyükse, pozitif bir değer döndürülür.
// Notlar:
//   - Bu fonksiyon,
// bellek bloklarını karşılaştırmak için kullanılır.
//   - 'n' parametresi,
// karşılaştırılacak maksimum bayt sayısını belirtir.
