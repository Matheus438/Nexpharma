#include <stdio.h>
#include <string.h>
#include <windows.h>

#define TF 10

typedef struct
{
    char nome[50], email[50], cpf[12], tel[15], password[20];
} clientes;

typedef struct
{
    char nome_produto[50], descricao[50];
    int qtd, cod;
    float valor;
} produtos;

typedef struct
{
    char nome[50], email[50], cpf[12], tel[15], password[20];
} funcionarios;

// Vetores globais
clientes vet_clientes[TF];
produtos vet_produtos[TF];
funcionarios vet_funcionarios[TF];

int cont_clientes = 0, cont_produtos = 0, cont_funcionarios = 0;

// ------------------ MENU ------------------
void menu()
{
    printf("-------------------MENU-------------------\n");
    printf("1 - Cadastrar Cliente\n");
    printf("2 - Listar Clientes\n");
    printf("3 - Pesquisar Cliente\n");
    printf("4 - Excluir Cliente\n");
    printf("5 - Cadastrar Produto\n");
    printf("6 - Pesquisar Produto\n");
    printf("7 - Listar Produto\n");
    printf("8 - Excluir Produto\n");
    printf("9 - Comprar Produto\n");
    printf("10 - Cadastrar Funcionario\n");
    printf("11 - Listar Funcionario\n");
    printf("12 - Pesquisar Funcionario\n");
    printf("13 - Excluir Funcionario\n");
    printf("14 - Finalizar Programa\n");
}

// ------------------ CLIENTES ------------------

// 1 - Cadastrar Cliente
void cadastrarClientes()
{
    clientes c;
    int i = 1;
    while (i != 2 && cont_clientes < TF)
    {
        printf("Digite o Nome do cliente: \n");
        fflush(stdin);
        gets(c.nome);

        // Email
        int emailValido = 0;
        while (!emailValido)
        {
            printf("Digite o E-mail do cliente: \n");
            fflush(stdin);
            gets(c.email);

            emailValido = 1;
            int j = 0;
            while (j < cont_clientes && emailValido)
            {
                int igual = strcmp(c.email, vet_clientes[j].email) == 0;
                emailValido = emailValido * !igual;
                j++;
            }
            if (!emailValido)
                printf("E-mail ja cadastrado!\n");
        }

        // CPF
        int cpfValido = 0;
        while (!cpfValido)
        {
            printf("Digite o CPF do cliente: \n");
            fflush(stdin);
            gets(c.cpf);

            cpfValido = 1;
            int j = 0;
            while (j < cont_clientes && cpfValido)
            {
                int igual = strcmp(c.cpf, vet_clientes[j].cpf) == 0;
                cpfValido = cpfValido * !igual;
                j++;
            }
            if (!cpfValido)
                printf("CPF ja cadastrado!\n");
        }

        // Telefone
        int telValido = 0;
        while (!telValido)
        {
            printf("Digite o Telefone do cliente: \n");
            fflush(stdin);
            gets(c.tel);

            int tamanhoValido = (strlen(c.tel) >= 11 && strlen(c.tel) <= 14);
            int telefoneDuplicado = 0;
            int j = 0;
            while (j < cont_clientes)
            {
                telefoneDuplicado += (strcmp(c.tel, vet_clientes[j].tel) == 0);
                j++;
            }

            telValido = tamanhoValido * (telefoneDuplicado == 0);
            if (!telValido)
                printf("Telefone invalido ou ja cadastrado.\n");
        }

        printf("Digite a senha do cliente: \n");
        fflush(stdin);
        gets(c.password);

        vet_clientes[cont_clientes] = c;
        cont_clientes++;
        printf("\nCliente cadastrado com sucesso!\n");

        printf("Deseja cadastrar mais clientes? 1-Sim 2-Nao\n");
        scanf("%d", &i);
        fflush(stdin);
    }
}

// 2 - Listar Clientes
void listarClientes()
{
    if (cont_clientes == 0)
    {
        printf("\nNenhum cliente cadastrado.\n");
        return;
    }

    int i = 0;
    while (i < cont_clientes)
    {
        printf("\nNome: %s", vet_clientes[i].nome);
        printf("\nTelefone: %s", vet_clientes[i].tel);
        printf("\nEmail: %s", vet_clientes[i].email);
        printf("\nCPF: %s", vet_clientes[i].cpf);
        printf("\nSenha: %s\n", vet_clientes[i].password);
        i++;
    }
}

// 3 - Pesquisar Cliente
void pesquisarCliente()
{
    char buscar[12];
    int i = 0, encontrado = 0;
    printf("Digite o CPF do cliente: \n");
    fflush(stdin);
    gets(buscar);

    while (i < cont_clientes)
    {
        int igual = strcmp(buscar, vet_clientes[i].cpf) == 0;
        encontrado += igual;

        if (igual)
        {
            printf("\nCliente encontrado:\n");
            printf("Nome: %s\n", vet_clientes[i].nome);
            printf("Telefone: %s\n", vet_clientes[i].tel);
            printf("Email: %s\n", vet_clientes[i].email);
            printf("CPF: %s\n", vet_clientes[i].cpf);
            printf("Senha: %s\n", vet_clientes[i].password);
        }
        i++;
    }

    if (!encontrado)
        printf("\nCPF nao encontrado.\n");
}

