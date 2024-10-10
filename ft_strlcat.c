/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:34:34 by jboon             #+#    #+#             */
/*   Updated: 2024/10/07 17:50:32 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (dst[len])
		len++;
	while (src[i] && (len + i) < (size - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	if (size > 0 && len < size)
		dst[len + i] = '\0';
	return (len + i);
}
