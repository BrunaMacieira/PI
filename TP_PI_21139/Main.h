#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 99
// ex: 0001 ; Paulo ; 123456789 ; 52
struct dados
{
    char numPraticante[5];
    char nome[200];
    int numTelefone;
    int idade;
};

// ex: 0001 ; 12-07-2022 ; Marcha ; 23 ; 2 ; km
struct atividades
{
    char numPraticante[5];
    char data[20];
    char nomeAtividade[50];
    int duracao;
    int valor;
    char unidade[5];
};

// ex: 0001 ; 01-01-2022 ; 20-01-2022 ; Marcha ; 15km
struct planoAt
{
    char numPraticante[5];
    char dataInicio[20];
    char dataFim[20];
    char nomeAtividade[50];
    int valor;
    char unidade[5];
};

// funcoes.c
void exercicio2(struct atividades atividades[], int atividadesLen, char nomeAtividade[], char dataI[], char dataF[]);
void exercicio3(struct dados praticantes[], int praticantesLen, struct atividades atividades[], int atividadesLen, char dataI[], char dataF[]);
void exercicio4(struct planoAt plano[], int planoLen, char tipo[], char dataI[], char dataF[]);
void exercicio5(struct atividades atividades[], int atividadesLen, struct dados praticantes[], int praticantesLen);
void exercicio6(struct planoAt planoAtividades[], int planoLen, struct dados praticantes[], int praticantesLen);
void exercicio7(int ex, struct dados praticantes[], int praticantesLen, struct atividades atividades[], int atividadesLen, struct planoAt plano[], int planoLen);
// auxiliar.c
int convertToDate(int dia, int mes, int ano);
