/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:50:28 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 06:00:37 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		div;
	char	c;

	div = 1;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	while (n / div > 9)
		div = div * 10;
	while (div > 0)
	{
		c = (n / div) + '0';
		n = n - ((n / div) * div);
		ft_putchar_fd(c, fd);
		div = div / 10;
	}
}

// #include "libft.h"

// int main(void)
// {
//     int n1 = 123;
//     int n2 = -456;
//     int n3 = 0;
//     int n4 = 987654321;
//     int n5 = -2147483648;

//     // Printing integers using ft_putnbr_fd
//     ft_putnbr_fd(n1, 1); // Output: 123
//     // ft_putchar_fd('\n', 1);
//     ft_putnbr_fd(n2, 1); // Output: -456
//     // ft_putchar_fd('\n', 1);
//     ft_putnbr_fd(n3, 1); // Output: 0
//     // ft_putchar_fd('\n', 1);
//     ft_putnbr_fd(n4, 1); // Output: 987654321
//     // ft_putchar_fd('\n', 1);
//     ft_putnbr_fd(n5, 1); // Output: -2147483648
//     // ft_putchar_fd('\n', 1);

//     return (0);
// }
