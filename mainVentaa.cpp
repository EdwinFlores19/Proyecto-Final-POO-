#include <iostream>
#include<windows.h>
#include "productovector.h"
#include "vectorCliente.h"
#include "vectorDVenta.h"
#include <vector>
#include "stdio.h"
#include "dos.h"
#include "time.h"
#include "conio.h"
#include <locale.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>
#define MAX 110
#include "vendedorvector.h"

using namespace std;

struct Usuarios
{
    char espacio1[20];
	char nombre[20];
	char espacio2[20];
    char password[20];
};
int ConfirmarCredenciales(FILE *archivo);
void CrearArchivoBinario(FILE *archivo);

ClienteVector vectorCliente;
ProductoVector vectorProducto;
ProductoVector productovector;
DetVentaVector vectorDVenta;
VendedorVector vendedorvector; /*Instancia de la clase vendedor*/

void menuPrincipal();
void menuDeOpciones(); 
void menuDeOpciones2();

void generarVenta();
	void adicionarClientes();
	void buscarClientes();
	void listarClientes();
	void detalleDVenta();
	
void registroDeProductos();
	void adicionarProducto();
	void listarProductos();
	void eliminarProducto();
	void modificarProducto();
	void buscarProducto();
	void abrirArchivo();
	
	//Prototipos vendedor
void menuDeOpcionesM();
void adicionarVendedor();
void listarVendedors();
void modificarVendedor();
void buscarVendedor();

/*Titulo del programa vendedor*/
void tituloPrincipal();
	

int main()
{
	setlocale(LC_ALL,"spanish");
	
	
	
	menuPrincipal();
}

void menuPrincipal()
{

	FILE *fuser; 
	system("cls");
	
	
	
	 CrearArchivoBinario(fuser); 
	char usuario[20];
	char password[20];
	bool Confirmar=false;
	int intentos=0;
	int Opcion;
	
	do
		{
			system("cls");
			
			tituloPrincipal();
			
			memcpy(password, "",20);
			memcpy(usuario, "",20);
			cout<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\tBIENVENIDOS!!!!"<<endl;
			
			cout<<"\t\t\t\t----------------------------------"<<endl;
			cout<<"\t\t\t\t- ADMINISTRADOR ....[1]"<<endl;
			cout<<"\t\t\t\t- VENDEDOR .........[2]"<<endl;
			cout<<"\t\t\t\t----------------------------------"<<endl;
			cout<<"\t\t\t\t- Ingrese una opcion...[1-2]"<<endl;
			cout<<"\t\t\t\t----------------------------------"<<endl;
			cout << "\t\t\t\t-->";
			cin>>Opcion;
			
				if(Opcion==1 || Opcion==2)
		{
			intentos++;
			system("cls");
			
			cout<<endl;
			cout<<endl;
			cout<<"\t\t\t\t\t LOGIN DE USUARIO"<<endl;
			cout<<"\t\t\t\t\t ----------------"<<endl;
			
			cout<<"\t\t\t\t\t- Usuario: ";
			//cin.getline(usuario,20, '\n');
			cin>>usuario;
			//cin.ignore();
			
			cout<<"\t\t\t\t\t- Password: ";
			 
			char caracter;
			caracter = getch();
			 
			int posi=0;
			while(caracter != 13)
			{
				
				if(caracter != 8)
				{
					password[posi]=caracter;
					cout<<"*";	
				}
				posi++;
	
				caracter = getch();
			}
			
			//cout<<endl<<endl<<usuario<<"-"<<password<<endl;
			
			//confirmar si las credenciales son correctas
		 	FILE *archivo; 
			archivo=fopen("Registro.txt","r");
			struct Usuarios Registrar;
			int Revisar=0;
			if(archivo==NULL)
			{
				printf("No existe el archivo ...\n\n");
			}
			else
			{
				int i=1;
				fread(&Registrar,sizeof(Usuarios),1,archivo);
				while (!feof(archivo))//este ciclo trae todos los usuarios
				{
		 			if(Registrar.nombre[0]==usuario[0] && Registrar.nombre[1]==usuario[1] && Registrar.nombre[2]==usuario[2]  && Registrar.nombre[3]==usuario[3] && Registrar.nombre[4]==usuario[4] )
		 			{
	 					 if(Registrar.password[0]==password[0] && Registrar.password[1]==password[1] && Registrar.password[2]==password[2] && Registrar.password[3]==password[3] && Registrar.password[4]==password[4] && posi<6)
	 					{
		 					i=i+1;	
							Revisar=1;
						}					 
					}
					fread(&Registrar,sizeof(Usuarios),1,archivo);		
				}  		
			}
			fclose(archivo);
				
				if(Revisar==1)
				{
					cout<<endl<<"\n\n\t\t\t\tUsuario y/o Contrasena CORRECTOS"<<endl;
					system("pause");
					
					if(Opcion==2)
					{
						//system("cls");

						system("cls");
						menuDeOpciones();
						system("pause");
						break;
					}
					else
					{
						system("cls");
						menuDeOpciones2();
						system("pause");
						break;
					}
				}
				else
				{
					cout<<endl<<"\t\t\t\tUsuario y/o Password INCORRECTOS"<<endl;
				}
		}
			else
			{
				cout<<endl<<"\t\tERROR: esa no es una opcion valida."<<endl<<endl;
			}	
				system("pause");
		}while(Confirmar==false &&intentos<3);
		
}

