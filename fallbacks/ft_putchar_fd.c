#include "../utils/utils.h"

void ft_putchar_fd(char c, int fd)
{
	(void)c; (void)fd;
	dprintf(fd, "⚠️ ft_putchar_fd not implemented: '%c'\n", c);
}
