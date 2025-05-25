#include "utils.h"

void	print_result(const char *desc, int passed)
{
	printf("Test %-50s: %s\n", desc, passed ? "✅ OK" : "❌ FAIL");
}

void	print_line_len(int len)
{
	while (len-- > 0)
		putchar('-');
	putchar('\n');
}

void 	print_line(void)
{
	print_line_len(56);
}