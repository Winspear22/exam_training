/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minipaint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:36:21 by user42            #+#    #+#             */
/*   Updated: 2022/01/03 20:59:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <math.h> 

void ft_putstr(char *str) 
{ 
    int i = -1;
    while (str[++i] != '\0')
        write(1, str, i);
 }

int ft_close(FILE *f) 
{ 
    ft_putstr("Error: Operation file corrupted\n");
    fclose(f); 
    return (1);
} 

int main(int argc, char **argv) 
{ 
    FILE *f;
    int w;
    int h; 
    char bc; 
    char tab[300][301]; 
    int i = -1; 
    int j = -1; 
    int s; 
    char c; 
    float xa; 
    float ya; 
    float r; 
    float xb; 
    float yb; 
    char nbc; 
    float d; 
    
    if (argc != 2) 
    { 
        ft_putstr("Error: argument\n");
        return (1);
    } 
    if ((f = fopen(argv[1], "r")) == NULL) 
    { 
        ft_putstr("Error: Operation file corrupted\n"); 
        return (1); 
    } 
    if (fscanf(f, "%d %d %c\n", &w, &h, &bc) != 3) 
        return (ft_close(f)); 
    if (w > 300 || w < 1)
        return (ft_close(f)); 
    if (h > 300 || h < 1) 
        return (ft_close(f)); 
    while (++i < 300) 
    {
        j = -1; 
        while (++j < 300) 
        tab[i][j] = '\0';
            tab[i][j] = '\0'; 
    } 
    i = -1; 
    while (++i < h) 
    { 
        j = -1; 
        while (++j < w) 
        tab[i][j] = bc; tab[i][j] = '\0'; 
    } 
    while ((s = fscanf(f, "%c %f %f %f %c\n", &c, &xa, &ya, &r, &nbc)) == 5) 
    { 
        i = -1;
        if (c != 'c' && c != 'C') 
            return (ft_close(f)); 
        if (r <= 0.00000000) 
            return (ft_close(f));
        if (c == 'C' || c == 'c') 
        { 
            while (++i < h) 
            { 
                yb = (float)i;
                j = -1; 
                while (++j < w) 
                { 
                    xb = (float)j; 
                    d = sqrtf((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
                    if (c == 'C') 
                    { 
                        if (d <= r) 
                        tab[i][j] = nbc; 
                    } 
                    if (c == 'c') 
                    { 
                        if (d <= r) 
                        { 
                            if (r - d < 1.00000000) tab[i][j] = nbc; 
                        } 
                    } 
                } 
            } 
        } 
    } 
    if (s != -1) 
        return (ft_close(f)); 
    i = -1; 
    while (++i < h) 
    { 
        ft_putstr(tab[i]); 
        ft_putstr("\n"); 
    } 
    fclose(f); 
    return (0); 
}