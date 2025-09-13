#include <stdio.h>
#include <windows.h>
typedef struct{

}clientes;
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
void menu_principal(){
    printf("\nDeseja entra em qual conta?");
    printf("\n1 - Administrador");
    printf("\n2 - Cliente");
    printf("\n3 - Sair");
}

void menu_administrador(){
    printf("\n1 - Gerenciar Clientes");
    printf("\n2 - Gerenciar Produtos");
    printf("\n3 - Gerenciar Laboratorios");
    printf("\n4 - Relatorios");
    printf("\n5 - Voltar");
}

void menu_cliente(){ //INCREMENTAR MAIS COISAS
    printf("\n1 - Produtos");
    printf("\n2 - Produtos em Promocoes");
    printf("\n3 - Voltar");
}

void menu_gerenciarClientes(){
    printf("\nGerenciamento de Clientes");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Editar");
    printf("\n4 - Excluir");
    printf("\n5 - Voltar");
}

void menu_gerenciarProdutos(){
    printf("\nGerenciamento de Produtos");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Editar");
    printf("\n4 - Excluir");
    printf("\n5 - Voltar");
}

void menu_gerenciarLaboratorios(){
    printf("\nGerenciamento de Laboratorios");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Editar");
    printf("\n4 - Excluir");
    printf("\n5 - Voltar");
}

void menu_gerenciarLaboratorios(){
    printf("\nMenu de Relatorios");
    printf("\n1 - Cadastrar");
    printf("\n2 - Consultar");
    printf("\n3 - Editar");
    printf("\n4 - Excluir");
    printf("\n5 - Voltar");
}

main(){
    int escolha=0;

    menu_principal();
    scanf("%d",&escolha);
    while (escolha!=3)
    {
        switch (escolha)
        {
        case 1:
            
            break;
        case 2:

            break;
        case 3: 
            printf("\nEncerrando o programa...");
            break;
        default:
            printf("\nCodigo invalido. Tente novamente.");
            break;
        }
        menu_principal();
        scanf("%d",&escolha);
    }
}