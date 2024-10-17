/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:50:47 by jboon             #+#    #+#             */
/*   Updated: 2024/10/17 11:34:53 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	count_digits(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static void	fill_str_nbr(int n, size_t len, char *nbr)
{
	int	sign;

	if (n < 0)
	{
		sign = -1;
		nbr[0] = '-';
	}
	else
		sign = 1;
	if (n == 0)
		nbr[len - 1] = '0';
	while (n != 0)
	{
		--len;
		nbr[len] = '0' + (n % 10) * sign;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*nbr;
	int		direction;

	direction = 1;
	len = count_digits(n);
	if (n < 0)
	{
		direction = -1;
		++len;
	}
	nbr = malloc((len + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[len] = '\0';
	fill_str_nbr(n, len, nbr);
	return (nbr);
}
