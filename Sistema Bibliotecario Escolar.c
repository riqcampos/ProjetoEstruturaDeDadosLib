#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "clientF.h"
#include "disponiveis.h"
#include "locados.h"

#define Tam_Assunto 101
#define Tam_Nome 51

/*Nas funções 8 função abaixo onde tais emprestam e devolvem os livros, a pequena dificuldade não foi na construção de um código funcional
que alterasse as lista para coseguir realizar uma devlução ou um empréstimo de um livro, mas sim, a dificuldade pelo qual enfrentamos, foi
em fazer o código funcionar dentro de uma função void, já que após divérsas pesquisas, a manipulação de listas dentro de uma função void
na qual estavamos tentando fazer, não deveria receber o ponteiro da lista, mas sim, um duplo ponteiro da lista. Portanto, após uma breve
modificação na lógica dos códigos abaixo, nas váriaveis de parâmetro e na chamada de cada função, enfim, a modificação das listas usando cada
função foi concluida, e assim conseguimos realizar as modificações nas listas dentro da função. */

//Abaixo estão todas as funções usadas para realizar o empréstimo de livros.
void emprestimo_codigo_cliente_e_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, int codigo_livro)
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(L_Disponiveis1->cd_registro == codigo_livro)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

void emprestimo_codigo_cliente_titulo_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, char titulo[])
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(strcmp(titulo, L_Disponiveis1->Titulo) == 0)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

void emprestimo_nome_cliente_e_codigo_Livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome_cliente[], int codigo_livro)
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome_cliente, cliente1->Nome) == 0)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(L_Disponiveis1->cd_registro == codigo_livro)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

void emprestimo_nome_cliente_e_Livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome_cliente[], char titulo[])
{
    Livros_Disponiveis *aux1, *L_Disponiveis1, *aux2;
    Cliente *aux3, *cliente1;
    Livros_Emprestados *L_Emprestados1;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome_cliente, cliente1->Nome) == 0)
        {
            for(; L_Disponiveis1 != NULL; L_Disponiveis1 = L_Disponiveis1->prox)
            {
                if(strcmp(titulo, L_Disponiveis1->Titulo) == 0)
                {
                    L_Emprestados1 = Inputar_Emprestados_Ordenadamente(L_Emprestados1, cliente1->cd_Identificacao, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                    aux2 = Aux_Disp(aux2, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
                else
                {
                    aux1 = Inputar_Disponivel_Ordenadamente(aux1, L_Disponiveis1->cd_registro, L_Disponiveis1->Titulo, L_Disponiveis1->Assunto, L_Disponiveis1->Autor);
                }
            }
        }
        aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
        if(cliente1->Emprestimo != NULL)
        {
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
        if(aux2 != NULL)
        {
            aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
            aux2 = aux2->prox;
        }
    }
    *L_Disponiveis = aux1;
    *cliente = aux3;
    *L_Emprestados = L_Emprestados1;
}

//Abaixo estão todas as funções usadas para realizar a devolução do livros.
void devolucao_codigo_cliente_e_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, int codigo_livro)
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(L_Emprestados1->Cd_Identificacao_Livro_Emprestado == codigo_livro)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, codigo_livro, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(cliente1->Emprestimo->cd_registro != codigo_livro)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
            
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

void devolucao_codigo_cliente_titulo_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, int codigo_cliente, char titulo[])
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(cliente1->cd_Identificacao == codigo_cliente)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(strcmp(titulo, L_Emprestados1->Titulo) == 0)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(strcmp(titulo, cliente1->Emprestimo->Titulo) != 0)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

void devolucao_nome_cliente_e_codigo_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome[], int codigo_livro)
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome, cliente1->Nome) == 0)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(L_Emprestados1->Cd_Identificacao_Livro_Emprestado == codigo_livro)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(L_Emprestados1->Cd_Identificacao_Livro_Emprestado != codigo_livro)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

void devolucao_nome_cliente_e_livro(Livros_Disponiveis **L_Disponiveis, Livros_Emprestados **L_Emprestados, Cliente **cliente, char nome[], char titulo[])
{
    Livros_Emprestados *aux1, *L_Emprestados1;
    Cliente *aux3, *cliente1;
    Livros_Disponiveis *L_Disponiveis1, *aux2;
    int identificador;
    identificador = 0;
    aux1 = NULL;
    aux2 = NULL;
    aux3 = NULL;
    L_Disponiveis1 = *L_Disponiveis;
    cliente1 = *cliente;
    L_Emprestados1 = *L_Emprestados;

    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        if(strcmp(nome, cliente1->Nome) == 0)
        {
            identificador++;
            for(; L_Emprestados1 != NULL; L_Emprestados1 = L_Emprestados1->prox)
            {
                if(strcmp(titulo, L_Emprestados1->Titulo) == 0)
                {
                    L_Disponiveis1 = Inputar_Disponivel_Ordenadamente(L_Disponiveis1, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
                else
                {
                    aux1 = Inputar_Emprestados_Ordenadamente(aux1, L_Emprestados1->Cd_Identificacao_Cliente, L_Emprestados1->Cd_Identificacao_Livro_Emprestado, L_Emprestados1->Titulo, L_Emprestados1->Assunto, L_Emprestados1->Autor);
                }
            }
        }
        if(identificador != 0)
        {
            identificador = 0;
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                if(strcmp(titulo, cliente1->Emprestimo->Titulo) != 0)
                {
                    aux2 = Aux_Disp(aux2, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
                    aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, aux2->cd_registro, aux2->Titulo, aux2->Assunto, aux2->Autor);
                }
            }
        }
        else
        {
            aux3 = Aux_Cliente(aux3, cliente1->cd_Identificacao, cliente1->Nome);
            for(; cliente1->Emprestimo != NULL; cliente1->Emprestimo = cliente1->Emprestimo->prox)
            {
                aux3->Emprestimo = Inputar_Disponivel_Ordenadamente(aux3->Emprestimo, cliente1->Emprestimo->cd_registro, cliente1->Emprestimo->Titulo, cliente1->Emprestimo->Assunto, cliente1->Emprestimo->Autor);
            }
        }
    }
    *L_Disponiveis = L_Disponiveis1;
    *cliente = aux3;
    *L_Emprestados = aux1;
}

