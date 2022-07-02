#include "ft_printf.h"

// ft_strlen

size_t	ft_strlen(const char *str)
{
	size_t		counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter += 1;
	}
	return (counter);
}

// ft_int_length

int	ft_int_length(int x)
{
	int		index;

	index = 0;
	if (x < 0)
		index++;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		index++;
	}
	return (index);
}

// putnbr
void	ft_putchar(int digit)
{
	int		d;

	d = digit + '0';
	write(1, &d, 1);
}

void	recursion(int nb)
{
	if (nb > 9)
	{
		nb = nb / 10;
		recursion(nb);
		ft_putchar(nb % 10);
	}
}

void	ft_putnbr(int nb)
{	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	recursion(nb);
	ft_putchar(nb % 10);
}

// ft_put_unsign_nb

int	ft_unsign_length(unsigned int x)
{
	int		index;

	index = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 10;
		index++;
	}
	return (index);
}

void	unsign_recursion(unsigned int nb)
{
	if (nb > 9)
	{
		nb = nb / 10;
		unsign_recursion(nb);
		ft_putchar(nb % 10);
	}
}

void	ft_put_unsign_nb(unsigned int nb)
{	
	unsign_recursion(nb);
	ft_putchar(nb % 10);
}

// ft_put_low_hexadec_nb

int	ft_hexadec_length(unsigned int x)
{
	int		index;

	index = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x /= 16;
		index++;
	}
	return (index);
}

void	ft_put_low_hexadec_nb(unsigned int nb)
{	
	int		out;
	
	if (nb >= 16)
	{
		ft_put_low_hexadec_nb(nb / 16);
		ft_put_low_hexadec_nb(nb % 16);
	}
	else
	{
		if (nb >= 10 && nb <= 15)
		{
			out = nb - 10 + 'a';
			write(1, &out, 1);
		}
		else
		{
			out = nb + '0';
			write(1, &out, 1);
		}
		
	}
}

// ft_put_upp_hexadec_nb

void	ft_put_upp_hexadec_nb(unsigned int nb)
{	
	int		out;
	
	if (nb >= 16)
	{
		ft_put_upp_hexadec_nb(nb / 16);
		ft_put_upp_hexadec_nb(nb % 16);
	}
	else
	{
		if (nb >= 10 && nb <= 15)
		{
			out = nb - 10 + 'A';
			write(1, &out, 1);
		}
		else
		{
			out = nb + '0';
			write(1, &out, 1);
		}
		
	}
}