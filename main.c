#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	char *result;

	fd = open("41_no_nl", O_RDONLY);
	result = get_next_line(fd);
	printf("%s", result);
	free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	// result = get_next_line(fd);
	// printf("%s", result);
	// free(result);
	close(fd);
}
