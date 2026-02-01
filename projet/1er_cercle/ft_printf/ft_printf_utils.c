/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:05:23 by amary             #+#    #+#             */
/*   Updated: 2025/11/20 12:59:11 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	count = 0;
	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i])
		count += write(fd, &s[i++], 1);
	return (count);
}

int	ft_putpointeur(void *po)
{
	unsigned long	adresse;
	int				count;

	count = 0;
	if (!po)
		return (write(1, "(nil)", 5));
	adresse = (unsigned long)po;
	count += write(1, "0x", 2);
	count += ft_putnbr_hex(adresse, 0);
	return (count);
}
