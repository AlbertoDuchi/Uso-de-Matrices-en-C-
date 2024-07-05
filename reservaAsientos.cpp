#include<iostream>
#include<iomanip>
using namespace std;
const int tamFila=6;
const int tamColum=2;
string asientos[tamFila][tamColum];
void iniciaAsientos(int tamFila, int tamColum);
void mapaAsientos(int tamFila, int tamColum);
void ingresodatos(int tamFila, int tamColum);
void menu();
int main(){



	int op;
	//inicializar matriz
	iniciaAsientos(tamFila, tamColum);
	//menu
	do{
		menu();
		cin>>op;
		switch (op){
			case 1: //codigo de la reserva
				ingresodatos(tamFila, tamColum);
				break;
			case 2: //listar los asientos
				mapaAsientos(tamFila, tamColum);
				break;
			case 3://salir
				cout<<"\tFin de Programa\n";
				break;
			default://mostrar error
				cout<<"\tOpcion no valida....!\n";
			    break;			
		}
	}while(op!=3);
	return 0;
};
void iniciaAsientos(int tamFila, int tamColum){
	for(int i=0;i<tamFila;i++){//filas
		for(int j=0;j<tamColum;j++){
			asientos[i][j]="LIBRE";
		}
	}	
};
void mapaAsientos(int tamFila, int tamColum){
	//etiqueta para las columnas
	cout<<setw(3)<<left<<" "<<setw(20)<<"    A "<<setw(20)<<"    B "<<endl;
	cout<<"______________________________________________"<<endl;
	//mostrar datos de la matriz
	for(int i=0;i<tamFila;i++){//filas
		cout<<setw(3)<<left<<i+1<<"| ";
		for (int j=0;j<tamColum;j++) {
			cout<<setw(20)<<asientos[i][j];
		}	
		cout<<endl;	
	};	
};
void menu(){
	cout<<"\n****** Latam Airlines vuelo LA1440 *****\n";
	cout<<"1.- Reserva un asiento\n";
	cout<<"2.- Mapa de Asientos\n";
	cout<<"3.- Salir\n";
	cout<<"Opcion: ";	
};
void ingresodatos(int tamFila, int tamColum){
	int numColumna;
	int fila;
	char columna;
	string nombrePAsajero;
	cout<<"Nombre del pasajero: ";
	getline(cin>>ws,nombrePAsajero);
	//verificar la fila y columna	
	do{
		cout<<"Asiento: ";
		cin>>fila;
		cin>>columna;	
		columna=toupper(columna);
		if((fila<0 or fila>5) or (columna != 'A' && columna != 'B')){
			cout<<" es incorrecto. Codificacion de asientos: 1A 1B 2A 2B ... 6A 6B\n";
		}	
	}while((fila<0 or fila>5) or (columna != 'A' && columna != 'B'));
	/*if (columna=='A'){
		numColumna=0;
	}else{
		numColumna=1;
	}*/
	numColumna=(columna=='A')?0:1;
	if(asientos[fila-1][numColumna]=="LIBRE"){
		asientos[fila-1][numColumna]=nombrePAsajero;
	}else{
		cout<<" Esta ocupado\n";
	}
					
};