void CrearArchivoBinario(FILE *archivo)
{
	
	archivo=fopen("Registro.txt","a");
	struct Usuarios Registrar;
	if(archivo==NULL)
		{
			printf("No existe el archivo Usuario...");//validamos si existe el archivo, sino existe lo crea
			printf("Creando Archivo... ");
			archivo=fopen("Agenda.txt","w");
		}	
	
	 	memcpy(Registrar.espacio1,"l"+ '\n',1);
	    memcpy(Registrar.nombre, "admin",20);
	    memcpy(Registrar.password, "76543",20);
	    memcpy(Registrar.espacio2,"$"+ '\n',1);
		
		fwrite(&Registrar,sizeof(Usuarios),1,archivo);
  
    
		memcpy(Registrar.nombre, "anto",20);
	    memcpy(Registrar.password, "12345",20); 
		
		fwrite(&Registrar,sizeof(Usuarios),1,archivo);
    
		memcpy(Registrar.nombre, "pedro",20);
    	memcpy(Registrar.password, "56789",20);
    
		fwrite(&Registrar,sizeof(Usuarios),1,archivo);
    
		memcpy(Registrar.nombre, "juani",20);
		memcpy(Registrar.password, "24680",20);   
	
		fwrite(&Registrar,sizeof(Usuarios),1,archivo);
	
		memcpy(Registrar.nombre, "sam",20);
		memcpy(Registrar.password, "13579",20);   
		
		fwrite(&Registrar,sizeof(Usuarios),1,archivo);
	
		memcpy(Registrar.nombre, "rober",20);
		memcpy(Registrar.password, "33445",20);   
	
		fwrite(&Registrar,sizeof(Usuarios),1,archivo);

		memcpy(Registrar.nombre, "anita",20);
		memcpy(Registrar.password, "77889",20);   
	
		fwrite(&Registrar,sizeof(Usuarios),1,archivo);
 
		fclose(archivo);
}

void menuDeOpciones()
{
	int rp;
	
	do
	{
		cout << endl;
		tituloPrincipal();
		cout<<endl;
		cout <<"\t\t\t\t\t-------------VENTAS-------------\n";
		cout <<"\t\t\t\t\t================================\n";
		cout << "\t\t\t\t\tREALIZAR VENTA		...[1]\n";
		cout << "\t\t\t\t\tSALIR 			...[2]\n";
		cout <<"\t\t\t\t\tIngrese una opcion 	...[1-2]:" << endl;
		cout << "\t\t\t\t\t	-->";
		cin>>rp;
		
		switch(rp)
		{
			case 1 : 	system("cls");	
						buscarClientes();
				break;
				
			case 2 : 	system("cls");	
						menuPrincipal();
				break; 
			default : cout<<"\t\t\t\t\t	* INGRESE UN OPCION CORRECTA [1-2] *"<<endl;
		}
	}
	while(rp != 2);
}

