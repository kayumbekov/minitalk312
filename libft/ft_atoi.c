/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:27:51 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/29 02:03:35 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//The atoi() function converts the initial portion of the string pointed to by
// str to int representation.

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == ' ' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// int main ()
// {
//     char myStr[] = "  -1213546 8";

//     int num = (ft_atoi(myStr));

//     printf("the ingeter value is: %d\n", num );

//     return (0);
// }
