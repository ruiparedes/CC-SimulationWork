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
#define Infinito 10000000.0
int matriz [300][5];

/*
 * 
 */

void shuffle(int index, int totalClientes) {
    for (int i = 0; i < totalClientes - 1; i++) {
        int j = i + rand() / (RAND_MAX / (totalClientes - i) + 1);
        int t = matriz[j][index];
        matriz[j][index] = matriz[i][index];
        matriz[i][index] = t;
    }
}

int printRandoms(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void tempoLevantamentoClientes(int nClientesLevantaram, int totalClientes, int nClientesTL1, int nClientesTL2, int nClientesTL3, int nClientesTL4) {
    int tempoLevantamento = 0;

    for (int j = 0; j < totalClientes; j++) {
        matriz[j][4] = -1;
    }
    int countLevantaram =0;
    for (int k = 0; k < totalClientes; k++) {
        if (matriz[k][3] != -1) {
                if (nClientesTL1 != 0) {
                    tempoLevantamento = printRandoms(0, 299);
                    matriz[k][4] = tempoLevantamento;
                    nClientesTL1--;
                    printf("\n L1 %d Cliente: %d", nClientesTL1, k);
                } else if (nClientesTL2 != 0) {
                    tempoLevantamento = printRandoms(300, 599);
                    matriz[k][4] = tempoLevantamento;
                    nClientesTL2--;
                    printf("\n L2 %d Cliente: %d", nClientesTL2, k);
                } else if (nClientesTL3 != 0) {
                    tempoLevantamento = printRandoms(600, 899);
                    matriz[k][4] = tempoLevantamento;
                    nClientesTL3--;
                    printf("\n L3 %d Cliente: %d", nClientesTL3, k);
                } else if (nClientesTL4 != 0) {
                    tempoLevantamento = printRandoms(900, 1200);
                    matriz[k][4] = tempoLevantamento;
                    nClientesTL4--;
                    printf("\n L4 %d Cliente: %d", nClientesTL4, k);
                }
                countLevantaram++;
                if(countLevantaram==nClientesLevantaram){
                    break;
                }
        }
    }
}

void tempoPagamentoClientes(int nClientesCompram, int totalClientes, int nClientesTP1, int nClientesTP2, int nClientesTP3, int nClientesTP4) {
    int tempoPagamento = 0;
    for (int j = 0; j < totalClientes; j++) {
        matriz[j][3] = -1;
    }
    for (int i = 0; i < nClientesCompram; i++) {
        if (nClientesTP1 != 0) {
            tempoPagamento = printRandoms(0, 59);
            matriz[i][3] = tempoPagamento;
            nClientesTP1--;
        } else if (nClientesTP2 != 0) {
            tempoPagamento = printRandoms(60, 119);
            matriz[i][3] = tempoPagamento;
            nClientesTP2--;
        } else if (nClientesTP3 != 0) {
            tempoPagamento = printRandoms(120, 179);
            matriz[i][3] = tempoPagamento;
            nClientesTP3--;
        } else if (nClientesTP4 != 0) {
            tempoPagamento = printRandoms(180, 240);
            matriz[i][3] = tempoPagamento;
            nClientesTP4--;
        }
    }
    shuffle(3, totalClientes);
}

void tempoAtendimentoClientes(int totalClientes, int clientesTa1, int clientesTa2, int clientesTa3, int clientesTa4, int clientesTa5) {
    int tempoAtendimento = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (clientesTa1 != 0) {
            tempoAtendimento = printRandoms(0, 299);
            matriz[i][2] = tempoAtendimento;
            clientesTa1--;
        } else if (clientesTa2 != 0) {
            tempoAtendimento = printRandoms(300, 599);
            matriz[i][2] = tempoAtendimento;
            clientesTa2--;
        } else if (clientesTa3 != 0) {
            tempoAtendimento = printRandoms(600, 899);
            matriz[i][2] = tempoAtendimento;
            clientesTa3--;
        } else if (clientesTa4 != 0) {
            tempoAtendimento = printRandoms(900, 1200);
            matriz[i][2] = tempoAtendimento;
            clientesTa4--;
        } else if (clientesTa5 != 0) {
            tempoAtendimento = printRandoms(1200, 3600); //Atribuido 1h como tempo máximo de atendimento
            matriz[i][2] = tempoAtendimento;
            clientesTa5--;
        }
    }
    shuffle(2, totalClientes);
}

void tempoChegadaClientes(int totalClientes, int cPrimeiroP, int cSegundoP, int cTerceiroP, int cQuartoP) {
    int tempoChegada = 0;

    for (int i = 0; i < totalClientes; i++) {
        if (cPrimeiroP != 0) {
            tempoChegada = printRandoms(0, 10799);
            matriz[i][1] = tempoChegada;
            cPrimeiroP--;
        } else if (cSegundoP != 0) {
            tempoChegada = printRandoms(10800, 21599);
            matriz[i][1] = tempoChegada;
            cSegundoP--;
        } else if (cTerceiroP != 0) {
            tempoChegada = printRandoms(21600, 32399);
            matriz[i][1] = tempoChegada;
            cTerceiroP--;
        } else if (cQuartoP != 0) {
            tempoChegada = printRandoms(32400, 43200);
            matriz[i][1] = tempoChegada;
            cQuartoP--;
        }
        matriz[i][0] = i + 1;
    }
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

    int nClientesCompram = trunc(0.8 * totalClientes);
    int nClientesTP1 = trunc(0.15 * nClientesCompram); //Nota: Faltavam 5%, adicionados aos 0.10
    int nClientesTP2 = trunc(0.25 * nClientesCompram);
    int nClientesTP3 = trunc(0.4 * nClientesCompram);
    int nClientesTP4 = trunc(0.20 * nClientesCompram);

    int nClientesLevantaram = trunc(0.6 * nClientesCompram);
    int nClientesTL1 = trunc(0.3 * nClientesLevantaram);
    int nClientesTL2 = trunc(0.4 * nClientesLevantaram);
    int nClientesTL3 = trunc(0.25 * nClientesLevantaram);
    int nClientesTL4 = trunc(0.05 * nClientesLevantaram);

    if (nClientesLevantaram != (nClientesTL1 + nClientesTL2 + nClientesTL3 + nClientesTL4)) {
        int diferenca = nClientesLevantaram - (nClientesTL1 + nClientesTL2 + nClientesTL3 + nClientesTL4);
        nClientesTL2 = nClientesTL2 + diferenca;
    }

    printf("Clientes levantaram: %d", nClientesLevantaram);
    printf("Soma: %d", nClientesTL1 + nClientesTL2 + nClientesTL3 + nClientesTL4);

    srand(time(NULL));

    tempoChegadaClientes(totalClientes, clientesPrimeiroP, clientesSegundoP, clientesTerceiroP, clientesQuartoP);
    tempoAtendimentoClientes(totalClientes, clientesTa1, clientesTa2, clientesTa3, clientesTa4, clientesTa5);
    tempoPagamentoClientes(nClientesCompram, totalClientes, nClientesTP1, nClientesTP2, nClientesTP3, nClientesTP4);
    tempoLevantamentoClientes(nClientesLevantaram, totalClientes, nClientesTL1, nClientesTL2, nClientesTL3, nClientesTL4);

    for (int i = 0; i < totalClientes; i++) {
        printf("\n Cliente %d: [%d][%d][%d][%d]", matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4]);
    }
    int count = 0;
    for (int i = 0; i < totalClientes; i++) {
        if (matriz[i][4] != -1) {
            count++;
        }
    }
    printf("\n %d", count);

    return (EXIT_SUCCESS);
}

