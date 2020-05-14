#include <iostream>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;
void menu();
void opcionSeleccionada(int);
void Ingresar();
void Modificar();
void Eliminar();
void mostrar();




int Cuenta(string s, const char Separadorr, int &TotalChars) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] == Separadorr) TotalChars++;
	}


void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 	}  

void OcultarCursor()
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 50;
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(hCon,&cursor);
}


	void split(string Linea, char Separador, vector<string> &TempBuff, int &TotalVector) {
    TempBuff.resize(0);
    TotalVector = 0;
    int Nums = -1;
    int NumPos = -1;
    int ValorNum = 0;
    int TotalChars = 0;
    int TotalEspacios = Linea.length();
    string Valor;
    Cuenta(Linea, Separador, TotalChars);
    if (TotalChars != 0) {
        while (Nums < TotalChars) {
            Nums++;
            ValorNum = Linea.find(Separador, NumPos + 1);
            Valor = Linea.substr(NumPos + 1,ValorNum);
            Valor = Valor.substr(0, Valor.find_first_of(Separador));
            TempBuff.push_back(Valor);
            NumPos = ValorNum;
            TotalEspacios++;
        }
        TotalVector = TempBuff.size();
    }
    else {
        //TempBuff.push_back(Linea.substr(0, Linea.find_first_of(Separador)));
        TotalVector = 0;
    }
}
//la direccion del archivo para almacenar y hacer cambios
const char *nombre_archivo="../Base de Datos/Marcas.txt";
const char *nombre_auxiliar="../Base de Datos/MarcasAux.txt";
bool esNumerico(string); 
bool VeririficarRepetido(string);
void ingresar_marcaArchivo(string,string);
void valoresIniciales();
void mod(string,string);
void eli(string);

int main() 
{	
	system ("color 70");

//	Creamos una funcion llamada valoresIniciales que es el menu y las opciones
	valoresIniciales();
	return 0;
} 

void valoresIniciales(){
	system("cls");
	int opcion;
	OcultarCursor();
	menu();
	
	gotoxy(10,21);
	cout<<" ---------"<<endl;
	gotoxy(10,22);
	cout<<"|         |"<<endl;
	gotoxy(10,23);
	cout<<" ---------"<<endl;
	
	gotoxy(15,22);
	cin>>opcion;
	opcionSeleccionada(opcion);
}

void opcionSeleccionada(int op){
	switch(op){
		case 1:
			 Ingresar();
		break;
		case 2:
			 Modificar();
		break;
		case 3:
			 Eliminar();
		break;
		default:
		
			gotoxy(34,21);
			cout<<" ------------------"<<endl;
			gotoxy(34,22);
			cout<<"| Opcion no valida |";
			gotoxy(34,23);
			cout<<" ------------------"<<endl;
		
		
		break;
	}
}

