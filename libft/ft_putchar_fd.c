/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:50:14 by kbekov            #+#    #+#             */
/*   Updated: 2024/03/25 06:04:32 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//putchar_fd: Write a character to a file descriptor.
//This function writes the specified character 'c'
//to the given file descriptor 'fd'.
//Parameters:
//c : The character to be written.
//fd: The file descriptor where the character will be written.
//Return:
//None
//Note:
//This function uses the 'write' system call from the <unistd.h> header.

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
