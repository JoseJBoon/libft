/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_helper.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/28 11:20:47 by jboon         #+#    #+#                 */
/*   Updated: 2025/01/05 13:36:37 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/*
	Zero pad the right align string.
	@return Pointer of dst where the prefix/sign can be added.
*/
static char	*apply_zero_pad(char *dst, char *start, t_format *f, t_nbr *d)
{
	int	amount;

	if ((f->flags & ZERO_PAD) != 0 && f->precis == -1 && f->width > d->nbr_cnt)
	{
		if ((f->flags & PREFIX) != 0 && d->nbr != 0)
			start += ft_strlen(d->pre);
		ft_memset(start, '0', dst - start);
		return (start);
	}
	else if (f->precis > d->nbr_cnt)
	{
		amount = f->precis - d->nbr_cnt;
		ft_memset(dst - amount, '0', amount);
		return (dst - amount);
	}
	return (dst);
}

/*
	Helper function for dealing with uint printing.
*/
void	apply_format_uint(t_format *f)
{
	f->flags &= ~(BLANK_SIGN | SHOW_SIGN);
}

/*
	Helper function for dealing with hex printing.
*/
void	apply_format_hex(const char c, t_format *f)
{
	f->flags &= ~(BLANK_SIGN | SHOW_SIGN);
	f->use_upper = (c == 'X');
}

/*
	Apply left align on t_nbr into dst.
	@param dst The buffer to insert t_nbr into.
	@param f The format to apply on dst.
	@param d Container holding the data for dst.
	@param conv function for inserting the nbr into dst in the desired base
	system.
*/
void	left_align_nbr(char *dst, t_format *f, t_nbr *data, convert conv)
{
	if (f->precis == 0 && data->nbr == 0)
		return ;
	if ((f->flags & (SHOW_SIGN | BLANK_SIGN)) != 0 || data->is_minus)
	{
		if (data->is_minus)
			*dst = '-';
		else if ((f->flags & SHOW_SIGN) != 0)
			*dst = '+';
		++dst;
	}
	if ((f->flags & PREFIX) != 0 && data->nbr != 0)
	{
		ft_memcpy(dst, data->pre, ft_strlen(data->pre));
		dst += ft_strlen(data->pre);
	}
	if (f->precis > data->nbr_cnt)
	{
		ft_memset(dst, '0', (f->precis - data->nbr_cnt));
		dst += (f->precis - data->nbr_cnt);
	}
	conv(dst, data);
}

/*
	Apply right align on t_nbr into dst.
	@param dst The buffer to insert t_nbr into.
	@param f The format to apply on dst.
	@param d Container holding the data for dst.
	@param conv function for inserting the nbr into dst in the desired base
	system.
*/
void	right_align_nbr(char *dst, t_format *f, t_nbr *d, convert conv)
{
	char	*start;

	if (f->precis == 0 && d->nbr == 0)
		return ;
	start = dst;
	dst += (d->str_len - d->nbr_cnt);
	if ((f->flags & (SHOW_SIGN | BLANK_SIGN)) != 0 || d->is_minus)
		++start;
	start = apply_zero_pad(dst, start, f, d);
	if (d->is_minus)
		*(start - 1) = '-';
	else if ((f->flags & SHOW_SIGN) != 0)
		*(start - 1) = '+';
	if ((f->flags & PREFIX) != 0 && d->nbr != 0)
		ft_memcpy(start - ft_strlen(d->pre), d->pre, ft_strlen(d->pre));
	conv(dst, d);
}
