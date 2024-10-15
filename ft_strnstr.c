/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:09:16 by jboon             #+#    #+#             */
/*   Updated: 2024/10/15 11:31:03 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	count;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	count = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[count])
			++count;
		else
		{
			i -= count;
			count = 0;
		}
		if (needle[count] == '\0')
			return ((char *)(haystack + (i - (count - 1))));
		++i;
	}
	return (NULL);
}
