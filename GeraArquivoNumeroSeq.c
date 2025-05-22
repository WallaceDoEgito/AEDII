#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    int tam = atoi(argv[1]);
    if(tam <= 1){
        printf("A sequencia precisa ir alem do numero 1\n");
        exit(0);
    }
    int init = 1;

    srand(time(NULL));
    int pos = rand() % (tam -1);

    FILE *file = fopen("sequencia.txt", "wb");

    fprintf(file, "%d\n", tam - 1);

    for (int i = 0; i < tam; i++) {
        if (i == pos) continue;

        fprintf(file, "%d\n", init + i);
    }

    fclose(file);
    printf("O arquivo de %i de tamanho foi criado\n", tam);
    return 0;
}
