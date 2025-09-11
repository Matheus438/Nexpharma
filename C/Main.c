#include <stdio.h>
#include <string.h>
#include <windows.h>
#define TF 10
//[]
typedef struct
{
    char nome[50], email[50], cpf[11], tel[14],password[20];
} funcionarios;

typedef struct
{
    char nome_produto[50], descricao[50];
    int qtd, cod;
    float valor;

} produtos;

typedef struct
{
    char nome[50], email[50], endereco[50], cpf[11], password[20], tel[14];
} clientes;

clientes vet_clientes[TF];
produtos vet_produtos[TF];
funcionarios vet_funcionarios[TF];
// menu
void menu()
{
    printf("-------------------MENU-------------------\n");
    printf("\n1 - Cadastrar Cliente");      // CERTO
    printf("\n2 - Listar Clientes");        // CERTO
    printf("\n3 - Pesquisar Cliente");      // CERTO
    printf("\n4 - Excluir Cliente");        // EM ANDAMENTO
    printf("\n5 - Cadastrar Produto");      // CERTO
    printf("\n6 - Pesquisar Produto");      // CERTO
    printf("\n7 - Listar Produto");         // CERTO
    printf("\n8 - Excluir Produto");        // EM ANDAMENTO
    printf("\n9 - Comprar Produto");        // EM ANDAMENTO
    printf("\n10 - Cadastrar Funcionario"); // CERTO
    printf("\n11 - Listar Funcionario");    // CERTO
    printf("\n12 - Pesquisar Funcionario"); // CERTO
    printf("\n13 - Excluir Funcionario");   // EM ANDAMENTO
    printf("\n14 - Finalizar Programa");    // CERTO
}
// 1
void cadastarClientes()
{
    clientes c;
    int i = 1, j;
    //[]
    while (i != 2)
    {
        printf("Digite o Nome do cliente a ser cadastrado: \n");
        gets(c.nome);
        fflush(stdin);
        printf("Digite o E-mail do cliente a ser cadastrado: \n");
        gets(c.email);
        fflush(stdin);
        for (j = 0; j < TF; j++)
        {
            if (strcmp(c.email, vet_clientes[j].email) == 0)
            {
                printf("E-mail ja cadastrado. Tente novamente.\n");
                printf("Digite o E-mail do cliente a ser cadastrado: \n");
                gets(c.email);
                fflush(stdin);
            }
        }
        printf("Digite o CPF do cliente a ser cadastrado: \n");
        gets(c.cpf);
        fflush(stdin);
        for (j = 0; j < TF; j++)
        {
            if (strcmp(c.cpf, vet_clientes[i].cpf) == 0)
            {
                printf("CPF ja cadastrado no sistema!!!\n");
                printf("Digite o CPF do cliente a ser cadastrado: \n");
                gets(c.cpf);
                fflush(stdin);
            }
        }

        printf("Digite o Telefone do cliente a ser cadastrado: \n");
        gets(c.tel);
        fflush(stdin);
        // CONFERIR ABAIXO
        if (strlen(c.tel) < 11 || strlen(c.tel) > 14)
        {
            printf("Telefone invalido. Cadastre como no Exemplo: (99)99999-9999\n");
            printf("Digite o Telefone a ser do cliente a ser cadastrado: \n");
            gets(c.tel);
            fflush(stdin);
        }
        for (j = 0; j < TF; j++)
        {
            if (strcmp(c.tel, vet_clientes[j].tel) == 0)
            {
                printf("Telefone ja cadastrado. Tente novamente.\n");
                printf("Digite o Telefone a ser cadastrado: \n");
                gets(c.tel);
                fflush(stdin);
            }
        }

        printf("Digite a senha do cliente: ");
        gets(c.password);
        fflush(stdin);

        vet_clientes[i] = c;

        printf("\nCliente Cadastrado com Sucesso.\n");

        printf("\nDeseja cadastrar mais algum cliente?");
        printf("\n1 - Sim");
        printf("\n2 - Nao");
        scanf("%d", &i);
    }
}
// 2
void listarClientes()
{
    int i;
    clientes c;
    for (i = 0; i < TF; i++)
    {
        printf("\nNome: %s", c.nome);
        printf("\nTelefone: %d", c.tel);
        printf("\nEmail: %s", c.email);
        printf("\nCPF: %s", c.cpf);
        printf("\nSenha: %s", c.password);
    }
}
// 3
void pesquisarCliente()
{
    int i;
    char busca;
    clientes c;
    printf("Insira o CPF a ser buscado:\n");
    fflush(stdin);
    gets(busca);

    for (i = 0; i < TF; i++)
    {
        if (strcmp(busca, vet_clientes[i].cpf) == 0)
        {
            printf("\nCPF Encontrado\n");
            printf("\nNome: %s", c.nome);
            printf("\nTelefone: %s", c.tel);
            printf("\nEmail:%s", c.email);
            printf("\nCPF: %s", c.cpf);
            printf("\nSenha: %s", c.password);
        }
        else
        {
            printf("\nCPF nao encontrado.");
        }
    }
}
// 4
void excluirCliente()
{
    int i, j;
    char buscar[11];
    printf("Insira o CPF do cliente que deseja excluir: \n");
    gets(buscar);
    for (i = 0; i < TF; i++)
    {
        if (strcmp(buscar, vet_clientes[i].cpf) == 0)
        {

            for (j = i; j < TF - 1; j++)
            {
                vet_clientes[j] = vet_clientes[j + 1];
            }
            
        }
        else
            printf("Cliente nao encontrado.\n");
        
    }
}
// 5
void cadastroProduto()
{
    int i = 1, j;
    produtos p;
    while (i != 2)
    {
        printf("Digite o codigo do produto: \n");
        scanf("%d", &p.cod);
        fflush(stdin);
        for (j = 0; j < TF; j++)
        {
            if (p.cod == vet_produtos[j].cod)
            {
                printf("Produto ja existente.\n");
                printf("Digite o codigo do produto: \n");
                scanf("%d", &p.cod);
                fflush(stdin);
            }
        }
        printf("Digite o Nome do produto a ser cadastrado: \n");
        gets(p.nome_produto);
        fflush(stdin);
        printf("Digite a descricao: \n");
        gets(p.descricao);
        fflush(stdin);
        printf("Digite a quantidade de produto em estoque: \n");
        scanf("%d", &p.qtd);
        fflush(stdin);
        printf("Digite o valor dos produtos: \n");
        scanf("%f", &p.valor);
        fflush(stdin);
        vet_produtos[i] = p;
        printf("\nProduto Cadastrado com Sucesso.\n");
        printf("\nDeseja cadastrar mais algum Produto?");
        printf("\n1 - Sim");
        printf("\n2 - Nao");
        scanf("%d", &i);
    }
}
// 6
void pesquisarProduto()
{
    int i;
    int busca;
    produtos p;
    printf("Insira o codigo a ser buscado:\n");
    fflush(stdin);
    scanf("%d", &busca);

    for (i = 0; i < TF; i++)
    {
        if (busca == vet_produtos[i].cod)
        {
            printf("\nProduto Encontrado\n");
            printf("\nNome: %s", p.nome_produto);
            printf("\nCodigo: %d", p.cod);
            printf("\nValor: %.2f", p.valor);
            printf("\nQuantidade em estoque:%d", p.qtd);
        }
        else
        {
            printf("\nProduto nao encontrado.");
        }
    }
}
// 7
void listarProduto()
{
    int i;
    produtos p;
    for (i = 0; i < TF; i++)
    {
        printf("\nCodigo: %d", p.cod);
        printf("\nNome: %s", p.nome_produto);
        printf("\nDescricao: %s", p.descricao);
        printf("\nValor:%.2f", p.valor);
        printf("\nQuantidade em estoque: %d", p.qtd);
    }
}
// 8
void excluirProduto()
{
}
// 9
void comprarProduto()
{
    // verificar cliente 
    // verificar quantidade no estoque
    // se tiver produto no estoque abater estoque
    // verificar se o produto existe 
    // verificar qual funcionario vendeu
}
// 10

