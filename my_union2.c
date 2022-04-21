#include <unistd.h>

void ft_remplir(char *argv, char *str)
{
    int i;

    i = 0;
    while (argv[i])
    {
        if (str[(unsigned int)argv[i]] == 0)
        {
            write(1, &argv[i], 1);
            str[(unsigned int)argv[i]] = 1;
        }
        i++;
    }

}

void ft_union(char **argv)
{
    char str[255] = {0};

    ft_remplir(argv[1], str);
    ft_remplir(argv[2], str);
}


int main(int argc, char **argv)
{
    if (argc == 3)
        ft_union(argv);
    write(1, "\n", 1);
    return (0);
}