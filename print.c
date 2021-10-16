#include <unistd.h>
#include <stdlib.h>

int print(char *value, unsigned int *fd)
{
    unsigned int    flag;

    flag = 0;
    if (fd == NULL)
    {
        fd = malloc(sizeof(unsigned int) * 1);
        flag = 1;
        if (fd == 0)
            return (-1);
    }
    if (value == NULL)
    {
        write(*fd, "", 1);
        return (0);
    }
    while (*value)
    {
        if (write(*fd, value++, 1) == -1)
        {
            if (flag)
                free(fd);
            return (-1);
        }
    }
    if (flag)
        free(fd);
    return (0);
}

int main(void)
{
    char            *a = "Hello World!";
    unsigned int    fd = 1;

    print(NULL, NULL);
    print(a, NULL);
    print(a, &fd);
    print(NULL, &fd);
    return (0);
}