void menuDeOpciones2()
{
	int rp1;
	
	do
	{
		
		tituloPrincipal();
		
		cout<<endl;
		cout<<"\t\t\t\t- REGISTRO DE CLIENTES .........[1]"<<endl;
		cout<<"\t\t\t\t- REGISTRO DE PRODUCTOS ........[2]"<<endl;
		cout<<"\t\t\t\t- REGISTRO DE VENDEDORES .......[3]"<<endl; //it now work btw :)
		cout<<"\t\t\t\t- REGISTRO DE FACTURAS .........[4]"<<endl;
		cout<<"\t\t\t\t- ATRAS ........................[5]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t\t- Ingrese una opcion...........[1-5]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout <<"\t\t\t\t-->";
		cin >> rp1;
		
		switch(rp1)
		{
			case 1 : 	system("cls");	
						listarClientes();
				break;
				
			case 2 : 	system("cls");	
						registroDeProductos();
				break;
				
			case 3 : 	system("cls");	
						//registrarVendedores();
						menuDeOpcionesM();
				break;
				
			case 4 : 	system("cls");	
						abrirArchivo();
				break;
				
			case 5 : 	system("cls");	
						menuPrincipal();
				break; 
			default : cout<<"\t\t\t\t\t	* INGRESE UN OPCION CORRECTA [1-5] *"<<endl;
		}
		
	}
	while(rp1 != 5);
	
}



//SECCIÓN VENDEDOR


void menuDeOpcionesM()
{
	//Declarar Variables
	int cho;
	do
	{
		tituloPrincipal();
		cout<<"\n"<<endl;
 		cout<<"\t\t\t\t\tREGISTRO DE VENDEDORES\n";
 		cout<<"\t\t\t***************************************************\n";
 		cout<<endl;
		cout<<"\t\t\t- Ingresar Vendedor(a) 			[1]\n ";
		cout<<"\t\t\t- Modificar Vendedor(a) 		[2]\n ";
		cout<<"\t\t\t- Buscar Vendedor(a) 			[3]\n ";
		cout<<"\t\t\t- Listar Vendedores  			[4]\n ";
		cout<<"\t\t\t- Salir 				[5]\n ";
		cout<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese solo una opción : 		[1 - 5]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t--> ";
		cin>>(cho);
		cout<<endl;	
	switch(cho)
		{
			case 1: system("cls");
					adicionarVendedor();
					break;
					
			case 2:system("cls");
					modificarVendedor();
					break;
					
			case 3:system("cls");
					buscarVendedor();
					break;
					
			case 4: system ("cls");
					listarVendedors();
					break;
					
					cout<<endl;
			case 5: cout <<"\t\t\t------------Muchas Gracias Por Tu Visita------------\n";
					
					system("pause");
					system("cls");
					
					
					menuDeOpciones2();
					
					
					
					exit(0);
					break;
			default:cout<<"\t\t\t---------Ingresar una opción correcta [1-6]---------\n"<<endl;		
		}
	}
	while(cho!=5);
}
	
