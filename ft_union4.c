/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:38:19 by user42            #+#    #+#             */
/*   Updated: 2021/12/09 15:03:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_sort(char *s1, char *str)
{
    int i;

    i = 0;
    while (s1[i])
    {
        if (str[(unsigned int)s1[i]] == 0)
        {
            write(1, &s1[i], 1);
            str[(unsigned int)s1[i]] = 1;
        }
        i++;
    }
}


int ft_puntbr(int nb, int base)
{
    char *hex = "012356789abcdef";
    char *dec = "0123456789";
    int i;
    int count = 0;

    if (nb / base != 0)
        count = count + ft_puntbr(nb / base, base);
    i = nb % base;
    if (base == 10)
        count = count + ft_putchar(dec[i]);
    else if (base == 16)
        count = count + ft_putchar(hex[i]);
    return (count);
}




void    ft_union(char **argv)
{
    char str[255] = {0};

    ft_sort(argv[1], str);
    ft_sort(argv[2], str);
}

int     main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv);
    write(1, "\n", 1);
    return (0);
}