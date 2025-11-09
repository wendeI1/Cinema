# 🎟️ CCinemork - Sistema de Gerenciamento de Cinema (em C)

> **Status: ⚠️ Em Desenvolvimento (Projeto Acadêmico)**
>
> Este projeto está sendo desenvolvido para o segundo semestre do curso de Ciência da Computação na [Universidade Braz Cubas](https://brazcubas.br/). O objetivo foi aplicar conceitos fundamentais de programação procedural, estruturas de dados e gerenciamento de memória em C.


---

## 💡 Conceito do Projeto

O CCinemork é um sistema de console, implementado em linguagem C, que simula as operações básicas de um cinema. O sistema é dividido em dois módulos principais: um **Painel Administrativo** para gerenciar as sessões e um **Painel do Cliente** para cadastro e reserva de assentos.

---

## ✨ Features (Funcionalidades)

### 👨‍💼 Painel Administrativo
Acesso via credenciais estáticas (`admin`/`1234`).
* **Criar Sessão:** Adiciona um novo filme, com horário e sala (limite de 5 salas).
* **Editar Sessão:** Altera o nome do filme de uma sessão existente.
* **Ver Sessões:** Exibe todas as sessões e o mapa de assentos (matriz 8x10).
* **Excluir Sessão:** Remove o filme de uma sessão.
* **Ver Clientes:** Lista todos os usuários cadastrados no sistema.

### 🧑 Painel do Cliente
* **Cadastro e Login:** Permite que novos clientes se cadastrem e acessem o sistema.
* **Acessar Sessões:** Visualiza os filmes em cartaz e seus mapas de assentos.
* **Reservar Assento:** Permite ao cliente escolher uma sessão e um assento vago (marcado com `0`).
* **Cancelar Reserva:** Libera um assento previamente reservado (marcado com `1`).

---

## 🛠️ Tecnologias e Conceitos Aplicados

* **Linguagem C**: Projeto 100% desenvolvido em C (padrão C99/C11).
* **Programação Procedural**: Organização do código em funções modulares.
* **Estruturas de Dados (`structs`)**: Uso de `struct User` e `struct Sala` para modelar os dados do domínio.
* **Arrays e Matrizes**: Uso de uma matriz 2D (`sala[LINHA][COLUNA]`) para representar o mapa de assentos.
* **Variáveis Globais**: Utilização de arrays globais para armazenar o estado dos usuários e salas durante a execução.
* **Ponteiros**: Uso de ponteiros na `struct User` para vincular um usuário à sua reserva (`struct Sala* reserva`).
* **Lógica de Console**: Interação com o usuário via `stdio.h` (funções `printf`, `fgets`).

---

## ⚠️ Limitações e Pontos de Melhoria

Este é um projeto acadêmico e possui limitações intencionais para focar nos conceitos da disciplina:

* **Persistência de Dados:** O sistema **não** salva dados em arquivos. Todas as informações (cadastros, sessões, reservas) são armazenadas em memória (variáveis globais) e perdidas ao fechar o programa.
* **Reservas Múltiplas:** A estrutura atual permite que um usuário tenha apenas uma reserva por vez.
* **Compatibilidade:** Utiliza `system("cls")` e `system("pause")`, que são específicos do Windows (prompt `cmd`).

---

## 🏁 Como Compilar e Executar

**Pré-requisitos:**
* Um compilador C (como GCC ou MinGW para Windows).

**Instruções (Usando GCC):**

1.  Clone o repositório.
2.  Abra seu terminal e navegue até a pasta do projeto.
3.  Compile o programa:
    ```bash
    gcc main.c -o cinemork
    ```
4.  Execute o arquivo gerado:
    * No Windows: `.\cinemork.exe`
    * No Linux/macOS: `./cinemork`