void adicionarVendedor()
{
	int cod; 
	string nom;
	string usu;
	string contra; 
	string esta;
	string rpta;
	
	do
	{
		//Entrada de Datos
		cod = vendedorvector.getCorrelativo();
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t\t*****************************************\n";		
		cout<<"\t\t\t\t\t==> INGRESAR VENDEDOR(A) <==\n";
		cout<<"\t\t\t\t*****************************************\n";
		cout<<endl;
		cout<<"\t\t\t\tCódigo ("<<cod<<")"<<endl;
		cin.ignore();
		
		cout<<"\t\t\t\t- Ingresar Nombre de Vendedor(a) : ";
		getline(cin,nom);
		
		cout<<"\t\t\t\t- Ingresar Usuario de Vendedor(a) : ";
		getline(cin,usu);
		
		cout<<"\t\t\t\t- Ingresar Contrasena de Vendedor(a) : ";
		getline(cin,contra);
		
		cout<<"\t\t\t\t- Ingresar Estado de Vendedor(a) : ";
		cin>>esta;
		cout<<endl;
		
		Vendedor vendedor; /*Crear el Objeto*/
		
		vendedor.setCodigo(cod);
		vendedor.setNombreM(nom);
		vendedor.setUsuario(usu);
		vendedor.setContrasena(contra);
		vendedor.setEstado(esta);

		vendedorvector.add(vendedor); //Agregar el Objeto al Vector dinamico	
		vendedorvector.grabarEnArchivo(vendedor);
		
		cout<<"\t\t\t*********************************************************\n";
		cout<<"\t\t\t- Si usted desea continuar debe pulsar (YES o yes) : ";
		cin>>rpta;
		cout<<"\t\t\t*********************************************************\n";
		system("cls"); //Limpiar	
	}
	while(rpta =="YES" || rpta =="yes");
}

void listarVendedors()//Listado
	{
		for(int i=0;i<vendedorvector.rows();i++)
		{
			cout<<"\n"<<endl;
			cout<<"\t\t\t- El Código : "<<vendedorvector.get(i).getCodigo()<<"\n";
			cout<<"\t\t\t- El Nombre : "<<vendedorvector.get(i).getNombreM()<<"\n";
			cout<<"\t\t\t- El Usuario : "<<vendedorvector.get(i).getUsuario()<<"\n";
			cout<<"\t\t\t- La Contrasena : "<<vendedorvector.get(i).getContrasena()<<"\n";
			cout<<"\t\t\t- El Estado : "<<vendedorvector.get(i).getEstado()<<"\n";	
			cout<<endl;
		}
		system("pause");
		system("cls");
}

void modificarVendedor()
{
	int cod;
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***********************************************************\n";
		cout<<"\t\t\t- Ingrese el código del vendedor(a) que usted desea modificar : ";
		cin>>cod;
		cout<<"\t\t\t***********************************************************\n";
		cout<<endl;
	Vendedor objAModificar = vendedorvector.buscarPorCodigo1(cod);
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tRegistro Encontrado\n";
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t- El Código : "<<objAModificar.getCodigo()<<"\n";
		cout<<"\t\t\t- El Nombre : "<<objAModificar.getNombreM()<<"\n";
		cout<<"\t\t\t- El Usuario : "<<objAModificar.getUsuario()<<"\n";
		cout<<"\t\t\t- La Contrasena : "<<objAModificar.getContrasena()<<"\n";
		cout<<"\t\t\t- El Estado : "<<objAModificar.getEstado()<<"\n";
		cin.ignore();
		cout<<endl;
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tModificar campos\n";
		cout<<"\t\t\t**************************************************\n";
		string nomModificado;
		cout<<"\t\t\t- El Nuevo Nombre es :\n "; 
		cout<<"\t\t\t"; getline(cin,nomModificado);
		
		string usuModificado;
		cout<<"\t\t\t- El Nuevo Usuario es :\n "; 
		cout<<"\t\t\t"; getline(cin,usuModificado);
		
		string contraModificado;
		cout<<"\t\t\t- La Nueva Contraseña es :\n "; 
		cout<<"\t\t\t"; getline(cin,contraModificado);
		
		string estaModificado;
		cout<<"\t\t\t- El Nuevo Estado es :\n "; 
		cout<<"\t\t\t"; getline(cin,estaModificado);
	
	bool estado = vendedorvector.modificar(objAModificar,nomModificado,usuModificado,contraModificado,estaModificado);
		if(estado == true)
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tRegistro Modificado Exitosamente\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				/*Grabar en archivo*/
				vendedorvector.grabarModificarArchivo();
			}
		else
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tNo se Logró Editar el Registro!!\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				system("pause");
				menuDeOpcionesM();
			}
		system("pause");
		system("cls");	
}

