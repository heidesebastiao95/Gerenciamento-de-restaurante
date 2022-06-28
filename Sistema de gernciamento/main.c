#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// Variaveis globais.
int res,contFuncionario=0,contEncomenda=0,respostaEncomenda,contCliente=0,contVendas=0;
float dinheiroEncomenda;

// Estrutura para gerenciamento de pratos.

typedef struct Pratos
{
	char pratos[30];
	int codPratos;
	int precPratos;
	
};
 struct Pratos NomePratos[10];
 struct Pratos codigoPratos[10];
 struct Pratos precoPratos[10];
 

typedef struct Cliente
{
	char nomecliente[20];
	char generocliente[10];
	char moradacliente[15];
};

struct Cliente NomeCliente[20];
struct Cliente GeneroCliente[20];
struct Cliente MoradaCliente[20];


//Gerir Encomenda.
void GerirEncomenda(struct Cliente *listanome,struct Cliente *listaGenero,struct Cliente *listaMorada,struct Pratos *listapratos,struct Pratos *listaprecos, struct Pratos *listacodigo){
	printf("Oque deseja encomendar?\n\n");
	
	int i,sair;
    	printf("Pratos\t\t\t\t\t\tPrecos\t\t\t\t\t\tCodigos\n\n");
	for(i=0;i<=9;i++)
	{
		printf("%i.%s\t\t\t\t\t%ikz\t\t\t\t\t%i",i,listapratos[i].pratos,listaprecos[i].precPratos,listacodigo[i].codPratos);
		printf("\n\n\n");
	}
	contEncomenda++;
	scanf("%i",&respostaEncomenda);
	printf("Insira o seu Nome:\n");
	scanf("%s",&listanome[contEncomenda].nomecliente);
	printf("\nInsira o Genero:\n");
	scanf("%s",&listaGenero[contEncomenda].generocliente);
	printf("\nInsira a sua morada:\n");
	scanf("%s",&listaMorada[contEncomenda].moradacliente);
	printf("Insira o valor!\n");
	scanf("%f",&dinheiroEncomenda);
	contCliente++;
	//contEncomenda+=1;
	if(dinheiroEncomenda<listaprecos[respostaEncomenda].precPratos)
	{
		printf("\n\nValor insuficiente!\n\n");
		contEncomenda--;
		contCliente--;
		main();
		
	}else if(dinheiroEncomenda>listaprecos[respostaEncomenda].precPratos|| dinheiroEncomenda==listaprecos[respostaEncomenda].precPratos)
	{
		
		printf("Sair[0]");
		scanf("%i",&sair);
		if(sair==0)
		{
			main();
		}
		
	}
	

}
// Efectuar Venda.

void EfectuarVendas(float valor, int resp,struct Pratos *listaPratos,struct Pratos *listaPrecos,struct Pratos *listaCodigo,struct Cliente *listaNome){
	int rsp;
	float troco;
	if(contEncomenda<=0)
	{
		printf("\n-----Ainda nao foi feita nenhuma encomenda!----\n");
		main();
	}else
	{
		if(valor>listaPrecos[resp].precPratos)
		{
			troco=valor-listaPrecos[resp].precPratos;
		}
		else 
		{
			troco=0;
		}
		printf("-----Venda efectuada!----\n");
		contVendas++;
		printf("\nProduto\t   Valor\tCodigo\tTroco\tCliente\n\n");
		printf("%s %.3fkz  %i %.2fkz %s",listaPratos[resp].pratos,valor,listaCodigo[resp].codPratos,troco,listaNome[contEncomenda].nomecliente);
	//	contEncomenda--;
		printf("\n\nSair[0]");
		scanf("%i",&rsp);
		if(rsp==0)
		{
			main();
		}else
		{
			main();
		}
	}
}

//Gerir Cliente.

