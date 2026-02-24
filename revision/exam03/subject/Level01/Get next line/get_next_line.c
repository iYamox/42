#include "get_next_line.h"

char *ft_strdup(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    char *dup = malloc(sizeof(char) * i + 1);
    if (!dup)
        return NULL;
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return(dup);
}

char *get_next_line(int fd)
{
    static int pos = 0;
    static int readed = 0;
    int i = 0;
    static char buf[BUFFER_SIZE];
    char line[70000];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (1)
    {
        if(pos >= readed)
        {
            readed = read(fd, buf, BUFFER_SIZE);
			if (readed == -1)
				return (NULL);
            pos = 0;
            if (readed == 0)
                break;
        }
        line[i++] = buf[pos++];
        if (line[i - 1] == '\n')
            break;
    }
    if (i == 0)
        return NULL;
    line[i] = '\0';
    return (ft_strdup(line));
}

int main ()
{
    int fd = open("test.txt", O_RDONLY);
    char *line = get_next_line(fd);
    while(line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
}
