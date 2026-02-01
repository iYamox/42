/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:05:23 by amary             #+#    #+#             */
/*   Updated: 2025/11/20 12:48:27 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	if (c == 'p')
		return (ft_putpointeur(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_dec(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(const char *s1, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!s1)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, s1);
	while (s1[i])
	{
		if (s1[i] == '%')
		{
			count += ft_format(s1[i + 1], args);
			i++;
		}
		else
			count += ft_putchar_fd(s1[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
// 	int prout = 0;

// 	int o = ft_printf("Hello la team %p\n", &prout);
// 	int n = printf("Hello la team %p\n", &prout);

// 	printf("le mien renvoie %d\n", o);
// 	printf("le vrai renvoie %d\n", n);
// } 