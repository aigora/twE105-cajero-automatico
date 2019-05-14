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

float Tranferencia(float saldoemisor,float saldoreceptor,float transf);

int main()
{
	system("cls");//Limpiar pantalla
	
	float retirada;
	float ingreso;
	float cantidad;
	int numcliente=0;//para guardar el cliente que ha entrado en el banco
	int nt;//numero de tarjeta introducido por el usuario al iniciar sesion.
	int comparar;
	int comparar2;
	int comparar3;
	int clienreceptor=0;//para guardar al cliente al que se le va a realizar la tranferencia
	int nuevopin,np,pin;
	char operacion;
	char sn;
	int intentos=0;
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
		while(fscanf(pf,"%[^\t]\t%d\t%d\t%f\n",clientes[j].nombrecliente,&clientes[j].numerotarjeta,&clientes[j].pintarjeta,&clientes[j].saldo)!=EOF)
		{
			j++;
		}
	}
	fclose(pf);
	printf("Bienvenido.\n");
	printf("Iniciar sesion:\n");
	//primero introduce la tarjeta y verificamos que el numero de tarjeta existe en nuestro cajero.
	do{
	printf("Introduce el numero de tu tarjeta.\n");
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
	if(comparar==0)
		{
			printf("El numero de tarjeta es incorrecto.");
		}
	intentos++;	
	}while(intentos<3 && comparar==0);
	//le pedimos el pin al usuario y tiene tres intentos para introducirlo correctamente.
	do{ 
			printf("Introduzca el pin:\n "); 
			scanf("%d", &pin); 
			if(pin==clientes[numcliente].pintarjeta)
			{
				comparar2=1;
			printf("\n El pin es correcto.\n");
			printf("Bienvenido.\n");
		    } 
		    intentos++;
			}while (intentos<4 && comparar2==0);
		if(comparar2==0)
			{
				printf("Ha superado el numero de intentos.\n");
				printf("Vuelva a intentarlo mas tarde.\n");
				return 0;
			}
	
	//menu	
	system("cls");
	printf("---------MENU--------\n");

	printf("Elige su opcion:\n\n");

	printf("1-Retirar dinero:\n");

	printf("2-Ingresar dinero:\n");

	printf("3-Cambiar codigo pin:\n");

	printf("4-Consultar saldo actual:\n");
	
	printf("5-Realizar una tranaferencia:\n");

	printf("6-Salir:\n");

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
		break;
		case 2:
			
			printf ("Escriba la cantidad de dinero que desee ingresar:\n");
			scanf("%i",&cantidad);
			printf("Ingreso realizado con exito.\n");
                clientes[numcliente].saldo=saldoTarjeta(0,cantidad,clientes[numcliente].saldo);
			printf("su nuevo saldo es %.3f",clientes[numcliente].saldo);
						
		break;
		case 3:
			do{ 
				printf("Escriba su pin actual.\n"); 
				scanf("%d", &pin); 
					if(pin==clientes[numcliente].pintarjeta) 
					{
						comparar2=1;
						do{
						printf("Introduzca su nuevo pin:\n");
						scanf("%d",&nuevopin);
						printf("Confirme el nuevo pin:\n");
						scanf("%d",&np);
						
								if(np=nuevopin)
								{
									comparar3=1;
									clientes[numcliente].pintarjeta=nuevopin;
									printf("Su codigo pin se ha cambiado con exito.\n");
								}
								intentos++;
						}while (intentos<3 && comparar3==0);
						if(comparar3==0)
						{
							printf("Ha agotado el numero de intentos.\n");
							printf("Vuelva a intentarlo más tarde.\n");
						}	    
					}
					intentos++;  
			}while (intentos<3 && comparar2==0);
		 break; 
		case 4:
			
			printf("Su saldo actual es de:%.2f",&clientes[numcliente].saldo);
		break;
		case 5:
			{
				printf("Se le presentara una lista en pantalla con los nombres de las personas\n");
				printf(" a las que puede realizar una tranferencia.\n");
				for(i=0;i<12;i++)
				{
					printf("%i:  %s\n",i+1,clientes[i].nombrecliente);

				}
				printf("Teclee el nombre del usuario al que desee realizar una transferencia:");

				scanf("%s",clientes[clienreceptor].nombrecliente);

				printf("Escriba la cantidad que desee transferir:\n");

				scanf("%f",&cantidad);
				
				clientes[numcliente].saldo=Transferencia(clientes[numcliente].saldo,clientes[clienreceptor].saldo,cantidad);

				printf("Se ha realizado la transferencia correctamente.\n");

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
						fprintf(pf,"%i  %[^\t]\t%d\t%d\t%f\n",i+1,clientes[i].nombrecliente,&clientes[i].numerotarjeta,&clientes[i].pintarjeta,&clientes[i].saldo);
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
	return 0;
}

//Esta funcion calcula el saldo tras una operacion.
float saldoTarjeta(float retirada,float ingreso,float saldoactual)
{
	saldoactual=saldoactual+ingreso-retirada;
	return saldoactual;
}
	
//Esta funcion realiza los cambios de saldo tras una transferencia.
float Tranferencia(float saldoemisor,float saldoreceptor,float transf)
{
	saldoemisor=saldoemisor - transf;
	saldoreceptor=saldoreceptor +transf;
	return saldoemisor;
}	
	
	
