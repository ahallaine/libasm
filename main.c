/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:03:01 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/04 19:56:45 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(char *);
char	*ft_strcpy(char *, const char *);
int		ft_strcmp(const char *, const char *);
ssize_t	ft_write(int, const void *, size_t);
ssize_t	ft_read(int, void *, size_t);
char	*ft_strdup(const char *);

void	ft_putchar(char c)
{
	ft_write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	ft_write(1, str, ft_strlen(str));
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n = -147483648;
		}
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int		main(void)
{
	char		*str;
	char		dest[256] = {0};
	int			fd;

	str = "Hello World!";
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');
	ft_putstr(ft_strcpy(dest, (const char *)str));
	ft_putchar('\n');
	ft_putnbr(ft_strcmp("aa", "ac"));
	ft_putchar('\n');
	ft_putnbr(ft_write(1, str, ft_strlen(str)));
	ft_putchar('\n');
	if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
		return (1);
	ft_putnbr(ft_read(fd, dest, 10));
	close(fd);
	ft_putstr(dest);
	ft_putchar('\n');
	str = ft_strdup("salut :D");
	ft_putstr(str);
	ft_putchar('\n');
	free(str);
	return (0);
}
