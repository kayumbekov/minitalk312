/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbekov <kbekov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 05:06:00 by kbekov            #+#    #+#             */
/*   Updated: 2024/09/14 23:39:48 by kbekov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long nbr, int base, char *format)
{
	char				nbr_list[100];
	int					i;
	int					len;
	unsigned long long	unbr;

	i = 0;
	len = 0;
	if (nbr == 0)
		return (write(1, "0", 1));
	if (nbr < 0 && base == 10)
	{
		len += write(1, "-", 1);
		unbr = (unsigned long long)(-nbr);
	}
	else
		unbr = (unsigned long long)nbr;
	while (unbr)
	{
		nbr_list[i++] = format[unbr % base];
		unbr = unbr / base;
	}
	while (i--)
		len += write(1, &(nbr_list[i]), 1);
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					len;

	addr = (unsigned long long)ptr;
	len = ft_putstr("0x");
	len += ft_putnbr(addr, 16, "0123456789abcdef");
	return (len);
}

int	ft_sformat_call(va_list args, char format)
{
	int		len = 0;
	char	c;

	if (format == 'c')
	{
		c = va_arg(args, int);
		len = write(1, &c, 1);
	}
	else if (format == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (format == 'u')
		len = ft_putnbr(va_arg(args, unsigned int), 10, "0123456789");
	else if (format == 'd' || format == 'i')
		len = ft_putnbr(va_arg(args, int), 10, "0123456789");
	else if (format == 'p')
		len = ft_putptr(va_arg(args, void *));
	else if (format == 'x')
		len = ft_putnbr(va_arg(args, unsigned int), 16, "0123456789abcdef");
	else if (format == 'X')
		len = ft_putnbr(va_arg(args, unsigned int), 16, "0123456789ABCDEF");
	else if (format == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_sformat_call(args, format[++i]);
		else
			len += write(1, &(format[i]), 1);
		i++;
	}
	va_end(args);
	return (len);
}
