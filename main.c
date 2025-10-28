#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINHA 8
#define COLUNA 10
#define TAM_NOME 50

struct User
{
  char nome[TAM_NOME];
  char senha[10];
  int indice;
  struct Sala *reserva;
};

struct Sala
{
  char nomeFilme[TAM_NOME];
  int numeroSala;
  int horario;
  int sala[LINHA][COLUNA];
  struct User *cinefilo;
};

struct User users[100];
struct Sala salas[5];

int verificarUser(char user[TAM_NOME], char senha[10], int totalUser)
{
  for (int i = 0; i < totalUser; i++)
  {
    if (strcmp(users[i].nome, user) == 0 && strcmp(users[i].senha, senha) == 0)
    {
      return i;
    }
  }
  return -1;
}

void mostrarUsers(int totalUsers)
{
  if (totalUsers > 0)
  {
    printf("Clientes cadastrados: \n");
    for (int i = 0; i < totalUsers; i++)
    {

      printf("ID: %d\n", users[i].indice);
      printf("Cliente: %s\n", users[i].nome);
      printf("Reserva: %s\n", users[i].reserva->nomeFilme);
      printf("-----------------------");
    }
  }
  else
  {
    printf("Nenhum usuario cadastrado! :(\n");
    system("pause");
  }
}

