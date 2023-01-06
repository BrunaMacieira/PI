#include "Main.h"

// Apresentação do número de praticantes que realizaram determinada atividade, num determinado período
void exercicio2(struct atividades atividades[], int atividadesLen, char nomeAtividade[], char dataI[], char dataF[])
{
    int diaI, diaF, diaT;
    int mesI, mesF, mesT;
    int anoI, anoF, anoT;

    int ans = 0;

    int totalI = 0;
    int totalF = 0;
    int totalT = 0;

    // Data é uma string. Para converter uma string do tipo "3" para o VALOR 3, é necessário subtrair-lhe 48 (tabela ASCII)
    // O dia / mês é uma string como "12". Para converter isto para 12,
    //é necessário converter ambos os dígitos (individualmente) para valores inteiros, multiplicar o primeiro (o dígito das dezenas) por 10, e somar ambos. (1 * 10 + 2 = 12)
    diaI = (dataI[0] - 48) * 10 + (dataI[1] - 48);
    mesI = (dataI[3] - 48) * 10 + (dataI[4] - 48);

    // A lógica acima também se aplica para o ano. (2012 = 2 * 1000 + 0 * 100 + 1 * 10 + 2 * 1)
    anoI = (dataI[6] - 48) * 1000 + (dataI[7] - 48) * 100 + (dataI[8] - 48) * 10 + (dataI[9] - 48) * 1;

    diaF = (dataF[0] - 48) * 10 + (dataF[1] - 48);
    mesF = (dataF[3] - 48) * 10 + (dataF[4] - 48);
    anoF = (dataF[6] - 48) * 1000 + (dataF[7] - 48) * 100 + (dataF[8] - 48) * 10 + (dataF[9] - 48) * 1;

    // Recebe um dia, mes e ano, e retorna o valor absoluto do dia no ano (ex: 15-03-2004 retorna: 31(JAN) + 28(FEV) + 1(ano bissexto) + 15 (MAR) = 75)
    totalI = convertToDate(diaI, mesI, anoI);
    totalF = convertToDate(diaF, mesF, anoF);

    int i;

    for (i = 0; i < atividadesLen; i++)
    {
        // A atividade que estamos a ver, é a que queremos encontrar?
        if (strcmp(atividades[i].nomeAtividade, nomeAtividade) == 0)
        {
            diaT = (atividades[i].data[0] - 48) * 10 + (atividades[i].data[1] - 48);
            mesT = (atividades[i].data[3] - 48) * 10 + (atividades[i].data[4] - 48);
            anoT = (atividades[i].data[6] - 48) * 1000 + (atividades[i].data[7] - 48) * 100 + (atividades[i].data[8] - 48) * 10 + (atividades[i].data[9] - 48) * 1;
            // O ano da atividade que estamos a ver, está dentro dos anos do limite?
            if (anoT >= anoI && anoT <= anoF)
            {
                totalT = convertToDate(diaT, mesT, anoT);
                // Se o valor absoluto do dia for entre o valor absoluto do intervalo selecionado, é uma resposta válida
                if (totalT >= totalI && totalT <= totalF)
                {
                    ans++;
                }
            }
        }
    }
    if (ans != 0)
    {
        printf("A atividade %s foi realizada %d vez%s entre %s e %s.\n", nomeAtividade, ans, ans > 1 ? "es" : "", dataI, dataF);
    }
    else
    {
        printf("A atividade %s não foi realizada entre %s e %s.\n", nomeAtividade, dataI, dataF);
    }
}

// Listagem dos praticantes, ordenada por ordem decrescente do número de praticante, que realizaram alguma atividade desportiva num determinado período
void exercicio3(struct dados praticantes[], int praticantesLen, struct atividades atividades[], int atividadesLen, char dataI[], char dataF[])
{

    int diaI, diaF, diaT;
    int mesI, mesF, mesT;
    int anoI, anoF, anoT;

    int ans = 0;

    int totalI = 0;
    int totalF = 0;
    int totalT = 0;

    diaI = (dataI[0] - 48) * 10 + (dataI[1] - 48);
    mesI = (dataI[3] - 48) * 10 + (dataI[4] - 48);
    anoI = (dataI[6] - 48) * 1000 + (dataI[7] - 48) * 100 + (dataI[8] - 48) * 10 + (dataI[9] - 48) * 1;

    diaF = (dataF[0] - 48) * 10 + (dataF[1] - 48);
    mesF = (dataF[3] - 48) * 10 + (dataF[4] - 48);
    anoF = (dataF[6] - 48) * 1000 + (dataF[7] - 48) * 100 + (dataF[8] - 48) * 10 + (dataF[9] - 48) * 1;

    totalI = convertToDate(diaI, mesI, anoI);
    totalF = convertToDate(diaF, mesF, anoF);

    int i;
    int p;
    for (i = 0; i < atividadesLen; i++)
    {
        for (p = praticantesLen; p >= 0; p--)
        {
            if (strcmp(atividades[i].numPraticante, praticantes[p].numPraticante) == 0)
            {
                diaT = (atividades[i].data[0] - 48) * 10 + (atividades[i].data[1] - 48);
                mesT = (atividades[i].data[3] - 48) * 10 + (atividades[i].data[4] - 48);
                anoT = (atividades[i].data[6] - 48) * 1000 + (atividades[i].data[7] - 48) * 100 + (atividades[i].data[8] - 48) * 10 + (atividades[i].data[9] - 48) * 1;
                if (anoT >= anoI && anoT <= anoF)
                {
                    totalT = convertToDate(diaT, mesT, anoT);
                    if (totalT >= totalI && totalT <= totalF)
                    {
                        printf("O praticante %s nº %s praticou %s no intervalo selecionado.\n", praticantes[p].nome, praticantes[p].numPraticante, atividades[i].nomeAtividade);
                    }
                }
            }
        }
    }
}