void GerirCliente(struct Cliente *listaNome,struct Cliente *listaGenero,struct Cliente *listaMorada){
	
	int i,saida;
	if(contCliente<=0)
	{
		printf("-------Ainda nao temos clientes cadastrados, Efectue uma venda primeiro!--------\n\n ");
		main();
	}else
	{
			printf("Nomes\t\t\t\t\t\tGenero\t\t\t\t\t\tMorada\n\n");
	for(i=0;i<=contCliente;i++)
	{
		printf("%s\t\t\t\t\t%s\t\t\t\t\t%s",listaNome[i].nomecliente,listaGenero[i].generocliente,listaMorada[i].moradacliente);
		printf("\n\n");
	}
	printf("\nSair[0]:\n");
	scanf("%i",&saida);
	if(saida==0)
	{
		main();
	}else
	{
		GerirCliente(NomeCliente,GeneroCliente,MoradaCliente);
	}
	}
	
}

// Ponteiros Para Gerenciamento de pratos.
long int *PonteiroPratos[10];


// Ponteiros Para Gerenciamento de funcionarios.
long int *PonteiroFuncionario[40];
long int *PonteiroMorada[40];
long int *PonteiroCategoria[40];
long int *PonteiroCodigos[40];
long int *PonteiroDatadenascimento[40];


