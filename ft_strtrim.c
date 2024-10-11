/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:11:45 by jboon             #+#    #+#             */
/*   Updated: 2024/10/11 18:52:49 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	is_seperator(char c, char const *set)
{
	while (*set && *set != c)
		set++;
	return (*set != '\0');
}

static char	*create_str(size_t size)
{
	char	*s;

	s = malloc(size * sizeof(char));
	if (s == NULL)
		return (NULL);
	*s = '\0';
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	const char	*start;
	char		*dst;

	if (s1 == NULL || *s1 == '\0')
		return (create_str(1));
	while (*s1 && is_seperator(*s1, set))
		s1++;
	start = s1;
	while (*s1)
		s1++;
	while (is_seperator(*s1, set) || *s1 == '\0')
		s1--;
	if (s1 > start)
		len = (s1 + 1) - start;
	else
		len = 0;
	dst = create_str(len + 1);
	if (dst == NULL)
		return (NULL);
	dst = ft_memcpy(dst, start, len);
	dst[len] = '\0';
	return (dst);
}
