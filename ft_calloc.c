/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:40:28 by jboon             #+#    #+#             */
/*   Updated: 2024/10/10 12:44:55 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

static int	is_int_overflow(size_t a, size_t b)
{
	if (b > 0 && a > ULONG_MAX / b)
		return (1);
	return (0);
}

void	*ft_calloc(size_t elements, size_t size)
{
	if (is_int_overflow(elements, size))
		return (NULL);
	return (malloc(elements * size));
}