typedef struct Funcionarios
     {
      char nome[100];
      char morada[100];
      char categoria[100];
      char datadenascimento[20];
     int codigo;
    
     };
   
   // Referencias da estrutura Funcionarios.  
  struct  Funcionarios Nome[40];
  struct  Funcionarios Morada[40];
  struct  Funcionarios Categoria[40];
  struct  Funcionarios Codigo[40];
  struct Funcionarios Datadenascimento[40];
  
  
  //Funcao Menu Gerir Funcionarios.
  void MenuGerirFuncionario(){
	  
	  	int resposta,resp2;
	printf("\n-------Menu gerir funcionarios ,esclolha uma opcao----- \n\n");
	printf("\nRegistrar[1]\tActualizar[2]\tConsultar[3]\nListar[4]\tEliminar[5]\t Ir para o Menu principal[6]\n");
	scanf("%i", &resposta);
	switch(resposta)
	{
	case 1:
		AdicionarFuncionarios(Nome,Codigo,Categoria,Morada,Datadenascimento);
	
	case 2:
		//printf("Escolheu a opcao actualizar\n");
		
	     	Actualizar();
			break;
		case 3:
		//	printf("Escolheu a opcao consultar\n");
			Consultar();
			break;
		case 4:
		//	printf("Escolheu a opcao Listar\n");
			Listar(Nome,Categoria);
			break;
		case 5:
		//	printf("Escolheu a Eliminar\n");
		Eliminar(Nome,Categoria);
			break;
		case 6:
			main();
			break;
	
	default:
		MenuGerirFuncionario();
		
		break;
	
	}
	  
  }
  // Funcao para registro. 
  void AdicionarFuncionarios(struct Funcionarios *lista,struct Funcionarios *listaCodigo,struct Funcionarios *listaCategoria,struct Funcionarios *listaMorada,struct Funcionarios *listaDatadenascimento){
  	
  	int i,j,resposta;
     
	 if(contFuncionario==0)
	 {
	 	 printf("\n\n \t\t\t---Iniciar registro---\n\n");
     printf("----Insira o 0 Nome, codigo,categoria , morada e Data de nascimento!---- \n");
     printf("Nome:\n");
		scanf("%s",&lista[0].nome);	
		 	 PonteiroFuncionario[0]= &lista[0].nome;
		printf("Codigo:\n");
			scanf("%i",&listaCodigo[0].codigo);
				PonteiroCodigos[0]=listaCodigo[0].codigo;
        printf("Data de nascimento:\n");
        	scanf("%s",&listaDatadenascimento[0].datadenascimento);
        	PonteiroDatadenascimento[0]=&listaDatadenascimento[0].datadenascimento;
		printf("Categoria:\n");
			scanf("%s",&listaCategoria[0].categoria);
			   	PonteiroCategoria[0]=&listaCategoria[0].categoria;
		printf("Morada:\n");
			scanf("%s",&listaMorada[0].morada);
			 PonteiroMorada[0]=&listaMorada[0].morada;
			 contFuncionario++;
			 
			 	for(i=contFuncionario;i <= 39; i++)
		  {
			
			
		printf(" -----Deseja continuar? SIm [1] Nao[0]-----\n");
		   scanf("%i", &resposta);
			   if(resposta==0)
			  {
			  	MenuGerirFuncionario();
			  	break;
				 
			  }else if(contFuncionario>0)
			  {
			  	
			  	 printf("%iNome:\n",i);
		scanf("%s",&lista[i].nome);	
		printf("%iCodigo:\n",i);
			scanf("%i",&listaCodigo[i].codigo);
        printf("%iData de nascimento:\n",i);
        	scanf("%s",&listaDatadenascimento[i].datadenascimento);
        	PonteiroDatadenascimento[i]=&listaDatadenascimento[i].datadenascimento;
		printf("%iCategoria:\n",i);
			scanf("%s",&listaCategoria[i].categoria);
		printf("%iMorada:\n",i);
			scanf("%s",&listaMorada[i].morada);
			
				contFuncionario++;//Conta a quantidade de funcionarios cadastrados.
				   
			  PonteiroFuncionario[i]= &lista[i].nome;
			  PonteiroMorada[i]=&listaMorada[i].morada;
			PonteiroCategoria[i]=&listaCategoria[i].categoria;
			PonteiroCodigos[i]=listaCodigo[i].codigo;
			  }
			 
			 
			 
			 
		  }
			 
				//contFuncionario++;//Conta a quantidade de funcionarios cadastrados.
		 
	 }else
	 {
	 int j=	contFuncionario;
		 	for(i=j;i <= 39; i++)
		  {
			
			
		printf(" Deseja continuar? SIm [1] Nao[0]\n");
		   scanf("%i", &resposta);
			   if(resposta==0)
			  {
			  	MenuGerirFuncionario();
			  	break;
				 
			  }else
			  {
			  	
			  	 printf("%iNome:\n",i);
		scanf("%s",&lista[i].nome);	
		printf("%iCodigo:\n",i);
			scanf("%i",&listaCodigo[i].codigo);
        printf("%iData de nascimento:\n",i);
        	scanf("%s",&listaDatadenascimento[i].datadenascimento);
        	PonteiroDatadenascimento[i]=&listaDatadenascimento[i].datadenascimento;
		printf("%iCategoria:\n",i);
			scanf("%s",&listaCategoria[i].categoria);
		printf("%iMorada:\n",i);
			scanf("%s",&listaMorada[i].morada);
			
				contFuncionario++;//Conta a quantidade de funcionarios cadastrados.
				   
			  PonteiroFuncionario[i]= &lista[i].nome;
			  PonteiroMorada[i]=&listaMorada[i].morada;
			PonteiroCategoria[i]=&listaCategoria[i].categoria;
			PonteiroCodigos[i]=listaCodigo[i].codigo;
			  }
			 
			 
			 
			 
		  }
	 }
		  
	 
   
		 
  	
	  
  }
  // Funcao Actualizar.
  void Actualizar(){
  	int resposta;
	  printf("-----Ao todo temos:\n\n%i funcionarios cadastrados\n\n %i de %i vagas desponiveis-------",contFuncionario,40-contFuncionario,40);
	  printf("\nVoltar[1]");
	  scanf("%i",&resposta);
	  switch(resposta)
	  {
	  case 1:
		  MenuGerirFuncionario();
		  break;
	  default:
	  	MenuGerirFuncionario();
		  break;
	  }
	  
  }
  //Funcao Listar.
  void Listar(struct Funcionarios *lista,struct Funcionarios *listaCategoria){
  	int i,respost;
  	printf("-------Lista de todos funcionarios cadastrados------\n\n");
	  for(i=0;i<=contFuncionario-1;i++)
	  {
		  printf("%i %s\t\t%s\n",i,lista[i].nome,listaCategoria[i].categoria);
	  }
	  printf("Sair[0]\n");
	  scanf("%i",&respost);
	  	  if(respost==0)
			{
				MenuGerirFuncionario();
			}else
			{
				MenuGerirFuncionario();
			}
	  
  }
  
  //Funcao Consultar.
  
  void Consultar(){
  	int resp;
	  printf("\n\n-----O sistema esta com %i funionarios cadastrados--------- ",contFuncionario);
	  printf("\nSair[0]");
	  scanf("%i",&resp);
	  if(resp==0)
	  {
		  MenuGerirFuncionario();
	  }else
	  {
		  
	  }
	  
  }
     
	//Funcao Eliminar.
	void Eliminar(struct Funcionarios *lista,struct Funcionarios *listacategoria){
		int i, elim,responder,sair,certeza;
		if(contFuncionario<=0)
		{
			printf("\n-----Ainda nao tem funcionarios cadastrados,faca registros!----\n\n");
			MenuGerirFuncionario();
		}else
		{
				printf("-------Quem pretende eliminar?------\n\n");
		for(i=0;i<=contFuncionario-1;i++)
		{
			printf("[%i] %s\n",i,lista[i].nome);
		}
		printf("\n\n Cancelar[0] Continuar[Numero!=0]\n");
		scanf("%i",&sair);
		if(sair==0)
		{
				printf("\n\n------Processo Finalizado--------\n\n");
			MenuGerirFuncionario();
		}else
		{
				printf("-------Quem pretende eliminar?------Olhe para lista.\n\n");
					for(i=0;i<=contFuncionario-1;i++)
		{
			printf("[%i] %s\n\n",i,lista[i].nome);
		}
			scanf("%i",&elim);
			printf("Tem a certeza ?\n\n Sim[1] Nao[0]");
			scanf("%i",&certeza);
			if(certeza==1)
			{
				 strcpy(listacategoria[elim].categoria,"--");
		strcpy(lista[elim].nome,"--");
		printf("\n\n------Processo Finalizado--------\n\n");
		printf("\n\nSair[0]");
		scanf("%i",&responder);
		contFuncionario--;
		MenuGerirFuncionario();
			}
			else
			{
				int elim;
				printf("\n\n--------Processo cancelado-------\n\n");
				MenuGerirFuncionario();
			}
	   
		}
	
		}
	
	}
	
	//funcao Mostrar relatorio.
	
	void MostrarRelatorio(){
		int Sair;
		printf("\n\n-----A quantidade de cliente(s) cadastrado(s) e %i, foram feitas %i encomendas e %i vendas----\n\n",contCliente,contEncomenda,contVendas);
		printf("Sair[0]");
		scanf("%i",&Sair);
		if(Sair==0)
		{
			main();
		}else
		{
			MostrarRelatorio();
		}
	}
	
