#include <stdio.h>
#include <string.h>
#include <windows.h>
#define TF 10
//[]

typedef struct
{
    char nome_produto[50], descricao[50];
    int qtd, cod;
    float valor;

} produtos;

typedef struct
{
    char nome[50], email[50], endereco[50], cpf[13], password[20], tel[15];
} clientes;

clientes vet_clientes[TF];
produtos vet_produtos[TF];

int cont_clientes = 0, cont_produtos = 0;
// menu
void menu()
{
    printf("-------------------MENU-------------------\n");
    printf("\n1 - Cadastrar Cliente");   // email validação.
    printf("\n2 - Listar Clientes");     // CERTO ok
    printf("\n3 - Pesquisar Cliente");   // CERTO ok
    printf("\n4 - Excluir Cliente");     // CERTO ok
    printf("\n5 - Cadastrar Produto");   // validar o codigo
    printf("\n6 - Pesquisar Produto");   // CERTO ok
    printf("\n7 - Listar Produto");      // CERTO ok
    printf("\n8 - Excluir Produto");     // Mensagem que excluiu
    printf("\n9 - Comprar Produto");     // EM ANDAMENTO
    printf("\n10 - Finalizar Programa"); // CERTO
}
// 1
void cadastrarClientes()
{
    clientes c;
    int i = 1, j, valido;
    //[]
    while (i == 1)
    {

        if (cont_clientes >= TF)
        {
            printf("\nLimite maximo de clientes atingido!\n");
        }

        printf("Digite o Nome do cliente a ser cadastrado: \n");
        gets(c.nome);
        fflush(stdin);

        // email
        valido = 0;
        while (valido == 0)
        {
            printf("Digite o E-mail do cliente a ser cadastrado: \n");
            gets(c.email);
            fflush(stdin);

            int temArroba = 0;
            for (j = 0; j < strlen(c.email); j++)
            {
                if (c.email[j] == '@')
                {
                    temArroba = 1;
                }
            }

            if (temArroba == 1 && c.email[0] != '@' && c.email[strlen(c.email) - 1] != '@')
            {
                int repetido = 0;
                for (j = 0; j < cont_clientes; j++)
                {
                    if (strcmp(c.email, vet_clientes[j].email) == 0)
                    {
                        repetido = 1;
                    }
                }
                if (repetido == 1)
                {
                    printf("\nEmail ja cadastrado no sistema!!\n");
                    valido = 0;
                }
                else
                {
                    valido = 1;
                }
            }
            else
            {
                printf("E-mail invalido! Deve conter '@' e nao pode comecar ou terminar com ele.\n");
            }
        }

        // cpf
        valido = 0;
        while (valido == 0)
        {
            printf("Digite o CPF do cliente a ser cadastrado: \n");
            gets(c.cpf);
            fflush(stdin);

            int apenasNumeros = 1;
            int tamanho = strlen(c.cpf);

            for (j = 0; j < tamanho; j++)
            {
                if (c.cpf[j] < '0' || c.cpf[j] > '9') // se não for número
                {
                    apenasNumeros = 0;
                }
            }

            if (tamanho == 11 && apenasNumeros == 1)
            {
                j = 0;
                while (j < cont_clientes && strcmp(c.cpf, vet_clientes[j].cpf) != 0)
                {
                    j++;
                }
                if (j == cont_clientes) // não achou cpf repetido
                {
                    valido = 1;
                }
                else
                {
                    printf("CPF ja cadastrado. Tente novamente.\n");
                }
            }
            else
            {
                printf("CPF invalido! Digite exatamente 11 numeros.\n");
            }
        }

        // telefone
        valido = 0;
        while (valido == 0)
        {
            printf("Digite o Telefone do cliente a ser cadastrado: \n");
            gets(c.tel);
            fflush(stdin);

            // telefone precisa ter entre 11 e 14 caracteres
            if (strlen(c.tel) >= 11 && strlen(c.tel) <= 14)
            {
                j = 0;
                while (j < cont_clientes && strcmp(c.tel, vet_clientes[j].tel) != 0)
                {
                    j++;
                }

                if (j == cont_clientes) // não achou telefone repetido
                {
                    valido = 1;
                }
                else
                {
                    printf("Telefone ja cadastrado. Tente novamente.\n");
                }
            }
            else
            {
                printf("Telefone invalido. Cadastre como no Exemplo: (99)99999-9999\n");
            }
        }

        printf("Digite a senha do cliente: \n");
        gets(c.password);
        fflush(stdin);

        vet_clientes[cont_clientes] = c;
        cont_clientes++;
        printf("\nCliente Cadastrado com Sucesso.\n");
        printf("\nDeseja cadastrar mais algum cliente?");
        printf("\n1 - Sim");
        printf("\n2 - Nao");
        scanf("%d", &i);
        fflush(stdin);
    }
}
// 2
void listarClientes()
{
    int i;

    for (i = 0; i < cont_clientes; i++)
    {
        printf("\nNome: %s", vet_clientes[i].nome);
        printf("\nTelefone: %s", vet_clientes[i].tel);
        printf("\nEmail: %s", vet_clientes[i].email);
        printf("\nCPF: %s", vet_clientes[i].cpf);
        printf("\nSenha: %s", vet_clientes[i].password);
    }
    if(cont_clientes==0){
        printf("\nNenhum cliente cadastrado.");
    }
}
// 3
void pesquisarCliente()
{
    int i;
    char buscar[11];
    int encontrado = 0;

    printf("Insira o CPF a ser buscado:\n");
    fflush(stdin);
    gets(buscar);

    for (i = 0; i < cont_clientes; i++) // percorre só os clientes cadastrados
    {
        if (strcmp(buscar, vet_clientes[i].cpf) == 0)
        {
            printf("\nCPF Encontrado\n");
            printf("Nome: %s\n", vet_clientes[i].nome);
            printf("Telefone: %s\n", vet_clientes[i].tel);
            printf("Email: %s\n", vet_clientes[i].email);
            printf("CPF: %s\n", vet_clientes[i].cpf);
            printf("Senha: %s\n", vet_clientes[i].password);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("\nCPF nao encontrado.\n");
}

// 3
void excluirCliente()
{
    int i, j, encontrado = 0;
    char buscar[11];
    printf("Insira o CPF do cliente que deseja excluir: \n");
    fflush(stdin);
    gets(buscar);
    for (i = 0; i < cont_clientes; i++)
    {
        if (strcmp(buscar, vet_clientes[i].cpf) == 0)
        {
            encontrado = 1;
            for (j = i; j < cont_clientes - 1; j++)
            {
                vet_clientes[j] = vet_clientes[j + 1];
            }
            j--;
        }
    }
    if (!encontrado)
        printf("Cliente nao encontrado.\n");
    else
    {
        printf("Cliente excluido com sucesso.\n");
        cont_clientes--;
    }
}
// 4
void cadastroProduto(int *cont_produtos)
{
    produtos p;
    int i = 1, j;

    while (i != 2 && *cont_produtos < TF)
    {
        printf("Digite o codigo do produto: \n");
        scanf("%d", &p.cod);
        fflush(stdin);
        for (j = 0; j < *cont_produtos; j++)
        {
            while (p.cod == vet_produtos[j].cod)
            {
                printf("Produto ja existente.\nDigite outro codigo: \n");
                scanf("%d", &p.cod);
                fflush(stdin);
                j = 0;
            }
        }

        // Nome
        printf("Digite o Nome do produto: \n");
        gets(p.nome_produto);
        fflush(stdin);

        // Descrição
        printf("Digite a descricao: \n");
        gets(p.descricao);
        fflush(stdin);

        // Quantidade
        printf("Digite a quantidade em estoque: \n");
        scanf("%d", &p.qtd);
        fflush(stdin);

        // Valor
        printf("Digite o valor do produto: \n");
        scanf("%f", &p.valor);
        fflush(stdin);

        // Salva no vetor
        vet_produtos[*cont_produtos] = p;
        (*cont_produtos)++;

        printf("\nProduto cadastrado com sucesso!\n");

        // Pergunta se deseja continuar
        printf("\nDeseja cadastrar mais algum Produto?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &i);
        fflush(stdin);
    }
}

// 5
void pesquisarProduto(int cont_produtos)
{
    if (cont_produtos == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    int busca, i, encontrado = 0;
    printf("Insira o codigo a ser buscado:\n");
    scanf("%d", &busca);
    fflush(stdin);

    for (i = 0; i < cont_produtos; i++)
    {
        if (vet_produtos[i].cod == busca)
        {
            printf("\nProduto Encontrado\n");
            printf("Nome: %s\n", vet_produtos[i].nome_produto);
            printf("Codigo: %d\n", vet_produtos[i].cod);
            printf("Descricao: %s\n", vet_produtos[i].descricao);
            printf("Valor: %.2f\n", vet_produtos[i].valor);
            printf("Quantidade em estoque: %d\n", vet_produtos[i].qtd);
            encontrado = 1;
        }
    }

    if (!encontrado)
        printf("\nProduto nao encontrado.\n");
}

// 6
int listarProduto(int cont_produtos)
{
    int i;

    if (cont_produtos == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        return 0;
    }

    for (i = 0; i < cont_produtos; i++)
    {
        printf("\nCodigo: %d", vet_produtos[i].cod);
        printf("\nNome: %s", vet_produtos[i].nome_produto);
        printf("\nDescricao: %s", vet_produtos[i].descricao);
        printf("\nValor: %.2f", vet_produtos[i].valor);
        printf("\nQuantidade em estoque: %d\n", vet_produtos[i].qtd);
    }
    return cont_produtos;
}

// 7
void excluirProduto(int *cont)
{
    int i, j, encontrado = 0, cod = 0;

    printf("\nDigite o codigo do produto que deseja excluir: ");
    scanf("%d", &cod);
    for (i = 0; i < *cont; i++)
    {
        if (cod == vet_produtos[i].cod)
        {
            encontrado = 1;
            for (j = i; j < *cont - 1;)
            {
                vet_produtos[j] = vet_produtos[j + 1];
            }
            (*cont)--;
        }
    }
    if (!encontrado)
        printf("\nProduto nao encontrado.");
    else
        printf("\nProduto excluido.");
}
// 8
void comprarProduto()
{

    int i, j, quantidade = 0, escolha = 0, encontrado, produtoencontrado, comprar;
    float valor;
    char cpf[15], produto[30];
    while (escolha != 2)
    {
        valor = 0;
        encontrado = 0;
        printf("\nDigite o seu CPF: ");
        fflush(stdin);
        gets(cpf);
        fflush(stdin);
        for (i = 0; i < cont_clientes && escolha != 2; i++) // CORRIGIR
        {
            if (strcmp(cpf, vet_clientes[i].cpf) == 0)
            {
                printf("\nCPF encontrado, boas compras.");
                encontrado = 1;
            }
        }
        if (encontrado == 1) // NÃO VOLTAR CONSEGUIR DIGITAR O CPF NOVAMENTE APÓS QUERER COMPRAR MAIS PRODUTOS.
        {
            produtoencontrado = 0;
            printf("\nDigite o nome do produto que deseja: ");
            gets(produto);
            fflush(stdin);
            for (j = 0; j < cont_produtos; j++)
            {
                if (strcmp(produto, vet_produtos[j].nome_produto) == 0)
                {
                    produtoencontrado = 1;
                    printf("\nQuantidade em estoque: %d", vet_produtos[j].qtd);
                    printf("\nDigite a quantas unidades voce deseja: ");
                    scanf("%d", &quantidade);
                    fflush(stdin);
                    if (quantidade > vet_produtos[j].qtd)
                    {
                        printf("\nEstoque insuficiente.");
                    }
                    else
                    {
                        valor *= quantidade;
                        printf("\nTotal: %.2f", valor);
                        printf("\nDeseja comprar? ");
                        printf("\n1 - Sim");
                        printf("\n2 - Nao");
                        scanf("%d", &comprar);
                        fflush(stdin);
                        if (comprar == 1)
                        {
                            printf("\nCompra realizada com sucesso.");
                            vet_produtos[j].qtd -= quantidade;
                        }
                        else
                        {
                            printf("\nCompra cancelada.");
                        }
                    }
                }
                if (produtoencontrado == 0)
                {
                    printf("\nProduto nao encontrado.");
                }
            }
        }
        else
        {
            printf("\nCPF nao encontrado.");
        }
        printf("\nDeseja comprar mais produtos? ");
        printf("\n1 - Sim");
        printf("\n2 - Nao");
        scanf("%d", &escolha);
    }
}

main()
{
    int op;

    do
    {
        menu();
        printf("\nEscolha a opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            cadastrarClientes(); // função atualizada para usar o contador
            break;

        case 2:
            listarClientes();
            break;

        case 3:
            pesquisarCliente();
            break;

        case 4:
            excluirCliente();
            break;

        case 5:
            cadastroProduto(&cont_produtos);
            break;

        case 6:
            pesquisarProduto(cont_produtos);
            break;

        case 7:
            cont_produtos = listarProduto(cont_produtos);
            break;

        case 8:
            excluirProduto(&cont_produtos);
            break;

        case 9:
            comprarProduto(cont_clientes, cont_produtos);
            break;

        case 10:
            printf("\nEncerrando o codigo...\n");
            break;

        default:
            printf("\nValor invalido...\n");
            break;
        }

        if (op != 10)
        {
            printf("\n");
            system("pause");
            system("cls");
        }

    } while (op != 10);
}
//[]