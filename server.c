/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 23:41:13 by kbekov            #+#    #+#             */
/*   Updated: 2024/09/15 21:34:58 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

size_t	finalize_message(char *str, int count)
{
	str[count] = '\0';
	ft_printf("%s\n", str);
	free(str);
	return (0);
}

size_t	assemble_message_bits(int signal, char *str, size_t len)
{
	static int	current_bit;
	static int	current_byte;
	static int	byte_count;

	if (len > 0)
	{
		if (current_bit < 8)
		{
			if (signal == SIGUSR1)
				current_byte |= (1 << current_bit);
			current_bit++;
		}
		if (current_bit == 8)
		{
			str[byte_count] = (char)current_byte;
			byte_count++;
			current_bit = 0;
			current_byte = 0;
			len--;
		}
	}
	if (len == 0)
		byte_count = finalize_message(str, byte_count);
	return len;
}

void	handle_signal(int signal)
{
	static size_t	message_len;
	static size_t	bit_count;
	static char		*message_str;

	if (bit_count == (sizeof(size_t) * 8))
	{
		message_str = (char *)malloc(sizeof(char) * message_len + 1);
		if (message_str == NULL)
			exit(EXIT_FAILURE);
		bit_count++;
	}
	if (bit_count < (sizeof(size_t) * 8))
	{
		if (signal == SIGUSR1)
			message_len |= ((size_t)1 << bit_count);
		bit_count++;
	}
	else
	{
		message_len = assemble_message_bits(signal, message_str, message_len);
		if (message_len == 0)
			bit_count = 0;
	}
}

int main(void)
{
	ft_printf("%d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();
	}
	return(0);
}
