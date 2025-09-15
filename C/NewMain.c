#include <stdio.h>
#include <string.h>
#include <windows.h>
#define TF 10
//[]
/*
    Funções Basicas:
    - Gerenciar Clientes
        - Nome, RG, Telefone, e Endereço.
        - Permite cadastrar, consultar, editar e excluir informações de clientes
    - Gerenciar Produtos
        - Nome do Produto, Marca, Categoria, Estoque, Preço
        - Permite cadastrar, consultar, editar e excluir suplementos vendidos
    - Gerenciar Tipos de Produtos
        - Tipo (Ex: Medicamento,Cosmético)
        - Definir ou editar tipos vinculados aos produtos
    - Gerenciar Laboratorios
        - Nome, CNPJ, Contato
        - Cadastro e controle de laboratórios fabricantes
    - Gerenciar Categorias
        - Categoria (ex: Genérico, Controlado)
        - Definir e editar categorias de produtos

    Funções Fundamentais:
    - Promoção dos produtos prócimos ao vencimento
        - Definir data (ex: 3 meses antes de vencer) para entrar em promoção
    - Efetuar Venda
    - Efetuar Compra
    - Efetuar Descarte

    Relatorios Gerais:
    (Esses relatórios estão no Trabalho de APS então precisam ser feitos!)

    - Listar produtos proximo ao vencimento com filtro por periodo.
        -
    - Relatório de Produtos com Estoque Zerado.
        - Autoexplicativo
    - Relatório de Vendas por Cliente
        - Quanto cada Cliente Comprou
    - Relatório de Vendas por Periodo
        - Vendas na última semana
        - Vendas no último mes
        - Vendas nos últimos seis meses
        - Vendas no último ano
*/
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

// MENUS

void menu_principal()
{
    printf("\nDeseja entra em qual conta?");
    printf("\n1 - Administrador");
    printf("\n2 - Cliente");
    printf("\n3 - Sair");
}

void menu_administrador()
{
    printf("\n1 - Gerenciar Clientes");
    printf("\n2 - Gerenciar Produtos");
    printf("\n3 - Gerenciar Laboratorios");
    printf("\n4 - Relatorios");
    printf("\n5 - Voltar");
}

void menu_cliente()
{ // INCREMENTAR MAIS COISAS
    printf("\n1 - Produtos");
    printf("\n2 - Produtos em Promocoes");
    printf("\n3 - Voltar");
}

void menu_gerenciarClientes()
{
    printf("\nGerenciamento de Clientes");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Editar");
    printf("\n4 - Excluir");
    printf("\n5 - Voltar");
}

void menu_gerenciarProdutos()
{
    printf("\nGerenciamento de Produtos");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Editar");
    printf("\n4 - Excluir");
    printf("\n5 - Voltar");
}

void menu_gerenciarLaboratorios()
{
    printf("\nGerenciamento de Laboratorios");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Editar");
    printf("\n4 - Excluir");
    printf("\n5 - Voltar");
}

void menu_relatorios()
{
    printf("\nMenu de Relatorios");
    printf("\n1 - Relatorio de produtos com estoque zerado.");
    printf("\n2 - Relatorio de Vendas por Cliente.");
    printf("\n3 - Relatorio de Vendas por Periodo.");
    printf("\n4 - Relatorio de produtos proximos ao vencimento.");
    printf("\n5 - Voltar");
}

int main()
{
    int menuprincipal = 0, menuadm = 0, menucliente = 0, menugerenciacli = 0, menugerenciaprodu = 0, menugerencialab = 0;

    do
    {
        menu_principal();
        printf("\nEscolha a opcao: ");
        scanf("%d", &menuprincipal);
        fflush(stdin);
        switch (menuprincipal)
        {
        case 1: // menu principal ------------------------
            menu_administrador();
            printf("\nEscolha a opcao: ");
            scanf("%d", &menuadm);
            fflush(stdin);
            switch (menuadm)
            {
            case 1://menuadm -----------------------
                menu_gerenciarClientes();
                printf("\nEscolha a opcao: ");
                scanf("%d", &menugerenciacli);
                fflush(stdin);
                switch (menugerenciacli)
                {
                case 1://menugerencli ----------------------------
                    //cadastrarClientes();
                    break;
                case 2:
                    //pesquisarCliente();
                    break;
                case 3:

                    // fazer editar cliente

                case 4:
                    //excluirCliente(&cont_clientes);
                    break;
                case 5:
                    printf("\nVoltando...");
                    break;
                default://menugerencli ---------------------
                    printf("\nCodigo invalido. Tente novamente.");
                    break;
                }
                break;
            case 2:
                menu_gerenciarProdutos();
                printf("\nEscolha a opcao: ");
                scanf("%d", &menugerenciaprodu);
                fflush(stdin);
                switch (menugerenciaprodu)
                {
                case 1://menugerenprodu ----------------------------
                    //cadastroProduto();
                    break;
                case 2:
                    //pesquisarProduto();
                    break;
                case 3:
                    // fazer editar cliente
                    break;
                case 4:
                    //excluirProduto(&cont_produtos);
                    break;
                case 5:
                    printf("\nVoltando...");
                    break;
                default://menugerenprodu ---------------------------
                    printf("\nCodigo invalido. Tente novamente.");
                    break;
                }
                break;
                
            case 3:
                menu_gerenciarLaboratorios();
                printf("\nEscolha a opcao: ");
                scanf("%d", &menugerencialab);
                fflush(stdin);
                switch (menugerencialab)
                {
                    
                case 1://menugerenlab --------------------------
                    //cadastroLab(); // fazer
                    break;
                case 2:
                    //pesquisarLab(); // fazer
                    break;
                case 3:
                    // fazer editar laboratorio
                    break;
                case 4:
                    //excluirLab(); // fazer
                    break;
                case 5:
                    printf("\nVoltando..."); // fazer
                    break;
                default: //menugerenlab ---------------------------
                    printf("\nCodigo invalido. Tente novamente."); // fazer
                    break;
                }
                break;
            case 4:
                // FAZER TODOS RELATÓRIOS
                break;
            case 5:
                printf("\nVoltando...");
                break;
            default://menuadm ------------------------
                printf("\nCodigo invalido. Tente novamente");
                break;
            }
            break;
        case 2: 
            menu_cliente();
            printf("\nEscolha a opcao: ");
            scanf("%d", &menucliente);
            fflush(stdin);
            switch (menucliente)
            {
            case 1://cliente -------------------

                break;
            case 2:

                break;
            case 3:
                printf("\nVoltando...");
                break;
            default://cliente -------------------
                printf("\nCodigo invalido. Tente novamente");
                break;
            }
            break;
        case 3: 
            printf("\nEncerrando o programa...");
            break;
        default: //menuprincipal ------------------
            printf("\nCodigo invalido. Tente novamente.");
            break;
        }
        system("pause");
        system("cls");
    } while (menuprincipal != 3);
    //[]
}