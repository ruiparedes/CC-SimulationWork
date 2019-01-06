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
#define Infinito 100000.0
#define TRUE 1
int matriz [300][6];

/*
 * 
 */

int *CreateQueue() {
    int *Q;

    Q = (int *) malloc(sizeof (int));
    if (Q == NULL)
        return NULL;
    Q[0] = -1.0; // indicate the end of Queue
    return Q;
}

int EmptyQueue(int *Q) {
    if (Q[0] < 0)
        return 1; // empty
    return 0;
}

int *InsertQueue(int X, int *Q) {
    int tam = 1;
    while (Q[tam - 1] >= 0)
        tam++;
    tam++;
    Q = (int *) realloc(Q, tam * sizeof (int));
    if (Q == NULL)
        return NULL;
    Q[tam - 2] = X;
    Q[tam - 1] = -1.0;
    return Q;
}

int *RemoveQueue(int *Q) {
    int i, tam = 1;

    while (Q[tam - 1] >= 0) {
        Q[tam - 1] = Q[tam];
        tam++;
    }
    tam--;
    Q = (int *) realloc(Q, tam * sizeof (int));
    return Q;
}

float Front(int *Q) {
    return Q[0];
}

void ShowQueue(int *Q) {
    int k = 0;
    while (Q[k] >= 0) {
        printf("%d \n", Q[k]);
        k++;
    }
}

void shuffle(int index, int totalClientes) {
    for (int i = 0; i < totalClientes - 1; i++) {
        int j = i + rand() / (RAND_MAX / (totalClientes - i) + 1);
        int t = matriz[j][index];
        matriz[j][index] = matriz[i][index];
        matriz[i][index] = t;
    }
}

void shuffle2(int index, int totalClientes) {
    for (int i = 0; i < totalClientes - 1; i++) {
        if (matriz[i][index] != -1) {
            /*
                        printf("Valor da Matriz i[%d][%d]: %d || ", i, index, matriz[i][index]);
             */
            int j = i + rand() / (RAND_MAX / (totalClientes - i) + 1);

            while (matriz[j][index] == -1) {
                j = i + rand() / (RAND_MAX / (totalClientes - i) + 1);
            }
            /*
                        printf("Valor da Matriz j[%d][%d]: %d \n", j, index, matriz[j][index]);
                        printf("Fez while %d vezes \n", count);
             */
            int t = matriz[j][index];
            matriz[j][index] = matriz[i][index];
            matriz[i][index] = t;
        }
    }
}

