/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:25:31 by kbekov            #+#    #+#             */
/*   Updated: 2024/09/15 21:25:33 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

// Function that sends the length of the message to the server
void	send_message_length(int pid, size_t len)
{
	size_t	bit = 0;

	while (bit < (sizeof(size_t) * 8))  // Send each bit of the message length
	{
		if ((len & ((size_t)1 << bit)) != 0)
			kill(pid, SIGUSR1);  // Send a '1' bit
		else
			kill(pid, SIGUSR2);  // Send a '0' bit
		usleep(150);  // Small delay to ensure the server processes each signal
		bit++;
	}
}

// Function that sends the actual message to the server bit by bit
void	send_message_bits(int pid, char *str)
{
	int		current_bit = 0;
	size_t	byte_index = 0;
	size_t	message_len = ft_strlen(str);  // Get the length of the message

	send_message_length(pid, message_len);  // Send the message length first

	while (byte_index < message_len)  // Send each byte of the message
	{
		while (current_bit < 8)  // Send each bit of the current byte
		{
			if ((str[byte_index] & (1 << current_bit)) != 0)
				kill(pid, SIGUSR1);  // Send a '1' bit
			else
				kill(pid, SIGUSR2);  // Send a '0' bit
			usleep(150);  // Delay to ensure the server processes each bit
			current_bit++;
		}
		byte_index++;  // Move to the next byte
		current_bit = 0;  // Reset bit counter for the next byte
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
		pid = ft_atoi(argv[1]);  // Get the server's PID from the arguments
		send_message_bits(pid, argv[2]);  // Send the message to the server
	}
	else
	{
		ft_printf("Input must be \"./client <pid> <message>\n");  // Error message
		return (1);
	}
	return (0);
}
