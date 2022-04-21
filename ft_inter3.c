#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    char str[255] = {0};

    if (argc == 3)
    {
        i = 2;
        while (i > 0)
        {
            j = 0;
            while (argv[i][j])
            {
                if (i == 2 && str[(unsigned char)argv[i][j]] == 0)
                    str[(unsigned char)argv[i][j]] = 1;
                else if (i == 1 && str[(unsigned char)argv[i][j]] == 1)
                {
                    write(1, &argv[i][j], 1);
                    str[(unsigned char)argv[i][j]] = 2;
                }
                j++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}