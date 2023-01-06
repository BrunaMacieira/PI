#include "Main.h"

// o programa imprime caracteres em UTF-8. para permitir a correta leitura dos outputs, é aconselhado ativar 'CHCP 65001'

int main()
{
    struct dados praticante[N];
    struct atividades atividadeRealizada[N];
    struct planoAt plano[N];

    int i = 0, praticantesLen = 0, atividadesLen = 0, planosLen = 0;
    // O código abaixo é semelhante para as nossas 3 estruturas. Funciona da seguinte maneira:
    // O respetivo ficheiro é aberto (estão localizados em /dados/nomeFicheiro.csv)
    FILE *filePraticantes = fopen("dados/dados.csv", "r");
    // Vamos ler, linha a linha, o que está no ficheiro. No caso abaixo, os dados encontram-se na seguinte estrutura -> Numero ; Nome ; NumTelefone ; Idade
    while (fscanf(filePraticantes, "%s ; %s ; %d ; %d", &praticante[i].numPraticante, &praticante[i].nome, &praticante[i].numTelefone, &praticante[i].idade) != EOF)
    {
        // Esses dados são inseridos na estrutura, e passamos à próxima linha
        praticantesLen++;
        i++;
    }
    // Quando terminado, o ficheiro é fechado, e o valor de i é reposto a 0, para permitir a leitura dos seguintes ficheiros
    fclose(filePraticantes);
    i = 0;
    FILE *fileAtividadesRealizadas = fopen("dados/atividades.csv", "r");
    while (fscanf(fileAtividadesRealizadas, "%s ; %s ; %s ; %d ; %d ; %s", &atividadeRealizada[i].numPraticante, &atividadeRealizada[i].data, &atividadeRealizada[i].nomeAtividade, &atividadeRealizada[i].duracao, &atividadeRealizada[i].valor, &atividadeRealizada[i].unidade) != EOF)
    {
        atividadesLen++;
        i++;
    }
    fclose(fileAtividadesRealizadas);
    i = 0;
    FILE *filePlanoAtividades = fopen("dados/planoAt.csv", "r");
    while (fscanf(filePlanoAtividades, "%s ; %s ; %s ; %s ; %d ; %s", &plano[i].numPraticante, &plano[i].dataInicio, &plano[i].dataFim, &plano[i].nomeAtividade, &plano[i].valor, &plano[i].unidade) != EOF)
    {
        planosLen++;
        i++;
    }
    fclose(filePlanoAtividades);
    i = 0;
    // ------------------------------------------- Exercícios -------------------------------------------

    printf("--------------------------- Exercicio 2 ---------------------------\n");
    exercicio2(atividadeRealizada, atividadesLen, "Natacao", "01-01-2001", "28-12-2022");
    printf("--------------------------- Exercicio 3 ---------------------------\n");
    exercicio3(praticante, praticantesLen, atividadeRealizada, atividadesLen, "01-01-2001", "28-12-2022");
    printf("--------------------------- Exercicio 4 ---------------------------\n");
    exercicio4(plano, planosLen, "Natacao", "01-01-2001", "28-12-2022");
    printf("--------------------------- Exercicio 5 ---------------------------\n");
    exercicio5(atividadeRealizada, atividadesLen, praticante, praticantesLen);
    printf("--------------------------- Exercicio 6 ---------------------------\n");
    exercicio6(plano, planosLen, praticante, praticantesLen);
    printf("--------------------------- Exercicio 7 & 8 -----------------------\n");
    exercicio7(7, praticante, praticantesLen, atividadeRealizada, atividadesLen, plano, planosLen);
    exercicio7(8, praticante, praticantesLen, atividadeRealizada, atividadesLen, plano, planosLen);

    getchar();
    return 0;
}