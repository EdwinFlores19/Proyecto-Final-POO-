#include <iostream>
#include <vector>
#include <fstream>
#include "client.h"
using std::stoi;
using namespace std;

class ClienteVector
	{
		private:
			vector<Cliente> vectorCliente;
		public:
			ClienteVector()
			{
				cargarDatos();
			}
			void add(Cliente obj)
			{
				vectorCliente.push_back(obj);
			}
			Cliente get(int pos) 
			{
				return vectorCliente[pos];
			}
			int size()
			{
				return vectorCliente.size();
			}
			
			Cliente buscarPorDNI(int dni)
			{
				Cliente objError;
				objError.setNombre("Error");
				for (Cliente x : vectorCliente)
				{
					if (dni == x.getDni())
					{
						return x;	
					}
				}
				return objError;
			}

			void grabarEnArchivo(Cliente cliente)
			{
				try 
				{		
					fstream archivoCliente;
					archivoCliente.open("cliente1.csv", ios::app);
					if (archivoCliente.is_open())
					{
						archivoCliente << 	cliente.getDni() 	<< ";" <<
											cliente.getTelefono() << ";" <<
											cliente.getNombre()  << ";" << endl;
						archivoCliente.close();			
					}
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro p:/";
				}
			}
			
			void cargarDatos()
			{
				try
				{
					int i;
					size_t posicion; //Cantidad maxima
					string linea;
					string temporal[3];
					fstream archivoCliente;
					archivoCliente.open("cliente1.csv", ios::in);
					if(archivoCliente.is_open())
					{
						while(!archivoCliente.eof())
						{
							while(getline(archivoCliente,linea))
							{
								i = 0;
								while((posicion = linea.find(";")) != string::npos) // string::npos = -1
								{
									temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
									linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
									i++; 
								}

								Cliente	cliente;
								cliente.setDNI(std::stoi(temporal[0]));
								cliente.setTelefono(std::stoi(temporal[1]));
								cliente.setNombre(temporal[2]);
								add(cliente);
							}
						}
					} 
					archivoCliente.close();	
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro >:/";
				}
			}

	};