int main()
{ 
	//Inicializacao de funcoes.
	
void Funcionarios();
int MenuPratos();
void MenuGerirFuncionario();
void AdicionarFuncionarios();
void Pratos();
void ConsultarPratos();
void Actualizar();
void Listar();
void Consultar();
void Eliminar();
void Troca();
void Cliente();



//void GerirEncomenda();

//Inicializar pratos.
strcpy(NomePratos[0].pratos,"Arros de pato");
strcpy(NomePratos[1].pratos,"Mufete       ");
strcpy(NomePratos[2].pratos,"Arroz doce");
strcpy(NomePratos[3].pratos,"Cuzido       ");
strcpy(NomePratos[4].pratos,"feijoada     ");
strcpy(NomePratos[5].pratos,"Caldo        ");
strcpy(NomePratos[6].pratos,"Calderada    ");
strcpy(NomePratos[7].pratos,"Sopa         ");
strcpy(NomePratos[8].pratos,"Saladas      ");
strcpy(NomePratos[9].pratos,"Bacalhão com natas");

	 //Inicializar precos
	 //printf("%.3f\n%.3f\n%.3f\n\n",precoPratos[0].precPratos,precoPratos[1].precPratos,precoPratos[2].precPratos);
 precoPratos[0].precPratos = 1500;
 precoPratos[1].precPratos = 2000;
 precoPratos[2].precPratos = 600;
 precoPratos[3].precPratos = 2500;
 precoPratos[4].precPratos = 1000;
 precoPratos[5].precPratos = 1500;
 precoPratos[6].precPratos = 2000;
 precoPratos[7].precPratos = 600;
 precoPratos[8].precPratos = 2000;
 precoPratos[9].precPratos = 2500;
 
 //Inicializar codigo dos pratos
 //printf("%i\n%i\n%i\n\n",codigoPratos[0].codPratos,codigoPratos[1].codPratos,codigoPratos[3].codPratos);
 codigoPratos[0].codPratos = 1304;
 codigoPratos[1].codPratos = 3101;
 codigoPratos[2].codPratos = 1302;
 codigoPratos[3].codPratos = 4403;
 codigoPratos[4].codPratos = 3604;
 codigoPratos[5].codPratos = 2105;
 codigoPratos[6].codPratos = 2410;
 codigoPratos[7].codPratos = 3712;
 codigoPratos[8].codPratos = 2013;
 codigoPratos[9].codPratos = 4014;
 



		printf("\t \t-------Menu inicial ,escolhe uma opcao!-----\n \n");
			printf("Gerir pratos[1] \tGerir funcionarios[2]\tGerir clientes[3]\n \nGerir encomenda[4]\tEfectuar venda[5]\tMostrar relatorio[6] \n\nSair[7]\n\n ");
		scanf("%i", &res);
		if(res==7){
			return 0;
		
		}else
		{
			switch(res)
	{
	case 1:
		contFuncionario++;
		MenuPratos();
		break;
	case 2:
		//	printf("escolheu a opcao Gerir funcionarios \n\n");
		   MenuGerirFuncionario();
			break;
		case 3:
			//	printf("escolheu a opcao Gerir clientes\n\n");
			 GerirCliente(NomeCliente,GeneroCliente,MoradaCliente);
				break;
			case 4:
				//	printf("escolheu a opcao Mostrar relatorio!\n\n");
				  GerirEncomenda(NomeCliente,GeneroCliente,MoradaCliente,NomePratos,precoPratos,codigoPratos);
					break;
				case 5:
					 EfectuarVendas(dinheiroEncomenda,respostaEncomenda,NomePratos,precoPratos,codigoPratos,NomeCliente);
					 break;
				 case 6:
				 	MostrarRelatorio();
				 	break;
				 case 7:
				 	return 0;
				 	break;
	default:
			//printf("------- Opcao invalida!\n\n");
			main();
		break;
	
	}
			
	
    
		}
	return 0;
		
}