void buscarVendedor()
{
	int cod;
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese el código que usted desea buscar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;

	Vendedor pro = vendedorvector.buscarPorCodigo1(cod);
	if(pro.getNombreM() != "Error")
		{
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t\t\tRegistro Encontrado\n";
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t- Código : "<<pro.getCodigo()<<"\n";
			cout<<"\t\t\t- Nombre : "<<pro.getNombreM()<<"\n";
			cout<<"\t\t\t- Usuario : "<<pro.getUsuario()<<"\n";
			cout<<"\t\t\t- Contrasena : "<<pro.getContrasena()<<"\n";
			cout<<"\t\t\t- Estado : "<<pro.getEstado()<<"\n";
			cout<<endl;
		}
	else
		{
			cout<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout <<"\t\t\t\tNo se encontró el registro!!!!!"<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout<<endl;
		}
		system("pause");
		system("cls");
		menuDeOpcionesM();
}

void tituloPrincipal()
{
	int i;
	cout<<"\n\t\t===================================================================\n";
	cout<<"\t\t\t\t\tEMPRESA ventaMas\n";
	cout<<"\t\t  Creación, eliminación, actualización, búsqueda, lista y reportes\n";
	cout<<"\t\t\t\t\t Copyright 2022\n";
	cout<<"\t\t===================================================================\n";
 
	i = 0;
	putchar('\n');
	for (; i < 110; i++) {
		putchar('_');
	}
}



//SECCIÓN CLIENTES


void adicionarClientes()
{
	int 	dni;
	int 	telf;
	string 	nom;
	string 	rpta;

		cout << "\t\t\t\t\t ---REGISTRAR NUEVO CLIENTE---" << "\n";	
		cout << "\t\t\t\t\tDNI: "; cin >> dni;
		cin.ignore();
		cout << "\t\t\t\t\t Ingresar nombre: "; getline(cin, nom);
		cout << "\t\t\t\t\t Ingresar telefono: "; cin >> telf;
		cout << endl;
		
		// funcion para poner la fecha y hora actual
		time_t   t,i;
		char *p;
		i = time (&t);
		p = ctime (&i); 
		
		Cliente cliente;
		
		cliente.setDNI(dni);
		cliente.setTelefono(telf);
		cliente.setNombre(nom);	
		
		DetalleVenta dVenta;
		dVenta.setTipoDV("Boleta");
		dVenta.setFechaDV(p);
		dVenta.setDNIDV(dni);
		dVenta.setNombreCDV(nom);
		dVenta.setTelefonoDV(telf);
		vectorDVenta.add(dVenta);
		vectorDVenta.grabarEnArchivoTV(dVenta);	
		vectorDVenta.grabarEnArchivoC(dVenta);	
				
		vectorCliente.add(cliente);
		vectorCliente.grabarEnArchivo(cliente);	
}

void buscarClientes()
{
	int dni;
	
	cout << "\t\t\t\t\t INGRESAR DNI: "; cin >> dni;
	Cliente client = vectorCliente.buscarPorDNI(dni);
	
	if(client.getNombre() != "Error")
	{
		cout << "\t\t\t\t\t   ¡¡¡Registro encontrado!!!" << endl;
		cout << endl;
		cout << "\t\t\t\t\t ***** BIENVENIDO/A " << client.getNombre() <<" *****";
		cout << endl;
		cout << endl;
		
		// funcion para poner la fecha y hora actual
		time_t   t,i;
		char *p;
		i = time (&t);
		p = ctime (&i); 
			
		DetalleVenta dVenta;
		dVenta.setTipoDV("Boleta");
		dVenta.setFechaDV(p);
		dVenta.setDNIDV(dni);
		dVenta.setNombreCDV(client.getNombre());
		dVenta.setTelefonoDV(client.getTelefono());
		vectorDVenta.add(dVenta);
		vectorDVenta.grabarEnArchivoTV(dVenta);
		vectorDVenta.grabarEnArchivoC(dVenta);	
		
		generarVenta();
	}
	else
	{
		cout << "\t\t\t\t\t ¡¡¡No se encontró el registro :( !!!" << endl;
		adicionarClientes();
		generarVenta();
	}
	system ("pause");
	system("cls");
	
}