// 4 - Excluir Cliente
void excluirCliente()
{
    char buscar[12];
    int i = 0, encontrado = 0;
    printf("Digite o CPF do cliente que deseja excluir: \n");
    fflush(stdin);
    gets(buscar);

    while (i < cont_clientes)
    {
        int igual = strcmp(buscar, vet_clientes[i].cpf) == 0;
        encontrado += igual;

        int deslocar = 0;
        while (deslocar < cont_clientes - i - 1 && igual)
        {
            vet_clientes[i + deslocar] = vet_clientes[i + deslocar + 1];
            deslocar++;
        }
        if (igual)
            cont_clientes--;
        i++;
    }

    if (!encontrado)
        printf("\nCliente nao encontrado.\n");
    else
        printf("\nCliente excluido com sucesso!\n");
}

// ------------------ PRODUTOS ------------------

// 5 - Cadastrar Produto
void cadastrarProduto()
{
    produtos p;
    int i = 1;
    while (i != 2 && cont_produtos < TF)
    {
        printf("Digite o codigo do produto: \n");
        scanf("%d", &p.cod);
        fflush(stdin);

        int codigoValido = 1;
        int j = 0;
        while (j < cont_produtos)
        {
            codigoValido = codigoValido * (p.cod != vet_produtos[j].cod);
            j++;
        }
        if (!codigoValido)
            printf("Produto ja existente!\n");

        printf("Digite o nome do produto: \n");
        gets(p.nome_produto);
        fflush(stdin);
        printf("Digite a descricao: \n");
        gets(p.descricao);
        fflush(stdin);
        printf("Digite a quantidade em estoque: \n");
        scanf("%d", &p.qtd);
        fflush(stdin);
        printf("Digite o valor do produto: \n");
        scanf("%f", &p.valor);
        fflush(stdin);

        vet_produtos[cont_produtos] = p;
        cont_produtos++;
        printf("\nProduto cadastrado com sucesso!\n");

        printf("Deseja cadastrar mais produtos? 1-Sim 2-Nao\n");
        scanf("%d", &i);
        fflush(stdin);
    }
}

// 6 - Pesquisar Produto
void pesquisarProduto()
{
    int busca, i = 0, encontrado = 0;
    printf("Digite o codigo do produto: \n");
    scanf("%d", &busca);
    fflush(stdin);

    while (i < cont_produtos)
    {
        int igual = busca == vet_produtos[i].cod;
        encontrado += igual;

        if (igual)
        {
            printf("\nProduto encontrado:\n");
            printf("Codigo: %d\n", vet_produtos[i].cod);
            printf("Nome: %s\n", vet_produtos[i].nome_produto);
            printf("Descricao: %s\n", vet_produtos[i].descricao);
            printf("Quantidade: %d\n", vet_produtos[i].qtd);
            printf("Valor: %.2f\n", vet_produtos[i].valor);
        }
        i++;
    }

    if (!encontrado)
        printf("\nProduto nao encontrado.\n");
}

