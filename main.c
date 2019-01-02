/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Rui Paredes
 *
 * Created on January 1, 2019, 4:05 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int matriz [320][5];

/*
 * 
 */


int printRandoms(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void tempoAtendimentoClientes(int totalClientes, int clientesTa1, int clientesTa2, int clientesTa3, int clientesTa4, int clientesTa5){
    int valorAtendimento=0;
}

void tempoChegadaClientes(int totalClientes, int cPrimeiroP, int cSegundoP, int cTerceiroP, int cQuartoP) {
    int valorChegada = 0;
    srand(time(NULL));
    for (int i = 0; i < totalClientes; i++) {
        if (cPrimeiroP != 0) {
            valorChegada = printRandoms(0, 10799);
            matriz[i][1] = valorChegada;
            cPrimeiroP--;
            printf("\n Primeiro: %d", cPrimeiroP);
        } else if (cSegundoP != 0) {
            valorChegada = printRandoms(10800, 21599);
            matriz[i][1] = valorChegada;
            cSegundoP--;
            printf("\n Segundo: %d", cSegundoP);
        } else if (cTerceiroP != 0) {
            valorChegada = printRandoms(21600, 32399);
            matriz[i][1] = valorChegada;
            cTerceiroP--;
            printf("\n Terceiro: %d", cTerceiroP);
        } else if (cQuartoP != 0) {
            valorChegada = printRandoms(32400, 43200);
            matriz[i][1] = valorChegada;
            cQuartoP--;
            printf("\n Quarto: %d", cQuartoP);
        }
        matriz[i][0]=i+1;
    }

    printf("Chegou ao fim");
    int temp = 0;
    for (int j = 0; j < totalClientes; j++) {
        for (int k = j + 1; k < totalClientes; k++) {
            if (matriz[j][1] > matriz[k][1]) {
                temp = matriz[j][1];
                matriz[j][1] = matriz[k][1];
                matriz[k][1] = temp;
            }
        }

    }

}

int main(int argc, char** argv) {
    
    //Percentagens intervalos de tempo
    float percPrimeiroP = 0.1;
    float percSegundoP = 0.3;
    float percTerceiroP = 0.15;
    float percQuartoP = 0.45;



    int totalClientes = 0;
    printf("Total Clients: ");
    scanf("%d", &totalClientes);

    //calculo clientes para cada intervalo de tempo
    int clientesPrimeiroP = trunc(percPrimeiroP * totalClientes);
    int clientesSegundoP = trunc(percSegundoP * totalClientes);
    int clientesTerceiroP = trunc(percTerceiroP * totalClientes);
    int clientesQuartoP = trunc(percQuartoP * totalClientes);
    
    //calculo clientes para cada intervalo tempo atendimento
    int clientesTa1 = trunc(0.1 * totalClientes);
    int clientesTa2 = trunc(0.25 * totalClientes);
    int clientesTa3 = trunc(0.4 * totalClientes);
    int clientesTa4 = trunc(0.2 * totalClientes);
    int clientesTa5 = trunc(0.05 * totalClientes);

    printf("%d,%d,%d,%d \n", clientesPrimeiroP, clientesSegundoP, clientesTerceiroP, clientesQuartoP);

    tempoChegadaClientes(totalClientes, clientesPrimeiroP, clientesSegundoP, clientesTerceiroP, clientesQuartoP);

    for (int i = 0; i < totalClientes; i++) {
        
        printf("\n Cliente %d: %d",matriz[i][0], matriz[i][1]);
    }

    return (EXIT_SUCCESS);
}

