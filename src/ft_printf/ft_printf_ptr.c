/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ptr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 11:16:51 by jboon         #+#    #+#                 */
/*   Updated: 2025/01/05 13:40:21 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_printf.h"

/*
	Create and return a formatted hex string representation of the ptr address.
	@param ptr The original ptr that will be converted to hex.
	@param f The format to apply on the nbr.
	@param str_len Length of the formatted string.
	@param use_up Whether to use the lower or upper case version of hexadecimal.
*/
int	ft_printf_ptr(t_printf_data p_data, t_format *f, char **dst)
{
	if (p_data.ptr == NULL)
	{
		f->precis = -1;
		p_data.str = "(nil)";
		return (ft_printf_str(p_data, f, dst));
	}
	p_data.u_lint = (t_ulint)p_data.ptr;
	f->flags |= PREFIX;
	return (ft_printf_hex(p_data, f, dst));
}
