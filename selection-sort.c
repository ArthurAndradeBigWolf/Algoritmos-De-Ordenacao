#include<stdlib.h>
#include<stdio.h>


void selection(int *vetor, int n, FILE *arquivo);



int main(int argc, char const *argv[])
{
    int vetor[] = {10,7,2,1,4};
    int n = 5;
    FILE* arquivo;

    arquivo = fopen("dadosSelection.csv","w");

    fputs("Vetor >> ", arquivo);
    for(int i=0; i<n; i++){
        fprintf(arquivo,"%d, ", vetor[i]);
    }
    fputs("\n", arquivo);



    selection(vetor,n,arquivo);

    for(int i=0; i<n; i++){
        printf("%d, ", vetor[i]);
    }

    fclose(arquivo);

    return 0;
}

void selection(int *vetor, int n, FILE *arquivo){
    int menor;
    int aux;

    for(int i = 0; i < n - 1; i++){
        menor = i;

        for(int j = i + 1; j < n ; j++){
            if(vetor[j] < vetor[menor]){
                menor = j;
            }
        }

        fprintf(arquivo,"Trocou %d que está na posica %d, com %d da posicao %d \n",vetor[i],i,vetor[menor],menor);
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;

        for(int k = 0; k<n; k++){
            fprintf(arquivo,"%d, ", vetor[k]);
        }
        fputs("\n", arquivo);
    }

}