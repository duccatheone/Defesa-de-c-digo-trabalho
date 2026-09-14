# 📦 Sistema de Gerenciamento de Estoque

Projeto desenvolvido em **linguagem C** para a disciplina de **Algoritmos e Pensamento Computacional**, como parte da Atividade Prática Integrada.

O programa simula um sistema simples de gerenciamento de estoque, permitindo cadastrar produtos, buscar produtos pelo código e gerar um relatório com algumas estatísticas do estoque.

## 🎯 Objetivo

Aplicar, na prática, os principais conteúdos estudados na disciplina:

* Operadores e expressões;
* Estruturas de decisão;
* Estruturas de repetição;
* Vetores;
* Busca em vetor;
* Processamento de dados.

## ⚙️ Funcionalidades

O sistema possui um menu principal com as seguintes opções:

### 1. Cadastrar Produtos

Permite cadastrar **5 produtos**, informando:

* Código do produto;
* Quantidade disponível em estoque;
* Preço unitário.

### 2. Buscar Produto por Código

Permite informar o código de um produto e realizar uma **busca linear no vetor**.

Quando o produto é encontrado, o sistema apresenta:

* Código;
* Quantidade em estoque;
* Preço unitário;
* Valor total daquele produto em estoque.

### 3. Exibir Relatório e Estatísticas

Apresenta informações gerais do estoque, incluindo:

* Total de produtos cadastrados;
* Valor total acumulado no estoque;
* Produto de maior valor unitário.

### 4. Sair

Encerra o programa.

## 🧠 Conceitos utilizados

### Estruturas de decisão

Utilização de `if`, `else if` e `else` para controlar as opções do menu e verificar situações durante a execução.

### Estruturas de repetição

Utilização de `for` para percorrer os vetores e `do-while` para manter o menu principal em execução até que o usuário escolha sair.

### Vetores

São utilizados três vetores para armazenar os dados dos produtos:

* `codigos[]` — códigos dos produtos;
* `quantidades[]` — quantidades em estoque;
* `precos[]` — preços unitários.

### Busca

O sistema utiliza uma **busca linear** para localizar um produto pelo seu código.

### Processamento

Os dados cadastrados são processados para:

* Calcular o valor total do estoque;
* Identificar o produto com maior preço unitário.

## 📥 Entradas

Durante a execução, o usuário informa:

* Opção do menu;
* Código dos produtos;
* Quantidade em est
