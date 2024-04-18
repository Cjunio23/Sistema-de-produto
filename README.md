# Sistema-de-produto
Considerando as seguintes estruturas
 typedef struct data{int mes, ano;} TDATA; 
 typedef struct prod{int cod; char nome[50]; float preco; TDATA validade;} TPROD;
Implemente um programa com as seguintes funcionalidades (implemente um menu de opções
contendo todas as funcionalidades).
1) Adicionar produto. O usuário poderá adicionar até 100 produtos. Crie um vetor de
estruturas.
2) Exibir todos os produtos (exiba todos os campos da estrutura). 
3) Exibir o produto mais caro e o mais barato.
4) Excluir um produto. Neste caso, o usuário deverá informar o nome do produto que deseja
excluir. Ao excluir, mova todos os elementos no vetor de tal maneira que não existam posições
vazias (ou com “lixos” de memória). Caso existam mais de um produto com o mesmo nome,
exclua todos eles. 
5) Ordenar produtos. A ordenação deve obedecer o seguinte critério:
a. em ordem crescente de nome (de A→ Z);
b. se dois produtos possuem o mesmo nome, o critério de desempate é a data de validade, isto
é, o produto que possui a data de validade mais próxima aparecerá primeiro; e
c. se os empates persistirem, o critério de desempate é o preço, em ordem decrescente.
