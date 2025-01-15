#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    printf("Opening file...\n");
    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Failed to open file\n");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
        
    close(fd);
    return 0;
}