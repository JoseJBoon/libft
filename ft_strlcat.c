/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:34:34 by jboon             #+#    #+#             */
/*   Updated: 2024/10/11 16:39:45 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (dst != NULL)
	{
		while (dst[len])
			len++;
	}
	if (size > 0)
	{
		while (src[i] && (len + i) < (size - 1))
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
	}
	while (src[i])
		i++;
	if (len > size)
		len = size;
	return (len + i);
}
