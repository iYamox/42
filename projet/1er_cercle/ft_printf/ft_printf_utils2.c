/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:05:23 by amary             #+#    #+#             */
/*   Updated: 2025/11/20 13:05:31 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long nb)
{
	int		count;

	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar_fd((nb % 10) + '0', 1);
	return (count);
}

int	ft_putnbr_dec(unsigned int nb)
{
	int		count;

	count = 0;
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	count += ft_putchar_fd((nb % 10) + '0', 1);
	return (count);
}

int	ft_putnbr_hex(unsigned long int nb, int is_upper)
{
	char	*base;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (is_upper == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 16)
	{
		i = nb % 16;
		count += ft_putchar_fd(base[i], 1);
	}
	if (nb >= 16)
	{
		count += ft_putnbr_hex((nb / 16), is_upper);
		count += ft_putnbr_hex((nb % 16), is_upper);
	}
	return (count);
}