void criarSala(int totalSalas)
{
  char horarioTemp[10];

  printf("Digite o nome do filme: ");
  fgets(salas[totalSalas].nomeFilme, TAM_NOME, stdin);
  printf("Digite o horario da sessao: ");
  fgets(horarioTemp, sizeof(horarioTemp), stdin);
  salas[totalSalas].horario = atoi(horarioTemp);
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
  printf("Horario: %d horas\n", salas[totalSala].horario);
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
  char user[TAM_NOME];
  char senha[10];
  int totalUsers = 0;
  int userLogado = -1;
  int numeroSala;
  int totalSalas = 0;
  int op = 0;
  char entrada0[10];
  char entrada1[10];
  int sair = 0;

  do
  {
    system("cls");
    printf("1 - Login\n");
    printf("2 - Cadastrar-se\n");
    printf("3 - Sair\n");
    printf("Escolha uma opcao: ");
    fgets(entrada0, sizeof(entrada0), stdin);
    op = atoi(entrada0);

    switch (op)
    {
    case 1:
      printf("Digite seu usuario: \n");
      fgets(user, sizeof(user), stdin);
      user[strcspn(user, "\n")] = '\0';

      printf("Digite sua senha: \n");
      fgets(senha, sizeof(senha), stdin);
      senha[strcspn(senha, "\n")] = '\0';

      userLogado = verificarUser(user, senha, totalUsers);

      if (strcmp(user, "admin") == 0 && strcmp(senha, "1234") == 0)
      {
        do
        {
          system("cls");
          printf("Painel Admnistrativo CCinemork\n");
          printf("Escolha o que deseja fazer\n");
          printf("1 - Criar sessao\n");
          printf("2 - Editar sessao\n");
          printf("3 - Ver sessoes\n");
          printf("4 - Excluir sessao\n");
          printf("5 - Ver clientes\n");
          printf("6 - Sair\n");
          fgets(entrada1, sizeof(entrada1), stdin);
          op = atoi(entrada1);

          switch (op)
          {
          case 1:
            if (totalSalas < 5)
            {
              system("cls");
              criarSala(totalSalas);
              mostrarSala(salas[totalSalas].sala, totalSalas, LINHA, COLUNA);
              printf("\n*Linha > -- *Coluna ^\n");
              printf("1 - Assento reservado\n0 - Assento disponivel\n");
              totalSalas++;
              printf("Sala criada!\n");
              system("pause");
            }
            else
            {
              printf("Numero de salas excedido!\n");
              system("pause");
            }
            break;

          case 2:
            printf("Digite o numero da sala que voce deseja alterar o filme: ");
            scanf("%d", &numeroSala);
            while (getchar() != '\n')
              ;

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
            printf("Digite o numero da sala que voce deseja excluir o filme: ");
            scanf("%d", &numeroSala);
            while (getchar() != '\n')
              ;

            for (int i = 0; i < totalSalas; i++)
            {
              if (salas[i].numeroSala == numeroSala)
              {
                strcpy(salas[i].nomeFilme, "Sessao sem filme.");
              }
            }
            printf("Sessao excluida!\n");
            system("pause");
            break;
          case 5:
            mostrarUsers(totalUsers);
            break;
          case 6:
            op = 6;
            printf("Saindo...\n");
            system("pause");
            break;
          default:
            printf("Opcao invalida!");
            system("pause");
            break;
          }
        } while (op != 6);
      }
      else if (userLogado != -1)
      {
        char nomeFilmeUser[TAM_NOME];
        char entradaLinha[10];
        char entradaColuna[10];
        int linha, coluna;
        printf("Ola %s!\n", user);
        // TO DO: Implementar interface de usuario e suas respectivas funções
        // acessar sala disponivel
        // reservar assentos
        // cancelar reserva
        // sobre a ccinemork
        do
        {
          printf("Bem vindo ao CCinemork!\n");
          printf("1 - Acessar sessoes disponiveis\n");
          printf("2 - Reservar assento\n");
          printf("3 - Cancelar reserva\n");
          printf("4 - Sobre a CCinemrok\n");
          printf("5 - Sair\n");
          printf("Escolhna uma opcao: ");
          fgets(entrada1, sizeof(entrada1), stdin);
          op = atoi(entrada1);

          switch (op)
          {
          case 1:
            printf("Salas disponiveis: \n");
            if (totalSalas > 0)
            {
              for (int i = 0; i < totalSalas; i++)
              {
                mostrarSala(salas[i].sala, i, LINHA, COLUNA);
              }
              system("pause");
            }
            else
            {
              printf("Sem sessoes disponiveis! :(\n");
              system("pause");
            }
            break;
          case 2:
            system("cls");
            printf("Digite o nome do filme que deseja: ");
            fgets(nomeFilmeUser, sizeof(nomeFilmeUser), stdin);

            for (int i = 0; i < totalSalas; i++)
            {
              if (strcmp(salas[i].nomeFilme, nomeFilmeUser) == 0)
              {
                mostrarSala(salas[i].sala, i, LINHA, COLUNA);

                printf("Digite a linha que deseja reservar o assento: ");
                fgets(entradaLinha, sizeof(entradaLinha), stdin);
                printf("Digite a coluna que deseja reservar o assento: ");
                fgets(entradaColuna, sizeof(entradaColuna), stdin);

                linha = atoi(entradaLinha) - 1;
                coluna = atoi(entradaColuna) - 1;

                salas[i].sala[linha][coluna] = 1;
                users[userLogado].reserva = &salas[i];
                printf("Assento reservado!\n");
                system("pause");
              }
              else
              {
                printf("Nenhuma sessao com esse filme disponivel! :(\n");
                system("pause");
              }
            }
            break;
          case 3:
            if (totalSalas > 0)
            {
              char assentoLinha[1];
              char assentoColuna[1];
              system("cls");
              printf("Digite o nome do filme que deseja retirar sua reserva: ");
              fgets(nomeFilmeUser, sizeof(nomeFilmeUser), stdin);
              for (int i = 0; i < totalUsers; i++)
              {
                if (strcmp(users[userLogado].reserva->nomeFilme, nomeFilmeUser) == 0)
                {
                  mostrarSala(users[userLogado].reserva->sala, i, LINHA, COLUNA);

                  printf("Digite a linha do assento que deseja remover: ");
                  fgets(assentoLinha, sizeof(assentoLinha), stdin);
                  printf("Digite a coluna do assento que deseja remover: ");
                  fgets(assentoColuna, sizeof(assentoColuna), stdin);

                  linha = atoi(assentoLinha);
                  coluna = atoi(assentoColuna);

                  users[userLogado].reserva->sala[linha][coluna] = 0;
                  users[userLogado].reserva = NULL;
                  printf("Reserva excluida!\n");
                  system("pause");
                }
              }
            }
            else
            {
              printf("Sem sessoes disponiveis! :(\n");
              system("pause");
            }

            break;
          case 4:
            // ADICIONAR INFOS SOBRE A CCINEMORK
            printf("placeholder");
            break;
          case 5:
            op = 5;
            printf("Saindo...\n");
            system("pause");
            break;
          default:
            break;
          }
        } while (op != 5);
      }
      else
      {
        printf("Usuario nao cadastrado! :(\n");
        system("pause");
      }
      break;
    case 2:
      printf("Digite o seu nome de usuario:");
      fgets(user, sizeof(user), stdin);
      user[strcspn(user, "\n")] = '\0';
      printf("Digite sua senha: ");
      fgets(senha, sizeof(senha), stdin);
      senha[strcspn(senha, "\n")] = '\0';

      strcpy(users[totalUsers].nome, user);
      strcpy(users[totalUsers].senha, senha);
      printf("Cadastro Efetuado!\n");
      totalUsers++;
      system("pause");
      break;
    case 3:
      printf("Saindo...\n");
      system("pause");
      sair = 1;
      break;
    default:
      printf("Opcao invalida!\n");
      system("pause");
      break;
    }
  } while (sair == 0);
  return 0;
}
