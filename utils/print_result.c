#include "utils.h"

void	print_result(const char *desc, int passed)
{
	printf("Test %-40s: %s\n", desc, passed ? "✅ OK" : "❌ FAIL");
}

void 	print_line(void)
{
	printf("----------------------------------------------\n");
}