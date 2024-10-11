/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:50:47 by jboon             #+#    #+#             */
/*   Updated: 2024/10/11 18:57:23 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static size_t	count_digits(int n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

#include <stdio.h>

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
		len += 1;
	}
	nbr = malloc((len + 1) * sizeof(char));
	if (nbr == NULL)
		return (NULL);
	nbr[len] = '\0';
	if (direction == -1)
		nbr[0] = '-';
	if (n == 0)
		nbr[len - 1] = '0';
	while (n != 0)
	{
		len--;
		nbr[len] = '0' + (n % 10) * direction;
		n /= 10;
	}
	return (nbr);
}
