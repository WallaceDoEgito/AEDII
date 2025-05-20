#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int tam = atoi(argv[1]);
    int init = 1;

    srand(time(NULL));
    int pos = rand() % tam;
    if (pos == 0) pos++;

    FILE *file = fopen("sequencia.txt", "wb");

    fprintf(file, "%d\n", tam);

    for (int i = 0; i <= tam; i++) {
        if (i == pos) continue;

        fprintf(file, "%d\n", init + i);
    }

    fclose(file);
    printf("O arquivo de %i de tamanho foi criado\n", tam);
    return 0;
}
