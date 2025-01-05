/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_int.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 11:13:22 by jboon         #+#    #+#                 */
/*   Updated: 2025/01/05 13:49:00 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Create and return a formatted string representation of nbr as an integer.
	@param nbr The original nbr.
	@param f The format to apply on the nbr.
	@param str_len Length of the formatted string.
*/
int	ft_printf_int(t_printf_data p_data, t_format *f, char **dst)
{
	if (p_data.i < 0)
	{
		f->is_negative = true;
		p_data.u_lint = (t_ulint) ~ p_data.i + 1;
	}
	else
	{
		f->is_negative = false;
		p_data.u_lint = p_data.i;
	}
	return (ft_printf_uint(p_data, f, dst));
}
