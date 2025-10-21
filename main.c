#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINHA 8
#define COLUNA 10
#define TAM_NOME 50

struct Sala
{
  char nomeFilme[TAM_NOME];
  int numeroSala;
  int sala[LINHA][COLUNA];
};

struct Sala salas[10];

void criarSala(int totalSalas)
{
  printf("Digite o nome do filme: ");
  fgets(salas[totalSalas].nomeFilme, TAM_NOME, stdin);
  salas[totalSalas].numeroSala = totalSalas;
  for (int i = 0; i < LINHA; i++)
  {
    for (int j = 0; j < COLUNA; j++)
    {
      salas[totalSalas].sala[i][j] = 0;
    }
  }
}
void mostrarSala(int sala[LINHA][COLUNA], int totalSala, int linhas, int colunas)
{
  printf("\n------------------------------\n");
  printf("Sala %d\n", salas[totalSala].numeroSala);
  printf("Filme: %s\n", salas[totalSala].nomeFilme);
  printf("    ");
  for (int i = 0; i < colunas; i++)
  {
    printf("%d  ", i + 1);
  }
  printf("\n");

  for (int i = 0; i < linhas; i++)
  {
    printf("%d   ", i + 1);
    for (int j = 0; j < colunas; j++)
    {
      printf("%d  ", sala[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  char user[10];
  char senha[10];
  int numeroSala;
  int totalSalas = 0;
  int op = 0;
  char entrada[10];

  printf("Digite seu usuario: \n");
  fgets(user, sizeof(user), stdin);
  user[strcspn(user, "\n")] = '\0';

  if (strcmp(user, "admin") == 0)
  {
    printf("Digite sua senha: \n");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';
    if (strcmp(senha, "1234") == 0)
    {
      do
      {
        system("cls");
        printf("Bem vindo ADM!\n");
        printf("Escolha o que deseja fazer\n");
        printf("1 - Criar sessao\n");
        printf("2 - Editar sessao\n");
        printf("3 - Ver sessoes\n");
        printf("4 - Excluir sessao\n");
        printf("5 - Sair\n");
        fgets(entrada, sizeof(entrada), stdin);
        int op = atoi(entrada);

        switch (op)
        {
        case 1:
          system("cls");
          criarSala(totalSalas);
          mostrarSala(salas[totalSalas].sala, totalSalas, LINHA, COLUNA);
          printf("\n*Linha > -- *Coluna ^\n");
          printf("1 - Assento reservado\n0 - Assento disponivel\n");
          totalSalas++;
          printf("Sala criada!\n");
          system("pause");
          break;

        case 2:
          printf("Digite o numero da sala que voce deseja alterar o filme: ");
          scanf("%d", &numeroSala);
          while (getchar() != '\n');

          for (int i = 0; i < totalSalas; i++)
          {
            if (salas[i].numeroSala == numeroSala)
            {
              printf("Digite o nome do novo filme: ");
              fgets(salas[i].nomeFilme, TAM_NOME, stdin);
              mostrarSala(salas[i].sala, i, LINHA, COLUNA);
            }
          }
          system("pause");  
          break;
        case 3:
          for (int i = 0; i < totalSalas; i++)
              {
                mostrarSala(salas[i].sala, i, LINHA, COLUNA);
              }
          system("pause");
          break;  
        case 4:
          printf("Digite o numero da sala que você deseja excluir o filme: ");
          scanf("%d", &numeroSala);
          while (getchar() != '\n');

          for (int i = 0; i < totalSalas; i++)
            {
              strcpy(salas[i].nomeFilme, "Sessao sem filme.");
            }
          printf("Sessao excluida!\n");
          system("pause");
          break;
        case 5:
          op = 5;
        break;
        default:
          printf("Opcao invalida!");
          system("pause");
          break;
        }
      } while (op != 5);
    }
    else
    {
      printf("Senha incorreta!");
    }
  }
  else
  {
    printf("Ola %s!", user);
    // TO DO: Implementar interface de usuario e suas respectivas funções
  }
  return 0;
}