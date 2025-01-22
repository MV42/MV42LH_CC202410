#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd[1000];
	int		max_open;
	int		max_iter;
	char	*line;
	int		i;

	if (argc >= 4)
	{
		max_open = atoi(argv[1]);
		i = 3;
		while (max_open-- > 0 && i < argc)
		{
			fd[i] = open(argv[i], O_RDONLY);
			printf("\n📂️ %i\n", fd[i]);
			max_iter = atoi(argv[2]);
			while (max_iter-- > 0)
			{
				line = get_next_line(fd[i]);
				printf("%s↩️", line);
				free(line);
			}
			i++;
		}
	}
}
