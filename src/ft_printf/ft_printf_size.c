/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_size.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 16:52:56 by jboon         #+#    #+#                 */
/*   Updated: 2025/01/05 11:54:32 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
	Calculates the maximum size needed to store the formatted string.
*/
void	ft_printf_size(t_nbr *d, t_format *f)
{
	int	ex;

	if (d->nbr == 0 && f->precis == 0 && f->width == 0)
	{
		d->str_len = 0;
		return ;
	}
	if ((f->flags & PREFIX) != 0 && d->nbr != 0)
		ex = 2;
	else
		ex = 0;
	if (f->is_negative || (f->flags & (SHOW_SIGN | BLANK_SIGN)) != 0)
		++ex;
	d->str_len = ft_max(ft_max(d->nbr_cnt + ex, f->width), f->precis + ex);
}
