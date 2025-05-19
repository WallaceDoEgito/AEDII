#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    long long tam = atoll(argv[1]);
    int init = atoi(argv[2]);

    srand(time(NULL));
    long long pos = rand() % tam;
    if (pos == 0) pos++;

    FILE *file = fopen("sequencia.txt", "wb");

    fprintf(file, "%lld\n", tam);

    for (long long i = 0; i < tam; i++) {
        if (i == pos) continue;

        fprintf(file, "%lld\n", (long long)init + i);
    }

    fclose(file);
    printf("O arquivo de %lli de tamanho foi criado\n", tam);
    return 0;
}
