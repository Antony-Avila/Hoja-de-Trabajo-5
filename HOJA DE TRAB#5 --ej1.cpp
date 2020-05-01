/*Realice un programa que genere la venta de compra de un terreno/casa/departamento. Este programa
debe realizar los cálculos de acuerdo con la tabla abajo listada:

Dada la categoría, zona, tipo y el área del terreno o inmueble determine a cuánto asciende el monto que
deberá pagar para comprar el inmueble. 

 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
using namespace std;

int opcionSelect;
string categ;
string zona;
string tipo;
float  precio;

struct ventas{
	string categ;
	string zona;
	string tipo;
	float precio;	
};

void menu();
void ventaT();
void leer_archivo();
void terrenos();
void comercial();
void residencial();
void comercial_A();
void comercial_B();
void residencial_A();
void residencial_B();
void residencial_C();


int main(){
	menu();
	
}

void menu(){
	int opcionSelec;
	do {
	
		system("CLS");
		cout<<" ----------SELECCIONAR OPCIÓN----------"<<"\n";
		cout<<" 1 - Realizar Venta "<<"\n";
		cout<<" 2 - Reprte Ventas "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cin>> opcionSelec;
		if (opcionSelec==1){		
			system("CLS");
			ventaT();			
		}
		else if (opcionSelec==2){		
			system("CLS");
			leer_archivo();
		}			
		else if (opcionSelec==3)
			exit (1);
		else
			break;
		
	} while(opcionSelec>3);
		cout<< "opcion incorrecta vuela a elegir una opcion valida" << endl;
		system("PAUSE");
		menu();		
}

void ventaT(){
	int tipoCateg;
	int tipo;
	float precio;
	float dist;
	
	cout << "-------INGRESE CATEGORIA-------------" << endl;
	cout << "1 - COMERCIAL" << endl;	
	cout << "2 - RESIDENCIAL " << endl;	
	cin >> tipoCateg;
	
	if (tipoCateg==1){		
		system("CLS");
		comercial();			
		}
		
	else if (tipoCateg==2){		
		system("CLS");
		residencial();
		}			
	else if  (tipoCateg>2){
		system("CLS");	
		cout<< "opcion incorrecta, vuelva a inciar proceso" << endl;			
		system("PAUSE()");
}
}
void comercial(){
	int tipoZonaC;
	
	cout << "-------INGRESE ZONA -------------" << endl;
	cout << "1 - ZONA *A* " << endl;	
	cout << "2 - ZONA *B* " << endl;	
	cin >> tipoZonaC;	
	
	if (tipoZonaC==1){		
		system("CLS");
		comercial_A();			
		}
		
	else if (tipoZonaC==2){		
		system("CLS");
		comercial_B();
		}
	else if  (tipoZonaC>2){
		system("CLS");	
		cout<< "opcion incorrecta, vuelva a inciar proceso" << endl;			
		system("PAUSE()");
}
}

void residencial(){
	int tipoZonaR;
	
	cout << "-------INGRESE ZONA -------------" << endl;
	cout << "1 - ZONA *A* " << endl;	
	cout << "2 - ZONA *B* " << endl;
	cout << "3 - ZONA *C* " << endl;	
	cin >> tipoZonaR;	
	
	if (tipoZonaR==1){		
		system("CLS");
		residencial_A();			
		}
		
	else if (tipoZonaR==2){		
		system("CLS");
		residencial_B();
		}
	else if (tipoZonaR==3){		
		system("CLS");
		residencial_C();
		}
	else if  (tipoZonaR>3){
		system("CLS");	
		cout<< "opcion incorrecta, vuelva a inciar proceso" << endl;			
		system("PAUSE()");
}
}

void comercial_A(){
	int tipocomA;
	float cantM;
	float total;
	
	cout << "-------INGRESE TIPO -------------" << endl;
	cout << "1 - TERRENO " << endl;	
	cout << "2 - CASA " << endl;
	cout << "3 - DEPARTAMENTO " << endl;	
	cin >> tipocomA;
	if (tipocomA>3){
		cout<< "opcion incorrecta vuelva a iniciar proceso" << endl;
		system("PAUSE");
		menu();
	}
	cout  << "CUANTOS METROS CUADRADOS DESEA COMPRAR: "  << endl;
	cin >> cantM; 
	
	if (tipocomA ==1){
		total = cantM *2200;
	}
	else if (tipocomA ==2){
		total = cantM * 2500;	
	}
	else if (tipocomA ==3){
		total = cantM * 2100;	
		}
		cout<<"el total a pagar por el terreno es de: "<< endl;
		cout<<total <<endl;
		system("PAUSE()");
	ofstream archivo; //leer archivo 
	archivo.open("terrenos.txt",ios::app);
	
	archivo<<"\n"<<"---------COMERCIAL TIPO A---------"<<endl;
	archivo<<"tipo	metros	total"<<endl;
	archivo<<tipocomA<<"\t"<<cantM<<"\t"<<total<<"\t"<<endl;
	archivo.close();	
}
	
void comercial_B(){
	int tipocomB;
	float cantMe;
	float totalCA;
	
	cout << "-------INGRESE TIPO B -------------" << endl;
	cout << "1 - TERRENO " << endl;	
	cout << "2 - CASA " << endl;
	cout << "3 - DEPARTAMENTO " << endl;	
	cin >> tipocomB;
	if (tipocomB>3){
		cout<< "opcion incorrecta vuelva a iniciar proceso" << endl;
		system("PAUSE");
		menu();
	}
	cout  << "CUANTOS METROS CUADRADOS DESEA COMPRAR: "  << endl;
	cin >> cantMe; 
	
	if (tipocomB ==1){
		totalCA = cantMe *1300;
	}
	else if (tipocomB ==2){
		totalCA = cantMe * 1500;	
	}
	else if (tipocomB ==3){
		totalCA = cantMe* 1200;	
		}
		cout<<"el total a pagar por el terreno es de: "<< endl;
		cout<<totalCA << endl;
		system("PAUSE()");
	ofstream archivo; //leer archivo 
	archivo.open("terrenos.txt",ios::app);
	
	archivo<<"\n"<<"---------COMERCIAL TIPO B---------"<<endl;
	archivo<<"tipo	metros	total"<<endl;
	archivo<<tipocomB<<"\t"<<cantMe<<"\t"<<totalCA<<"\t"<<endl;
	archivo.close();
}

void residencial_A(){
	int tipoResA;
	float cantMet;
	float totalRA;
	
	cout << "-------INGRESE TIPO -------------" << endl;
	cout << "1 - TERRENO " << endl;	
	cout << "2 - CASA " << endl;
	cout << "3 - DEPARTAMENTO " << endl;	
	cin >> tipoResA;
	if (tipoResA>3){
		cout<< "opcion incorrecta vuelva a iniciar proceso" << endl;
		system("PAUSE");
		menu();
	}
	cout  << "CUANTOS METROS CUADRADOS DESEA COMPRAR: "  << endl;
	cin >> cantMet; 
	
	if (tipoResA ==1){
		totalRA = cantMet *2100;
	}
	else if (tipoResA ==2){
		totalRA = cantMet * 2500;	
	}
	else if (tipoResA ==3){
		totalRA = cantMet* 2100;	
	}
		cout<<"el total a pagar por el terreno es de: "<< endl;
		cout<<totalRA << endl;
		system("PAUSE()");
	ofstream archivo; //leer archivo 
	archivo.open("terrenos.txt",ios::app);
	
	archivo<<"\n"<<"---------RESIDENCIALES TIPO A---------"<<endl;
	archivo<<"tipo	metros	total"<<endl;
	archivo<<tipoResA<<"\t"<<cantMet<<"\t"<<totalRA<<"\t"<<endl;
	archivo.close();
}

void residencial_B(){
	int tipoResB;
	float cantMetr;
	float totalRB;
	
	cout << "-------INGRESE TIPO B-------------" << endl;
	cout << "1 - TERRENO " << endl;	
	cout << "2 - CASA " << endl;
	cout << "3 - DEPARTAMENTO " << endl;	
	cin >> tipoResB;
	if (tipoResB>3){
		cout<< "opcion incorrecta vuelva a iniciar proceso" << endl;
		system("PAUSE");
		menu();
	}
	cout  << "CUANTOS METROS CUADRADOS DESEA COMPRAR: "  << endl;
	cin >> cantMetr; 
	
	if (tipoResB ==1){
		totalRB = cantMetr *1500;
	}
	else if (tipoResB ==2){
		totalRB = cantMetr * 1600;	
	}
	else if (tipoResB ==3){
		totalRB = cantMetr* 1300;	
	}
		cout<<"el total a pagar por el terreno es de: "<< endl;
		cout<<totalRB << endl;
		system("PAUSE()");	
	ofstream archivo; //leer archivo 
	archivo.open("terrenos.txt",ios::app);
	
	archivo<<"\n"<<"---------RESIDENCIALES TIPO B---------"<<endl;
	archivo<<"tipo	metros	total"<<endl;
	archivo<<tipoResB<<"\t"<<cantMetr<<"\t"<<totalRB<<"\t"<<endl;
	archivo.close();
}	

void residencial_C(){
	int tipoResC;
	float cantMetro;
	float totalRC;
	float totRC;
	
	cout << "-------INGRESE TIPO -------------" << endl;
	cout << "1 - TERRENO " << endl;	
	cout << "2 - CASA " << endl;
	cout << "3 - DEPARTAMENTO " << endl;	
	cin >> tipoResC;
	if (tipoResC>3){
		cout<< "opcion incorrecta vuelva a iniciar proceso" << endl;
		system("PAUSE");
		menu();
	}
	cout  << "CUANTOS METROS CUADRADOS DESEA COMPRAR: "  << endl;
	cin >> cantMetro; 
	
	if (tipoResC ==1){
		totalRC = cantMetro *1500;
	}
	else if (tipoResC ==2){
		totalRC = cantMetro * 1600;	
	}
	else if (tipoResC ==3){
		totalRC = cantMetro * 1300;	
	}
	totRC+= totalRC;
		cout<<"el total a pagar por el terreno es de: "<< endl;
		cout<<totalRC <<endl;
	system("PAUSE()");
	
	ofstream archivo; //leer archivo 
	archivo.open("terrenos.txt",ios::app);
	
	archivo<<"\n"<<"---------RESIDENCIALES TIPO C---------"<<endl;
	archivo<<"tipo	metros	total"<<endl;
	archivo<<tipoResC<<"\t"<<cantMetro<<"\t"<<totalRC<<"\t"<<endl;
	archivo.close();
}

void leer_archivo(){
	ifstream archivo; //leer archivo 
	archivo.open("terrenos.txt",ios::in); // leer archivo
	int lineas,i=0;
	string s,linea;	
	
	while (getline(archivo,s))
	archivo.close();
	
	archivo.open("terrenos.txt",ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}		
    archivo.close(); 
	system("Pause");
	
	ifstream leerarchivo;
	try {
		leerarchivo.open("terrenos.txt",ios::in);				
		while (getline(leerarchivo, s))
			cout<<s<<endl;		
		leerarchivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
}