//A função abaixo realiza a visualização mais detalhada dos livros Emprestado pelo codigo. Caso o cliente não tenha alugado o livro, a função também avisará do mesmo
void print_Livro_Emprestado_codigo(Livros_Emprestados *L_Emprestado, Livros_Disponiveis *L_Disponivel, int codigo)
{
    int identificador;
    identificador = 0;
    if(L_Emprestado == NULL)
    {
        printf("Não há nenhum livro emprestado na biblioteca. Já que,  ");
    }
    else
    {
        for(; L_Emprestado != NULL; L_Emprestado = L_Emprestado->prox)
        {
            if(L_Emprestado->Cd_Identificacao_Livro_Emprestado == codigo)
            {
                printf("Código do Livro: %i\n", L_Emprestado->Cd_Identificacao_Livro_Emprestado);
                printf("\tCódigo do Cliente que alugou o livro: %i\n", L_Emprestado->Cd_Identificacao_Cliente);
                printf("\tTítulo do livro: %s\n", L_Emprestado->Titulo);
                printf("\tAssunto do livro: %s\n", L_Emprestado->Assunto);
                printf("\tAutor do Livro: %s\n\n", L_Emprestado->Autor);
                identificador++;
                break;
            }
        }
    }
    if(identificador == 0)
    {
        for(; L_Disponivel != NULL; L_Disponivel = L_Disponivel->prox)
        {
            if(L_Disponivel->cd_registro == codigo)
            {
                printf("o livro está disponível para ser alugado na biblioteca\n\n");
                identificador++;
                break;
            }
        }
        if(identificador == 0)
        {
            printf("o livro do código %i, não está cadastrado no sistema.\n\n", codigo);
        }
    }
}

//A função abaixo realiza a visualização mais detalhada dos livros Emprestado pelo titulo. Caso o cliente não tenha alugado o livro, a função também avisará do mesmo
void print_Livro_Emprestado_titulo(Livros_Emprestados *L_Emprestado, Livros_Disponiveis *L_Disponivel, char titulo[])
{
    int identificador;
    identificador = 0;
    if(L_Emprestado == NULL)
    {
        printf("Não há nenhum livro emprestado na biblioteca. Já que,  ");
    }
    else
    {
        for(; L_Emprestado != NULL; L_Emprestado = L_Emprestado->prox)
        {
            if(strcmp(L_Emprestado->Titulo, titulo) == 0)
            {
                printf("Código do Livro: %i\n", L_Emprestado->Cd_Identificacao_Livro_Emprestado);
                printf("\tCódigo do Cliente que alugou o livro: %i\n", L_Emprestado->Cd_Identificacao_Cliente);
                printf("\tTítulo do livro: %s\n", L_Emprestado->Titulo);
                printf("\tAssunto do livro: %s\n", L_Emprestado->Assunto);
                printf("\tAutor do Livro: %s\n\n", L_Emprestado->Autor);
                identificador++;
                break;
            }
        }
    }
    if(identificador == 0)
    {
        for(; L_Disponivel != NULL; L_Disponivel = L_Disponivel->prox)
        {
            if(strcmp(L_Disponivel->Titulo, titulo) == 0)
            {
                printf("o livro está disponível para ser alugado na biblioteca\n\n");
                identificador++;
                break;
            }
        }
        if(identificador == 0)
        {
            printf("o livro com o título \"%s\", não está cadastrado no sistema.\n\n", titulo);
        }
    }
}

//Função que altera o titulo do livro que esta na lista de emprestimo e cliente.
void Editar_titulo_livros_emprestados_e_cliente(Livros_Emprestados **L_Emprestado, Cliente **cliente, int codigo, char titulo[])
{
    Livros_Disponiveis *aux;
    Livros_Emprestados *L_Emprestado1, *aux2;
    Cliente *cliente1, *aux1;
    cliente1 = *cliente;
    L_Emprestado1 = *L_Emprestado;
    aux = NULL;
    aux1 = NULL;
    aux2 = NULL;

    for(; L_Emprestado1 != NULL; L_Emprestado1 = L_Emprestado1->prox)
    {
        if(L_Emprestado1->Cd_Identificacao_Livro_Emprestado == codigo)
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
        else
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
    }
    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        aux1 = Aux_Cliente(aux1, cliente1->cd_Identificacao, cliente1->Nome );
        aux = cliente1->Emprestimo;
        for(; aux != NULL; aux = aux->prox)
        {
            if(aux->cd_registro == codigo)
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, titulo, aux->Assunto, aux->Autor);
            }
            else
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, aux->Autor);
            }
        }
    }
    aux1 = Ordenamento_Cliente(aux1);
    *L_Emprestado = aux2;
    *cliente = aux1;
}

//Função que altera o assunto do livro que esta na lista de emprestimo e cliente.
void Editar_assunto_livros_emprestados_e_cliente(Livros_Emprestados **L_Emprestado, Cliente **cliente, int codigo, char assunto[])
{
    Livros_Disponiveis *aux;
    Livros_Emprestados *L_Emprestado1, *aux2;
    Cliente *cliente1, *aux1;
    cliente1 = *cliente;
    L_Emprestado1 = *L_Emprestado;
    aux = NULL;
    aux1 = NULL;
    aux2 = NULL;

    for(; L_Emprestado1 != NULL; L_Emprestado1 = L_Emprestado1->prox)
    {
        if(L_Emprestado1->Cd_Identificacao_Livro_Emprestado == codigo)
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, assunto, L_Emprestado1->Autor);
        }
        else
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
    }
    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        aux1 = Aux_Cliente(aux1, cliente1->cd_Identificacao, cliente1->Nome );
        aux = cliente1->Emprestimo;
        for(; aux != NULL; aux = aux->prox)
        {
            if(aux->cd_registro == codigo)
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, assunto, aux->Autor);
            }
            else
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, aux->Autor);
            }
        }
    }
    aux1 = Ordenamento_Cliente(aux1);
    *L_Emprestado = aux2;
    *cliente = aux1;
}