// 7 - Listar Produto
void listarProduto()
{
    if (cont_produtos == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    int i = 0;
    while (i < cont_produtos)
    {
        printf("\nCodigo: %d", vet_produtos[i].cod);
        printf("\nNome: %s", vet_produtos[i].nome_produto);
        printf("\nDescricao: %s", vet_produtos[i].descricao);
        printf("\nQuantidade: %d", vet_produtos[i].qtd);
        printf("\nValor: %.2f\n", vet_produtos[i].valor);
        i++;
    }
}

// 8 - Excluir Produto
void excluirProduto()
{
    int cod, i = 0, encontrado = 0;
    printf("Digite o codigo do produto a ser excluido: \n");
    scanf("%d", &cod);
    fflush(stdin);

    while (i < cont_produtos)
    {
        int igual = cod == vet_produtos[i].cod;
        encontrado += igual;

        int deslocar = 0;
        while (deslocar < cont_produtos - i - 1 && igual)
        {
            vet_produtos[i + deslocar] = vet_produtos[i + deslocar + 1];
            deslocar++;
        }
        if (igual)
            cont_produtos--;
        i++;
    }

    if (!encontrado)
        printf("\nProduto nao encontrado.\n");
    else
        printf("\nProduto excluido com sucesso!\n");
}

// ------------------ FUNCIONARIOS ------------------

// 10 - Cadastrar Funcionario
void cadastrarFuncionario()
{
    funcionarios f;
    int i = 1;
    while (i != 2 && cont_funcionarios < TF)
    {
        printf("Digite o nome do funcionario: \n");
        fflush(stdin);
        gets(f.nome);

        // Email
        int emailValido = 0;
        while (!emailValido)
        {
            printf("Digite o email do funcionario: \n");
            fflush(stdin);
            gets(f.email);

            emailValido = 1;
            int j = 0;
            while (j < cont_funcionarios && emailValido)
            {
                int igual = strcmp(f.email, vet_funcionarios[j].email) == 0;
                emailValido = emailValido * !igual;
                j++;
            }
            if (!emailValido)
                printf("Email ja cadastrado!\n");
        }

        // CPF
        int cpfValido = 0;
        while (!cpfValido)
        {
            printf("Digite o CPF do funcionario: \n");
            fflush(stdin);
            gets(f.cpf);

            cpfValido = 1;
            int j = 0;
            while (j < cont_funcionarios && cpfValido)
            {
                int igual = strcmp(f.cpf, vet_funcionarios[j].cpf) == 0;
                cpfValido = cpfValido * !igual;
                j++;
            }
            if (!cpfValido)
                printf("CPF ja cadastrado!\n");
        }

        // Telefone
        int telValido = 0;
        while (!telValido)
        {
            printf("Digite o telefone do funcionario: \n");
            fflush(stdin);
            gets(f.tel);

            int tamanhoValido = (strlen(f.tel) >= 11 && strlen(f.tel) <= 14);
            int telefoneDuplicado = 0;
            int j = 0;
            while (j < cont_funcionarios)
            {
                telefoneDuplicado += (strcmp(f.tel, vet_funcionarios[j].tel) == 0);
                j++;
            }

            telValido = tamanhoValido * (telefoneDuplicado == 0);
            if (!telValido)
                printf("Telefone invalido ou ja cadastrado.\n");
        }

        printf("Digite a senha do funcionario: \n");
        fflush(stdin);
        gets(f.password);

        vet_funcionarios[cont_funcionarios] = f;
        cont_funcionarios++;
        printf("\nFuncionario cadastrado com sucesso!\n");

        printf("Deseja cadastrar mais funcionarios? 1-Sim 2-Nao\n");
        scanf("%d", &i);
        fflush(stdin);
    }
}

// 11 - Listar Funcionarios
void listarFuncionario()
{
    if (cont_funcionarios == 0)
    {
        printf("\nNenhum funcionario cadastrado.\n");
        return;
    }

    int i = 0;
    while (i < cont_funcionarios)
    {
        printf("\nNome: %s", vet_funcionarios[i].nome);
        printf("\nEmail: %s", vet_funcionarios[i].email);
        printf("\nCPF: %s", vet_funcionarios[i].cpf);
        printf("\nTelefone: %s", vet_funcionarios[i].tel);
        printf("\nSenha: %s\n", vet_funcionarios[i].password);
        i++;
    }
}

// 12 - Pesquisar Funcionario
void pesquisarFuncionario()
{
    char buscar[12];
    int i = 0, encontrado = 0;
    printf("Digite o CPF do funcionario: \n");
    fflush(stdin);
    gets(buscar);

    while (i < cont_funcionarios)
    {
        int igual = strcmp(buscar, vet_funcionarios[i].cpf) == 0;
        encontrado += igual;
        if (igual)
        {
            printf("\nFuncionario encontrado:\n");
            printf("Nome: %s\n", vet_funcionarios[i].nome);
            printf("Email: %s\n", vet_funcionarios[i].email);
            printf("CPF: %s\n", vet_funcionarios[i].cpf);
            printf("Telefone: %s\n", vet_funcionarios[i].tel);
            printf("Senha: %s\n", vet_funcionarios[i].password);
        }
        i++;
    }

    if (!encontrado)
        printf("\nCPF nao encontrado.\n");
}

// 13 - Excluir Funcionario
void excluirFuncionario()
{
    char buscar[12];
    int i = 0, encontrado = 0;
    printf("Digite o CPF do funcionario a ser excluido: \n");
    fflush(stdin);
    gets(buscar);

    while (i < cont_funcionarios)
    {
        int igual = strcmp(buscar, vet_funcionarios[i].cpf) == 0;
        encontrado += igual;

        int deslocar = 0;
        while (deslocar < cont_funcionarios - i - 1 && igual)
        {
            vet_funcionarios[i + deslocar] = vet_funcionarios[i + deslocar + 1];
            deslocar++;
        }
        if (igual)
            cont_funcionarios--;
        i++;
    }

    if (!encontrado)
        printf("\nFuncionario nao encontrado.\n");
    else
        printf("\nFuncionario excluido com sucesso!\n");
}

// ------------------ MAIN ------------------
int main()
{
    int op;
    do
    {
        menu();
        printf("Escolha a opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            cadastrarClientes();
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
            cadastrarProduto();
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
        case 10:
            cadastrarFuncionario();
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
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpcao invalida.\n");
            break;
        }

        system("pause");
        system("cls");
    } while (op != 14);

    return 0;
}
