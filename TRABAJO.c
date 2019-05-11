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


int main()
{
	system("cls");//Limpiar pantalla
	
	float retirada;
	float ingreso;
	float cantidad;
	int nt;//numero de tarjeta introducido por el usuario al iniciar sesion.
	int comparar;
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
		while(fscanf(pf,"%s[^\n]\t %i\t %i\t  %.2f\t" ,clientes[j].nombrecliente,&clientes[j].numerotarjeta,&clientes[j].pintarjeta,&clientes[j].saldo)!=EOF)
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
	for(k=0;k<20;i++)
		{
		comparar=strcmp(nt,clientes[k].numerotarjeta);
		if(comparar==0){
		printf("El numero de tarjeta es correcto.\n");	
		}
		}
	intentos++;	
	}while(intentos<3 && nt!=clientes[k].numerotarjeta);
	//le pedimos el pin al usuario y tiene tres intentos para introducirlo correctamente.
	do{ 
			printf("Introduzca el pin: "); 
			scanf("%d", &pin); 
			if(pin==clientes[i].pintarjeta) 
			printf("\n El pin es correcto.Bienvenido.\n");
			intentos++;  
			}while (intentos<3 && pin!=clientes[i].pintarjeta);
	
	//menu	
	system ("cls");
	printf("---------MENU--------");

	printf("Elige su opcion:\n\n");

	printf("1 Retirar dinero:\n");

	printf("2 Ingresar dinero:\n");

	printf("3 Realizar una transferencia:\n");

	printf("4 Ver estado de cuenta:\n");

	printf("5 Salir:\n");

	scanf("%i",&operacion);
	
	switch(operacion)
	{
		case 1:
			do{
			printf("Introducir cantidad que desea retirar:\n"); 
			scanf("%d", &cantidad);
			if(cantidad<=clientes[i].saldo)
					{
				      clientes[i].saldo=clientes[i].saldo-cantidad; 
					printf("Procedamos a la retirada.\n");
				    }
			intentos++;  
			}while (intentos<3 && cantidad>clientes[i].saldo);
		break;
		case 2:
			printf ("Escriba la cantidad de dinero que desee ingresar:\n");
			scanf("%i",&cantidad);
			printf("Ingreso realizado con exito.\n");
                clientes[i].saldo=clientes[i].saldo+cantidad;
			printf("su nuevo saldo es %.3f",clientes[i].saldo);			
		break;
		case 3:
			do{ 
				printf("Escriba su pin actual.\n"); 
				scanf("%d", &pin); 
					if(pin==clientes[i].pintarjeta) 
					    {
						do{
						printf("Introduzca su nuevo pin:\n");
						scanf("%d",&nuevopin);
						printf("Confirme el nuevo pin:\n");
						scanf("%d",&np);
						
								if(np=nuevopin)
								{
									clientes[i].pintarjeta=nuevopin;
								}
								intentos++;
							    }while (intentos<3 && np!=nuevopin);
							    
					printf("Su codigo pin se ha cambiado con exito.\n");
						}
					intentos++;  
			}while (intentos<3 && pin!=clientes[i].pintarjeta);
		 break; 
		case 4:
			
			printf("Su saldo actual es de:%.2f",&clientes[i].saldo);
		break;
		case 5:
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
						fprintf(pf,"%i  %s\t%i\t%i\t%.3f\n",i+1,clientes[i].nombrecliente,&clientes[i].numerotarjeta,&clientes[i].pintarjeta,&clientes[i].saldo);
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
}

	
	
	
