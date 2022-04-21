/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:25:57 by user42            #+#    #+#             */
/*   Updated: 2022/04/06 17:04:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

struct drawing draw, *pdraw;
struct rectangle rect_2, *prect;

struct drawing
{
    int largeur;
    int hauteur;
    char *matrice;
};

struct rectangle
{
    char type;
    char color;
    float x;
    float y;
    float largeur;
    float hauteur;
};

int execute(FILE *file)
{
    int rt;
    rectangle rect;
    drawing draw;

    if (!get_info(file, &drawing))
    {
        rt = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
        while (rt == 6)
        {
            if (apply_op(&rect, &draw))
                return (1);
            rt = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.color);
        }
        if (rt == -1)
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
        file = fopen(argv[1], "r");
        if (file && !execute(file))
            return (0);
        i = ft_strlen("Error: Operation file corrupted\n");
		write(1, "Error: Operation file corrupted\n", i);
    }
    else
    {
        i = ft_strlen("Error argument\n");
        write(1, "Error argument\n", i);
    }
    
}