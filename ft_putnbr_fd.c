/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:57:26 by jboon             #+#    #+#             */
/*   Updated: 2024/10/14 11:53:49 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	const short	max_size = 11;
	char		nbr[11];
	short		i;
	int			sign;

	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	i = max_size;
	sign = get_sign(n);
	while (n != 0)
	{
		--i;
		nbr[i] = '0' + ((n % 10) * sign);
		n /= 10;
	}
	if (sign == -1)
	{
		--i;
		nbr[i] = '-';
	}
	write(fd, &nbr[i], max_size - i);
}