//Funcao consultar pratos
void ConsultarPratos(struct Pratos *listapratos, struct Pratos *listaprecos,struct Pratos *listacodigo){
	int i;
    	printf("Pratos\t\t\t\t\t\tPrecos\t\t\t\t\t\tCodigos\n\n");
	for(i=0;i<=9;i++)
	{
		printf("%i.%s\t\t\t\t\t%ikz\t\t\t\t\t%i",i,listapratos[i].pratos,listaprecos[i].precPratos,listacodigo[i].codPratos);
		printf("\n\n");
	}
	
}
//Funcao Menu pratos
int MenuPratos(){
	
	int resposta,resp2;
	printf("\n-----Menu pratos ,esclolha uma opcao------ \n\n");
	printf("\nconsultar pratos[1]\tVoltar para o menu principal[2]\n\n");
	scanf("%i", &resposta);
	
	switch(resposta)
	{
	case 1:
		ConsultarPratos(NomePratos,precoPratos,codigoPratos);
		printf("\nPara voltar ao menu inicial prima[1]\n");
		scanf("%i",&resp2);
		if(resp2==1){
			main();
		}else
		{
			printf("\nOpcao invalida!, tente novamente\n");
				scanf("%i",&resp2);
				switch(resp2)
				{
				case 1:
						main();
					break;
				default:
					MenuPratos();
					break;
				}
		}
	
	case 2:
		main();
			
			break;
	
	default:
		MenuPratos();
		
		break;
	
	}
	return 0;
}