/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lade-lim <lade-lim@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:23:22 by lade-lim          #+#    #+#             */
/*   Updated: 2022/07/25 21:20:52 by lade-lim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define HEX_BASE		"0123456789abcdef"
# define DECIMAL_BASE	"0123456789"

typedef enum e_boolean
{
	FALSE,
	TRUE,
}	t_boolean;

typedef struct s_flags
{
	t_boolean	plus;
	t_boolean	sharp;
	t_boolean	space;
}	t_flags;

typedef struct s_str
{
	int		len;
	char	*str;
	char	*temp;
}	t_str;

int		ft_printf(const char *format, ...);
int		print_unsigned_int(int number, t_flags *flags, char spcif, t_str s);
int		print_void_hex(void *point, t_flags *flags, char spcif, t_str s);
int		print_char(int character, t_flags *flags, char spcif, t_str s);
int		print_int(int number, t_flags *flags, char spcif, t_str s);
int		print_str(char *str, t_flags *flags, char spcif, t_str s);
int		print_hex(int nb, t_flags *flags, char spcif, t_str s);
int		print_percentage(int percent, t_str s);
/*
utils
*/
void	is_true_flags(const char **format, t_flags *flags);
void	put_flags(t_str *s, t_flags *flags, char spcif);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_uitoahex(unsigned int number);
char	*ft_uipoint_hex(size_t number);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_strtolupper(char *str);
char	*ft_uitoa(unsigned int n);
char	*ft_strtolower(char	*str);
int		ft_putstr_len(char *str);
int		ft_atoi(const char *str);
int		ft_putchar_len(t_str *s);
t_flags	init_flags(void);
t_str	init_tstr(void);
char	*ft_itoa(int n);

#endif