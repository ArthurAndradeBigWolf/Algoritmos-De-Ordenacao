#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void insertion_sort(int n,  int *vetor, FILE *arquivo);

int main(int argc, char const *argv[])
{
    int vetor[] = {8,2,4,9,3,6};
    int n = 6;
    FILE *arquivo;
    
    arquivo = fopen("dadosInsertion.csv","a");

    fputs("Vetor >> ",arquivo);
    
    for(int i = 0; i<n; i++){
        fprintf(arquivo,"%d, ", vetor[i]);    
    }

    fputs("\n", arquivo);

    insertion_sort(6,vetor,arquivo);

    for(int i = 0; i<n; i++){
        printf("%d,", vetor[i]);
    }

    fclose(arquivo);

    return 0;
}

void insertion_sort(int n,  int *vetor, FILE *arquivo){
    int aux,j;
    
    for(int i = 1; i<n ;i++){
        
        aux = vetor[i];
        
        for(j = i - 1; j>=0 && aux < vetor[j]; j--){
            fprintf(arquivo,"Trocou %d com %d :\n ",vetor[j+1],vetor[j]);
            vetor[j+1] = vetor[j];
        }

        vetor[j+1] = aux;

        //Escreve no arquivo;
        for(int k = 0; k < n; k++){
            fprintf(arquivo,"%d ,",vetor[k]);
        }
        fputs("\n",arquivo);
      
    }

}
