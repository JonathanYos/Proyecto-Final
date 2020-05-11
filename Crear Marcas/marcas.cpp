#include <iostream>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <fstream>

using namespace std;
void menu();
void opcionSeleccionada(int);
void Ingresar();
void Modificar();
void Eliminar();

int Cuenta(string s, const char Separadorr, int &TotalChars) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] == Separadorr) TotalChars++;
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
const char *nombre_archivo="../Base de Datos/marcas.txt";

void ingresar();
void modificar();
void eliminar();
bool esNumerico(string); 
bool VeririficarRepetido(string);
void ingresar_marcaArchivo(string,string);
void valoresIniciales();
int main() 
{	
//	Creamos una funcion llamada valoresIniciales que es el menu y las opciones
	valoresIniciales();
	return 0;
} 
void valoresIniciales(){
	system("cls");
	int opcion;
	menu();
	cin>>opcion;
	opcionSeleccionada(opcion);
}
void opcionSeleccionada(int op){
	switch(op){
		case 1:
			 Ingresar();
		break;
		case 2:
			void modificar();
		break;
		case 3:
			void eliminar();
		break;
		default:
			cout<<"Opcion no valida";
		break;
	}
}
void menu(){
	cout<<"Bienvenido a mi Programa"<<endl;
	cout<<"Seleccione entre las siguientes opciones"<<endl;
	cout<<"1.Ingresar Marca"<<endl;
	cout<<"2.Modificar Marca"<<endl;
	cout<<"3.Eliminar"<<endl;
}
void Ingresar(){
	system("cls");
	string codig,desc;
	cout<<"Ingrese el codigo de la marca"<<endl;
	cin>>codig;
	cout<<"Ingrese el nombre de la marca"<<endl;
	cin>>desc;
	//Funcion que verifica si es numero
	if(esNumerico(codig)){
		//if(VeririficarRepetido(codig)){
		//	cout<<"Error-- Ya ha utilizado este codigo"<<endl;
		//	system("pause");
		//	Ingresar();
		//}else{	
			 ingresar_marcaArchivo(codig,desc);
		//}
	}
	else{
		cout<<"Error-- el codigo debe ser numerico"<<endl;
		system("pause");
		Ingresar();
	}
}
void modificar(){
	
}
void eliminar(){
	
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
	archivo<<cod<<" "<<desc<<endl;
	cout<<"Registro Guardado exitosamente"<<endl;
	cout<<"¿Continuar s/n?"<<endl;
	cin>>continuar;
	archivo.close();
	if(continuar=='s'||continuar=='S'){
	Ingresar();		
	}else{
	valoresIniciales();
	}
	
}
}
bool VeririficarRepetido(string codi){
	int  conteo;
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivo,ios::in);
	if(archivo.fail()){
		cout<<"Error de archivo"<<endl;
		exit(1);
	}else{
		system("cls");
		do{
			//obtengo la fila del archivo y la almaceno en la variable
			//contenido
			getline(archivo,contenido);
			
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
		}while(archivo.eof()==false);
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



  

