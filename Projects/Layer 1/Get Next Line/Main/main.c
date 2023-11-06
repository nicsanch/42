
#include "get_next_line.h"

void	ft_leaks(void)
{
	printf("\nLEAKS O.K.!");
	system("leaks -q a.out");
}

int main()
{
	int		fd;
	char    *string = NULL;
	int 	cnt;

	fd = open("prueba.txt", O_RDONLY);
	cnt = 0;
	printf("\nTAMAÑO DE BUFFER = %i", BUFFER_SIZE);
	while ((string = get_next_line(fd)) != NULL)
	{
		printf("\nTEXTO					LÍNEA %i: %s", cnt, string);
		free (string);
		string = NULL;
	}
	string = get_next_line(fd);
	printf("\nLÍNEA DE DOCUMENTO TERMINADO: 		%s", string);
	free (string);
	string = NULL;
	printf("\n\nCOMPROBANDO LEAKS...");
	close (fd);
	atexit(ft_leaks);
	return (0);
}
