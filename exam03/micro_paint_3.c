/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:15:36 by user42            #+#    #+#             */
/*   Updated: 2022/04/07 13:40:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_rectangle
{
    char type;
    float hauteur;
    float largeur;
    float x;
    float y;
    char color;
}               t_rectangle;

typedef struct s_drawing
{
    int hauteur;
    int largeur;
    char *matrice
}               t_drawing;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_check(FILE *file, t_drawing *draw)
{
    char background;
    char *tmp;
    int i;

    if (fscanf(file, "%d %c %c\n", &draw->largeur, &draw->hauteur, &background) == 3)
    {
        if (draw->hauteur < 1 || draw->hauteur > 300 || draw->largeur < 1 || draw->largeur > 300)
            return (1);
        tmp = (char *)malloc(draw->hauteur * draw->largeur);
        if (!tmp)
            return (1);
        draw->matrice = tmp;
        i = 0;
        while (i < draw->hauteur * draw->largeur)
            draw->matrice[i++] = background;
        return (0);
    }
    return (1);
}

int apply_op(t_drawing *draw, t_rectangle *rect)
{
    int i;
    int j;
    
    if (rect->hauteur <= 0.00000000 || rect->largeur <= 0.00000000 || rect->type != 'R' && rect->type != 'r')
        return (1);
    i = 0;
    while (i < draw->largeur)
    {
        j = 0;
        while (j < draw->hauteur)
            ft_execute(rect, draw, i, j++);
        i++;
    }
}

int execute(FILE *file)
{
    t_rectangle rect;
    t_drawing draw;
    int ret;
    
    if (!ft_check(file, &draw))
    {
        ret = fscanf(file, "%c %f %f %f %f %c\n", rect.type, rect.hauteur, rect.largeur, rect.x, rect.y, rect.color);
        while (ret == 6)
        {
            if (apply_op(&rect, &draw))
                return (1);
            ret = fscanf(file, "%c %f %f %f %f %c\n", rect.type, rect.hauteur, rect.largeur, rect.x, rect.y, rect.color);

        }
        if (ret == -1)
        {
            ft_print(&draw);
            return (0);
        }
    }
    return (1);
    
}

int main(int argc, char **argv)
{
    int i;
    FILE *file;

    if (argc == 2)
    {
        if (file && !exectute(file))   
            return (0);
        printf("File corrupted\n");
        return (1);
    }
    else
    {
        printf("Error\n");
    }
    return (1);
}