/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:37:17 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/26 15:18:31 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//calloc: Allocate and zero-initialize
// memory for an array.
//This function allocates memory
//  for an array of 'num' elements of 'size' bytes each,
//   and initializes all the bytes to zero (0).
//   Parameters:
//     num  : Number of elements to allocate.
//     size : Size of each element in bytes.
//   Return:
//     If successful, a pointer to the allocated memory is returned; otherwise,
// 	NULL is returned.
//   Note:
//     - The total amount of memory allocated is 'num * size' bytes.
// 	- Memory allocated by calloc must be released
//  using free when it is no longer needed.
//     - Unlike malloc,
// 	calloc guarantees that the allocated memory is initialized to zero.

void	*ft_calloc(size_t element_count, size_t element_size)
{
	size_t	total_size;
	void	*ptr;
	size_t	i;

	if (element_size > 0 && (SIZE_T_MAX / element_size) < element_count)
	{
		return (NULL);
	}
	total_size = element_count * element_size;
	ptr = malloc(total_size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < total_size)
	{
		*(((char *)ptr) + i) = 0;
		i++;
	}
	return (ptr);
}

// #include "libft.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*str;
// 	size_t	total_size;

// 	if (size > 0 && (UINT64_MAX / size) < count)
// 		return (NULL);
// 	total_size = count * size;
// 	str = malloc(total_size);
// 	if (!str)
// 		return (NULL);
// 	ft_bzero(str, total_size);
// 	return (str);
// }

// int	main(void)
// {
// 	int	*ptr;
// 	int	num_elements;

// 	num_elements = 5;

// 	//5 tane int boyutunda bellek tahsis et(ft_calloc ile)

// 	ptr = (int *)ft_calloc(num_elements, sizeof(int));

// 	//Bellek tahsinin basarili olup olmadigini kontrol et

// 	if (ptr == NULL)
// 	{
// 		printf("Bellek tahsisi basarisiz oldu. \n");
// 		return (1);
// 	}

// 	//Calisma zamaninda bellekte tahsis edilen degerleri yazdir
// 	for (int i = 0; i < num_elements; i++)
// 	{
// 		printf("%d\n", ptr[i]);
// 			//ft_calloc ile tahsis edilen bellek sifir degerleri ile doldurulur
// 	}

// 	// Bellegi serbet birak
// 	free(ptr);

// 	return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>

// void elmayi_ye(int *arkadasin_adresi)
// {
// 	*arkadasin_adresi = *arkadasin_adresi - 1;
// }
// void elmayi_yemeye_calis(int arkadas)
// {
// 	arkadas = arkadas - 1;
// }

// int main() {
// 	int arkadas = 42;

// 	// 42
// 	elmayi_yemeye_calis(arkadas);
// 	// 42
// 	printf("elma sayisi: %d\n", arkadas);

// 	elmayi_ye(&arkadas);
// 	// 41
// 	printf("elma sayisi: %d\n", arkadas);
// }

// void anlatim()
// {
// 	int int_variable;
// 	int *int_pointer;
// 	int *int_arr_pointer;
// 	int arr_size;

// 	int_variable = 42;
// 	int_pointer = &int_variable;

// 	arr_size = 5;
// 	int_arr_pointer = (int *) malloc(arr_size * sizeof(int));
// 	if (int_arr_pointer == NULL)
// 		return (NULL);

// }

// int main() {
//     int *ptr;
//     int num_elements = 100;

//     // 5 tane int boyutunda bellek tahsis et
//     ptr = (int *)calloc(num_elements, sizeof(int));

//     // Bellek tahsisinin başarılı olup olmadığını kontrol et
//     if (ptr == NULL) {
//         printf("Bellek tahsisi başarısız oldu.\n");
//         return (1);
//     }

//     // Çalışma zamanında bellekte tahsis edilen değerleri yazdır
//     for (int i = 0; i < num_elements; i++) {
//         printf("%d ", ptr[i]);
// calloc ile tahsis edilen bellek sıfır değerleri ile doldurulur
//     }

//     // Belleği serbest bırak
//     free(ptr);

//     return (0);
// }
