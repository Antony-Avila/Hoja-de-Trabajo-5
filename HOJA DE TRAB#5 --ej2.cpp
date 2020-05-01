/*Una persona desea comprar entradas para un concierto que se realizará en la explanada de cierto lugar
de la ciudad. El precio de la entrada varía según la zona elegida, así tenemos que la lista de precios es la
siguiente:
Zona Identificación Precio
VIP V 350.00
Platea P 130.00
Popular E 50.00
Adicionalmente los precios tendrán un descuento en función del número de entradas que se compran,
así como si la persona que las adquiere es socio o no.
descuento por número de entradas
número de entrada		%descuento								Descuento por ser socio
Entre 3 y 6					 5% 							¿es socio? 			 % de descuento
Entre 7 y 9				   7.5%									si						8%
>9							10%									no						0%

Se le pide elaborar un programa en C++ que solicite la zona elegida, el número de entradas a comprar y
consulte si es socio o no y nos determine y muestre el monto a pagar por la compra de las entradas. Todas
las ventas deben de ser grabadas un archivo de datos,
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
using namespace std;

float vip=0;
float plat=0;
float pop=0;
void menu();
void mostrar_archivo();
void venta();

int main(){
	menu();	
	
}void menu(){
	int opMenu;
	do {
		system("CLS");
		cout << "-------MENU PRINCIPAL-------------" << endl;
		cout << "1 - COMPRAR ENTRADAS " << endl;	
		cout << "2 - MOSTRAR ENTRADAS VENDIADAS" << endl;	
		cout << "3 - SALIR " << endl;
		cout<<"--------------------------"<<"\n";
		cin>> opMenu;
		if (opMenu==1){		
			system("CLS");
			venta();			
		}
		else if (opMenu==2){
			system("CLS");
			mostrar_archivo();
		}	
		else if (opMenu==3)
			exit(1);
		else
			break;		
	} while(opMenu!=3);
		cout<< "no valido" << endl;	
		system("PAUSE");
		menu();	
			
}
void venta(){
	bool op= true;
	int cantentradas;
	string tipoentrada, socio;
	float total,total2,total3,total4,precio,precio2;
	
	cout << "-------SELECCIONE TIPO DE ENTRADA-------------" << endl;
	cout << "VIP ==> ""V"" " << endl;	
	cout << "PLATEA ==> ""P"""  << endl;	
	cout << "POPULAR ==> ""E""" << endl;	
	cin>> tipoentrada;
	if  ((tipoentrada!="V") && (tipoentrada!="v") && (tipoentrada!="P") && (tipoentrada!="p") && (tipoentrada!="E")&&(tipoentrada!="e")){
		system("CLS");	
		cout<< "opcion incorrecta, vuelva a inciar proceso" << endl;			
		system("PAUSE()");
		menu();
	}
	cout<< "Cuantas entradas desea comprar: "  << endl;
	cin >> cantentradas;
	cout<< "¿es socio? // S - N:" << endl;
	cin>> socio;
	if  ((socio!="S") && (socio!="s") && (socio!="N") && (socio!="n")){
		system("CLS");	
		cout<< "opcion incorrecta, vuelva a inciar proceso" << endl;			
		system("PAUSE()");
		menu();
	}
	if ((tipoentrada =="V") || (tipoentrada=="v")){
		precio = cantentradas * 350;
		total= precio;
	
		if((cantentradas==1) || (cantentradas==2)){
			if((socio=="S") || (socio=="s")){
				precio2 = precio * 0.92;
				total=precio2;
			}
			else if ((socio=="N") || (socio=="n")){
				total=precio;
				}
		}
		else if((cantentradas>2) && (cantentradas<7)){
			if((socio=="S") || (socio=="s")){
				total3 = (precio * 0.92)*0.95;
				total= total3;
			}
			else if ((socio=="N") || (socio=="n")){
				total= precio *0.95;
				}
		}	
		else if ((cantentradas>6) && (cantentradas<10)){
			if((socio=="S") || (socio=="s")){
				total2= (precio *0.92) * 0.925;
				total=total2;
			}			
			else if((socio=="N") || (socio=="n")){
				total= precio * 0.925;
			}
		}
		else if (cantentradas>9){
			if((socio=="S") || (socio=="s")){
				total2= (precio *0.92) * 0.90;
				total=total2;
			}			
			else if((socio=="N") || (socio=="n")){
				total= precio * 0.90;
			}
		}
	}
	if ((tipoentrada =="P") || (tipoentrada=="p")){
		precio = cantentradas * 130;
		total= precio;
	
		if((cantentradas==1) && (cantentradas==2)){
			if((socio=="S") || (socio=="s")){
				precio2 = precio * 0.92;
				total=precio2;
			}
			else if ((socio=="N") || (socio=="n")){
				total=precio;
				}
		}
		else if((cantentradas>2) && (cantentradas<7)){
			if((socio=="S") || (socio=="s")){
				total3 = (precio * 0.92)*0.95;
				total= total3;
			}
			else if ((socio=="N") || (socio=="n")){
				total= precio *0.95;
				}
		}	
		else if ((cantentradas>6) && (cantentradas<10)){
			if((socio=="S") || (socio=="s")){
				total2= (precio *0.92) * 0.925;
				total=total2;
			}	
			else if((socio=="N") || (socio=="n")){
				total= precio * 0.925;
			}
		}
		else if (cantentradas>9){
			if((socio=="S") || (socio=="s")){
				total2= (precio *0.92) * 0.90;
				total=total2;
			}			
			else if((socio=="N") || (socio=="n")){
				total= precio * 0.90;
			}
		}		
	}	
	if ((tipoentrada =="E") || (tipoentrada=="e")){
		precio = cantentradas * 50;
		total= precio;
	
		if((cantentradas==1) || (cantentradas==2)){
			total= precio;
		
			if((socio=="S") || (socio=="s")){
				precio2 = precio * 0.92;
				total=precio2;
			}
			else if ((socio=="N") || (socio=="n")){
				total=precio;
				}
		}
		else if((cantentradas>2) && (cantentradas<7)){
			if((socio=="S") || (socio=="s")){
				total3 = (precio * 0.92)*0.95;
				total= total3;
			}
			else if ((socio=="N") || (socio=="n")){
				total= precio *0.95;
				}
		}
		else if ((cantentradas>6) && (cantentradas<10)){
					
			if((socio=="S") || (socio=="s")){
				total2= (precio *0.92) * 0.925;
				total=total2;
			}			
			else if((socio=="N") || (socio=="n")){
				total= precio * 0.925;
			}
		}	
		else if (cantentradas>9){
			if((socio=="S") || (socio=="s")){
				total2= (precio *0.92) * 0.90;
				total=total2;
			}			
			else if((socio=="N") || (socio=="n")){
				total= precio * 0.90;
			}
		}		
	}	
	cout<<"el total a pagar es:"<< endl;
	cout<<total <<endl;
	system("PAUSE");
	
	if ((tipoentrada=="V")||(tipoentrada=="v")){
	for ( int i=0; tipoentrada=="V" || tipoentrada=="v"; i++){
		vip += total;
		cout<< "el acumulado de vip es:" <<endl;			
		cout<< vip <<endl;
		system("pause");
		break;		
	}
	}
	
	if ((tipoentrada=="P")||(tipoentrada=="p")){
	for ( int i=0; tipoentrada=="P" || tipoentrada=="p"; i++){
		plat += total;
		cout<< "el acumulado de vip es:" <<endl;			
		cout<< plat <<endl;
		system("pause");
		break;		
	}
	}
	
	if ((tipoentrada=="E")||(tipoentrada=="e")){
	for ( int i=0; tipoentrada=="E" || tipoentrada=="e"; i++){
		pop += total;
		cout<< "el acumulado de vip es:" <<endl;			
		cout<< pop <<endl;
		system("pause");
		break;		
	}
	}

ofstream archivo;
archivo.open("entradas.txt",ios::app);	
archivo<<"\n"<<"---------entradas vendidas---------TOTAL GLOBAL POR CATEGORIA--------"<<endl;
archivo<<"tipo cant	total socio 	POPULAR	 VIP	PLATEA"<<endl;
archivo<<tipoentrada<<"\t"<<cantentradas<<"\t"<<total<<"\t"<<socio<<"\t"<<pop<<"\t"<<vip<<"\t"<<plat<<"\t"<<endl;
archivo.close();
menu();

}

void mostrar_archivo(){
	ifstream archivo;
	archivo.open("entradas.txt",ios::in);
	int lineas,i=0;
	string s,linea;	
	
	while (getline(archivo,s))
	archivo.close();
	
	archivo.open("entradas.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		system("Pause");
		menu();
	}		
    archivo.close(); 
	system("Pause");	
	ifstream leerarchivo;
	try {
		leerarchivo.open("entradas.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
		system("Pause");		
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");		
	}
}
