#include <stdio.h>

#include <string.h>

#include <math.h>

#include <stdlib.h>

#include <unistd.h>

#define N 100

typedef struct{
	char nombrecliente[N];
	int numerotarjeta,pintarjeta;
	float saldo;
}tarjeta;

float saldoTarjeta(float retirada,float ingreso,float saldoactual);

float transferencia(float saldoemisor,float saldoreceptor,float transf);

int main()
{
	system("cls");//Limpiar pantalla
	
	float retirada;
	float ingreso;
	float cantidad, cantidad2;
	int numcliente=0;//para guardar el cliente que ha entrado en el banco
	int nt;//numero de tarjeta introducido por el usuario al iniciar sesion.
	int comparar;
	int comparar2;
	int comparar3;
	int clienreceptor=0;//para guardar al cliente al que se le va a realizar la tranferencia
	int nuevopin,np,pin;
	char operacion;
	int sn;
	int pin2;
	int intentos=0,intentos2=0;
	int i=0,j=0,k;
	tarjeta clientes[N];
	FILE *pf;//puntero para el fichero
	pf=fopen("clientesdelbanco.txt","r");
	if(pf==NULL)
	{
		printf("No se puedo abrir correctamente el fichero\n");
		return -1;
	}
	else
	{
		while(fscanf(pf,"%[^;];%d;%d;%f\n",clientes[j].nombrecliente,&clientes[j].numerotarjeta,&clientes[j].pintarjeta,&clientes[j].saldo)!=EOF)
		{
			j++;
		}
	}
	fclose(pf);
	printf("Bienvenido.\n");
	printf("Iniciar sesion:\n");
	//primero introduce la tarjeta y verificamos que el numero de tarjeta existe en nuestro cajero.
	do{
	printf("Introduce el numero de tu tarjeta:\n");
	scanf("%d",&nt);
	for(k=0;k<12;k++)
		{
	
		if(nt==clientes[k].numerotarjeta)
		{
			comparar=1;
			numcliente=k;
		printf("El numero de tarjeta es correcto.\n");	
		}
		}

	intentos++;	
	}while(intentos<3 && comparar==0);
		if(comparar==0)
		{
			printf("Ha agotado el numero de intentos.\n");
			printf("Vuelva a intentarlo mas tarde.\n");
			printf("Procedemos a la retirada de la tarjeta.\n");
			return 0;
			
		}
	//le pedimos el pin al usuario y tiene tres intentos para introducirlo correctamente.
	do{ 
			printf("Introduzca el pin:\n "); 
			scanf("%d", &pin); 
			if(pin==clientes[numcliente].pintarjeta)
			{
				comparar=1;
			printf("\n El pin es correcto.\n");
			printf("Bienvenido.\n");
		    } 
		    intentos++;
			}while (intentos<3 && comparar==0);
		if(comparar==0)
			{
				printf("Ha superado el numero de intentos.\n");
				printf("Vuelva a intentarlo mas tarde.\n");
				return 0;
			}
	//este do-while lo he puesto para que tras cada operacion menos la opcion salir me de la posibilidad de realizar otra operacion.
	do{
	
	//menu	
	system("cls");
	printf("---------MENU--------\n");

	printf("Elige su opcion:\n\n");

	printf("1-Retirar dinero:\n");

	printf("2-Ingresar dinero:\n");

	printf("3-Cambiar codigo pin:\n");

	printf("4-Consultar saldo actual:\n");
	
	printf("5-Realizar una transferencia:\n");

	printf("6-Salir:\n");
	
	printf("Teclee el numero que aperece delante de la opcion deseada.\n");

	scanf("%i",&operacion);
	
	switch(operacion)
	{
		case 1:
			
			do{
			printf("Introducir cantidad que desea retirar:\n"); 
			scanf("%f", &cantidad);
			if(cantidad<=clientes[numcliente].saldo)
					{
				    clientes[numcliente].saldo=saldoTarjeta(cantidad,0,clientes[numcliente].saldo); 
					printf("Procedamos a la retirada de %.2f.\n",cantidad);
					printf("Tras la retirada dispone de %.2f\n",clientes[numcliente].saldo);
				    }
			intentos++;  
			}while (intentos<3 && cantidad>clientes[i].saldo);
			// en las 5 primeras opciones del menu hemos puesto la opcion de realizar otra 
			//operacion con un do-while.
			printf("¿Desea realizar otra operacion?\n");
			printf("Teclee 0 si desea realizar otra operacion\n");
			printf("en caso contrario pulse 1.\n");
			scanf("%d",&sn);
		break;
		case 2:
			
			printf ("Escriba la cantidad de dinero que desee ingresar:\n");
			scanf("%f",&cantidad2);
			printf("Ingreso realizado con exito.\n");
                clientes[numcliente].saldo=saldoTarjeta(0,cantidad2,clientes[numcliente].saldo);
			printf("Su nuevo saldo es %.2f\n",clientes[numcliente].saldo);
			printf("¿Desea realizar otra operacion?\n");
			printf("Teclee 0 si desea realizar otra operacion\n");
			printf("en caso contrario pulse 1.\n");
			scanf("%d",&sn);
						
		break;
		case 3:
			do{ 
				printf("Escriba su pin actual.\n"); 
				scanf("%i", &pin2); 
					if(pin2==clientes[numcliente].pintarjeta) //en caso de que los dos pines coincidan 
					{
						comparar3=1;
						printf("Introduzca su nuevo pin:\n");
						scanf("%d",&nuevopin);
									clientes[numcliente].pintarjeta=nuevopin;
									printf("Su codigo pin se ha cambiado con exito.\n");
					}
					intentos2++;  
			}while (intentos2<4 && comparar3==0);
			if(comparar3==0)//tras superar el numero de intentos se acaba el programa.
			{
				printf("Vuelva a intentarlo mas tarde.\n");
				return 0;
			}
			printf("¿Desea realizar otra operacion?\n");
			
			printf("Teclee 0 si desea realizar otra operacion\n");
			printf("en caso contrario pulse 1.\n");
			scanf("%d",&sn);
		 break; 
		case 4:
			
			printf("Su saldo actual es de:%.2f\n",clientes[numcliente].saldo);
		
			printf("¿Desea realizar otra operacion?\n");
			
			printf("Teclee 0 si desea realizar otra operacion\n");
			printf("en caso contrario pulse 1.\n");
			scanf("%d",&sn);
		break;
		case 5:
			{
				printf("Se le presentara una lista en pantalla con los nombres de las personas\n");
				printf(" a las que puede realizar una tranferencia.\n");
				for(i=0;i<12;i++)
				{
					printf("%i:%s\n",i+1,clientes[i].nombrecliente);

				}
				printf("Teclee el numero que aparece delante del usuario al que desee realizar una transferencia:\n");

				scanf("%i",&numcliente);
				// he restado un 1 ya que al imprimir la lista de nombres habia definido
				// i como 0.
				numcliente=numcliente-1;
				
				printf("Escriba la cantidad que desee transferir:\n");

				scanf("%f",&cantidad);
				
				clientes[numcliente].saldo=transferencia(clientes[numcliente].saldo,clientes[clienreceptor].saldo,cantidad);

				printf("Se ha realizado la transferencia correctamente.\n");
				printf("Su nuevo saldo es %.2f.\n",clientes[numcliente].saldo);
				
				printf("¿Desea realizar otra operacion?\n");
				printf("Teclee 0 si desea realizar otra operacion\n");
				printf("en caso contrario pulse 1.\n");
				scanf("%d",&sn);

				break;	

			}
		case 6:
				pf= fopen("clientesdelbanco.txt","w");
				if(pf==NULL)
				{
					printf("Error al abrir el fichero\n");
					return -1;
				}
				else
				{
					i=0;
					while(i<j)
					{
						fprintf(pf,"%i  %[^;];%d;%d;%f\n",i+1,clientes[i].nombrecliente,&clientes[i].numerotarjeta,&clientes[i].pintarjeta,&clientes[i].saldo);
						i++;
					}
					fclose(pf);
					printf("Hasta pronto.\n");	
				}
			break;
		default:

				printf("Opcion incorrecta\n");
			break;							 	
	}
	}while(sn==0 && operacion!=6);
	if(sn==1)
	{
		printf("¡Hasta pronto!\n");
		printf("Esperamos que haya disfrutado de nuestros servicios.\n");
	}
	return 0;
}

//Esta funcion calcula el saldo tras una operacion.
float saldoTarjeta(float retirada,float ingreso,float saldoactual)
{
	saldoactual=saldoactual+ingreso-retirada;
	return saldoactual;
}
	
//Esta funcion realiza los cambios de saldo tras una transferencia.
float transferencia(float saldoemisor,float saldoreceptor,float transf)
{
	saldoemisor=saldoemisor - transf;
	saldoreceptor=saldoreceptor +transf;
	return saldoemisor;
}	
	
	
