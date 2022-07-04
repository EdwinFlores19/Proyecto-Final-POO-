#include <iostream>
#include <vector>
#include<fstream>
#include <conio.h>
#include <stdlib.h>
#include "producto.h"
using std::stoi;
using namespace std;

class ProductoVector
{
	private:
		vector<Producto>vectorProducto;
	public:
		ProductoVector()
		{
			cargarDatosDelArchivoAlVector();
		}
	int getCorrelativo()
		{
			if(vectorProducto.size() == 0)
			{
				return 1;
			}
			else
			{
				return vectorProducto[vectorProducto.size() - 1].getCodigo() + 1;
			}
		}
	void add(Producto obj) 
		{
			vectorProducto.push_back(obj);
		}
	Producto get (int pos)
		{
			return vectorProducto[pos];
		}
	int rows()
		{	
			return vectorProducto.size();
		}
	Producto buscarPorCodigo1(int codigo)
		{
			Producto objError;
			objError.setNombre("Error");
			for(Producto x:vectorProducto)
			{
				if(codigo == x.getCodigo())
				{
					return x;
				}
			}
			return objError;
		}
	Producto buscarPorCodigo2(int codigo)
		{
			for(int i=0;i<rows();i++)
			{
				if(codigo == get(i).getCodigo())
				{
					return get(i);
				}
			}
		}
	int getPostArray(Producto obj)
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
	void remove(Producto obj)
		{
			vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));
		}		
	bool modificar(Producto obj,string nom,string mar,string descri,float pre,int sto)
		{
			for(int i=0;i<rows();i++)
			{
				if(obj.getCodigo() == get(i).getCodigo())
				{
					vectorProducto[i].setNombre(nom);
					vectorProducto[i].setMarca(mar);
					vectorProducto[i].setDescripcion(descri);
					vectorProducto[i].setPrecio(pre);
					vectorProducto[i].setStock(sto);
					
					return true;
				}
			}
			return false;
		}
	void grabarEnArchivo(Producto producto)
		{
			try
			{
				fstream archivoProducto;
				archivoProducto.open("productos.csv",ios::app);
				if(archivoProducto.is_open())
				{
					archivoProducto<<producto.getCodigo()<<";"<<producto.getNombre()<<";"<<producto.getMarca()<<";"<<producto.getDescripcion()<<";"<<producto.getPrecio()<<";"<<producto.getStock()<<";"<<endl;
					archivoProducto.close();
				}
			}
			catch(exception e)
			{
				cout<<"¡¡¡Ocurrio un error al grabar el registro!!!";
			}
		}
	void grabarModificarEliminarArchivo()
		{
			try
			{
				fstream archivoProductos;
				archivoProductos.open("productos.csv",ios::out);
				if(archivoProductos.is_open())
				{
					for(Producto x : vectorProducto)
					{
						archivoProductos<<x.getCodigo()<<";"<<x.getNombre()<<";"<<x.getMarca()<<";"<<x.getDescripcion()<<";"<<x.getPrecio()<<";"<<x.getStock()<<";"<<"\n";	
					}
					archivoProductos.close();
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
				string 	temporal[6];  //Cantidad de Columnas
				fstream archivoProducto;
				archivoProducto.open("productos.csv",ios::in);
				if(archivoProducto.is_open())
				{
					while(!archivoProducto.eof())
					{
						while(getline(archivoProducto,linea))
						{
							i = 0;
							while((posi = linea.find(";")) != string::npos)
							{
								temporal[i] = linea.substr(0,posi);
								linea.erase(0,posi + 1);
								i++;
							}
							//Crear un Objeto de Tipo Alumno
							Producto producto;
							producto.setCodigo(std::stoi(temporal[0]));
							producto.setNombre(temporal[1]);
							producto.setMarca(temporal[2]);
							producto.setDescripcion(temporal[3]);
							producto.setPrecio(std::stoi(temporal[4]));
							producto.setStock(std::stoi(temporal[5]));
						
							add(producto);
						}
					}
				}
				archivoProducto.close();
			}
			catch(exception e)
			{	
				cout<<"¡¡¡Ocurrio un error al cargar en el archivo!!!";
			}
		}
};
