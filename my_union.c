/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:31:24 by user42            #+#    #+#             */
/*   Updated: 2021/11/29 19:38:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_comp(char *s, char *str)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (str[(unsigned int)s[i]] == 0)
        {
            write(1, &s[i], 1);
            str[(unsigned int)s[i]] = 1;
        }
        i++;
    }
}

void    ft_union(char *s1, char *s2)
{
    char str[255] = {0};

    ft_comp(s1, str);
    ft_comp(s2, str);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}