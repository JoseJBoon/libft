/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 10:07:13 by jboon         #+#    #+#                 */
/*   Updated: 2025/01/05 14:38:43 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Create and return a formatted string based on c.
	@param c The original character.
	@param f The format to apply on c.
	@param str_len Length of the formatted string.
*/
int	ft_printf_char(t_printf_data p_data, t_format *f, char **dst)
{
	int		len;

	if (f->width > 1)
		len = f->width;
	else
		len = 1;
	if (ft_empty_str(dst, len) == false)
		return (-1);
	if ((f->flags & LEFT_ALIGN) != 0)
		**dst = p_data.c;
	else
		*(*dst + (len - 1)) = p_data.c;
	return (len);
}
