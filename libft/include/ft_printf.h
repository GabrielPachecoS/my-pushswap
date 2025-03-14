#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		p_format(va_list ap, const char format);
int		print_d_i(int n);
int		print_x_len(unsigned int n);
void	print_x_write(unsigned int n, char format);
int		print_x(unsigned int n, char format);
int		print_u(unsigned int n);
int		print_c(int c);
int		print_s(char *str);
int		print_p_len(uintptr_t ptr);
void	print_p_write(uintptr_t ptr);
int		print_p(void *pointer);
int		ft_unumlen(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_intlen(int n);
char	*ft_itoa(int n);
int		ft_islower(int c);

#endif
