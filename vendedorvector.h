#include <iostream>
#include <vector>
#include<fstream>
#include <conio.h>
#include <stdlib.h>
#include "vendedor.h"
using std::stoi;
using namespace std;

class VendedorVector
{
	private:
		vector<Vendedor>vectorVendedor;
	public:
		VendedorVector()
		{
			cargarDatosDelArchivoAlVector();
		}
	int getCorrelativo()
		{
			if(vectorVendedor.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorVendedor[vectorVendedor.size() - 1].getCodigo() + 1;
			}
		}
	void add(Vendedor obj) 
		{
			vectorVendedor.push_back(obj);
		}
	Vendedor get (int pos)
		{
			return vectorVendedor[pos];
		}
	int rows()
		{	
			return vectorVendedor.size();
		}
	Vendedor buscarPorCodigo1(int codigo)
		{
			Vendedor objError;
			objError.setNombreM("Error");
			for(Vendedor x:vectorVendedor)
			{
				if(codigo == x.getCodigo())
				{
					return x;
				}
			}
			return objError;
		}
	Vendedor buscarPorCodigo2(int codigo)
		{
			for(int i=0;i<rows();i++)
			{
				if(codigo == get(i).getCodigo())
				{
					return get(i);
				}
			}
		}
	int getPostArray(Vendedor obj)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					return i;
				}
			}
			return -1;
		}
	void remove(Vendedor obj)
		{
			vectorVendedor.erase(vectorVendedor.begin() + getPostArray(obj));
		}		
	bool modificar(Vendedor obj,string nom,string usu,string contra,string esta)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					vectorVendedor[i].setNombreM(nom);
					vectorVendedor[i].setUsuario(usu);
					vectorVendedor[i].setContrasena(contra);
					vectorVendedor[i].setEstado(esta);
					
					return true;
				}
			}
			return false;
		}
	void grabarEnArchivo(Vendedor vendedor)
		{
			try
			{
				fstream archivoVendedor;
				archivoVendedor.open("vendedors.csv",ios::app);
				if(archivoVendedor.is_open())
				{
					archivoVendedor<<vendedor.getCodigo()<<";"<<vendedor.getNombreM()<<";"<<vendedor.getUsuario()<<";"<<vendedor.getContrasena()<<";"<<vendedor.getEstado()<<";"<<endl;
					archivoVendedor.close();
				}
			}
			catch(exception e)
			{
				cout<<"¡¡¡Ocurrio un error al grabar el registro!!!";
			}
		}
	void grabarModificarArchivo()
		{
			try
			{
				fstream archivoVendedors;
				archivoVendedors.open("vendedors.csv",ios::out);
				if(archivoVendedors.is_open())
				{
					for(Vendedor x : vectorVendedor)
					{
						archivoVendedors<<x.getCodigo()<<";"<<x.getNombreM()<<";"<<x.getUsuario()<<";"<<x.getContrasena()<<";"<<x.getEstado()<<";"<<"\n";	
					}
					archivoVendedors.close();
				}
			}
			catch(exception e)
			{
				cout<<"¡¡¡Ocurrio un error al grabar en el archivo!!!";
			}
		}
	void cargarDatosDelArchivoAlVector()
		{
			try
			{
				int i;
				size_t 	posi; //Cantidad Maxima
				string 	linea;
				string 	temporal[5];  //Cantidad de Columnas
				fstream archivoVendedor;
				archivoVendedor.open("vendedors.csv",ios::in);
				if(archivoVendedor.is_open())
				{
					while(!archivoVendedor.eof())
					{
						while(getline(archivoVendedor,linea))
						{
							i = 0;
							while((posi = linea.find(";")) != string::npos)
							{
								temporal[i] = linea.substr(0,posi);
								linea.erase(0,posi + 1);
								i++;
							}
							//Crear un Objeto de Tipo Alumno
							Vendedor vendedor;
							vendedor.setCodigo(std::stoi(temporal[0]));
							vendedor.setNombreM(temporal[1]);
							vendedor.setUsuario(temporal[2]);
							vendedor.setContrasena(temporal[3]);
							vendedor.setEstado(temporal[4]);
						
							add(vendedor);
						}
					}
				}
				archivoVendedor.close();
			}
			catch(exception e)
			{	
				cout<<"¡¡¡Ocurrio un error al cargar en el archivo!!!";
			}
		}
};