void generarVenta()
{
	int i;
	string rpta;
	int codProd;
	int codVent;
	int cant;
	float subTotal;
	float Total = 0;
	
	do{
		cout << "\t\t\t\t\t >>>>>>>>>>>>>>>>>>>>>>>>>" << "\n";
		cout << "\t\t\t\t\t Codigo del producto: "; cin >> codProd;
		Producto prod = vectorProducto.buscarPorCodigo1(codProd);

		if(prod.getNombre() !="Error")
		{
			cout << "\t\t\t\t\t -------------------------" << "\n";
			cout << "\t\t\t\t\t Nombre del producto: " <<	prod.getNombre() << "\n"; 
			cout << "\t\t\t\t\t Marca del producto: " <<	prod.getMarca() << "\n";
			cout << "\t\t\t\t\t Precio del producto: S/." <<	prod.getPrecio() <<".0" << "\n";
			cout << "\t\t\t\t\t -------------------------" << "\n";
			cout << "\t\t\t\t\t Cantidad: "; cin >> cant;
			subTotal = cant * prod.getPrecio();
			Total += subTotal;
			cout << "\t\t\t\t\t ---> SUBTOTAL: S/." << subTotal << endl;	
			
			DetalleVenta dVenta;
			//Venta
			dVenta.setCodigoDV(prod.getCodigo());
			dVenta.setNombreDV(prod.getNombre());
			dVenta.setMarcaDV(prod.getMarca());
			dVenta.setDescripcionDV(prod.getDescripcion());
			dVenta.setCantidadDV(cant);
			dVenta.setPrecioDV(prod.getPrecio());
			dVenta.setsubTotalDV(subTotal);

			vectorDVenta.add(dVenta);
			vectorDVenta.grabarEnArchivoP(dVenta);		
		}
		else
		{
			cout << "\t\t\t\t\t ¡¡¡No se encontró el registro :( !!!" << endl;
		}
		cout << "\t\t\t\t\t ¿Añadir más? (Y / N): "; cin >> rpta;
		cout << endl;
	}
	while(rpta == "y" || rpta == "Y");
	
	cout << "\t\t\t\t\t TOTAL: S/." << Total <<".0" << "\n";
	DetalleVenta dVenta;
	dVenta.setTotalDV(Total);
	vectorDVenta.add(dVenta);
	vectorDVenta.grabarEnArchivoT(dVenta);	
	
	cout << "\t\t\t\t\t COMPRA FINALIZADA " << endl;
			system ("pause");
			system("cls");
			menuDeOpciones();
}


//Productos
void registroDeProductos()
{
	int cho;
	do
	{
		//tituloPrincipal();
		cout<<"\n"<<endl;
 		cout<<"\t\t\t\t\tREGISTRO DE PRODUCTOS\n";
 		cout<<"\t\t\t***************************************************\n";
 		cout<<endl;
		cout<<"\t\t\t- INGRESAR PRODUCTO .............[1]\n ";
		cout<<"\t\t\t- ELIMINAR PRODUCTO .............[2]\n ";
		cout<<"\t\t\t- MODIFICAR PRODUCTO ............[3]\n ";
		cout<<"\t\t\t- BUSCAR PRODUCTO ..................[4]\n ";
		cout<<"\t\t\t- LISTAR PRODUCTOS ..............[5]\n ";
		cout<<"\t\t\t- ATRAS .........................[6]\n ";
		cout<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese solo una opción : 		[1 - 6]"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t--> ";
		cin>>(cho);
		cout<<endl;	
	switch(cho)
		{
			case 1: system("cls");
					adicionarProducto();
					break;
					
			case 2:system("cls");
					eliminarProducto();
					break;
					
			case 3:system("cls");
					modificarProducto();
					break;
					
			case 4:system("cls");
					buscarProducto();
					break;
					
			case 5: system ("cls");
					listarProductos();
					break;
					
					
			case 6: system ("cls");
					menuDeOpciones2();
					break;;
			default:cout<<"\t\t\t---------Ingresar una opción correcta [1-6]---------\n"<<endl;		
		}
	}
	while(cho!=6);
}
	
