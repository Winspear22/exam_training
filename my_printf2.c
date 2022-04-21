#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int i;

    i = 0;
    if (!str)
        str = "(null)";
    while(str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
    return (i);
}

int ft_putnbr(unsigned int nb, int base)
{
    int count;
    char *hex = "0123456789abcdef";
    char *dec = "0123456789";
    int i;

    i = 0;
    count = 0;
    if (nb / base != 0)
        count = count + ft_putnbr(nb / base, base);
    i = nb % base;
    if (base == 10)
        count = count + ft_putchar(dec[i]);
    else if (base == 16)
        count = count + ft_putchar(hex[i]);
    return (count);
}

int ft_count(int nb)
{
    int count;

    count = 0;
    if (nb < 0)
    {
        nb = nb * (-1);
        count = count + ft_putchar('-');
    }
    count = count + ft_putnbr(nb, 10);
    return (count);
}

int ft_printf(const char *str, ...)
{
    int i;
    int count;
    va_list np;

    i = 0;
    count = 0;
    va_start(np, str);
    while(str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 's')
                count = count + ft_putstr(va_arg(np, char *));
            if (str[i] == 'd')
                count = count + ft_count(va_arg(np, int));
            if (str[i] == 'x')
                count = count + ft_putnbr(va_arg(np, unsigned int), 16);
        }
        else
            count = count + ft_putchar(str[i]);
        i++;
    }
    va_end(np);
    return (count);
}

int main(void)
{
    char str[] = "comment ça va ?";
    
    ft_printf("salut les amis %s nous sommes %d et en hexa %x", str, 152, 152);
    return (0);
}