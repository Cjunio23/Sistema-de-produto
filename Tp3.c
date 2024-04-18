#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#define max_produtos 100
typedef struct data{//Estrutura das validades
    int mes;
    int ano;
}TDATA;
typedef struct prod{//Estruturas dos produtos
    int cod;
    char nome[50];
    float preco;
    TDATA validade;
}TPROD;

  struct prod produtos[max_produtos];//Ate 100 produtos
   int P;
   int n_produtos = 0;//contador de produtos
    void cadastraproduto(struct prod produto){//Cadastrar um novo produto.(1)
    printf("\tCodigo: ");
      scanf("%d", &produto.cod);
      fflush(stdin);
    printf("\tNome: ");
      gets(produto.nome);
      fflush(stdin);
    printf("\tPreco R$: ");
      scanf("%f", &produto.preco);
      fflush(stdin);
    printf("\tValidade Mes e Ano: ");
      scanf("%d %d", &produto.validade.mes, &produto.validade.ano);
      produtos[n_produtos] = produto;
      n_produtos++;
}
void TodosOsProdutos(){//imprimir todos os produtos na tela(2)
    for (P=0; P < n_produtos; P++){
        printf("\n-------------------------------------------------------------\n");
        printf("\tCodigo: %d\n", produtos[P].cod);
        printf("\tNome: %s", produtos[P].nome);
        printf("\tPreco R$: %.2f \n", produtos[P].preco);
        printf("\tValidade Mes e Ano: %d %d", produtos[P].validade.mes,produtos[P].validade.ano);
        printf("\n-------------------------------------------------------------\n");
    }
}
void ProdutoMaisCaroBarato(){//Funcao para produto mais caro e o mais barato(3)
  float mn = produtos[0].preco, mm = 0;
   for (P=0; P < n_produtos; P++){
    if (produtos[P].preco < mn)
       mn = produtos[P].preco;
    if(produtos[P].preco > mm)
       mm = produtos[P].preco;
   }
      for(P=0; P < n_produtos; P++){
        if(produtos[P].preco == mm)
        printf("Produtos mais caro: %s  %.2f \n",produtos[P].nome,produtos[P].preco);
      }
        for(P=0; P < n_produtos; P++){
          if(produtos[P].preco == mn)
          printf("Produtos mais barato: %s   %.2f\n",produtos[P].nome,produtos[P].preco);
       }
}

void ExcluirUmProduto(){//Funcao para excluir produto(4)
  int i,valor[n_produtos],j = 0,k = 0,x = 0;
  char excluir[51];
  int vdd = 0;
  TPROD aux[100];
   printf("Qual produto(s) deseja excluir ?\n");
   gets(excluir);
       for(i = 0; i < n_produtos; i++){
         if (strcmp(produtos[i].nome, excluir) != 0){
         aux[k] = produtos[i];
         k++;
         vdd = 1;
         }else{j++;}
      }
      if(k == n_produtos){
       printf("Produto nao encontrado\n");
        return;
       }   n_produtos = n_produtos-j;
          for(i = 0; i < n_produtos; i++){
           produtos[i] = aux[i];
          }
          printf("Produto(s) excluido\n");
       return;
}

void trocar(int i, int j){//Organizar os produtos.
   TPROD k;
   k = produtos[i];
   produtos[i] = produtos[j];
   produtos[j] = k;
}

void OrdenaProduto(){//Funcao para ordena produto(5)
 int i,j;
   printf("\n-------------------------------------------------------------\n");
   printf("Produtos em ordem crecente de nome:\n");
   for(i=0 ; i < n_produtos; i++)
   {
    for(j=i+1; j < n_produtos; j++)
    {
       int comparacao = strcmp(produtos[i].nome, produtos[j].nome);//Comparacao de nome.
       if(comparacao > 0){
         trocar(i, j);
    }else if (comparacao == 0){
     if(produtos[i].validade.ano > produtos[j].validade.ano){//Comparacao de validade ano.
        trocar(i, j);
       }else if (produtos[i].validade.ano == produtos[j].validade.ano){
             if(produtos[i].validade.mes > produtos[j].validade.mes)//Comparacao de validade de mes.
             trocar(i, j);
            }else if (produtos[i].validade.mes == produtos[j].validade.mes){
                 if(produtos[i].preco > produtos[j].preco){//Comparacao de valor.
                  trocar(j, i);
                 }
                }
      }
     }
    }
TodosOsProdutos();//Funçao para exibir todos os produtos.
printf("\n-------------------------------------------------------------\n");
}

 int menu(){//Menu de opcoes de funçoes do programa
    int opcao;
    printf("\n--------------------------------------------------------------------\n");
    printf("\t\t\t\t MENU \n");
    printf("\t0: SAIR. \n");
    printf("\t1: Cadastrar um novo produto. \n");
    printf("\t2: Exibir todos os produtos. \n");
    printf("\t3: Exibir o produto mais caro e o mais barato. \n");
    printf("\t4: Excluir um produto. \n");
    printf("\t5: Ordenar produtos. \n");
    printf("\n Selecione uma opcao ? ");
    printf("\n--------------------------------------------------------------------\n");
    scanf("%d", &opcao);
    fflush(stdin);
    return opcao;
}
int main()//Inicio do programa
{
    int selecionada;//Opcao para selecionar sua funcao
    struct prod novo_produto;

    do {//Estrutura de repeticao
        selecionada = menu();
        switch(selecionada)//Para seleionar a funcao que deseje realizar
        {
            case 0:
                break;
            case 1: // código para inserir
                if (n_produtos == max_produtos)//Caso ultrapasse o valor de 100 itens
                {
                    printf("\n Cheio\n");
                    break;
                }
                cadastraproduto(novo_produto);//codigo para criar novo produto
                break;
            case 2: //codigo para exibir
                TodosOsProdutos();
                break;
            case 3: //codigo para exibir produto mais caro e o mais barato
                ProdutoMaisCaroBarato();
                break;
            case 4: //codigo para excluir um produto
                 ExcluirUmProduto();
                 break;
            case 5://codigo para ordenar um produto
                 OrdenaProduto();
                  break;
            default://se a opçao escolhida nao existir imprimir essa mensagem
                printf("----- OPCAO INVALIDA -----");
        }
    system("pause");
    system("cls");
    }while (selecionada != 0);//Vai continuar enquato o valor digitado for diferente de 0.
    return 0;
}
