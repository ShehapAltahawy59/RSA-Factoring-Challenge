#include <stdio.h>
#include <stdlib.h>

int find_divisor(long long int num)
{
	long long int factor;

	if (num % 2 == 0)
	{
		printf("%llu=%llu*%i\n", num, num / 2, 2);
		return 0;
	}

	factor = 3;
	while (factor * factor <= num)
	{
		if (num % factor == 0)
		{
			printf("%llu=%llu*%llu\n", num, num / factor, factor);
			return 0;
		}
		else
			factor += 2;
	}

	printf("%llu=%llu*%i\n", num, num, 1);

	return 0;
}
int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    long long int num;
    while(fscanf(file, "%lld", &num) == 1) {
        find_divisor(num);
    }

    fclose(file);
    return 0;
}

