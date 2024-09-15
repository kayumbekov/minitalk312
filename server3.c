/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:25:15 by kbekov            #+#    #+#             */
/*   Updated: 2024/09/15 21:26:14 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

// Function that finalizes message reception, prints it, and frees memory
size_t	finalize_message(char *str, int count)
{
	str[count] = '\0';  // Null-terminate the received message
	ft_printf("%s\n", str);  // Print the message
	free(str);  // Free the allocated memory for the message
	return (0);  // Reset the count to 0 for the next message
}

// Function that assembles the message from bits received via signals
size_t	assemble_message_bits(int signal, char *str, size_t len)
{
	static int	current_bit = 0;  // Tracks the current bit position
	static int	current_byte = 0;  // Accumulates the bits to form a byte
	static int	byte_count = 0;  // Tracks the number of bytes received

	// Process incoming bits only if there's more message to receive
	if (len > 0)
	{
		if (current_bit < 8)  // Accumulate bits to form a byte
		{
			if (signal == SIGUSR1)
				current_byte |= (1 << current_bit);  // Set the current bit
			current_bit++;
		}
		if (current_bit == 8)  // Once a full byte is formed
		{
			str[byte_count] = (char)current_byte;  // Store the byte in the message
			byte_count++;
			current_bit = 0;  // Reset bit counter for the next byte
			current_byte = 0;  // Reset current byte
			len--;  // Decrease remaining length
		}
	}
	if (len == 0)
		byte_count = finalize_message(str, byte_count);  // Finalize message when complete
	return len;
}

// Function that handles incoming signals, processes message length, and assembles the message
void	handle_signal(int signal)
{
	static size_t	message_len = 0;  // Length of the message
	static size_t	bit_count = 0;  // Counts bits received for the length
	static char		*message_str = NULL;  // Pointer to the message string

	// After receiving the message length, allocate memory for the message
	if (bit_count == (sizeof(size_t) * 8))
	{
		message_str = (char *)malloc(sizeof(char) * message_len + 1);
		if (message_str == NULL)
			exit(EXIT_FAILURE);
		bit_count++;
	}
	// Receiving the length of the message bit by bit
	if (bit_count < (sizeof(size_t) * 8))
	{
		if (signal == SIGUSR1)
			message_len |= ((size_t)1 << bit_count);  // Set the bit for length
		bit_count++;
	}
	else
	{
		// After receiving the length, assemble the message bit by bit
		message_len = assemble_message_bits(signal, message_str, message_len);
		if (message_len == 0)
			bit_count = 0;  // Reset for the next message
	}
}

int main(void)
{
	ft_printf("%d\n", getpid());  // Print the server's PID for the client
	while(1)
	{
		// Setup signal handlers for ONE and ZERO (SIGUSR1 and SIGUSR2)
		signal(SIGUSR1, handle_signal);
		signal(SIGUSR2, handle_signal);
		pause();  // Wait for incoming signals
	}
	return(0);
}
