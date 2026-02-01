/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amary <amary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:48:03 by amary             #+#    #+#             */
/*   Updated: 2025/11/20 12:11:38 by amary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *s1, ...);
int	ft_putnbr(long nb);
int	ft_putnbr_dec(unsigned int nb);
int	ft_putnbr_hex(unsigned long int nb, int is_upper);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putpointeur(void *po);

#endif