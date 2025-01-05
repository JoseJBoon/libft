/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 15:41:04 by jboon         #+#    #+#                 */
/*   Updated: 2025/01/05 14:36:56 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>

# define HEX_LOWER	"0123456789abcdef"
# define HEX_UPPER	"0123456789ABCDEF"
# define DECIMAL	"0123456789"

typedef struct s_nbr		t_nbr;
typedef unsigned long int	t_ulint;
typedef void (convert) (char *dst, t_nbr *data);

typedef struct s_format
{
	int			flags;
	int			width;
	int			precis;
	union
	{
		bool	use_upper;
		bool	is_negative;
	};
}	t_format;

typedef struct s_nbr
{
	t_ulint	nbr;
	int		nbr_cnt;
	int		str_len;
	bool	is_minus;
	char	*base;
	char	*pre;
}	t_nbr;

typedef union u_printf_data
{
	t_ulint	u_lint;
	int		i;
	char	c;
	char	*str;
	void	*ptr;
}	t_printf_data;

typedef struct s_printf
{
	char	specifier;
	int		(*call)(t_printf_data p_data, t_format *f, char **dst);
}	t_printf;

enum	e_print_flag
{
	PREFIX = 0x01,
	ZERO_PAD = 0x02,
	LEFT_ALIGN = 0x04,
	BLANK_SIGN = 0x08,
	SHOW_SIGN = 0x10,
};

int			ft_printf(const char *s, ...);
int			ft_printf_char(t_printf_data p_data, t_format *f, char **dst);
int			ft_printf_str(t_printf_data p_data, t_format *f, char **dst);
int			ft_printf_ptr(t_printf_data p_data, t_format *f, char **dst);
int			ft_printf_hex(t_printf_data p_data, t_format *f, char **dst);
int			ft_printf_int(t_printf_data p_data, t_format *f, char **dst);
int			ft_printf_uint(t_printf_data p_data, t_format *f, char **dst);
void		ft_printf_size(t_nbr *d, t_format *f);

const char	*ft_parse_format(const char *s, t_format *f);
bool		ft_empty_str(char **dst, int str_len);
void		apply_format_uint(t_format *f);
void		apply_format_hex(const char c, t_format *f);
void		left_align_nbr(char *dst, t_format *f, t_nbr *d, convert conv);
void		right_align_nbr(char *dst, t_format *f, t_nbr *d, convert conv);

int			ft_count_digits(t_ulint nbr);
int			ft_count_pow2(t_ulint nbr, int pow);
#endif
