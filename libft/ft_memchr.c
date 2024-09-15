/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:40:54 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 12:14:28 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//memchr: Bellek bloğu içinde bir baytı bulur.
//Bu fonksiyon, 's' ile işaret edilen bellek bloğunun ilk 'n' baytı içinde
//'c' baytının ilk oluşumunu arar.
//Parametreler:
//s : Arama yapılacak bellek bloğunun işaretçisi.
//c : Aranacak baytın değeri.
//n : Arama yapılacak bayt sayısı.
//Dönüş:
//Eğer bayt bulunursa, ilk oluşumun işaretçisi döndürülür;
//aksi halde, NULL döndürülür.
//Notlar:
//- Bu fonksiyon,bir bellek bloğu içinde
// belirli bir baytı aramak için kullanılabilir.
//- 'n' parametresi, arama yapılacak
// maksimum bayt sayısını belirtir.

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	size_t			i;

	cs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cs[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
// int main()
// {
// 	char str[] = "Merhaba, dunyalilar!";

// 	// Arancack karakter
// 	char ch = 'd';

// 	//'str'  icinde 'ch' karakterini Arancack
// 	void *result = memchr(str, ch, strlen(str));

// 	if(result != NULL)
// 	// Karakter bulundu
// 	{
// 		printf("'%c' karakteri '%s' icerisinde bulundu.\n", ch, str);

// 		// Bulunan karakterin indeksi hesaplanir
// 		int index = (char *)result - str;
// 		printf("'%c' karakterini indekisi: %d\n", ch, index);
// 	} else {
// 		//Karakter bulunmadi
// 		printf("'%c' karakteri '%s' icerisinde bulunamadi. \n", ch, str);
// 	}
// 	return (0);
// }
