#include "../utils/utils.h"

void ft_putstr_fd(char *s, int fd)
{
	(void)*s; (void)fd;
	dprintf(fd, "⚠️ ft_putstr_fd not implemented: \"%s\"\n", s);
}