// Apresentar o plano de atividades de determinado tipo (Corrida, Natação, BTT, outra), para um determinado período e praticante
void exercicio4(struct planoAt plano[], int planoLen, char tipo[], char dataI[], char dataF[])
{
    int diaI, diaF, diaI1, diaF1;
    int mesI, mesF, mesI1, mesF1;
    int anoI, anoF, anoI1, anoF1;

    int ans = 0;

    int totalI = 0;
    int totalF = 0;
    int totalI1 = 0;
    int totalF1 = 0;

    diaI = (dataI[0] - 48) * 10 + (dataI[1] - 48);
    mesI = (dataI[3] - 48) * 10 + (dataI[4] - 48);
    anoI = (dataI[6] - 48) * 1000 + (dataI[7] - 48) * 100 + (dataI[8] - 48) * 10 + (dataI[9] - 48) * 1;

    diaF = (dataF[0] - 48) * 10 + (dataF[1] - 48);
    mesF = (dataF[3] - 48) * 10 + (dataF[4] - 48);
    anoF = (dataF[6] - 48) * 1000 + (dataF[7] - 48) * 100 + (dataF[8] - 48) * 10 + (dataF[9] - 48) * 1;

    totalI = convertToDate(diaI, mesI, anoI);
    totalF = convertToDate(diaF, mesF, anoF);

    int i;

    for (i = 0; i < planoLen; i++)
    {
        if (strcmp(plano[i].nomeAtividade, tipo) == 0)
        {
            diaI1 = (plano[i].dataInicio[0] - 48) * 10 + (plano[i].dataInicio[1] - 48);
            mesI1 = (plano[i].dataInicio[3] - 48) * 10 + (plano[i].dataInicio[4] - 48);
            anoI1 = (plano[i].dataInicio[6] - 48) * 1000 + (plano[i].dataInicio[7] - 48) * 100 + (plano[i].dataInicio[8] - 48) * 10 + (plano[i].dataInicio[9] - 48) * 1;

            diaF1 = (plano[i].dataFim[0] - 48) * 10 + (plano[i].dataFim[1] - 48);
            mesF1 = (plano[i].dataFim[3] - 48) * 10 + (plano[i].dataFim[4] - 48);
            anoF1 = (plano[i].dataFim[6] - 48) * 1000 + (plano[i].dataFim[7] - 48) * 100 + (plano[i].dataFim[8] - 48) * 10 + (plano[i].dataFim[9] - 48) * 1;

            if (anoI1 >= anoI && anoF1 <= anoF)
            {
                totalI1 = convertToDate(diaI1, mesI1, anoI1);
                totalF1 = convertToDate(diaF1, mesF1, anoF1);

                if (totalI <= totalI1 && totalF1 <= totalF)
                {
                    printf("%s foi praticado no intervalo %s - %s pelo praticante nº%s\n", plano[i].nomeAtividade, dataI, dataF, plano[i].numPraticante);
                }
            }
        }
    }
}

