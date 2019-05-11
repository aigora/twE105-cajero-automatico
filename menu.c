#include <stdio.h>
#include<string.h>
#define N 100


typedef struct{
	char nombrecliente[N];
	int numerotarjeta,pintarjeta;
	float saldo;
}tarjeta;


int main()
{
	// sea a sacar efectivo,b ingresar efectivo,c cambiar el pin,d consultar saldo y e salir 
    int operacion;//para seleccionar la opcion que deseas realizar.
    int pintarjeta,pin,np,cp,intentos=0,i;
    //sea pintarjeta el pin de la tarjeta, pin el pin introducido, sea np nuevo pin, sea cp cambio de pin, intentos.
    //he asignado cantidad a la cantidad de dinero que desea retirar y a la cantidad de dinero que se desea ingresar.
    int cantidad;
	int clic=0,compara; 
	char nombredelcliente[17];
	tarjeta clientes[N]; 
    FILE *clientesdelbanco;
    //introduce el pin y en caso de que sea incorrecto tiene 3 oportunidades y sino lo acierta fin del programa.

    clientesdelbanco = fopen("clientesdelbanco.txt","r");
	if(clientesdelbanco==NULL)
	{
		printf("No se puedo abrir correctamente el fichero\n");
		return -1;
	}
	else
	{
		while(fscanf(clientesdelbanco,"%i  %s[^\n]\t %i\t %i\t  %.2f\t" ,
		&clic,clientes[clic].nombrecliente,&clientes[clic].numerotarjeta,&clientes[clic].pintarjeta,&clientes[clic].saldo)!=EOF)
		{
			clic++;
			if(clic!=0)
			{
				clic=clic-1;
			}
		}
	}

	fclose(clientesdelbanco);
	do
		{
				printf("Bienvenido.");
				printf("Iniciar sesion:\n");
			do
			{
				if(clic==0)
					{
						printf("Todavia no hay ningun usuario registrado en el cajero. Cree un usuario antes.");
					}
					else
					{
						 clientesdelbanco = fopen("clientesdelbanco.txt","r");
						if(clientesdelbanco==NULL)
						{
							printf("El fichero no se pudo abrir\n");
							return -1;
						}
						else
						{
							i=0;
								printf("Introduzca su usuario(nombre del cliente):\n");
								scanf("%s",nombredelcliente);
								printf("\n");
								for(i=0;i<clic;i++)
									{
									compara=strcmp(nombredelcliente,clientes[i].nombrecliente);
										if(compara==0)
										{
										printf("El usuario es correcto.\n");
										}
										else if(i==clic-1)
										{
											printf("Su usuario es incorrecto.\nPruebe otra vez\n\n");
										}
									}
								}while(compara==1||compara==-1);
							       //introduce el pin y en caso de que sea incorrecto tiene 3 oportunidades y sino lo acierta fin del programa.
							    do{ 
										printf("Introduzca el pin: "); 
										scanf("%d", &pin); 
										if(pin==pintarjeta) 
										printf("Bienvenido");
										intentos++;  
										}while (intentos<3 && pin!=pintarjeta);
							fclose(clientesdelbanco);

							}while (fscanf(clientesdelbanco,"%i  %s\t%i\t%i\t%f\t",&clic,clientes[clic].nombrecliente,&clientes[clic].numerotarjeta,&clientes[clic].pintarjeta,&clientes[clic].saldo)!=EOF);
						

	printf("Seleccione si desea sacar efectivo(a),ingresar efectivo(b),cambiar el pin(c),consultar saldo(d) o salir(e)");

	scanf("%i",&operacion);

	switch (operacion) 
		{ 
		case 1:
		     do{ 
					printf("introducir cantidad que desea retirar:"); 
					scanf("%d", &cantidad);
					if(cantidad<=clientes[i].saldo)
					{
				    clientes[i].saldo=clientes[i].saldo-cantidad; 
					printf("Procedamos a la retirada.");
				    }
					intentos++;  
					}while (intentos<3 && cantidad>clientes[i].saldo);	
		 break; 
		case 2:
					 printf ("Escriba la cantidad de dinero que desee ingresar");
					 scanf("%i",&cantidad);
					 printf("Ingreso realizado con exito");
                     clientes[i].saldo=clientes[i].saldo+cantidad;
					 printf("su nuevo saldo es %.3f",clientes[i].saldo);	 
		 break; 
		case 3:
				     do{ 
					printf("Escriba su pin actual"); 
					scanf("%d", &pin); 
					if(pin==pintarjeta) 
					    {
						printf("Introduzca su nuevo pin");
						scanf("%d",&np);
						pintarjeta=np;
						printf("Su codigo pin se ha cambiado con exito");
						}
					intentos++;  
					}while (intentos<3 && pin!=pintarjeta);
		 break; 
		case 4:
					printf ("Su saldo actual a dia de hoy es %.3f",clientes[i].saldo);
		 break;
		case 5:
				clientesdelbanco= fopen("clientesdelbanco.txt","w");
				if(clientesdelbanco==NULL)
				{
					printf("Error al abrir el fichero\n");
					return -1;
				}
				else
				{
					i=0;
					while(i<clic)
					{
						fprintf(clientesdelbanco,"%i  %s\t%i\t%i\t%.3f\n",i+1,clientes[i].nombrecliente,&clientes[i].numerotarjeta,&clientes[i].pintarjeta,&clientes[i].saldo);
						i++;
					}
					fclose(clientesdelbanco);
					printf("Hasta pronto.\n");	
				}
			break;
		 default:

				printf("Opcion incorrecta\n");
				break;
		}

	}
}




