#include <iostream>
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

const char *nombre_archivo="../Base de Datos/Marcas.txt";
const char *nombre_auxiliar="../Base de Datos/MarcasAux.txt";

const char *nombre_archivopro="../Base de Datos/Productos.txt";
const char *nombre_auxiliarpro="../Base de Datos/ProductosAux.txt";

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

void mostrar();
void valoresIniciales();
void menu();
void opcionSeleccionada(int);
void Ingresar();
void IngresarDb();
void Modificar();
void Eliminar();

bool esNumerico(string); 
bool VeririficarRepetido(string);
bool Existe(string);
void mostrarMarca();
void mostrarProducto();

void IngresarDb(string,string,string,float,float,char const*);
void mod(string,string,string,float,float,char const*);
void eli(string);
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

int main(){
	system ("color 70");
	valoresIniciales();
	return 0;
}


void valoresIniciales()
{
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

void opcionSeleccionada(int op)
{
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

void menu()
{
	gotoxy(10,4);
	cout<<" ---------------------------------------------------------------------------------------"<<endl;
	gotoxy(10,5);
	cout<<"|                                                                        	          |"<<endl;
	gotoxy(10,6);
	cout<<"|                         Bienvenido a nuestra seleccion de productos                   |"<<endl;
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
	cout<<" --------------------"<<endl;
	gotoxy(81,16);
	cout<<"|1.Ingresar producto |"<<endl;
	gotoxy(81,17);            
	cout<<" -------------------"<<endl;
                             	
	                          
	gotoxy(81,18);           
	cout<<" ---------------------"<<endl;
	gotoxy(81,19);             
	cout<<"|2.Modificar producto |"<<endl;
	gotoxy(81,20);
	cout<<" ---------------------"<<endl;
	
	gotoxy(81,21);
	cout<<" ---------------------"<<endl;
	gotoxy(81,22);
	cout<<"|3.Eliminar  producto |"<<endl;
	gotoxy(81,23);
	cout<<" ---------------------"<<endl;
}

void Ingresar()
{
	system("cls");
	mostrarMarca();
	string codig,desc,idmarca,r;
	float precioc,preciov;
	
	time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, 50, "%d/%m/%y-%X", curr_tm);	
	
	
	gotoxy(5,3);
	cout<<" -------------------------------"<<endl;
	gotoxy(5,4);
	cout<<"|Ingrese el codigo del producto |"<<endl;
	gotoxy(5,5);
	cout<<"--------------------------------"<<endl;
	
	
	gotoxy(5,6);
	cout<<" ----------"<<endl;
	gotoxy(5,7);
	cout<<"|           |"<<endl;
	gotoxy(5,8);
	cout<<" ----------"<<endl;
	
	gotoxy(10,7);
	cin>>codig;
	
	
	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--**-*-**-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*//	
	
	
	gotoxy(5,9);
	cout<<"--------------------------------"<<endl;
	gotoxy(5,10);
	cout<<"|Ingrese el nombre del producto |"<<endl;
	gotoxy(5,11);
	cout<<"--------------------------------"<<endl;
	
	
	gotoxy(5,12);
	cout<<" ----------"<<endl;
	gotoxy(5,13);
	cout<<"|           |"<<endl;
	gotoxy(5,14);
	cout<<" ----------"<<endl;
	
	gotoxy(10,13);
	cin>>desc;





//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--**-*-**-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*//




	gotoxy(5,15);
	cout<<"--------------------------------"<<endl;
	gotoxy(5,16);
	cout<<"|Ingrese el codigo de la marca  |"<<endl;
	gotoxy(5,17);
	cout<<"--------------------------------"<<endl;
	
	
	
	gotoxy(5,18);
	cout<<" -----------"<<endl;
	gotoxy(5,19);
	cout<<"|            |"<<endl;
	gotoxy(5,20);
	cout<<" -----------"<<endl;
	
	
	gotoxy(10,19);
	cin>>idmarca;



//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--**-*-**-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*//




	gotoxy(5,21);
	cout<<"--------------------------------"<<endl;
	gotoxy(5,22);
	cout<<"|Ingrese el precio de compra    |"<<endl;
	gotoxy(5,23);
	cout<<"--------------------------------"<<endl;
	
	
	
	gotoxy(5,24);
	cout<<" -----------"<<endl;
	gotoxy(5,25);
	cout<<"|Q           |"<<endl;
	gotoxy(5,26);
	cout<<" -----------"<<endl;
	
	gotoxy(10,25);
	cin>>precioc;
	
	
	
	
	
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--**-*-**-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*//	
	
	
	
	
	gotoxy(5,27);
	cout<<"--------------------------------"<<endl;
	gotoxy(5,28);
	cout<<"|Ingrese el precio de venta     |"<<endl;
	gotoxy(5,29);
	cout<<"--------------------------------"<<endl;
	
	
	
	
	
	gotoxy(5,30);
	cout<<" -----------"<<endl;
	gotoxy(5,31);
	cout<<"|Q           |"<<endl;
	gotoxy(5,32);
	cout<<" -----------"<<endl;

	gotoxy(10,31);
	cin>>preciov;
	
	
	//Funcion que verifica si es numero
	if(esNumerico(codig)){
		if(VeririficarRepetido(codig)){
			
			gotoxy(5,34);
			cout<<" -------------------------------------------"<<endl;
			gotoxy(5,35);
			cout<<"|같같Error-- Ya ha utilizado este codigo같같|"<<endl;
			gotoxy(5,36);
			cout<<" -------------------------------------------"<<endl;
			
			system("pause");
			Ingresar();
		}else{	
		if(Existe(idmarca)){
		IngresarDb(codig,desc,idmarca,precioc,preciov,date_string);
		}else{
			gotoxy(5,34);
			cout<<" -------------------------------------------"<<endl;
			gotoxy(5,35);
			cout<<"|같같    Error-- No existe la marca     같같|"<<endl;	
			gotoxy(5,36);
			cout<<" -------------------------------------------"<<endl;
		} 
		}
	}
	else{
		gotoxy(5,34);
		cout<<" -------------------------------------------"<<endl;
		gotoxy(5,35);
		cout<<"|같같Error-- el codigo debe ser numerico같같|"<<endl;
		gotoxy(5,36);
		cout<<" -------------------------------------------"<<endl;
		system("pause");
		Ingresar();
	}
}
void IngresarDb(string cod, string des,string idm,float prec, float prev,char const * time){
ofstream archivo;
	char continuar;
	archivo.open(nombre_archivopro,ios::app);
	
	if(archivo.fail()){
	cout<<"Error de archivo";
	}else
	{
	fflush(stdin);
	system("cls");
	archivo<<endl<<cod<<" "<<des<<" "<<idm<<" "<<prec<<" "<<prev<<" "<<time;
		gotoxy(5,6);
	cout<<" --------------------------------"<<endl;
	gotoxy(5,7);
	cout<<"| Registro Guardado exitosamente |"<<endl;
	gotoxy(5,8);
	cout<<" --------------------------------"<<endl<<endl;
	mostrarProducto();
	
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

void Eliminar(){ 
	system("cls");
 	string codig,desc,idmarca,r;
	float precioc,preciov;
	
 	mostrarProducto();
 	
 	gotoxy(5,3);
 	cout<<" ---------------------------------------"<<endl;
 	gotoxy(5,4);
	cout<<"| Ingrese el codigo que desea eliminar |"<<endl;
	gotoxy(5,5);
	cout<<" ---------------------------------------"<<endl;
	
	gotoxy(5,7);
	cout<<" ------------"<<endl;
	gotoxy(5,8);
	cout<<"|            |"<<endl;
	gotoxy(5,9);
	cout<<" -----------"<<endl;
	gotoxy(10,8);
	cin>>codig;
 	
	
 if(VeririficarRepetido(codig)){
 
 		eli(codig);
	 
 }else{
 	gotoxy(5,11);
	cout<<"------------------------------------"<<endl;
 	gotoxy(5,12);
	cout<<"|같같Error-- El codigo no existe같같|"<<endl;
 	gotoxy(5,13);
	cout<<"------------------------------------"<<endl;
	 system("pause");
	Eliminar();
 } 
}
void eli(string cod){
	ofstream aux;
	ifstream archivo;
	char Salir;
	string contenido;
	bool encontrado = false;
	
	archivo.open(nombre_archivopro,ios::in);
	aux.open(nombre_auxiliarpro,ios::out);
	
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
		remove(nombre_archivopro);
		rename(nombre_auxiliarpro,nombre_archivopro);
		cout<<" ----------------------------------"<<endl;
		cout<<"|Registro Eliminado de forma exitosa|"<<endl<<endl<<endl;
		cout<<" -----------------------------------"<<endl;
		system("pause");
		mostrarProducto();
		valoresIniciales();
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
bool VeririficarRepetido(string codi){
	int conteo;
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivopro,ios::in);
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
void Modificar(){
 system("cls");
 string codig,desc,idmarca,r;
	float precioc,preciov;
	
	time_t curr_time;
	tm * curr_tm;
	char date_string[100];
	
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	
	strftime(date_string, 50, "%d/%m/%y-%X", curr_tm);
 mostrarProducto();
 	
 	
 	gotoxy(5,3);
	cout<<"--------------------------------------"<<endl;
	gotoxy(5,4);
	cout<<"|Ingrese el codigo que desea modificar|"<<endl;
	gotoxy(5,5);
	cout<<"--------------------------------------"<<endl;
	
	gotoxy(5,6);
	cout<<" ------------"<<endl;
	gotoxy(5,7);
	cout<<"|            |"<<endl;
	gotoxy(5,8);
	cout<<" -----------"<<endl;
	gotoxy(10,7);
	cin>>codig;
 	
 	
 	
	gotoxy(5,9);
	cout<<"--------------------------------------"<<endl;
	gotoxy(5,10);
	cout<<"|Ingrese el nuevo nombre              |"<<endl;
 	gotoxy(5,11);
	cout<<"--------------------------------------"<<endl;
	
	
	gotoxy(5,12);
	cout<<" ------------"<<endl;
	gotoxy(5,13);
	cout<<"|            |"<<endl;
	gotoxy(5,14);
	cout<<" -----------"<<endl;
	gotoxy(10,13);
	cin>>desc;
 	
 	
 	
	gotoxy(5,15); 
	cout<<"--------------------------------------"<<endl;
	gotoxy(5,16);
	cout<<"|Ingrese el codigo de la marca        |"<<endl;
	gotoxy(5,17);
	cout<<"--------------------------------------"<<endl;
	
	
	
	gotoxy(5,18);
	cout<<" ------------"<<endl;
	gotoxy(5,19);
	cout<<"|            |"<<endl;
	gotoxy(5,20);
	cout<<" -----------"<<endl;
	gotoxy(10,19);
	cin>>idmarca;
	
	
	
	gotoxy(5,21);
	cout<<"--------------------------------------"<<endl;
	gotoxy(5,22);
	cout<<"|Ingrese el precio de compra          |"<<endl;
	gotoxy(5,23);
	cout<<"--------------------------------------"<<endl;
	
	
	
	gotoxy(5,24);
	cout<<" ------------"<<endl;
	gotoxy(5,25);
	cout<<"|Q           |"<<endl;
	gotoxy(5,26);
	cout<<" -----------"<<endl;
	gotoxy(10,25);
	cin>>precioc;
	
	
	
	gotoxy(5,27);
	cout<<"--------------------------------------"<<endl;
	gotoxy(5,28);
	cout<<"|Ingrese el precio de venta           |"<<endl;
	gotoxy(5,29);
	cout<<"--------------------------------------"<<endl;
	
	gotoxy(5,30);
	cout<<" ------------"<<endl;
	gotoxy(5,31);
	cout<<"|Q           |"<<endl;
	gotoxy(5,32);
	cout<<" -----------"<<endl;
	gotoxy(10,31);
	cin>>preciov;
	
 if(VeririficarRepetido(codig)){
 	if(Existe(idmarca)){
 		mod(codig,desc,idmarca,precioc,preciov,date_string);
	 }
	 else{
	 	gotoxy(5,33);
	 	cout<<" ----------------------------------"<<endl;
	 	gotoxy(5,34);
		cout<<"|같같ERROR-- La marca no existe같같|";
		gotoxy(5,35);
		cout<<" ----------------------------------"<<endl;	 
	 }
 }else{
 	gotoxy(5,33);
 	cout<<" -----------------------------------"<<endl;
 	gotoxy(5,34);
	cout<<"|같같Error-- El codigo no existe같같|"<<endl;
 	gotoxy(5,35);
	 cout<<" -----------------------------------"<<endl;
	 system("pause");
	Modificar();
 } 
}
bool Existe(string codi){
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
void mostrarMarca(){
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
				cout<<contenido<<endl;
				}
				}
		}
		//va a hacer en todas las filas del archivo
}
void mostrarProducto(){
	int conteo;
	ifstream archivo;
	string contenido;
	archivo.open(nombre_archivopro,ios::in);
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
				cout<<contenido<<endl;
				}
				}
		}
		//va a hacer en todas las filas del archivo
}

void mod(string cod, string des,string idm,float prec, float prev,char const * time){
	ofstream aux;
	ifstream archivo;
	char Salir;
	string contenido;
	archivo.open(nombre_archivopro,ios::in);
	aux.open(nombre_auxiliarpro,ios::out);
	
	if(archivo.fail()){
		cout<<"Archivo no encontrado"<<endl;
		exit(1);
	}else{		
		system("cls");
		do{
			getline(archivo,contenido);
			if(contenido.find(cod) != std::string::npos)
			{
			aux<<cod<<" "<<des<<" "<<idm<<" "<<prec<<" "<<prev<<" "<<time<<endl;
			}
			else{
				aux<<contenido<<endl;
			}
			
		}while(archivo.eof()==false);
		archivo.close();
		aux.close();
		remove(nombre_archivopro);
		rename(nombre_auxiliarpro,nombre_archivopro);
		cout<<" ------------------------------------"<<endl;
		cout<<"|Registro Modificado de forma exitosa|"<<endl<<endl<<endl;
		cout<<" ------------------------------------"<<endl;
		mostrarProducto();	
		system("pause");
		valoresIniciales();
	}
}