void menu(){
	gotoxy(10,4);
	cout<<" ---------------------------------------------------------------------------------------"<<endl;
	gotoxy(10,5);
	cout<<"|                                                                        	           |"<<endl;
	gotoxy(10,6);
	cout<<"|                         Bienvenido a nuestra seleccion de marca                       |"<<endl;
	gotoxy(10,7);
	cout<<"|                                                                                       |"<<endl;
	gotoxy(10,8);
	cout<<" ---------------------------------------------------------------------------------------"<<endl;
	
	
	gotoxy(10,15);
	cout<<"--------------------------------------------"<<endl;
	gotoxy(10,16);
	cout<<"| Seleccione entre las siguientes opciones |"<<endl;
	gotoxy(10,17);
	cout<<"--------------------------------------------"<<endl;
	
	
	gotoxy(81,15);
	cout<<" -----------------"<<endl;
	gotoxy(81,16);
	cout<<"|1.Ingresar Marca |"<<endl;
	gotoxy(81,17);            
	cout<<" -----------------"<<endl;
                             	
	                          
	gotoxy(81,18);           
	cout<<" -----------------"<<endl;
	gotoxy(81,19);             
	cout<<"|2.Modificar Marca|"<<endl;
	gotoxy(81,20);
	cout<<" -----------------"<<endl;
	
	gotoxy(81,21);
	cout<<" -----------------"<<endl;
	gotoxy(81,22);
	cout<<"|3.Eliminar       |"<<endl;
	gotoxy(81,23);
	cout<<" -----------------"<<endl;




}
void Ingresar(){
	system("cls");
	string codig,desc;
	
	
	
	gotoxy(5,5);
	cout<<"------------------------------"<<endl;
	gotoxy(5,6);
	cout<<"|Ingrese el codigo de la marca|"<<endl;
	gotoxy(5,7);
	cout<<"-----------------------------"<<endl;
	
gotoxy(36,6);
	cout<<">--->";   cin>>codig; 
	
	
	gotoxy(5,9);
	cout<<" -----------------------------"<<endl;
	gotoxy(5,10);
	cout<<"|Ingrese el nombre de la marca|"<<endl;
	gotoxy(5,11);
	cout<<" -----------------------------"<<endl;
	
	
	gotoxy(36,10);
	cout<<">--->"; cin>>desc;
	cout<<" "<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	
	
	
	//Funcion que verifica si es numero
	system("cls");
	if(esNumerico(codig)){
		if(VeririficarRepetido(codig)){
			gotoxy(5,5);
			cout<<" -------------------------------------------"<<endl;
			gotoxy(5,6);
			cout<<"|같같Error-- Ya ha utilizado este codigo같같|"<<endl;
			gotoxy(5,7);
			cout<<" -------------------------------------------"<<endl;
			system("pause");
			Ingresar();
		}else{	
			 ingresar_marcaArchivo(codig,desc);
		}
	}
	else{
		gotoxy(5,5);
		cout<<" -------------------------------------------"<<endl;
		gotoxy(5,6);
		cout<<"|같같Error-- el codigo debe ser numerico같같|"<<endl;
		gotoxy(5,7);
		cout<<" -------------------------------------------"<<endl;
		system("pause");
		Ingresar();
	}
}
void Modificar(){
 system("cls");
 string codig,ncodig;
 mostrar();	

gotoxy(5,5); 
 cout<<" ---------------------------------------"<<endl;
gotoxy(5,6); 
 cout<<"| Ingrese el codigo que desea modificar |"<<endl;
gotoxy(5,7); 
 cout<<" ---------------------------------------"<<endl;

gotoxy(46,6);
cout<<">--->";cin>>codig;
 
gotoxy(5,9); 
 cout<<" -------------------------"<<endl;
gotoxy(5,10); 
 cout<<"| Ingrese el nuevo nombre |"<<endl;
gotoxy(5,11); 
 cout<<"--------------------------"<<endl;
 
gotoxy(32,10);
cout<<">--->"; cin>>ncodig;
 
 
 
 if(VeririficarRepetido(codig)){
 	mod(codig,ncodig);
 }else{
 	
	gotoxy(5,13);
	cout<<"------------------------------"<<endl;	 
	gotoxy(5,14);
	cout<<"| Error-- El codigo no existe |"<<endl;
 	gotoxy(5,15);
	 cout<<"-----------------------------"<<endl;
	 system("pause");
	Modificar();
 

 
 } 
}