void cadastroFuncionario()
{
    funcionarios f;
    int i = 1;
    int j;
    while (i != 2)
    {
        printf("Digite o nome do funcionario a ser cadastrado: \n");
        gets(f.nome);
        fflush(stdin);
        printf("Digite o E-mail do funcionario a ser cadastrado: \n");
        gets(f.email);
        fflush(stdin);
        for (j = 0; j < TF; j++)
        {
            if (strcmp(f.email, vet_funcionarios[j].email) == 0)
            {
                printf("E-mail ja cadastrado no sistema!!\n");
                printf("Digite o E-mail do funcionario a ser cadastrado: \n");
                gets(f.email);
                fflush(stdin);
            }
        }
        printf("Digite o CPF do funcionario a ser cadastrado: \n");
        gets(f.cpf);
        fflush(stdin);
        for (j = 0; j < TF; j++)
        {
            if (strcmp(f.cpf, vet_clientes[j].cpf) == 0)
            {
                printf("CPF ja cadastrado no sistema!!\n");
                printf("Digite o CPF do funcionario a ser cadastrado: \n");
                gets(f.cpf);
                fflush(stdin);
            }
        }
        printf("Digite o Telefone do Funcionario: \n");
        gets(f.tel);
        fflush(stdin);
        for (j = 0; j < TF; j++)
        {
            if (strlen(f.tel) < 11 || strlen(f.tel) > 14)
            {
                printf("Telefone invalido. Cadastre como no Exemplo: (99)99999-9999 \n");
                printf("Digite o Telefone do cliente a ser cadastrado!! \n");
                gets(f.tel);
                fflush(stdin);
            }
            if (strcmp(f.tel, vet_funcionarios[j].tel) == 0)
            {
                printf("Telefone ja cadastrado. Tente novamente.\n");
                printf("Digite o Telefone a ser cadastrado: \n");
                gets(f.tel);
                fflush(stdin);
            }
        }
        printf("Digite a senha do funcionario: \n");
        gets(f.password);
        fflush(stdin);
        vet_funcionarios[i] = f;
        printf("\nFuncionario Cadastrado com Sucesso\n");
        printf("\nDeseja cadastrar mais algum funcionario?");
        printf("\n1 - Sim");
        printf("\n2 - Nao");
        scanf("%d", &i);
    }
}
// 11
void listarFuncionario()
{
    int i;
    funcionarios f;
    for (i = 0; i < TF; i++)
    {
        printf("\nNome: %s", f.nome);
        printf("\nEmail: %s", f.email);
        printf("\nCPF: %s", f.cpf);
        printf("\nTelefone: %s", f.tel);
        printf("\nSenha: %s", f.password);
    }
}
// 12
void pesquisarFuncionario()
{
    funcionarios f;
    int i;
    char buscar[15];
    printf("Digite o CPF do funcionario: \n");
    gets(buscar);
    fflush(stdin);
    for(i=0;i<TF;i++){
        if(strcmp(buscar, vet_funcionarios[i].cpf)==0){
            printf("\nNome: %s", f.nome);
            printf("\nEmail: %s", f.email);
            printf("\nCPF: %s", f.cpf);
            printf("\nTelefone: %s", f.tel);
            printf("\nSenha: %s", f.password);
        }
    }
}
// 13
void excluirFuncionario()
{
}

main()
{
    int op;
    clientes c;
    produtos p;
    funcionarios f;
    menu();
    printf("\nEscolha a opcao: ");
    scanf("%d", &op);
    while (op != 11)
    {
        switch (op)
        {
        case 1:
            cadastarClientes();
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
            cadastroProduto();
            break;
        case 6:
            pesquisarProduto();
            break;
        case 7:
            listarProduto();

            break;
        case 8:
            excluirProduto();
            break;
        case 9:
            comprarProduto();
            break;
        case 10:
            cadastroFuncionario();
            break;
        case 11:
            listarFuncionario();
            break;

        case 12:
            pesquisarFuncionario();
            break;
        case 13:
            excluirFuncionario();
            break;
        case 14:
            printf("\nSaindo...");
            break;
        default:
            printf("\nValor invalido...");
            break;
        }
        system("pause");
        system("cls");
        menu();
        printf("\nEscolha a opcao: ");
        scanf("%d", &op);
    }
}
//[]