#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>
int open_read(char* file_name, uint32_t* var)
{
	FILE* file;
	if ((file = fopen(file_name, "rb")) != NULL)
	{
		size_t len = fread(var, 4, 1, file);
		fclose(file);
		if (len) return 1;
		else
		{
			printf("Failed to read: %s\n", file_name);
			return 0;
		}
	}
	else
	{
		printf("Failed to open file: %s\n", file_name);
		return 0;
	}
}
int main(int argc, char* argv[])
{
	uint32_t thousand, five_hundred;
	if (open_read(argv[1], &thousand) && open_read(argv[2], &five_hundred))
	{
		thousand = ntohl(thousand);
		five_hundred = ntohl(five_hundred);
		uint32_t sum = thousand + five_hundred;
		printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", thousand, thousand, five_hundred, five_hundred, sum, sum);
	}
}