//eliminar
void Eliminar(){
 system("cls");
 string codig;
 mostrar();	
 
 gotoxy(5,5); 
 cout<<"---------------------------------------"<<endl;
 gotoxy(5,6); 
 cout<<"| Ingrese el codigo que desea eliminar |"<<endl;
gotoxy(5,7); 
 cout<<"--------------------------------------"<<endl;
 
 gotoxy(45,6); 
 cout<<">--->";cin>>codig;
 
 
 if(VeririficarRepetido(codig)){
 	eli(codig);
 }else{
 	
	gotoxy(5,9); 
	cout<<"------------------------------------";
	gotoxy(5,10); 	
	cout<<"|같같Error-- El codigo no existe같같|"<<endl;
 	gotoxy(5,11); 
	 cout<<"-----------------------------------";
	 
	 system("pause");
	Modificar();
 } 	
}
void ingresar_marcaArchivo(string cod,string desc){
	ofstream archivo;
	char continuar;
	archivo.open(nombre_archivo,ios::app);
	
	if(archivo.fail()){
	cout<<"Error de archivo";
	}else
	{
	
	fflush(stdin);
	system("cls");
	archivo<<endl<<cod<<" "<<desc;
	
	gotoxy(5,6);
	cout<<" --------------------------------"<<endl;
	gotoxy(5,7);
	cout<<"| Registro Guardado exitosamente |"<<endl;
	gotoxy(5,8);
	cout<<" --------------------------------"<<endl<<endl;
	
	gotoxy(5,10);
	cout<<"------------------"<<endl;
	gotoxy(5,11);
	cout<<"| 풠ontinuar s/n? |"<<endl;
	gotoxy(5,12);
	cout<<"------------------"<<endl;
	
	gotoxy(25,11);
	cout<<">--->";cin>>continuar;
	
	
	
	archivo.close();
		if(continuar=='s'||continuar=='S'){
			Ingresar();		
		}else{
			valoresIniciales();
		}
	}
}
bool VeririficarRepetido(string codi){
	int conteo;
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::in);
	if(archivo.fail()){
		cout<<"Error de archivo"<<endl;
		exit(1);
	}else{
		while(archivo.eof()==false){
		//obtengo la fila del archivo y la almaceno en la variable
			//contenido
				getline(archivo,contenido);
			    if(contenido=="" || contenido==" "){
				}else{
				vector<string> TempBuff(0);
				//creo un array para almacenar todos los string
			    int TotalVector;
				//TotalVector almacena la cantidad de palabras almacenadas
				split(contenido, *" ",  TempBuff, TotalVector);
				//Funcion split particiona un string y los agrega al array
				if(TempBuff[0]==codi){
				//Verificamos si la primera palabra es igual al codigo
					conteo++;
					//si es asi creamos un contador
				}
				}
					
		}
		//va a hacer en todas las filas del archivo
		
	}
	archivo.close();
	//Cierra el archivo
	if (conteo>0){
		//Si el contador es mayor a 0 retorna true
		return true;
	}else{
		//Si el contador es igual a 0 retorna false
		return false;
	}
}
bool esNumerico(string linea) 
{
   bool b = true;
   int longitud = linea.size();
 
   if (longitud == 0) { // Cuando el usuario pulsa ENTER
      b = false;
   } else if (longitud == 1 && !isdigit(linea[0])) {
      b = false;
   } else {
      int i;
      if (linea[0] == '+' || linea[0] == '-')
         i = 1;
      else
         i = 0;
 
      while (i < longitud) {
         if (!isdigit(linea[i])) {
            b = false;
            break;
         }
         i++;
      }
   }
   return b;
}
void mostrar(){
	int conteo;
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::in);
	if(archivo.fail()){
		cout<<"-----------------"<<endl;
		cout<<"Error de archivo"<<endl;
		cout<<"-----------------"<<endl;
		exit(1);
	}else{
		while(archivo.eof()==false){
		//obtengo la fila del archivo y la almaceno en la variable
			//contenido
				getline(archivo,contenido);
			    if(contenido=="" || contenido==" "){
				}else{
					
				cout<<"|--  "<<contenido<<"  --|"<<endl;
				}
				}
		}
		//va a hacer en todas las filas del archivo
}

void mod(string cod, string desc){
	ofstream aux;
	ifstream archivo;
	char Salir;
	string contenido;
	bool encontrado = false;
	
	archivo.open(nombre_archivo,ios::in);
	aux.open(nombre_auxiliar,ios::out);
	
	if(archivo.fail()){
		cout<<"Archivo no encontrado"<<endl;
		exit(1);
	}else{		
		system("cls");
		do{
			getline(archivo,contenido);
			if(contenido.find(cod) != std::string::npos)
			{
			aux<<cod<<" "<<desc<<endl;
			}
			else{
				aux<<contenido<<endl;
			}
			
		}while(archivo.eof()==false);
		archivo.close();
		aux.close();
		remove(nombre_archivo);
		rename(nombre_auxiliar,nombre_archivo);
		
		gotoxy(5,6);
		cout<<" --------------------------------------"<<endl;
		gotoxy(5,7);
		cout<<"| Registro Modificado de forma exitosa |"<<endl;
		gotoxy(5,8);
		cout<<" --------------------------------------"<<endl;
		
		
		mostrar();	
		system("pause");
		valoresIniciales();
	}
} 

void eli(string cod){
	ofstream aux;
	ifstream archivo;
	char Salir;
	string contenido;
	bool encontrado = false;
	
	archivo.open(nombre_archivo,ios::in);
	aux.open(nombre_auxiliar,ios::out);
	
	if(archivo.fail()){
		cout<<"Archivo no encontrado"<<endl;
		exit(1);
	}else{		
		system("cls");
		do{
			getline(archivo,contenido);
			if(contenido.find(cod) != std::string::npos)
			{
			aux<<"";
			}
			else{
				aux<<contenido<<endl;
			}
			
		}while(archivo.eof()==false);
		archivo.close();
		aux.close();
		remove(nombre_archivo);
		rename(nombre_auxiliar,nombre_archivo);
		
		gotoxy(5,6);
		cout<<" -------------------------------------"<<endl;
		gotoxy(5,7);
		cout<<"| Registro Eliminado de forma exitosa |"<<endl<<endl<<endl;
		gotoxy(5,8);
		cout<<" -------------------------------------"<<endl;
		
		
		system("pause");
		mostrar();
		valoresIniciales();
	}
} 


