/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:48:57 by adaly             #+#    #+#             */
/*   Updated: 2017/05/16 08:23:35 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_printf_conv
{
	int						length;
	int						precision;
	int						width;
	int						capitalized;
	char					type;
	char					import_type;
	int						base;
	int						parameter;
	int						*flags;
	char					*string;
}							t_pfconv;

t_pfconv	*ft_new_pfconv(void);
t_pfconv	*ft_conversion_parsing(char **str);
char		*ft_parse_parameter(char *str, t_pfconv *new);
char		*ft_parse_flags(char *str, t_pfconv *new);
char		*ft_parse_width(char *str, t_pfconv *new);
char		*ft_parse_precision(char *str, t_pfconv *new);
char		*ft_parse_length(char *str, t_pfconv *new, char **options);
char		*ft_parse_type(char *str, t_pfconv *new, char **types);
char		**ft_build_types(void);
char		**ft_build_lengths(void);
void		ft_eval_unum(t_pfconv *current, unsigned long long num);
void		ft_eval_num(t_pfconv *current, long long num);
void		ft_eval_float(t_pfconv *current, long double num);
void		ft_eval_str(t_pfconv *current, char *str);
char		*ft_float_standard(t_pfconv *current, long double num, int base);
char		*ft_float_normal(t_pfconv *current, long double num, int base);
char		**ft_float_build_invalids(int capitalized);
char		*ft_itoa_float(long double num, int base);
void		ft_import_type(t_pfconv *current);
t_pfconv	**ft_parse_for_conversions(char *str);
void		ft_printf_int(char *str, t_pfconv *current, va_list args);
void		ft_printf_double(char *str, t_pfconv *current, va_list args);
void		ft_printf_other(char *str, t_pfconv *current, va_list args);

#endif