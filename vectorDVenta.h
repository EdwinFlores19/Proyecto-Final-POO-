#include <iostream>
#include <vector>
#include <fstream>
#include "detalleVenta.h"
using std::stoi;
using namespace std;

class DetVentaVector
{
	private:
		vector <DetalleVenta> vectorDVenta;
	public:
			DetVentaVector()
			{
			}
			void add(DetalleVenta obj) //Agregar objetos al vector
			{
				vectorDVenta.push_back(obj);
			}
			DetalleVenta get(int pos) // Entregar el objeto actual, segun la posicion pasada como parámetro
			{
				return vectorDVenta[pos];
			}
			int size()
			{
				return vectorDVenta.size();
			}
		
		/******************************************/
		void grabarEnArchivoTV(DetalleVenta Dventa)
			{
				try 
				{		
					fstream archivoDVenta3;
					archivoDVenta3.open("DetalleVenta1.csv", ios::app);
					if (archivoDVenta3.is_open())
					{
						archivoDVenta3 << 	Dventa.getTipoDV() << ";" << 
											Dventa.getFechaDV();
						archivoDVenta3.close();			
					}
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro B/";
				}
			}
		
		/******************************************/
		void grabarEnArchivoC(DetalleVenta Dventa)
			{
				try 
				{		
					fstream archivoDVenta1;
					archivoDVenta1.open("DetalleVenta1.csv", ios::app);
					if (archivoDVenta1.is_open())
					{
						archivoDVenta1 <<Dventa.getDniDV() << ";" <<
										Dventa.getNombreCDV()  << ";" <<
										Dventa.getTelefonoDV() << ";" << endl;
						archivoDVenta1.close();			
					}
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro B/";
				}
			}
					
		/******************************************/
		void grabarEnArchivoP(DetalleVenta Dventa)
			{
				try 
				{		
					fstream archivoDVenta;
					archivoDVenta.open("DetalleVenta1.csv", ios::app);
					if (archivoDVenta.is_open())
					{
						archivoDVenta << 
										Dventa.getCodigoDV() << ";" <<
										Dventa.getNombreDV() << ";" <<
										Dventa.getMarcaDV() << ";" << 
										Dventa.getDescripcionDV()  << ";" << 
										Dventa.getCantidadDV() << ";" <<
										Dventa.getStockDV() << ";" << "S/." <<
										Dventa.getPrecioDV() <<  ";" << "S/." <<
										Dventa.getSubTotalDV() <<  ";" << endl;
						archivoDVenta.close();			
					}
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro B/";
				}
			}
		
		/******************************************/	
		void grabarEnArchivoT(DetalleVenta Dventa)
			{
				try 
				{		
					fstream archivoDVenta2;
					archivoDVenta2.open("DetalleVenta1.csv", ios::app);
					if (archivoDVenta2.is_open())
					{
						archivoDVenta2 	<< "Total" << ";" << ";" << ";" << ";" << ";"
						 				<< ";" << ";" << "S/." << Dventa.getTotalDV() << ";" << "\n\n";
						archivoDVenta2.close();			
					}
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro B/";
				}
			}
			
			
			/*void cargarDatosTV()
			{
				try
				{
					int i;
					size_t posicion; //Cantidad maxima
					string linea;
					string temporal[2];
					fstream archivoDVenta3;
					archivoDVenta3.open("DetalleVenta1.csv", ios::in);
					if(archivoDVenta3.is_open())
					{
						while(!archivoDVenta3.eof())
						{
							while(getline(archivoDVenta3,linea))
							{
								i = 0;
								while((posicion = linea.find(";")) != string::npos) // string::npos = -1
								{
									temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
									linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
									i++; 
								}
								
								//Crear un objeto de tipo alumno
								DetalleVenta dVenta1;
								
								dVenta1.setTipoDV(temporal[0]);
								dVenta1.setFechaDV(temporal[1]);
								add(dVenta1);
							}						
						}
					} 
					archivoDVenta3.close();	
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro <:/";
				}
			}
				
			
			void cargarDatosC()
			{
				try
				{
					int i;
					size_t posicion; //Cantidad maxima
					string linea;
					string temporal[3];
					fstream archivoDVenta1;
					archivoDVenta1.open("DetalleVenta1.csv", ios::in);
					if(archivoDVenta1.is_open())
					{
						while(!archivoDVenta1.eof())
						{
							while(getline(archivoDVenta1,linea))
							{
								i = 0;
								while((posicion = linea.find(";")) != string::npos) // string::npos = -1
								{
									temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
									linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
									i++; 
								}
								
								//Crear un objeto de tipo alumno
								DetalleVenta dVenta2;
								dVenta2.setDNIDV(std::stoi(temporal[0]));
								dVenta2.setNombreCDV(temporal[1]);
								dVenta2.setTelefonoDV(std::stoi(temporal[2]));
								add(dVenta2);
							}						
						}
					} 
					archivoDVenta1.close();	
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro <:/";
				}
			}
				
	
			void cargarDatosP()
			{
				try
				{
					int i;
					size_t posicion; //Cantidad maxima
					string linea;
					string temporal[7];
					fstream archivoDVenta;
					archivoDVenta.open("DetalleVenta1.csv", ios::in);
					if(archivoDVenta.is_open())
					{
						while(!archivoDVenta.eof())
						{
							while(getline(archivoDVenta,linea))
							{
								i = 0;
								while((posicion = linea.find(";")) != string::npos) // string::npos = -1
								{
									temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
									linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
									i++; 
								}
								
								//Crear un objeto de tipo alumno
								DetalleVenta dVenta;
								
								dVenta.setCodigoDV(std::stoi(temporal[0]));
								dVenta.setNombreDV(temporal[1]);
								dVenta.setMarcaDV(temporal[2]);
								dVenta.setDescripcionDV(temporal[3]);
								dVenta.setCantidadDV(std::stoi(temporal[4]));
								dVenta.setStockDV(std::stoi(temporal[5]));
								dVenta.setPrecioDV(std::stoi(temporal[6]));
								dVenta.setsubTotalDV(std::stoi(temporal[7]));
								add(dVenta);
							}						
						}
					} 
					archivoDVenta.close();	
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro <:/";
				}
			}
			
						
			void cargarDatosT()
			{
				try
				{
					int i;
					size_t posicion; //Cantidad maxima
					string linea;
					string temporal[1];
					fstream archivoDVenta2;
					archivoDVenta2.open("DetalleVenta1.csv", ios::in);
					if(archivoDVenta2.is_open())
					{
						while(!archivoDVenta2.eof())
						{
							while(getline(archivoDVenta2,linea))
							{
								i = 0;
								while((posicion = linea.find(";")) != string::npos) // string::npos = -1
								{
									temporal[i] = linea.substr(0, posicion); //substr obtiene/ saca una parte de la cadena
									linea.erase(0, posicion + 1); //se pone +1 para borrar el primer string(0) mas el ";"
									i++; 
								}
								
								//Crear un objeto de tipo alumno
								DetalleVenta dVenta3;
								
								dVenta3.setTotalDV(std::stoi(temporal[0]));
								add(dVenta3);
							}						
						}
					} 
					archivoDVenta2.close();	
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro <:/";
				}
			}
				*/
				
				
				
			
		
};
