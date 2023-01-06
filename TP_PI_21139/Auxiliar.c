#include "Main.h"

// recebe um dia, mes e ano. Retorna a posição absoluta do dia no ano. Ex -> 1 janeiro retorna 1. 12 de fevereiro retorna 31+12 = 43 (43º dia do ano)
int convertToDate(int dia, int mes, int ano)
{
    int total = 0;
    int bissexto = 0;

    if (ano % 4 == 0)
    {
        bissexto = 1;
    }

    mes -= 1;
    total += dia;
    if (mes >= 1)
    {
        total += 31;
    }
    if (mes >= 2)
    {
        total += 28;
        if (bissexto)
        {
            total += 1;
        }
    }
    if (mes >= 3)
    {
        total += 31;
    }
    if (mes >= 4)
    {
        total += 30;
    }
    if (mes >= 5)
    {
        total += 31;
    }
    if (mes >= 6)
    {
        total += 30;
    }
    if (mes >= 7)
    {
        total += 31;
    }
    if (mes >= 8)
    {
        total += 31;
    }
    if (mes >= 9)
    {
        total += 30;
    }
    if (mes >= 10)
    {
        total += 31;
    }
    if (mes >= 11)
    {
        total += 30;
    }
    return total;
}