void adicionarProducto()
{
	int 	cod;
	string 	nom,  mar, descri;
	float   pre;
	int     sto;
	string  rpta;
	
	do
	{
		//Entrada de Datos
		cod = productovector.getCorrelativo();
		//tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t\t*****************************************\n";		
		cout<<"\t\t\t\t\t==> INGRESAR PRODUCTO <==\n";
		cout<<"\t\t\t\t*****************************************\n";
		cout<<endl;
		cout<<"\t\t\t\tCódigo ("<<cod<<")"<<endl;
		cin.ignore();
		
		cout<<"\t\t\t\t- Ingresar Nombre de Producto : ";
		getline(cin,nom);
		
		cout<<"\t\t\t\t- Ingresar Marca de Producto : ";
		getline(cin,mar);
		
		cout<<"\t\t\t\t- Ingresar Descripción de Producto : ";
		getline(cin,descri);
		
		cout<<"\t\t\t\t- Ingresar Precio de Producto : ";
		cin>>pre;
		
		cout<<"\t\t\t\t- Ingresar stock (cantidad)  de  Producto : ";
		cin>>sto;
		cout<<endl;
		
		Producto producto; /*Crear el Objeto*/
		
		producto.setCodigo(cod);
		producto.setNombre(nom);
		producto.setMarca(mar);
		producto.setDescripcion(descri);
		producto.setPrecio(pre);
		producto.setStock(sto);
	
		productovector.add(producto); //Agregar el Objeto al Vector dinamico	
		productovector.grabarEnArchivo(producto);
		
		cout<<"\t\t\t*********************************************************\n";
		cout<<"\t\t\t- Si usted desea continuar debe pulsar (Y / N) : ";
		cin>>rpta;
		cout<<"\t\t\t*********************************************************\n";
		system("cls"); //Limpiar	
	}
	while(rpta =="y" || rpta =="Y");
}

void listarProductos()
{
		for(int i=0;i<productovector.rows();i++)
		{
			cout<<"\n"<<endl;
			cout<<"\t\t\t- El Código : "<<productovector.get(i).getCodigo()<<"\n";
			cout<<"\t\t\t- El Nombre : "<<productovector.get(i).getNombre()<<"\n";
			cout<<"\t\t\t- La Marca : "<<productovector.get(i).getMarca()<<"\n";
			cout<<"\t\t\t- La Descripción : "<<productovector.get(i).getDescripcion()<<"\n";
			cout<<"\t\t\t- El Precio : "<<productovector.get(i).getPrecio()<<"\n";	
			cout<<"\t\t\t- El Stock (cantidad) : "<<productovector.get(i).getStock()<<"\n";
			cout<<endl;
		}
		system("pause");
		system("cls");
}

void eliminarProducto()
{
	int cod;
		//tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t\t- Ingresar el código a eliminar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;
	Producto objAEliminar = productovector.buscarPorCodigo1(cod);
		if(objAEliminar.getNombre() != "Error")
			{
				productovector.remove(objAEliminar);
				cout<<"\t\t\t------>Registro Eliminado Satisfactoriamente<------\n";
				productovector.grabarModificarEliminarArchivo();
			}
		else
			{
		cout<<endl;
		cout<<"\t\t\t---------------------------------------------------\n";		
		cout<<"\t\t\t\t--> No se encontró el registro !!!! \n";
		cout<<"\t\t\t---------------------------------------------------\n";
		cout<<endl;
			}
		system ("pause");
		system("cls");	
		registroDeProductos();
}