int printRandoms(int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void clientesPrioritarios(int totalClientes, int nClientesPrioritarios) {
    for (int i = 0; i < totalClientes; i++) {
        if (nClientesPrioritarios != 0) {
            matriz[i][5] = 1;
            nClientesPrioritarios--;
        } else {
            matriz[i][5] = 0;
        }
    }
    shuffle(5, totalClientes);
}

void tempoLevantamentoClientes(int nClientesLevantaram, int totalClientes, int nClientesTL1, int nClientesTL2, int nClientesTL3, int nClientesTL4) {
    int tempoLevantamento = 0;

    for (int j = 0; j < totalClientes; j++) {
        matriz[j][4] = -1;
    }
    int countLevantaram = 0;
    for (int k = 0; k < totalClientes; k++) {
        if (matriz[k][3] != -1) {
            if (nClientesTL1 != 0) {
                tempoLevantamento = printRandoms(0, 299);
                matriz[k][4] = tempoLevantamento;
                nClientesTL1--;

            } else if (nClientesTL2 != 0) {
                tempoLevantamento = printRandoms(300, 599);
                matriz[k][4] = tempoLevantamento;
                nClientesTL2--;
            } else if (nClientesTL3 != 0) {
                tempoLevantamento = printRandoms(600, 899);
                matriz[k][4] = tempoLevantamento;
                nClientesTL3--;
            } else if (nClientesTL4 != 0) {
                tempoLevantamento = printRandoms(900, 1200);
                matriz[k][4] = tempoLevantamento;
                nClientesTL4--;
            }
            countLevantaram++;
            if (countLevantaram == nClientesLevantaram) {
                break;
            }
        }
    }
    shuffle2(4, totalClientes);
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

void inicializacao(int *clock, int *evento, int *nrCliente, int *tempoProximaChegada, int *estadoPA1, int *estadoPA2, int *estadoPA3, int *estadoPA4, int *estadoPA5, int *estadoPA6, int *estadoPA7, int *estadoPA8, int *estadoPA9, int *estadoPA10, int *tPartidaPA1, int *tPartidaPA2, int *tPartidaPA3, int *tPartidaPA4, int *tPartidaPA5, int *tPartidaPA6, int *tPartidaPA7, int *tPartidaPA8, int *tPartidaPA9, int *tPartidaPA10, int *estadoPP1, int *estadoPP2, int *estadoPP3, int *estadoPP4, int *tPartidaPP1, int *tPartidaPP2, int *tPartidaPP3, int *tPartidaPP4, int *estadoPL1, int *estadoPL2, int *tempoPartidaPL1, int *tempoPartidaPL2, int *tempoEspera, int **filaPAtendimento, int **filaPP1, int **filaPP2, int **filaPP3, int **filaPP4, int **filaPLevantamento) {

    *clock = 0;
    *evento = 0;
    *nrCliente = matriz[0][0];
    *tempoProximaChegada = matriz[0][1];
    *estadoPA1 = 0;
    *estadoPA2 = 0;
    *estadoPA3 = 0;
    *estadoPA4 = 0;
    *estadoPA5 = 0;
    *estadoPA6 = 0;
    *estadoPA7 = 0;
    *estadoPA8 = 0;
    *estadoPA9 = 0;
    *estadoPA10 = 0;
    *tPartidaPA1 = Infinito;
    *tPartidaPA2 = Infinito;
    *tPartidaPA3 = Infinito;
    *tPartidaPA4 = Infinito;
    *tPartidaPA5 = Infinito;
    *tPartidaPA6 = Infinito;
    *tPartidaPA7 = Infinito;
    *tPartidaPA8 = Infinito;
    *tPartidaPA9 = Infinito;
    *tPartidaPA10 = Infinito;
    *estadoPP1 = 0;
    *estadoPP2 = 0;
    *estadoPP3 = 0;
    *estadoPP4 = 0;
    *tPartidaPP1 = Infinito;
    *tPartidaPP2 = Infinito;
    *tPartidaPP3 = Infinito;
    *tPartidaPP4 = Infinito;
    *estadoPL1 = 0;
    *estadoPL2 = 0;
    *tempoPartidaPL1 = Infinito;
    *tempoPartidaPL2 = Infinito;
    *tempoEspera = 0;
    *filaPAtendimento = CreateQueue();
    *filaPP1 = CreateQueue();
    *filaPP2 = CreateQueue();
    *filaPP3 = CreateQueue();
    *filaPP4 = CreateQueue();
    *filaPLevantamento = CreateQueue();


}

void gestaoTempo(int tempoProximaChegada, int tPartidaPA1, int tPartidaPA2, int tPartidaPA3, int tPartidaPA4, int tPartidaPA5, int tPartidaPA6, int tPartidaPA7, int tPartidaPA8, int tPartidaPA9, int tPartidaPA10, int *clock, int *evento) {
    *clock = tempoProximaChegada;
    *evento = 0; //Chegada
    if (tPartidaPA1 < *clock) {
        *clock = tPartidaPA1;
        *evento = 1;
    }
    if (tPartidaPA2 < *clock) {
        *clock = tPartidaPA2;
        *evento = 2;
    }
    if (tPartidaPA3 < *clock) {
        *clock = tPartidaPA3;
        *evento = 3;
    }
    if (tPartidaPA4 < *clock) {
        *clock = tPartidaPA4;
        *evento = 4;
    }
    if (tPartidaPA5 < *clock) {
        *clock = tPartidaPA5;
        *evento = 5;
    }
    if (tPartidaPA6 < *clock) {
        *clock = tPartidaPA6;
        *evento = 6;
    }
    if (tPartidaPA7 < *clock) {
        *clock = tPartidaPA7;
        *evento = 7;
    }
    if (tPartidaPA8 < *clock) {
        *clock = tPartidaPA8;
        *evento = 8;
    }
    if (tPartidaPA9 < *clock) {
        *clock = tPartidaPA9;
        *evento = 9;
    }
    if (tPartidaPA10 < *clock) {
        *clock = tPartidaPA10;
        *evento = 10;
    }
    if (*clock == Infinito) {
        *evento = -1;
    }
}

void eventoChegada(int *cliente, int tempo, int *estadoPA1, int *estadoPA2, int *estadoPA3, int *estadoPA4, int *estadoPA5, int *estadoPA6, int *estadoPA7, int *estadoPA8, int *estadoPA9, int *estadoPA10, int **filaPVendedores, int *tempoProximaChegada, int *tPartidaPA1, int *tPartidaPA2, int *tPartidaPA3, int *tPartidaPA4, int *tPartidaPA5, int *tPartidaPA6, int *tPartidaPA7, int *tPartidaPA8, int *tPartidaPA9, int *tPartidaPA10, int *nrClienteOcupaPA1, int *nrClienteOcupaPA2, int *nrClienteOcupaPA3, int *nrClienteOcupaPA4, int *nrClienteOcupaPA5, int *nrClienteOcupaPA6, int *nrClienteOcupaPA7, int *nrClienteOcupaPA8, int *nrClienteOcupaPA9, int *nrClienteOcupaPA10) {
    *tempoProximaChegada = matriz[*cliente][1];

    if (*estadoPA1 == 1) {
        if (*estadoPA2 == 1) {
            if (*estadoPA3 == 1) {
                if (*estadoPA4 == 1) {
                    if (*estadoPA5 == 1) {
                        if (*estadoPA6 == 1) {
                            if (*estadoPA7 == 1) {
                                if (*estadoPA8 == 1) {
                                    if (*estadoPA9 == 1) {
                                        if (*estadoPA10 == 1) {
                                            *filaPVendedores = InsertQueue(*cliente, *filaPVendedores);
                                        } else {
                                            *estadoPA10 = 1;
                                            *tPartidaPA10 = tempo + matriz[*cliente][2];
                                            *nrClienteOcupaPA10 = *cliente;
                                        }
                                    } else {
                                        *estadoPA9 = 1;
                                        *tPartidaPA9 = tempo + matriz[*cliente][2];
                                        *nrClienteOcupaPA9 = *cliente;
                                    }
                                } else {
                                    *estadoPA8 = 1;
                                    *tPartidaPA8 = tempo + matriz[*cliente][2];
                                    *nrClienteOcupaPA8 = *cliente;
                                }
                            } else {
                                *estadoPA7 = 1;
                                *tPartidaPA7 = tempo + matriz[*cliente][2];
                                *nrClienteOcupaPA7 = *cliente;
                            }
                        } else {
                            *estadoPA6 = 1;
                            *tPartidaPA6 = tempo + matriz[*cliente][2];
                            *nrClienteOcupaPA6 = *cliente;
                        }
                    } else {
                        *estadoPA5 = 1;
                        *tPartidaPA5 = tempo + matriz[*cliente][2];
                        *nrClienteOcupaPA5 = *cliente;
                    }
                } else {
                    *estadoPA4 = 1;
                    *tPartidaPA4 = tempo + matriz[*cliente][2];
                    *nrClienteOcupaPA4 = *cliente;
                }
            } else {
                *estadoPA3 = 1;
                *tPartidaPA3 = tempo + matriz[*cliente][2];
                *nrClienteOcupaPA3 = *cliente;
            }
        } else {
            *estadoPA2 = 1;
            *tPartidaPA2 = tempo + matriz[*cliente][2];
            *nrClienteOcupaPA2 = *cliente;
        }
    } else {
        *estadoPA1 = 1;
        *tPartidaPA1 = tempo + matriz[*cliente][2];
        *nrClienteOcupaPA1 = *cliente;
    }
    *cliente = *cliente +1;
}

void eventoPartidaPA1(int *nrClienteOcupaPA1, int tempo, int *estadoPA1, int **filaPVendedores, int *tPartidaPA1, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA1 = 0;
        *tPartidaPA1 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA1 = clienteNaFila;
        *tPartidaPA1 = tempo + matriz[*nrClienteOcupaPA1][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA2(int *nrClienteOcupaPA2, int tempo, int *estadoPA2, int **filaPVendedores, int *tPartidaPA2, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA2 = 0;
        *tPartidaPA2 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA2 = clienteNaFila;
        *tPartidaPA2 = tempo + matriz[*nrClienteOcupaPA2][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA3(int *nrClienteOcupaPA3, int tempo, int *estadoPA3, int **filaPVendedores, int *tPartidaPA3, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA3 = 0;
        *tPartidaPA3 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA3 = clienteNaFila;
        *tPartidaPA3 = tempo + matriz[*nrClienteOcupaPA3][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA4(int *nrClienteOcupaPA4, int tempo, int *estadoPA4, int **filaPVendedores, int *tPartidaPA4, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA4 = 0;
        *tPartidaPA4 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA4 = clienteNaFila;
        *tPartidaPA4 = tempo + matriz[*nrClienteOcupaPA4][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA5(int *nrClienteOcupaPA5, int tempo, int *estadoPA5, int **filaPVendedores, int *tPartidaPA5, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA5 = 0;
        *tPartidaPA5 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA5 = clienteNaFila;
        *tPartidaPA5 = tempo + matriz[*nrClienteOcupaPA5][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA6(int *nrClienteOcupaPA6, int tempo, int *estadoPA6, int **filaPVendedores, int *tPartidaPA6, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA6 = 0;
        *tPartidaPA6 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA6 = clienteNaFila;
        *tPartidaPA6 = tempo + matriz[*nrClienteOcupaPA6][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA7(int *nrClienteOcupaPA7, int tempo, int *estadoPA7, int **filaPVendedores, int *tPartidaPA7, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA7 = 0;
        *tPartidaPA7 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA7 = clienteNaFila;
        *tPartidaPA7 = tempo + matriz[*nrClienteOcupaPA7][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA8(int *nrClienteOcupaPA8, int tempo, int *estadoPA8, int **filaPVendedores, int *tPartidaPA8, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA8 = 0;
        *tPartidaPA8 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA8 = clienteNaFila;
        *tPartidaPA8 = tempo + matriz[*nrClienteOcupaPA8][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA9(int *nrClienteOcupaPA9, int tempo, int *estadoPA9, int **filaPVendedores, int *tPartidaPA9, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA9 = 0;
        *tPartidaPA9 = Infinito;
    } else {
       clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA9 = clienteNaFila;
        *tPartidaPA9 = tempo + matriz[*nrClienteOcupaPA9][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

void eventoPartidaPA10(int *nrClienteOcupaPA10, int tempo, int *estadoPA10, int **filaPVendedores, int *tPartidaPA10, int *tempoEspera) {
    int tempoChegadaCliente, tempoEsperaCliente, tempoServico, clienteNaFila;

    if (EmptyQueue(*filaPVendedores)) {
        *estadoPA10 = 0;
        *tPartidaPA10 = Infinito;
    } else {
        clienteNaFila = Front(*filaPVendedores);
        tempoChegadaCliente = matriz[clienteNaFila][1];
        tempoEsperaCliente = tempo - tempoChegadaCliente;
        *nrClienteOcupaPA10 = clienteNaFila;
        *tPartidaPA10 = tempo + matriz[*nrClienteOcupaPA10][2];
        *filaPVendedores = RemoveQueue(*filaPVendedores);
        *tempoEspera = *tempoEspera + tempoEsperaCliente;
    }
}

int main(int argc, char** argv) {

    //Variáveis Necessárias processo
    int terminar = 0, numClientes = 0, tempoTotalSistema, clock, evento, nrCliente, tempoProximaChegada, estadoPA1, estadoPA2, estadoPA3, estadoPA4, estadoPA5, estadoPA6, estadoPA7, estadoPA8, estadoPA9, estadoPA10,
            tPartidaPA1, tPartidaPA2, tPartidaPA3, tPartidaPA4, tPartidaPA5, tPartidaPA6, tPartidaPA7, tPartidaPA8, tPartidaPA9, tPartidaPA10,
            estadoPP1, estadoPP2, estadoPP3, estadoPP4, tPartidaPP1, tPartidaPP2, tPartidaPP3, tPartidaPP4, estadoPL1, estadoPL2, tempoPartidaPL1, tempoPartidaPL2, tempoEspera;

    int *filaPVendedores, *filaPP1, *filaPP2, *filaPP3, *filaPP4, *filaPLevantamento;
    int cliente = 0 , nrClienteOcupaPA1, nrClienteOcupaPA2,nrClienteOcupaPA3, nrClienteOcupaPA4, nrClienteOcupaPA5, nrClienteOcupaPA6, nrClienteOcupaPA7, nrClienteOcupaPA8, nrClienteOcupaPA9, nrClienteOcupaPA10;
    


    //Percentagens intervalos de tempo
    float percPrimeiroP = 0.1;
    float percSegundoP = 0.3;
    float percTerceiroP = 0.15;
    float percQuartoP = 0.45;

    //Inserção nr Clientes
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
    
    int nClientesPrioritarios = trunc(0.05 * totalClientes);
    
    srand(time(NULL));

    tempoChegadaClientes(totalClientes, clientesPrimeiroP, clientesSegundoP, clientesTerceiroP, clientesQuartoP);
    tempoAtendimentoClientes(totalClientes, clientesTa1, clientesTa2, clientesTa3, clientesTa4, clientesTa5);
    tempoPagamentoClientes(nClientesCompram, totalClientes, nClientesTP1, nClientesTP2, nClientesTP3, nClientesTP4);
    tempoLevantamentoClientes(nClientesLevantaram, totalClientes, nClientesTL1, nClientesTL2, nClientesTL3, nClientesTL4);
    clientesPrioritarios(totalClientes, nClientesPrioritarios);
    for (int i = 0; i < totalClientes; i++) {
        printf("\n Cliente %d: [%d][%d][%d][%d][%d]", matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4], matriz[i][5]);
    }
    inicializacao(&clock, &evento, &nrCliente, &tempoProximaChegada, &estadoPA1, &estadoPA2, &estadoPA3, &estadoPA4, &estadoPA5, &estadoPA6, &estadoPA7, &estadoPA8, &estadoPA9, &estadoPA10, &tPartidaPA1, &tPartidaPA2, &tPartidaPA3, &tPartidaPA4, &tPartidaPA5, &tPartidaPA6, &tPartidaPA7, &tPartidaPA8, &tPartidaPA9, &tPartidaPA10, &estadoPP1, &estadoPP2, &estadoPP3, &estadoPP4, &tPartidaPP1, &tPartidaPP2, &tPartidaPP3, &tPartidaPP4, &estadoPL1, &estadoPL2, &tempoPartidaPL1, &tempoPartidaPL2, &tempoEspera, &filaPVendedores, &filaPP1, &filaPP2, &filaPP3, &filaPP4, &filaPLevantamento);


    while (TRUE) {
        
        gestaoTempo(tempoProximaChegada, tPartidaPA1, tPartidaPA2, tPartidaPA3, tPartidaPA4, tPartidaPA5, tPartidaPA6, tPartidaPA7, tPartidaPA8, tPartidaPA9, tPartidaPA10, &clock, &evento);
        //printf("TempoProximaChegada = %d \n tPartidaPA1 = %d \n tPartidaPA2 = %d \n tPartidaPA3 = %d \n tPartidaPA4 = %d \n tPartidaPA5 = %d \n tPartidaPA6 = %d \n tPartidaPA7 = %d \n tPartidaPA8 = %d \n tPartidaPA9 = %d \n tPartidaPA10 = %d \n clock = %d \n evento = %d \n", tempoProximaChegada, tPartidaPA1, tPartidaPA2, tPartidaPA3, tPartidaPA4, tPartidaPA5, tPartidaPA6, tPartidaPA7, tPartidaPA8, tPartidaPA9, tPartidaPA10, clock, evento);
        //printf("\n Clock: %d , Evento: %d , TPC: %d, ePA1: %d, tPtPA1: %d, ePA2: %d, tPtPA2: %d, ePA3: %d, tPtPA3: %d, ePA4: %d, tPtPA4: %d, ePA5: %d, tPtPA5: %d, ePA6: %d, tPtPA6: %d, ePA7: %d, tPtPA7: %d, ePA8: %d, tPtPA8: %d, ePA9: %d, tPtPA9: %d, ePA10: %d, tPtPA10: %d, tempoEspera: %d", clock, evento, tempoProximaChegada, estadoPA1, tPartidaPA1, estadoPA2, tPartidaPA2, estadoPA3, tPartidaPA3, estadoPA4, tPartidaPA4, estadoPA5, tPartidaPA5, estadoPA6, tPartidaPA6, estadoPA7, tPartidaPA7, estadoPA8, tPartidaPA8, estadoPA9, tPartidaPA9, estadoPA10, tPartidaPA10, tempoEspera);
        if (evento == -1) {
            break;
        }
        switch (evento) {
            case 0:
                numClientes++;
                eventoChegada(&cliente, clock, &estadoPA1, &estadoPA2, &estadoPA3, &estadoPA4, &estadoPA5, &estadoPA6, &estadoPA7, &estadoPA8, &estadoPA9, &estadoPA10, &filaPVendedores, &tempoProximaChegada, &tPartidaPA1, &tPartidaPA2, &tPartidaPA3, &tPartidaPA4, &tPartidaPA5, &tPartidaPA6, &tPartidaPA7, &tPartidaPA8, &tPartidaPA9, &tPartidaPA10, &nrClienteOcupaPA1, &nrClienteOcupaPA2, &nrClienteOcupaPA3, &nrClienteOcupaPA4, &nrClienteOcupaPA5, &nrClienteOcupaPA6, &nrClienteOcupaPA7, &nrClienteOcupaPA8, &nrClienteOcupaPA9, &nrClienteOcupaPA10);
                if (numClientes == totalClientes) {
                    tempoProximaChegada = Infinito;
                }
                break;
            case 1:
                eventoPartidaPA1(&nrClienteOcupaPA1, clock, &estadoPA1, &filaPVendedores, &tPartidaPA1, &tempoEspera);
                break;
            case 2:
                eventoPartidaPA2(&nrClienteOcupaPA2, clock, &estadoPA2, &filaPVendedores, &tPartidaPA2, &tempoEspera);
                break;
            case 3:
                eventoPartidaPA3(&nrClienteOcupaPA3, clock, &estadoPA3, &filaPVendedores, &tPartidaPA3, &tempoEspera);
                break;
            case 4:
                eventoPartidaPA4(&nrClienteOcupaPA4, clock, &estadoPA4, &filaPVendedores, &tPartidaPA4, &tempoEspera);
                break;
            case 5:
                eventoPartidaPA5(&nrClienteOcupaPA5, clock, &estadoPA5, &filaPVendedores, &tPartidaPA5, &tempoEspera);
                break;
            case 6:
                eventoPartidaPA6(&nrClienteOcupaPA6, clock, &estadoPA6, &filaPVendedores, &tPartidaPA6, &tempoEspera);
                break;
            case 7:
                eventoPartidaPA7(&nrClienteOcupaPA7, clock, &estadoPA7, &filaPVendedores, &tPartidaPA7, &tempoEspera);
                break;
            case 8:
                eventoPartidaPA8(&nrClienteOcupaPA8, clock, &estadoPA8, &filaPVendedores, &tPartidaPA8, &tempoEspera);
                break;
            case 9:
                eventoPartidaPA9(&nrClienteOcupaPA9, clock, &estadoPA9, &filaPVendedores, &tPartidaPA9, &tempoEspera);
                break;
            case 10:
                eventoPartidaPA10(&nrClienteOcupaPA10, clock, &estadoPA10, &filaPVendedores, &tPartidaPA10, &tempoEspera);
                break;
            default: terminar == 1;
        }
        if (terminar == 1) {
            break;
        }
        printf("NumClientes = %d", numClientes);
    }




    return (EXIT_SUCCESS);
}

