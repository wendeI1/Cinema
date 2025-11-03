# CCinemork - Sistema de Gerenciamento de Cinema
Projeto do segundo semestre de Ciência da Computação na insituição de ensino Braz Cubas

`CCinemork` é um sistema simples de gerenciamento e reserva de assentos de cinema, implementado na linguagem C. Este projeto foi desenvolvido como uma aplicação de console para simular as operações básicas de um cinema, incluindo um painel administrativo e uma área para clientes.

O sistema permite o cadastro de usuários, login, criação de sessões de filmes, e a reserva ou cancelamento de assentos.

## 🚀 Funcionalidades

O sistema é dividido em dois painéis principais: Administrador e Cliente.

### Painel Administrativo

Acesso através do login:
* **Usuário:** `admin`
* **Senha:** `1234`

Funcionalidades disponíveis para o administrador:
* **Criar Sessão:** Adiciona um novo filme, com horário e número da sala (limite de 5 salas).
* **Editar Sessão:** Altera o nome do filme de uma sessão existente.
* **Ver Sessões:** Exibe todas as sessões cadastradas e o mapa de assentos (8x10).
* **Excluir Sessão:** Remove o filme de uma sessão (define o nome como "Sessao sem filme.").
* **Ver Clientes:** Lista todos os usuários cadastrados no sistema.

### Painel do Cliente

Acesso através de cadastro e login.

Funcionalidades disponíveis para o cliente:
* **Cadastrar-se:** Cria um novo perfil de usuário (nome e senha).
* **Login:** Acessa o painel do cliente.
* **Acessar Sessões Disponíveis:** Visualiza todos os filmes em cartaz e seus respectivos mapas de assentos.
* **Reservar Assento:** Permite ao usuário escolher um filme, uma linha e uma coluna para reservar um assento vago (marcado com `0`).
* **Cancelar Reserva:** Permite ao usuário remover uma reserva existente, liberando o assento (marcado com `1`).
* **Sobre:** Exibe uma breve descrição do projeto.

## 🛠️ Como Compilar e Executar

### Pré-requisitos
Para compilar e executar este projeto, você precisará de:
* Um compilador C (como **GCC** ou **MinGW** para Windows)

### Compilação (Usando GCC)

1.  Salve o código-fonte em um arquivo chamado `main.c`.
2.  Abra seu terminal ou prompt de comando.
3.  Navegue até o diretório onde você salvou o arquivo.
4.  Execute o seguinte comando para compilar o programa:

    ```bash
    gcc main.c -o cinemork
    ```

### Execução

* **No Windows:**
    ```bash
    .\cinemork.exe
    ```
    *(Ou simplesmente execute `cinemork`)*

* **No Linux/macOS:**
    ```bash
    ./cinemork
    ```

> **Nota:** O programa utiliza os comandos `system("cls")` e `system("pause")`, que são específicos do Windows. Para compatibilidade total com Linux/macOS, `system("cls")` deve ser substituído por `system("clear")` e `system("pause")` pode ser substituído por uma função que aguarda a entrada do usuário (como um `getchar()`).

## ⚙️ Estrutura do Código

### Constantes
* `LINHA`: Define o número de fileiras de assentos (8).
* `COLUNA`: Define o número de colunas de assentos (10).
* `TAM_NOME`: Define o tamanho máximo para nomes (50 caracteres).

### Structs
* `struct User`: Armazena os dados do cliente, incluindo nome, senha, índice e um ponteiro para a sala (`struct Sala* reserva`) onde fez sua reserva.
* `struct Sala`: Armazena os dados da sessão, incluindo nome do filme, número da sala, horário e a matriz de assentos (`sala[LINHA][COLUNA]`).

### Variáveis Globais
* `struct User users[100]`: Um array para armazenar até 100 usuários.
* `struct Sala salas[5]`: Um array para armazenar até 5 sessões de cinema.

### Principais Funções
* `verificarUser()`: Verifica se um usuário e senha correspondem a um registro no array `users`.
* `mostrarUsers()`: (Admin) Itera e exibe todos os usuários cadastrados.
* `criarSala()`: (Admin) Preenche os dados de uma nova `struct Sala` e inicializa seus assentos como vagos (`0`).
* `mostrarSala()`: Exibe os detalhes de uma sessão (filme, horário) e o mapa de assentos.
* `main()`: Contém o loop principal do programa, gerenciando os menus de login, cadastro, admin e cliente.

## ⚠️ Limitações Conhecidas

* **Persistência de Dados:** O sistema **não** salva dados em arquivos. Todas as informações (cadastros de usuários, sessões criadas e reservas) são armazenadas em memória (variáveis globais) e **são perdidas** assim que o programa é fechado.
* **Reservas Múltiplas:** A estrutura atual permite que um usuário tenha apenas **uma reserva** por vez (definida pelo ponteiro `users[i].reserva`).
* **Validação de Entrada:** A validação de entradas (como a escolha de assentos fora dos limites da matriz) é limitada.