void modificarProducto()
{
	int cod;
		//tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese el código que usted desea modificar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;
	Producto objAModificar = productovector.buscarPorCodigo1(cod);
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tRegistro Encontrado\n";
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t- El Código : "<<objAModificar.getCodigo()<<"\n";
		cout<<"\t\t\t- El Nombre : "<<objAModificar.getNombre()<<"\n";
		cout<<"\t\t\t- La Marca : "<<objAModificar.getMarca()<<"\n";
		cout<<"\t\t\t- La Descripción : "<<objAModificar.getDescripcion()<<"\n";
		cout<<"\t\t\t- El Precio : "<<objAModificar.getPrecio()<<"\n";
		cout<<"\t\t\t- El Stock : "<<objAModificar.getStock()<<"\n";
		cin.ignore();
		cout<<endl;
		cout<<"\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\tModificar campos\n";
		cout<<"\t\t\t**************************************************\n";
		string nomModificado;
		cout<<"\t\t\t- El Nuevo Nombre es :\n "; 
		cout<<"\t\t\t"; getline(cin,nomModificado);
		
		string marModificado;
		cout<<"\t\t\t- La Nueva Marca es :\n "; 
		cout<<"\t\t\t"; getline(cin,marModificado);
		
		string descriModificado;
		cout<<"\t\t\t- La Nueva Descripción es :\n "; 
		cout<<"\t\t\t"; getline(cin,descriModificado);
		
		float preModificado;
		cout<<"\t\t\t- El Nuevo Precio es :\n "; 
		cout<<"\t\t\t"; cin>>preModificado;
		
		int stoModificado;
		cout<<"\t\t\t- El Nuevo Stock (cantidad) es :\n"; 
		cout<<"\t\t\t"; cin>>stoModificado;
	
	bool estado = productovector.modificar(objAModificar,nomModificado,marModificado,descriModificado,preModificado,stoModificado);
		if(estado == true)
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tRegistro Modificado Exitosamente\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				/*Grabar en archivo*/
				productovector.grabarModificarEliminarArchivo();
			}
		else
			{
				cout<<endl;
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<"\t\t\t\tNo se Logró Editar el Registro!!\n";
				cout<<"\t\t\t------------------------------------------------\n";
				cout<<endl;
				system("pause");
				registroDeProductos();
			}
		system("pause");
		system("cls");	
}

void buscarProducto()
{
	int cod;
		//tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese el código que usted desea buscar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;

	Producto pro = productovector.buscarPorCodigo1(cod);
	if(pro.getNombre() != "Error")
		{
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t\t\tRegistro Encontrado\n";
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t- Código : "<<pro.getCodigo()<<"\n";
			cout<<"\t\t\t- Nombre : "<<pro.getNombre()<<"\n";
			cout<<"\t\t\t- Marca : "<<pro.getMarca()<<"\n";
			cout<<"\t\t\t- Descripción : "<<pro.getDescripcion()<<"\n";
			cout<<"\t\t\t- Precio : "<<pro.getPrecio()<<"\n";
			cout<<"\t\t\t- Stock : "<<pro.getStock()<<"\n";
		}
	else
		{
			cout<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout <<"\t\t\t\tNo se encontró el registro!!!!!"<<endl;
			cout<<"\t\t\t------------------------------------------------\n";
			cout<<endl;
		}
		system("pause");
		system("cls");
		registroDeProductos();
}

void listarClientes()
{
	for(int i=0; i<vectorCliente.size(); i++) 
	{
		cout << "DNI: "<<vectorCliente.get(i).getDni()<< "\n";
		cout << "Nombre: "<<vectorCliente.get(i).getNombre()<< "\n";
		cout << "Telefono: "<<vectorCliente.get(i).getTelefono()<< "\n";
		cout << endl;
	}
	system("pause");
	system("cls");
}

void abrirArchivo()
{
	int c;
	FILE * archivo;
	archivo = fopen("DetalleVenta1.csv", "r");
	if (archivo)
	{
		while ((c = getc(archivo)) != EOF)
			putchar(c);
		fclose(archivo);
	}
	system("pause");
	system("cls");
}