//Função que altera o autor do livro que esta na lista de emprestimo e cliente.
void Editar_autor_livros_emprestados_e_cliente(Livros_Emprestados **L_Emprestado, Cliente **cliente, int codigo, char autor[])
{
    Livros_Disponiveis *aux;
    Livros_Emprestados *L_Emprestado1, *aux2;
    Cliente *cliente1, *aux1;
    cliente1 = *cliente;
    L_Emprestado1 = *L_Emprestado;
    aux = NULL;
    aux1 = NULL;
    aux2 = NULL;

    for(; L_Emprestado1 != NULL; L_Emprestado1 = L_Emprestado1->prox)
    {
        if(L_Emprestado1->Cd_Identificacao_Livro_Emprestado == codigo)
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, autor);
        }
        else
        {
            aux2 = Inputar_Emprestados_Ordenadamente(aux2, L_Emprestado1->Cd_Identificacao_Cliente, L_Emprestado1->Cd_Identificacao_Livro_Emprestado, L_Emprestado1->Titulo, L_Emprestado1->Assunto, L_Emprestado1->Autor);
        }
    }
    for(; cliente1 != NULL; cliente1 = cliente1->prox)
    {
        aux1 = Aux_Cliente(aux1, cliente1->cd_Identificacao, cliente1->Nome );
        aux = cliente1->Emprestimo;
        for(; aux != NULL; aux = aux->prox)
        {
            if(aux->cd_registro == codigo)
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, autor);
            }
            else
            {
                aux1->Emprestimo = Inputar_Disponivel_Ordenadamente(aux1->Emprestimo, aux->cd_registro, aux->Titulo, aux->Assunto, aux->Autor);
            }
        }
    }
    aux1 = Ordenamento_Cliente(aux1);
    *L_Emprestado = aux2;
    *cliente = aux1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //Abaixo está a declaração das variáveis.
    Livros_Disponiveis *L_D;
    Livros_Emprestados *Livro_emprestado;
    Cliente *cliente;
    int opcao, opcao2, Codigo_Cliente, Codigo_Livro, identificador, i, cd_aux_cliente, cd_aux_Disponivel;
    char nome[Tam_Nome], titulo[Tam_Nome], assunto[Tam_Assunto], autor[Tam_Nome], res[1];

    Codigo_Cliente = 0;
    Codigo_Livro = 0;
    L_D = NULL;
    Livro_emprestado = NULL;
    cliente = NULL;

    printf("BEM VINDO À CENTRAL BIBLIOTECÁRIA!!!\n\n");
    while(1)
    {
        printf("Escolha uma das opções abaixo:\n");
        printf("\t1) Cadastro de novo livro.\n");
        printf("\t2) Cadastro de cliente.\n");
        printf("\t3) Realizar emprestimo de livro.\n");
        printf("\t4) Realizar devolução de livro.\n");
        printf("\t5) Visualização de livros emprestados.\n");
        printf("\t6) Visualização de livros disponíveis na Biblioteca.\n");
        printf("\t7) Visualização de lista de clientes.\n");
        printf("\t8) Editar cadastro de cliente ou Livros.\n");
        printf("\t9) Sair da Central.\n\n");
        printf("Digite o número da opcão desejada: ");
        scanf("%i", &opcao);
        identificador = 0;

        if(opcao == 1)
        {
            //Aqui está sendo realizado o cadastro de um novo livro.
            do
            {
                system("cls");
                Codigo_Livro++;
                while(1)
                {
                    printf("Digite o título do Livro: ");
                    fflush(stdin);
                    gets(titulo);
                    if(titulo[0] == ' ')
                    {
                        printf("\nOOOPS!! No início da digitação, há um espaço em branco.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }
                    if(Identificador_livro_existente(L_D, titulo))
                    {
                        printf("O Livro já é existente no catálogo.\n\n");
                        system("pause");
                        system("cls");
                        identificador++;
                        Codigo_Livro--;
                        break;
                    }
                    break;
                }
                while(identificador == 0)
                {
                    printf("Digite o assunto do livro: ");
                    fflush(stdin);
                    gets(assunto);
                    if(assunto[0] == ' ')
                    {
                        printf("\nOOOPS!!! tem um espaço vazio no início da digitação.\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite o título do Livro: %s\n", titulo);
                        continue;
                    }
                    
                    break;
                }
                while(identificador == 0)
                {
                    printf("Digite o nome do autor(a) do livro: ");
                    fflush(stdin);
                    gets(autor);

                    if(autor[0] == ' ')
                    {
                        printf("\nOOOPS!!! Há um espaço vazio no início do nome.\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite o título do Livro: %s\n", titulo);
                        printf("Digite o assunto do livro: %s\n", assunto);
                        continue;
                    }
                    for(i = 0; autor[i] != '\0'; i++)
                    {
                        if(isdigit(autor[i]))
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador != 0)
                    {
                        identificador = 0;
                        printf("\nOOOPS!!! Não se pode colocar número ou símbolos em um assunto de um livro.\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite o título do Livro: %s\n", titulo);
                        printf("Digite o assunto do livro: %s\n", assunto);
                        continue;
                    }
                    break;
                }
                if(identificador == 0)
                {
                    autor[0] = toupper(autor[0]);
                    if(isdigit(titulo[0]) == 0)
                    {
                        titulo[0] = toupper(titulo[0]);
                    }
                    assunto[0] = toupper(assunto[0]);
                    for(i = 1; autor[i] != '\0'; i++)
                    {
                        if(isdigit(titulo[i]) == 0)
                        {
                            titulo[i] = tolower(titulo[i]);
                        }
                        autor[i] = tolower(autor[i]);
                    }
                    for(i = 1; assunto[i] != '\0'; i++)
                    {
                        assunto[i] = tolower(assunto[i]);
                    }
                    L_D = Inputar_Disponivel_Ordenadamente(L_D, Codigo_Livro, titulo, assunto, autor);
                    system("cls");
                    printf("O livro \"%s\" do autor(a) \"%s\" foi cadastrado com sucesso!!\n", titulo, autor);
                    printf("O código do livro é: %i\n\n", Codigo_Livro);
                    printf("ATENÇÃO: Para realizar uma alteração de qualquer informação do livro, será solicitado o código do mesmo!!\n\n");
                    system("pause");
                }
                identificador = 0;
                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo: \n");
                    printf("\t1) Cadastrar um novo livro.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite escolha uma das opções acima: ");
                    scanf("%i", &opcao);

                    if(opcao == 1 || opcao == 2)
                    {
                        break;
                    }
                    else
                    {
                        printf("Digitação inválida, por favor tente novamente.\n\n");
                        system("pause");
                        continue;
                    }
                }
            }while(opcao == 1);

            system("cls");
            continue;
        }
        //Abaixo está sendo cadastrado um novo cliente.
        if(opcao == 2)
        {
            do
            {
                system("cls");
                Codigo_Cliente++;
                //Abaixo estamos solicitando o nome do cliente para seu cadastro
                while(1)
                {
                    printf("Digite o nome do(a) cliente: ");
                    fflush(stdin);
                    gets(nome);
                    if(Identificador_Clientes_Existentes(cliente, nome))
                    {
                        printf("OOOPS!!! O(A) cliente já foi cadastrado no sistema.\n\n");
                        system("pause");
                        system("cls");
                        Codigo_Cliente--;
                    }
                    if(nome[0] == ' ')
                    {
                        printf("OOPS!! Há um espaço no começo da digitação.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }
                    for(i = 0; nome[i] != '\0'; i++)
                    {
                        if(isdigit(nome[i]))
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador != 0)
                    {
                        identificador = 0;
                        printf("Há um número ou símbolo na digitação do nome do(a) cliente, por favor, reescreva o nome.\n\n");
                        system("pause");
                        system("cls");
                        continue;
                    }
                    nome[0] = toupper(nome[0]);
                    for(i = 1; nome[i] != '\0'; i++)
                    {
                        nome[i] = tolower(nome[i]);
                    }
                    break;
                }
                cliente = Aux_Cliente(cliente, Codigo_Cliente, nome);
                cliente = Ordenamento_Cliente(cliente);
                system("cls");
                printf("O cliente \"%s\" foi cadastrado com sucesso!!\n", nome);
                printf("O código do cliente é: %i\n", Codigo_Cliente);
                printf("\nATENÇÃO: Para realizar uma alteração do nome do cliente, será necessário saber o código do mesmo.\n\n");
                system("pause");
                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo: \n");
                    printf("\t1) Cadastrar outro cliente.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite ao lado o número da opção desejada: ");
                    scanf("%i", &opcao);

                    if(opcao == 1 || opcao == 2)
                    {
                        break;
                    }
                    printf("OOOPS!! O número digitado, não condiz com o solicitado.\n\n");
                    system("pause");
                }
            }while(opcao == 1);
            system("cls");
            continue;
        }

        //Abaixo iá ser realizado o processo de empréstimo de um livro
        if(opcao == 3 || opcao == 4)
        {
            do
            {
                while(1)
                {
                    system("cls");
                    if(opcao == 3)
                    {
                        printf("Escolha como deseja procurar o cliente que irá realizar o empréstimo do livro.\n");
                    }
                    else
                    {
                        printf("Escolha como deseja procurar o cliente que irá realizar a devolução do livro.\n");
                    }
                    printf("\t1) Código do cliente.\n");
                    printf("\t2) Nome do cliente.\n\n");
                    printf("Digite a opção desejada: ");
                    scanf("%i", &opcao2);

                    if(opcao2 == 1 || opcao2 == 2)
                    {
                        break;
                    }
                    printf("O número digitado não condiz com o solicitado.\n\n");
                    system("pause");
                }
                if(opcao2 == 1)
                {
                    while(1)
                    {
                        system("cls");
                        printf("Digite o codigo do cliente: ");
                        scanf("%i", &cd_aux_cliente);
                        if(Identificador_Clientes_Existentes_codigo(cliente, cd_aux_cliente))
                        {
                            break;
                        }
                        system("cls");
                        printf("Código do cliente não encontrado no sistema.\n");
                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar novamente uma digitação: ");
                        scanf("%s", &res[0]);
                        res[0] = toupper(res[0]);
                        if(res[0] == 'N')
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador == 0)
                    {
                        while(1)
                        {
                            system("cls");
                            if(opcao == 3)
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será emprestado.\n");
                            }
                            else
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será devolvido.\n");
                            }
                            printf("\t1) Código do livro.\n");
                            printf("\t2) Título do livro.\n");
                            printf("Digite a opção desejada ao lado: ");
                            scanf("%i", &opcao2);;

                            if(opcao2 == 1 || opcao2 == 2)
                            {
                                break;
                            }
                            printf("OOOPS!! Digite apenas 1 ou 2 para realizae a busca pelo livro emprestado.\n\n");
                            system("pause");
                        }
                        if(opcao2 == 1)
                        {
                            do
                            {
                                system("cls");
                                printf("Digite o código do livro: ");
                                scanf("%i", &cd_aux_Disponivel);
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        printf("O livro já foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        printf("Este livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);
                            }while(res[0] != 'N');
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_codigo_cliente_e_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_codigo_cliente_e_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                        else
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Digite o título do livro: ");
                                fflush(stdin);
                                gets(titulo);
                                if(isdigit(titulo[0]) == 0)
                                {
                                    titulo[0] = toupper(titulo[0]);
                                }
                                for(i = 1; titulo[i]!= '\0'; i++)
                                {
                                    if(isdigit(titulo[i]) == 0)
                                    {
                                        titulo[i] = tolower(titulo[i]);
                                    }
                                }
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        printf("O livro já foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! Não há livro com esse títilo é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        printf("O Livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O título do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);

                                if(res[0] == 'N')
                                {
                                    break;
                                }
                            }
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_codigo_cliente_titulo_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_codigo_cliente_titulo_livro(&L_D, &Livro_emprestado, &cliente, cd_aux_cliente, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                    }
                    else
                    {
                        identificador = 0;
                    }
                }
                else
                {
                    while(1)
                    {
                        system("cls");
                        printf("Digite o nome do cliente: ");
                        fflush(stdin);
                        gets(nome);
                        nome[0] = toupper(nome[0]);
                        for(i = 1; nome[i]!= '\0'; i++)
                        {
                            nome[i] = tolower(nome[i]);
                        }
                        if(Identificador_Clientes_Existentes(cliente, nome))
                        {
                            break;
                        }
                        system("cls");
                        printf("Nome do cliente não encontrado no sistema.\n");
                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar novamente uma digitação: ");
                        scanf("%s", &res[0]);
                        res[0] = toupper(res[0]);
                        if(res[0] == 'N')
                        {
                            identificador++;
                            break;
                        }
                    }
                    if(identificador == 0)
                    {
                        while(1)
                        {
                            system("cls");
                            if(opcao == 3)
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será emprestado.\n");
                            }
                            else
                            {
                                printf("Escolha abaixo como deseja realizar a procura do livro que será devolvido.\n");
                            }
                            printf("\t1) Código do livro.\n");
                            printf("\t2) Título do livro.\n");
                            printf("Digite a opção desejada ao lado: ");
                            scanf("%i", &opcao2);
                            if(opcao2 == 1 || opcao2 == 2)
                            {
                                break;
                            }
                            printf("OOOPS!! Digite apenas 1 ou 2 para realizae a busca pelo livro emprestado.\n\n");
                            system("pause");
                        }
                        if(opcao2 == 1)
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Digite o código do livro: ");
                                scanf("%i", &cd_aux_Disponivel);
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        printf("O livro já foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel))
                                    {
                                        printf("O livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O código do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);

                                if(res[0] == 'N')
                                {
                                    break;
                                }
                            }
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_nome_cliente_e_codigo_Livro(&L_D, &Livro_emprestado, &cliente, nome, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_nome_cliente_e_codigo_livro(&L_D, &Livro_emprestado,& cliente, nome, cd_aux_Disponivel);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                        else
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Digite o título do livro: ");
                                fflush(stdin);
                                gets(titulo);
                                titulo[0] = toupper(titulo[0]);
                                if(isdigit(titulo[0]) == 0)
                                {
                                    titulo[0] = toupper(titulo[0]);
                                }
                                for(i = 1; titulo[i]!= '\0'; i++)
                                {
                                    if(isdigit(titulo[i]) == 0)
                                    {
                                        titulo[i] = tolower(titulo[i]);
                                    }
                                }
                                if(opcao == 3)
                                {
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        printf("O livro já foi alugado.\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O título do livro é inválido.\n\n");
                                    }
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo))
                                    {
                                        identificador++;
                                        break;
                                    }
                                    if(Identificador_livro_existente(L_D, titulo))
                                    {
                                        printf("O livro ainda não foi alugado.\n\n");
                                    }
                                    else
                                    {
                                        printf("OOOPS!! O titulo do livro é inválido.\n\n");
                                    }
                                }
                                system("pause");
                                printf("\nDigite qualquer coisa diferente de \"n ou N\" para realizar outra digitação: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);

                                if(res[0] == 'N')
                                {
                                    break;
                                }
                            }
                            if(identificador != 0)
                            {
                                system("cls");
                                identificador = 0;
                                if(opcao == 3)
                                {
                                    emprestimo_nome_cliente_e_Livro(&L_D, &Livro_emprestado, &cliente, nome, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Empréstimo realizado com sucesso!!!\n\n");
                                }
                                else
                                {
                                    devolucao_nome_cliente_e_livro(&L_D, &Livro_emprestado, &cliente, nome, titulo);
                                    cliente = Ordenamento_Cliente(cliente);
                                    printf("Devolução realizada com sucesso!!!\n\n");
                                }
                                system("pause");
                            }
                        }
                    }
                    else
                    {
                        identificador = 0;
                    }
                }

                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    printf("\t1) Realizar outro empréstimo de livro.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite um número da opção desejada ao lado: ");
                    scanf("%i", &opcao2);

                    if(opcao2 == 1 || opcao2 == 2)
                    {
                        break;
                    }
                    printf("OOOPS!! O número digitado não condiz com o solicitado.\n\n");
                    system("pause");
                }
            } while(opcao2 == 1);
            system("cls");
            continue;
        }
        if(opcao == 5 || opcao == 6 || opcao == 7)
        {
            while(1)
            {   while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    if(opcao == 5)
                    {
                        printf("\t1) Visualizar os livros Emprestados à um cliente escolhido.\n");
                        printf("\t2) Visualizar todos os clientes com seus respectivos livros alugados .\n");
                        printf("\t3) Visualizar com mais detalhes a informação de um livro emprestado escolhido.\n");
                        printf("\t4) Visualizar todos os livros emprestados.\n\n");
                    }
                    else
                    {
                        if(opcao == 6)
                        {
                            printf("\t1) Visualizar os livros disponíveis procurando pelo código.\n");
                            printf("\t2) Visualizar todos os livros disponíveis procurando por título.\n");
                            printf("\t3) Visualizar todos os livros disponíveis.\n\n");
                        }
                        else
                        {
                            printf("\t1) Visualizar todos os clientes procurando pelo código.\n");
                            printf("\t2) Visualizar todos os clienres procurando por nome.\n");
                            printf("\t3) Visualizar todos os clientes cadastrados.\n\n");
                        }
                    }
                    printf("Digite a opção escolhida ao lado: ");
                    scanf("%i", &opcao2);
                    if(opcao2 == 4 && opcao == 5)
                    {
                        break;
                    }
                    if(opcao2 < 4 && opcao2 > 0)
                    {
                        break;
                    }
                    printf("OOOPS!! O número digitado não condiz com o solicitado.\n\n");
                    system("pause");
                }
                system("cls");
                if(opcao == 5)
                {
                    if(opcao2 == 1)
                    {
                        while(1)
                        {
                            system("cls");
                            printf("1) Código do cliente.\n");
                            printf("2) Nome do cliente.\n\n");
                            printf("Digite uma das opções abaixo: ");
                            scanf("%i", &opcao2);
                            if(opcao2 < 3 && opcao2 > 0)
                            {
                                break;
                            }
                            printf("OOOPS!!! opção incorreta, o número digitado deverá ser 1 ou 2.\n\n");
                            system("pause");
                            printf("cls");
                            printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando: ");
                            scanf("%s", &res[0]);
                            res[0] = toupper(res[0]);
                            if(res[0] == 'N')
                            {
                                identificador++;
                                break;
                            }
                        }
                        if(identificador != 0)
                        {
                            identificador = 0;
                        }
                        else
                        {
                            while(1)
                            {
                                system("cls");
                                if(opcao2 == 1)
                                {
                                    printf("Digite o código do cliente ao lado: ");
                                    scanf("%i", &cd_aux_cliente);
                                    if(Identificador_Clientes_Existentes_codigo(cliente, cd_aux_cliente) == 1)
                                    {
                                        system("cls");
                                        print_emprestimo_cliente_codigo(cliente, cd_aux_cliente);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("O código do cliente não está cadastrado.\n\n");
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    printf("Digite o nome do cliente ao lado: ");
                                    fflush(stdin);
                                    gets(nome);
                                    nome[0] = toupper(nome[0]);
                                    for(i = 1; nome[i] != '\0'; i++)
                                    {
                                        nome[i] = tolower(nome[i]);
                                    }
                                    if(Identificador_Clientes_Existentes(cliente, nome))
                                    {
                                        system("cls");
                                        print_emprestimo_cliente_nome(cliente, nome);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("O código do cliente não está cadastrado.\n\n");
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if(opcao2 == 2)
                        {
                            print_livros_emprestados_por_cliente(cliente);
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            if(opcao2 == 3)
                            {
                                while(1)
                                {
                                    system("cls");
                                    printf("1) Código do livro.\n");
                                    printf("2) Título do livro.\n\n");
                                    printf("Digite uma das opções abaixo: ");
                                    scanf("%i", &opcao2);
                                    if(opcao2 < 3 && opcao2 > 0)
                                    {
                                        break;
                                    }
                                    printf("OOOPS!!! opção incorreta, o número digitado deverá ser 1 ou 2.\n\n");
                                    system("pause");
                                    printf("cls");
                                    printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando: ");
                                    scanf("%s", &res[0]);
                                    res[0] = toupper(res[0]);
                                    if(res[0] == 'N')
                                    {
                                        identificador++;
                                        break;
                                    }
                                }
                                if(identificador != 0)
                                {
                                    identificador = 0;
                                }
                                else
                                {
                                    while(1)
                                    {
                                        system("cls");
                                        if(opcao2 == 1)
                                        {
                                            printf("Digite o código do livro ao lado: ");
                                            scanf("%i", &cd_aux_Disponivel);
                                            if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel) == 1 || Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel) == 1)
                                            {
                                                system("cls");
                                                print_Livro_Emprestado_codigo(Livro_emprestado, L_D, cd_aux_Disponivel);
                                                system("pause");
                                                break;
                                            }
                                            else
                                            {
                                                printf("O código digitado não está cadastrado.\n\n");
                                                printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                                scanf("%s", &res[0]);
                                                res[0] = toupper(res[0]);
                                                if(res[0] == 'N')
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            printf("Digite o título do livro ao lado: ");
                                            fflush(stdin);
                                            gets(titulo);
                                            if(isdigit(titulo[0]) == 0)
                                            {
                                                titulo[0] = toupper(titulo[0]);
                                            }
                                            for(i = 1; titulo[i] != '\0'; i++)
                                            {
                                                if(isdigit(titulo[i]) == 0)
                                                {
                                                    titulo[i] = tolower(titulo[i]);
                                                }
                                            }
                                            if(Identificador_livro_Emprestado_existente(Livro_emprestado, titulo) == 1 || Identificador_livro_existente(L_D, titulo) == 1)
                                            {
                                                system("cls");
                                                print_Livro_Emprestado_titulo(Livro_emprestado, L_D, titulo);
                                                system("pause");
                                                break;
                                            }
                                            else
                                            {
                                                printf("O código digitado não está cadastrado.\n\n");
                                                printf("Digite qualquer coisa diferente de \"n ou N\" para tentar uma nova digitação: ");
                                                scanf("%s", &res[0]);
                                                res[0] = toupper(res[0]);
                                                if(res[0] == 'N')
                                                {
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                system("cls");
                                print_livros_emprestados(Livro_emprestado);
                            }
                        }
                    }
                }
                else
                {
                    if(opcao == 6)
                    {
                        if(opcao2 == 1)
                        {
                            do
                            {
                                system("cls");
                                printf("Digite o código do livro ao lado: ");
                                scanf("%i", &cd_aux_Disponivel);
                                if(cd_aux_Disponivel < 1)
                                {
                                    printf("OOPS!! não se tem código de livros disponíveis menores ou igual a 0.\n\n");
                                    system("pause");
                                    system("cls");
                                }
                                else
                                {
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel) == 1)
                                    {
                                        identificador = 0;
                                        system("cls");
                                        print_visualizacao_livros_disponiveis_codigo(L_D, cd_aux_Disponivel);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("OOPS!! o codigo do livro não foi encontrado.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                }
                                printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um código: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);
                            }while(res[0] != 'N');
                        }
                        else
                        {
                            if(opcao2 == 2)
                            {
                                do
                                {
                                    system("cls");
                                    printf("Digite o título do livro: ");
                                    fflush(stdin);
                                    gets(titulo);
                                    if(titulo[0] == ' ')
                                    {
                                        printf("OOOPS!! há um espaço em branco no início do titulo.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        titulo[0] = toupper(titulo[0]);
                                        for(i = 1; i < Tam_Nome; i++)
                                        {
                                            if(isdigit(titulo[i]) == 0)
                                            {
                                                titulo[i] = tolower(titulo[i]);
                                            }
                                        }
                                        if(Identificador_livro_existente(L_D, titulo) == 1)
                                        {
                                            system("cls");
                                            print_visualizacao_livros_disponiveis_titulo(L_D, titulo);
                                            system("pause");
                                            break;
                                        }
                                        else
                                        {
                                            printf("OOPS!! o título do livro não foi encontrado.\n\n");

                                            system("pause");
                                            system("cls");
                                        }
                                    }
                                    
                                    printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um título: ");
                                    scanf("%s", &res[0]);
                                    res[0] = toupper(res[0]);
                                }while(res[0] != 'N');
                            }
                            else
                            {
                                print_livros_disponiveis(L_D);
                            }
                        }
                    }
                    else
                    {
                        if(opcao2 == 1)
                        {
                            do
                            {
                                system("cls");
                                printf("Digite o código do cliente ao lado: ");
                                scanf("%i", &cd_aux_cliente);
                                if(cd_aux_cliente < 1)
                                {
                                    printf("OOPS!! não se tem códigos de cliente menor ou igual a 0.\n\n");
                                    system("pause");
                                    system("cls");
                                }
                                else
                                {
                                    if(Identificador_livro_existente_por_codigo(L_D, cd_aux_cliente) == 1)
                                    {
                                        identificador = 0;
                                        system("cls");
                                        print_clientes_codigo(cliente, cd_aux_cliente);
                                        system("pause");
                                        break;
                                    }
                                    else
                                    {
                                        printf("OOPS!! o codigo do cliente não foi encontrado.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                }
                                printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um código: ");
                                scanf("%s", &res[0]);
                                res[0] = toupper(res[0]);
                            }while(res[0] != 'N');
                        }
                        else
                        {
                            if(opcao2 == 2)
                            {
                                do
                                {
                                    system("cls");
                                    printf("Digite o nome do cliente: ");
                                    fflush(stdin);
                                    gets(nome);
                                    if(titulo[0] == ' ')
                                    {
                                        printf("OOOPS!! há um espaço em branco no início do titulo.\n\n");
                                        system("pause");
                                        system("cls");
                                    }
                                    else
                                    {
                                        if(isdigit(nome[0]) == 1)
                                        {
                                            printf("Não se pode ter número no nome do cliente.\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                        else
                                        {
                                            nome[0] = toupper(nome[0]);
                                            identificador = 0;
                                            for(i = 1; i < Tam_Nome; i++)
                                            {
                                                if(isdigit(nome[i]) == 1)
                                                {
                                                    identificador++;
                                                    break;
                                                }
                                                nome[i] = tolower(nome[i]);
                                            }
                                            if(identificador != 0)
                                            {
                                                identificador = 0;
                                                printf("Não se pode ter digitação de número no nome do cliente.\n\n");
                                                system("pause");
                                                system("cls");
                                            }
                                            else
                                            {
                                                if(Identificador_Clientes_Existentes(cliente, nome) == 1)
                                                {
                                                    system("cls");
                                                    print_clientes_nome(cliente, nome);
                                                    system("pause");
                                                    break;
                                                }
                                                else
                                                {
                                                    printf("OOPS!! o nome do cliente não foi encontrado.\n\n");
                                                    system("pause");
                                                    system("cls");
                                                }
                                            }
                                        }
                                    }
                                    printf("Digite qualquer coisa diferente de \"n ou N\" para continuar digitando um título: ");
                                    scanf("%s", &res[0]);
                                    res[0] = toupper(res[0]);
                                }while(res[0] != 'N');
                            }
                            else
                            {
                                print_clientes_cadastrados(cliente);
                            }
                        }
                    }
                }

                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo: \n");
                    if(opcao == 5)
                    {
                        printf("\t1) Vizualizar novamente todas as opções de visualização dos livros emprestados.\n");
                    }
                    else
                    {
                        if(opcao == 6)
                        {
                            printf("\t1) Vizualizar novamente todas as opções de visualização dos livros disponíveis.\n");
                        }
                        else
                        {
                            printf("\t1) Vizualizar novamente todas as opções de visualização do cliente.\n");
                        }
                    }
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite o número da opção que deseja seguir: ");
                    scanf("%i", &opcao2);
                    if(opcao2 == 1 || opcao2 == 2)
                    {
                        break;
                    }
                    printf("OOOPS! o número digitado não esta de acordo com o solicitado.\n\n");
                    system("pause");
                }
                if(opcao2 == 2)
                {
                    break;
                }
            }
            system("cls");
            continue;
        }
        if(opcao == 8)
        {
            identificador = 0;
            do
            {
                while(1)
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    printf("\t1) Alterar o nome de um cliente.\n");
                    printf("\t2) Alterar as informações de um livro.\n\n");
                    printf("Digite a opção desejada ao lado: ");
                    scanf("%i", &opcao2);
                    if(opcao2 < 1 || opcao2 > 2)
                    {
                        printf("OOOPS!! digitação incorreta!!!\n\n");
                        system("pause");
                        system("cls");
                        printf("Digite qualquer coisa diferente de \"n ou N\" para continuar realizando uma digitação\n");
                        scanf("%s", &res[0]);
                        res[0] = toupper(res[0]);
                        if(res[0] != 'N')
                        {
                            continue;
                        }
                        identificador++;
                    }
                    break;
                }
                if(identificador == 0)
                {
                    if(opcao2 == 1)
                    {
                        while(1)
                        {
                            system("cls");
                            printf("Digite o código do cliente: ");
                            scanf("%i", &cd_aux_cliente);
                            if(cd_aux_cliente <= 0)
                            {
                                printf("OOOPS!! O código do cliente tem de ser um número maior ou igual a 0.\n\n");
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                if(Identificador_Clientes_Existentes_codigo(cliente, cd_aux_cliente) == 1)
                                {
                                    while(1)
                                    {
                                        system("cls");
                                        printf("Digite como deseja renomear o cliente: ");
                                        fflush(stdin);
                                        gets(nome);
                                        printf("Se deseja digitar novamente, tecle qualquer botão diferente de \"n ou N\": ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] != 'N')
                                        {
                                            continue;
                                        }
                                        if(titulo[0] == ' ')
                                        {
                                            printf("OOOPS!! há um espaço em branco no início do titulo.\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                        else
                                        {
                                            if(isdigit(nome[0]) == 1)
                                            {
                                                printf("OOOPS!!! não se pode haver digitação de número no nome do cliente.\n\n");
                                                system("pause");
                                                system("cls");
                                            }
                                            else
                                            {
                                                nome[0] = toupper(nome[0]);
                                                for(i = 1; nome[i] < Tam_Nome; i++)
                                                {
                                                    if(isdigit(nome[i]) == 1)
                                                    {
                                                        identificador++;
                                                        break;
                                                    }
                                                    nome[i] = tolower(nome[i]);
                                                }
                                                if(identificador != 0)
                                                {
                                                    identificador = 0;
                                                    printf("OOOPS!!! não se pode haver digitação de número no nome do cliente.\n\n");
                                                    system("pause");
                                                    system("cls");
                                                }
                                                else
                                                {
                                                    system("cls");
                                                    cliente = Editar_cliente(cliente, cd_aux_cliente, nome);
                                                    printf("O nome foi alterado com sucesso!!!\n\n");
                                                    system("pause");
                                                    system("cls");
                                                    break;
                                                }
                                            }
                                        }
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para tentar realizar uma nova digitação: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            break;
                                        }
                                    }
                                    break;
                                }
                                else
                                {
                                    printf("Não existe cliente cadastrado com o código \"%i\"\n\n", cd_aux_cliente);
                                    system("pause");
                                    system("cls");
                                }
                            }
                            printf("Digite qualquer coisa diferente de \"n ou N\" para realizar uma nova digitação: ");
                            scanf("%s", &res[0]);
                            res[0] = toupper(res[0]);
                            if(res[0] == 'N')
                            {
                                break;
                            }
                        }
                    }
                    else
                    {
                        while(1)
                        {
                            system("cls");
                            printf("Digite o código do livro ao lado: ");
                            scanf("%i", &cd_aux_Disponivel);
                            if(cd_aux_Disponivel < 1)
                            {
                                printf("Não existe nenhum livro cadastrado que tenha um código menor ou igual a 0.\n\n");
                                system("pause");
                                system("cls");
                            }
                            else
                            {
                                if(Identificador_livro_existente_por_codigo(L_D, cd_aux_Disponivel) == 1)
                                {
                                    opcao = 1;
                                    break;
                                }
                                else
                                {
                                    if(Identificador_livro_Emprestado_existente_por_codigo(Livro_emprestado, cd_aux_Disponivel) == 1)
                                    {
                                        opcao = 2;
                                        break;
                                    }
                                    else
                                    {
                                    printf("O livro com o código \"%i\" não consta no sistema.\n\n", cd_aux_Disponivel);
                                    system("pause");
                                    system("cls");
                                    }
                                }
                            }
                            printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente um código: ");
                            scanf("%s", &res[0]);
                            res[0] = toupper(res[0]);
                            if(res[0] == 'N')
                            {
                                identificador++;
                                break;
                            }
                        }
                        if(identificador == 0)
                        {
                            while(1)
                            {
                                system("cls");
                                printf("Escolha uma das opções abaixo.\n");
                                printf("\t1) Alterar título.\n");
                                printf("\t2) Alterar assunto.\n");
                                printf("\t3) Alterar autor.\n\n");
                                printf("Digite o número da opção que deseja realizar a edição de informação: ");
                                scanf("%i", &opcao2);
                                if(opcao2 == 1)
                                {
                                    //Edição do titulo de um livro.
                                    while(1)
                                    {
                                        system("cls");
                                        printf("Digite o novo titulo do livro: ");
                                        fflush(stdin);
                                        gets(titulo);
                                        if(titulo[0] == ' ')
                                        {
                                            printf("OOOPS!!! há um espaço em branco no inicio do titulo.\n\n");
                                            system("pause");
                                            system("cls");
                                        }
                                        else
                                        {
                                            titulo[0] = toupper(titulo[0]);
                                            for(i = 1; titulo[i] < Tam_Nome; i++)
                                            {
                                                titulo[i] = tolower(titulo[i]);
                                            }
                                            break;
                                        }
                                        printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente um titulo para o livro: ");
                                        scanf("%s", &res[0]);
                                        res[0] = toupper(res[0]);
                                        if(res[0] == 'N')
                                        {
                                            identificador++;
                                            break;
                                        }
                                    }
                                    if(identificador == 0)
                                    {
                                        system("cls");
                                        if(opcao == 1)
                                        {
                                            //colocar a função de edição do titulo na lista de livros disponiveis
                                            L_D = Edicao_titulo_livro_disponivel(L_D, cd_aux_Disponivel, titulo);
                                        }
                                        else
                                        {
                                            //colocar a função de edição do titulo na lista de livros emprestados e na lista de livros disponiveis dentro da lista de clientes
                                            Editar_titulo_livros_emprestados_e_cliente(&Livro_emprestado, &cliente, cd_aux_Disponivel, titulo);
                                        }
                                        printf("O titulo do livro foi alterado com sucesso!!\n\n");
                                        system("pause");
                                        system("cls");
                                    }   
                                    else
                                    {
                                        identificador = 0;
                                    }
                                }
                                else
                                {
                                    if(opcao2 == 2)
                                    {
                                        //Edição do assunto de um livro
                                        while(1)
                                        {
                                            system("cls");
                                            printf("Digite o novo assunto do livro: ");
                                            fflush(stdin);
                                            gets(assunto);
                                            if(assunto[0] == ' ')
                                            {
                                                printf("OOOPS!!! há um espaço em branco no inicio do assunto.\n\n");
                                                system("pause");
                                                system("cls");
                                            }
                                            else
                                            {
                                                assunto[0] = toupper(assunto[0]);
                                                for(i = 1; assunto[i] < Tam_Nome; i++)
                                                {
                                                    assunto[i] = tolower(assunto[i]);
                                                }
                                                break;
                                            }
                                            printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente o assunto do livro: ");
                                            scanf("%s", &res[0]);
                                            res[0] = toupper(res[0]);
                                            if(res[0] == 'N')
                                            {
                                                identificador++;
                                                break;
                                            }
                                        }
                                        if(identificador == 0)
                                        {
                                            system("cls");
                                            if(opcao == 1)
                                            {
                                                //colocar a função de edição do assunto na lista de livros disponiveis
                                                L_D = Edicao_assunto_livro_disponivel(L_D, cd_aux_Disponivel, assunto);
                                            }
                                            else
                                            {
                                                //colocar a função de edição do assunto na lista de livros emprestados e na lista de livros disponiveis dentro da lista de clientes
                                                Editar_assunto_livros_emprestados_e_cliente(&Livro_emprestado, &cliente, cd_aux_Disponivel, assunto);
                                            }
                                            printf("O assunto do livro foi alterado com sucesso!!\n\n");
                                            system("pause");
                                            system("cls");
                                        }   
                                        else
                                        {
                                            identificador = 0;
                                        }
                                    }
                                    else
                                    {
                                        if(opcao2 == 3)
                                        {
                                            //Edição do autor de um livro
                                            while(1)
                                            {
                                                system("cls");
                                                printf("Digite o novo nome do autor do livro: ");
                                                fflush(stdin);
                                                gets(autor);
                                                if(autor[0] == ' ')
                                                {
                                                    printf("OOOPS!!! há um espaço em branco no inicio do nome do autor.\n\n");
                                                    system("pause");
                                                    system("cls");
                                                }
                                                else
                                                {
                                                    if(isdigit(autor[0]) == 1)
                                                    {
                                                        printf("Não se pode ter digitação de número no nome do autor.\n\n");
                                                        system("pause");
                                                        system("cls");
                                                    }
                                                    else
                                                    {
                                                        identificador = 0;
                                                        autor[0] = toupper(autor[0]);
                                                        for(i = 1; autor[i] < Tam_Nome; i++)
                                                        {
                                                            if(isdigit(autor[i]) == 0)
                                                            {
                                                                autor[i] = tolower(autor[i]);
                                                            }
                                                            else
                                                            {
                                                                identificador++;
                                                                break;
                                                            }
                                                        }
                                                        if(identificador == 0)
                                                        {
                                                            break;
                                                        }
                                                        else
                                                        {
                                                            identificador = 0;
                                                            printf("Não se pode ter número na digitação do nome do autor.\n\n");
                                                            system("pause");
                                                            system("cls");
                                                        }
                                                    }
                                                }
                                                printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente um o nome do autor: ");
                                                scanf("%s", &res[0]);
                                                res[0] = toupper(res[0]);
                                                if(res[0] == 'N')
                                                {
                                                    identificador++;
                                                    break;
                                                }
                                            }
                                            if(identificador == 0)
                                            {
                                                system("cls");
                                                if(opcao == 1)
                                                {
                                                    //colocar a função de edição do nome do autor na lista de livros disponiveis
                                                    L_D = Edicao_autor_livro_disponivel(L_D, cd_aux_Disponivel, autor);
                                                }
                                                else
                                                {
                                                    //colocar a função de edição do nome do autor na lista de livros emprestados e n alista de livros disponiveis dentro da lista de clientes
                                                    Editar_autor_livros_emprestados_e_cliente(&Livro_emprestado, &cliente, cd_aux_Disponivel, autor);
                                                }
                                                printf("O nome do autor foi alterado com sucesso!!\n\n");
                                                system("pause");
                                                system("cls");
                                            }   
                                            else
                                            {
                                                identificador = 0;
                                            }
                                        }
                                        else
                                        {
                                            printf("OOOPS!! O número digitado não condiz com a solicitação.\n\n");
                                            system("pause");
                                            system("cls");
                                            printf("Digite qualquer coisa diferente de \"n ou N\" para digitar novamente uma opção: ");
                                            scanf("%s", &res[0]);
                                            res[0] = toupper(res[0]);
                                            if(res[0] == 'N')
                                            {
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            identificador = 0;
                        }
                    }
                }
                else
                {
                    identificador = 0;
                }
                do
                {
                    system("cls");
                    printf("Escolha uma das opções abaixo.\n");
                    printf("\t1) Realizar outra alteração de cadastro.\n");
                    printf("\t2) Voltar ao menu principal.\n\n");
                    printf("Digite uma das opção desejada ao lado: ");
                    scanf("%i", &opcao2);
                    if(opcao2 < 1 || opcao2 > 2)
                    {
                        printf("OOOPS!! digitação incorreta, por favor escolha a opção 1 ou 2.\n\n");
                        system("pause");
                    }
                }while(opcao2 < 1 || opcao2 > 2);
            } while(opcao2 != 2);
            system("cls");
            continue;
        }
        if(opcao == 9)
        {
            system("cls");
            break;
        }
        else
        {
            printf("O número digitado não é compatível com nenhuma das opções dadas.\n\n");
            system("pause");
            system("cls");
        }
    }
    printf("OBRIGADO POR USAR ESTE SISTEMA BIBLIOTECÁRIO!!!\n");
    printf("VOLTE SEMPRE!!\n\n");
    system("pause");
    return 0;
}
