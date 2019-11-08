#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX1 50
#define MAXcad 10

//Giovanne Pierazolli Sant'Anna Marconcin
//1912885

struct Cadastro
{
    int sit;
    int id;
char nome[MAX1];
int d;
int m;
int a;
char cpf[MAX1];

};
typedef struct Cadastro cad;

	void flush_in()
	{
	   int ch;
	
	   while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
	} 


void cad1(cad c[], int id);
void list2(cad c[]);
void pesq3(cad c[]);
void at4(cad c[]);
void rem5(cad c[]);



int main()
{
    cad c[MAX1];
    int op;
    int id=0;

    do
    {
    printf("\n _________________\n");
    printf("|Digite uma opcao:|\n");
    printf("|_________________|\n\n");
    printf("1-Cadastrar\n");
    printf("2-Listar\n");
    printf("3-Pesquisar\n");
    printf("4-Atualizar\n");
    printf("5-Remover\n");
    printf("6-Sair\n\n");

    scanf("%d", &op);



    if(op==1){  //Cadastrar
        if(id>MAXcad-1){}
        else{
        cad1(c, id);
        id++;
        op=0;
        continue;
        }
     }

    if(op==2){ //Listar
        list2(c);
        op=0;
        continue;

     }

    if(op==3){ //Pesquisar
        pesq3(c);
        op=0;
        continue;
    }


    if(op==4){ //Atualizar
        at4(c);
        op=0;
        continue;
    }


    if(op==5){ //Remover
        rem5(c);
        op=0;
        continue;

    }

    else{}
    }while(op!=6);

}

void cad1(cad c[], int id)
{


	flush_in();
    printf("Digite o Nome:\n");
    gets(c[id].nome);




    printf("Digite o dia, mes e ano de nascimento, respectivamente:\n");
	scanf(" %d %d %d", &c[id].d, &c[id].m, &c[id].a);



	
    while(c[id].d>31 || c[id].d<=0 || c[id].m>12 || c[id].m<=0)
    {
        printf("Erro, digite novamente\n");
        
        printf("Digite o dia, mes e ano de nascimento, respectivamente:\n");
        scanf(" %d %d %d", &c[id].d, &c[id].m, &c[id].a);
		
    }

	

	flush_in();
    printf("Digite o CPF:\n");
    gets(c[id].cpf);


    c[id].sit=1;
    c[id].id=id+1;

    printf("\nCadastro realizado com sucesso!!\n");
}

void list2(cad c[])
{
    int i;
    for (i=0; i<MAXcad; i++) {
            if (c[i].sit==1){
                printf("\nDados do Estudante %d:\n", i+1);
                printf("ID = %d\n", c[i].id);
                printf("Nome = %s\n", c[i].nome);
                printf("Data de Nascimento = %d/%d/%d\n", c[i].d, c[i].m, c[i].a);
                printf("CPF = %s\n\n", c[i].cpf);
            }
            else{}
}
}

void pesq3(cad c[]){

    char test[MAX1];
    int i, r;

    flush_in();
    printf("Digite o nome do estudante (Utilize letras maiusculas, minusculas, espacos e qualquer pontuacao q contenha no nome):\n");
    gets(test);

    for (i=0; i<MAXcad; i++) {
        r=strcmp(test, c[i].nome);
        if (r==0){
            if (c[i].sit==1){
                printf("\nDados do Estudantes %d:\n", i+1);
                printf("ID = %d\n", c[i].id);
                printf("Nome = %s\n", c[i].nome);
                printf("Data de Nascimento = %d/%d/%d\n", c[i].d, c[i].m, c[i].a);
                printf("CPF = %s\n\n", c[i].cpf);

            }

        }

    }


}

void at4(cad c[]){

    int id;

    printf("Digite o ID que voce deseja atualizar:\n");
    scanf(" %d", &id);

    id--;

    flush_in();
    printf("Digite o Nome:\n");
    gets(c[id].nome);


    //flush_in();
    printf("Digite o dia, mes e ano de nascimento, respectivamente:\n");
    scanf(" %d %d %d", &c[id].d, &c[id].m, &c[id].a);

    while(c[id].d>31 || c[id].d<=0 || c[id].m>12 || c[id].m<=0)
    {
        printf("Erro, digite novamente\n");
       // flush_in();
        printf("Digite o dia, mes e ano de nascimento, respectivamente:\n");
        scanf(" %d %d %d", &c[id].d, &c[id].m, &c[id].a);
    }

    flush_in();
    printf("Digite o CPF:\n");
    gets(c[id].cpf);



    c[id].sit=1;

    printf("\nAtualizacao realizada com sucesso!!\n");

}

void rem5(cad c[]){

    int id;

    printf("Digite o ID que voce deseja remover:\n");
    scanf(" %d", &id);

    id--;

    c[id].sit=0;

    printf("\nID removido com sucesso!!\n");
}





