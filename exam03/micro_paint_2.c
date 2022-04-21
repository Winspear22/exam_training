/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:15:12 by user42            #+#    #+#             */
/*   Updated: 2022/04/07 11:45:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//typedef struct rectangle rectangle_1, *rectangle_2;

typedef struct s_rectangle
{
    char color;
    char type;
    float hauteur;
    float largeur;
    float x;
    float y;
}               t_rectangle;

//typedef struct drawing draw_1, *draw_2;

typedef struct s_drawing
{
    char *matrice;
    int hauteur;
    int largeur;
}               t_drawing;

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}


int get_info(FILE *file, t_drawing *draw)
{
    char *tmp;
    char background;
    int i;

    if (fscanf(file, "%d %d %c\n", &draw->largeur, &draw->hauteur, &background) == 3)
    {
        if (draw->hauteur > 300 || draw->hauteur < 1 || draw->largeur > 300 || draw->largeur < 1)
            return (1);
        tmp = (char *)malloc(draw->largeur * draw->hauteur);
        draw->matrice = tmp;
        if (!draw->matrice)
            return (1);
        i = 0;
        while (i < draw->largeur * draw->hauteur)
            draw->matrice[i++] = background;
        return (0);
    }
    return (1);
}

int execute(FILE *file)
{
    t_rectangle rect;
    t_drawing draw;
    int ret;

    if (!get_info(file, &draw))
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
            print_info(&draw);
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
        file = fopen(file, "r");
        if (file && !execute(file))
            return (0);
        i = ft_strlen("Corrupted file\n");
        write(2, "Corrupted file\n", i);
    }
    else
    {
        i = ft_strlen("Error\n");
        write(2, "Error\n", i);
        return (1);
    }
    return (1);
}