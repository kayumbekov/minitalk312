/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:58:51 by kbekov            #+#    #+#             */
/*   Updated: 2024/09/15 21:13:28 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	send_message_length(int pid, size_t len)
{
	size_t	bit;

	bit = 0;
	while (bit < (sizeof(size_t) * 8))
	{
		if ((len & ((size_t) 1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit++;
	}
}

void	send_message_bits(int pid, char *str)
{
	int		current_bit;
	size_t	byte_index;
	size_t	message_len;


	current_bit = 0;
	byte_index = 0;
	message_len = ft_strlen(str);

	send_message_length(pid, message_len);

	while (byte_index < message_len)
	{
		while (current_bit < 8)
		{
			if ((str[byte_index] & (1 << current_bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			current_bit++;
		}
		byte_index++;
		current_bit = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		if (ft_strlen(argv[2]) < 1)
		{
			ft_printf("Empty string\n");
			return (1);
		}
		pid = ft_atoi(argv[1]);
		send_message_bits(pid, argv[2]);
	}
	else
	{
		ft_printf("Input must be \"./client <pid> <message>\n");
		return (1);
	}
	return (0);
}