// Cálculo das médias dos tempos em que cada praticante esteve envolvido em atividades físicas
void exercicio5(struct atividades atividades[], int atividadesLen, struct dados praticantes[], int praticantesLen)
{
    // iteradores para as nossas estruturas (Praticantes e Atividades(realizadas), respetivamente)
    int indiceP;
    int indiceA;
    // total de segundos gasto em atividades por praticante
    float ans;
    // número de atividades realizadas por praticante
    int counter;
    // ver todos os praticantes
    for (indiceP = 0; indiceP < praticantesLen; indiceP++)
    {
        // reiniciar os contadores
        ans = 0;
        counter = 0;
        // ver todas as atividades realizadas
        for (indiceA = 0; indiceA < atividadesLen; indiceA++)
        {
            // encontramos uma atividade praticada pelo praticante
            if (strcmp(praticantes[indiceP].numPraticante, atividades[indiceA].numPraticante) == 0)
            {
                // contadores são incrementados
                ans += atividades[indiceA].duracao;
                counter++;
            }
        }
        printf("O praticante %s demorou cerca de %.2f segundos em média por atividade.\n", praticantes[indiceP].nome, ans / counter);
    }
}

// Gerar a tabela de atividades planeadas e realizadas para todos os praticantes
void exercicio6(struct planoAt planoAtividades[], int planoLen, struct dados praticantes[], int praticantesLen)
{
    // cabeçalho da tabela
    printf("Numero \t Nome \t Atividade \t Inicio \t Fim \t\t Valor \t Unidade\n");
    int indiceA;
    int indiceP;
    char nome[200];
    // iterar pelo plano das atividades
    for (indiceA = 0; indiceA < planoLen; indiceA++)
    {
        // não sabemos o nome do praticante
        strcpy(nome, "");
        for (indiceP = 0; indiceP < praticantesLen; indiceP++)
        {
            // encontramos o praticante que queremos
            if (strcmp(planoAtividades[indiceA].numPraticante, praticantes[indiceP].numPraticante) == 0)
            {
                // guardamos o nome do praticante
                strcpy(nome, praticantes[indiceP].nome);
            }
        }
        // imprimir a linha da tabela
        printf("%s \t %s \t %s \t %s \t %s \t %d \t %s\n", planoAtividades[indiceA].numPraticante, nome, planoAtividades[indiceA].nomeAtividade, planoAtividades[indiceA].dataInicio, planoAtividades[indiceA].dataFim, planoAtividades[indiceA].valor, planoAtividades[indiceA].unidade);
    }
}


// Ir a cada plano de atividades de cada praticante. Imprimir os dados das atividades (que se encontram no plano) realizadas por cada praticante
void exercicio7(int ex, struct dados praticantes[], int praticantesLen, struct atividades atividades[], int atividadesLen, struct planoAt plano[], int planoLen)
{
    // indices para iterações
    // pac -> paciente / AR -> atividadesRealizadas / plano -> plano
    int indicePac;
    int indiceAR;
    int indicePlano;

    int maxVal = 0;
    char maxData[20];
    char nome[200];

    int tempo = 0;
    int total = 0;

    char aux[20];
    char ans[5000];

    FILE *ex8 = fopen("ex8.bin", "w");
    if (ex == 7)
    {
        printf("Numero \t Nome \t Inicio \t Fim \t\t Total \t Tempo \t Dia D \t\n");
    }
    for (indicePlano = 0; indicePlano < planoLen; indicePlano++)
    {
        total = 0;
        tempo = 0;
        for (indicePac = 0; indicePac < praticantesLen; indicePac++)
        {
            if (strcmp(plano[indicePlano].numPraticante, praticantes[indicePac].numPraticante) == 0)
            {
                for (indiceAR = 0; indiceAR < atividadesLen; indiceAR++)
                {
                    // encontramos uma atividade realizada pelo praticante, que pertence ao plano
                    if (strcmp(atividades[indiceAR].numPraticante, praticantes[indicePac].numPraticante) == 0 && strcmp(atividades[indiceAR].nomeAtividade, plano[indicePlano].nomeAtividade) == 0)
                    {
                        total += atividades[indiceAR].valor;
                        // guardar a unidade do valor
                        strcpy(aux, atividades[indiceAR].unidade);
                        tempo += atividades[indiceAR].duracao;
                        // é o dia em que foi colocado mais esforço?
                        if (atividades[indiceAR].valor > maxVal)
                        {
                            maxVal = atividades[indiceAR].valor;
                            strcpy(maxData, atividades[indiceAR].data);
                        }
                    }
                }
                if (ex == 7)
                {
                    printf("%s \t %s \t %s \t %s \t %d%s \t %d \t %s \t\n", praticantes[indicePac].numPraticante, praticantes[indicePac].nome, plano[indicePlano].dataInicio, plano[indicePlano].dataFim, total, aux, tempo, maxData);
                }
                else
                {
                    fprintf(ex8, "%s \t %s \t %s \t %s \t %d%s \t %d \t %s \t\n", praticantes[indicePac].numPraticante, praticantes[indicePac].nome, plano[indicePlano].dataInicio, plano[indicePlano].dataFim, total, aux, tempo, maxData);
                }
            }
        }
    }
}