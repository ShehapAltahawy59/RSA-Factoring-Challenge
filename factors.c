#include <stdio.h>
#include <stdlib.h>

void factorize_and_print(long long num) {
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            printf("%lld=%d*%lld\n", num, i, num / i);
            return;
        }
    }
    printf("%lld=%d*%lld\n", num, 1, num);
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
        factorize_and_print(num);
    }

    fclose(file);
    return 0;
}

