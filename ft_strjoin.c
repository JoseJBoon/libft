/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboon <jboon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:01:54 by jboon             #+#    #+#             */
/*   Updated: 2024/10/11 18:06:00 by jboon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_1;
	size_t	len_2;

	if (s1 != NULL)
		len_1 = ft_strlen(s1);
	else
		len_1 = 0;
	if (s2 != NULL)
		len_2 = ft_strlen(s2);
	else
		len_2 = 0;
	dst = malloc((len_1 + len_2 + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, s1, len_1);
	ft_memcpy(dst + len_1, s2, len_2);
	*(dst + len_1 + len_2) = '\0';
	return (dst);
}

int	main(void)
{

}
