#include <stdio.h>
#include <stdio.h>
#include<stdbool.h>



void bubleSort(int *v, int n, FILE*arquivo);


int main(int argc, char const *argv[])
{
    
    int vetor[] = {9,4,6,7,1,10,16,3};
    //VETOR QUE VAI SER ORDENADOR
    int n = sizeof(vetor)/4;
    
    FILE* arquivo;
    arquivo = fopen("dadosBuble.csv", "w");
    
    fputs("Vetor para ser ordenado >> ",arquivo);

    for(int k = 0; k<n; k++){
        fprintf(arquivo,"%d, ", vetor[k]);
    }

    fputs("\n",arquivo);


    //ORDENANDO 
    bubleSort(vetor,n,arquivo);

    fputs("Vetor ordenado >>> ", arquivo);

    for(int i = 0; i<n; i++){
        fprintf(arquivo,"%d, ", vetor[i]);
    }



    fclose(arquivo);
    return 0;
}


void bubleSort(int *vetor, int n, FILE*arquivo){
    bool estaOrd = false;
    int aux;
    int numeroDetrocas = 0;
    int numeroDecompara = 0;

    while(estaOrd == false){
        
        estaOrd = true;

        for(int i = 0; i <= n - 2; i++){

            numeroDecompara++;
            if(vetor[i]>vetor[i+1]){
                numeroDetrocas++;
                fprintf(arquivo,"Troca %d com %d...\n",vetor[i],vetor[i+1]);
                estaOrd = false;
                aux = vetor[i];
                vetor[i] =vetor[i+1];
                vetor[i+1] = aux;
            }

        }
    }

    fprintf(arquivo,"Número de trocas >> |%d| \n",numeroDetrocas);
    fprintf(arquivo,"Número de comparações >> |%d| \n", numeroDecompara);

}