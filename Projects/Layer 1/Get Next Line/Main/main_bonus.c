
#include "get_next_line_bonus.h"

void	ft_leaks(void)
{
	printf("\nLEAKS O.K.!");
	system("leaks -q a.out");
}

int main()
{
	int		fd;
	int		fd2;
	char    *string = NULL;
	int 	cnt;
	char	*string2 = NULL;

	fd = open("prueba.txt", O_RDONLY);
	fd2 = open("prueba2.txt", O_RDONLY);
	cnt = 0;
	printf("\nTAMAÑO DE BUFFER = %i", BUFFER_SIZE);
	while ((string = get_next_line(fd)) != NULL)
	{
		printf("\nTEXTO 1 (INGLES)					LÍNEA %i: %s", cnt, string);
		free (string);
		string = NULL;
	}
	string = get_next_line(fd);
	printf("\nTEXTO 1 (INGLES) LÍNEA DE DOCUMENTO TERMINADO: 		%s", string);
	free (string);
	string = NULL;
	cnt = 0;
	while ((string = get_next_line(fd2)) != NULL)
	{
		printf("\nTEXTO 2 (ESPAÑOL)					LÍNEA %i: %s", cnt, string);
		free (string);
		string = NULL;
	}
	while (++cnt && (string = get_next_line(fd)) != NULL && (string2 = get_next_line(fd2)) != NULL)
	{
		printf("\nTEXTO 1 (INGLES)					LÍNEA %i: %s", cnt, string);
		printf("\nTEXTO 2 (ESPAÑOL)					LÍNEA %i: %s", cnt, string2);
		free (string);
		free (string2);
		string = NULL;
		string2 = NULL;
	}
	string = get_next_line(fd);
	printf("\nTEXTO 2 (ESPAÑOL) LÍNEA DE DOCUMENTO TERMINADO: 	%s", string);
	free (string);
	string = NULL;
	printf("\n\nCOMPROBANDO LEAKS...");
	close (fd);
	atexit(ft_leaks);
	return (0);
}
