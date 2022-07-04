#include <iostream>
#include <vector>
#include <fstream>
#include "venta.h"
#include "client.h"
using std::stoi;
using namespace std;

class VentaVector
	{
		private:
			vector<Venta1> vectorVenta;
		public:
			VentaVector()
			{
				cargarDatos();
			}
			void add(Venta1 obj) //Agregar objetos al vector
			{
				vectorVenta.push_back(obj);
			}
			Venta1 get(int pos) // Entregar el objeto actual, segun la posicion pasada como parámetro
			{
				return vectorVenta[pos];
			}
			int size()
			{
				return vectorVenta.size();
			}
		
			void grabarEnArchivo(Venta1 venta)
			{
				try 
				{		
					fstream archivoVenta;
					archivoVenta.open("venta1.csv", ios::app);
					if (archivoVenta.is_open())
					{
						archivoVenta << venta.getCodVen() << ";" <<
										venta.getCodCli() << ";" <<
										venta.getFecha()  << ";" <<
										venta.getEstado() << ";" <<
										venta.getTotal()  << ";" << endl;
						archivoVenta.close();			
					}
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro °:/";
				}
			}
			
			void cargarDatos()
			{
				try
				{
					int i;
					size_t posicion; //Cantidad maxima
					string linea;
					string temporal[5];
					fstream archivoVenta;
					archivoVenta.open("venta1.csv", ios::in);
					if(archivoVenta.is_open())
					{
						while(!archivoVenta.eof())
						{
							while(getline(archivoVenta,linea))
							{
								i = 0;
								while((posicion = linea.find(";")) != string::npos) // string::npos = -1
								{
									temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
									linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
									i++; 
								}
								
								//Crear un objeto de tipo alumno
								Venta1 venta;
								
								venta.setCodVen(std::stoi(temporal[0]));
								venta.setCodCli(std::stoi(temporal[1]));
								venta.setFecha(temporal[2]);
								venta.setEstado(std::stoi(temporal[3]));
								venta.setTotal(std::stoi(temporal[4]));
								add(venta);
							}						
						}
					} 
					archivoVenta.close();	
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro |:/";
				}
			}
	};
			
	
