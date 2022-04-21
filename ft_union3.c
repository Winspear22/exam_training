#include <unistd.h>

void ft_lolo(char *s1, char *str)
{
    int i = 0;

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

void    ft_union(char **argv)
{
    char str[255] = {0};

    ft_lolo(argv[1], str);
    ft_lolo(argv[2], str);
}

int main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv);
    write(1, "\n", 1);
    return (0);
}