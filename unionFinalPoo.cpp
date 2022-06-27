#include <iostream>
#include <vector>
#include <locale.h>
#include <string>
#include <cstring>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#define MAX 110

using std::stoi;
using namespace std;

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//INICIO DE CLASES
//////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


//CLASE VENDEDOR 


class Vendedor
{
	private:
	int codigo;
	string nombreM;
	string usuario;
	string contrasena;
	string estado;
	
	public:
	Vendedor(int cod, string nom, string usu, string contra, string esta)
	{
		this -> codigo = cod;
		this -> nombreM = nom;
		this -> usuario = usu;
		this -> contrasena = contra;
		this -> estado = esta;
	}
	Vendedor()
	{
		
	}
	~Vendedor()
	{
		
	}
	void setCodigo(int cod)
	{
		codigo = cod;
	}
	void setNombreM(string nom)
	{
		nombreM = nom;
	}
	void setUsuario(string usu)
	{
		usuario = usu;
	}
	void setContrasena(string contra)
	{
		contrasena = contra;
	}
	void setEstado(string esta)
	{
		estado = esta;
	}
		
	int getCodigo()
	{
	return this->codigo;
	}
	string getNombreM()
	{
	return this->nombreM;
	}
	string getUsuario()
	{
	return this->usuario;
	}
	string getContrasena()
	{
	return this->contrasena;
	}
	string getEstado()
	{
	return this->estado;
	}	
};







//CLASE CLIENTE

class Cliente
{
	private:
		int DNI;
		int telefono;
		string nombreC;
	public:
		Cliente(int dni, int telf, string nom)
		{
			this -> DNI = dni;
			this -> telefono = telf;
			this -> nombreC = nom;
		}
		Cliente()
		{
		}
		~Cliente()
		{
		}
		
		void setDNI(int dni)
		{
			DNI = dni;
		}
		void setTelefono(int telf)
		{
			telefono = telf;
		}
		void setNombreC(string nom)
		{
			nombreC = nom;
		}
		
		int getDni()
		{
			return this -> DNI;
		}
		int getTelefono()
		{
			return this -> telefono;
		}
		string getNombreC()
		{
			return this -> nombreC;
		}
};

//CLASE PRODUCTO 

class Producto
{
	private:
	int codigo;
	string nombreP, marca, descripcion;
	float precio;
	int stock;
	
	public:
	Producto(int cod, string nom, string mar, string descri, float pre, int sto)
	{
		this -> codigo = cod;
		this -> nombreP = nom;
		this -> marca = mar;
		this -> descripcion = descri;
		this -> precio = pre;
		this -> stock = sto;
	}
	Producto()
	{
		
	}
	~Producto()
	{
		
	}
	void setCodigo(int cod)
	{
		codigo = cod;
	}
	void setNombreP(string nom)
	{
		nombreP = nom;
	}
	void setMarca(string mar)
	{
		marca = mar;
	}
	void setDescripcion(string descri)
	{
		descripcion = descri;
	}
	void setPrecio(float pre)
	{
		precio = pre;
	}
	void setStock(int sto)
	{
		stock = sto;
	}
		
	int getCodigo()
	{
		return this->codigo;
	}
	string getNombreP()
	{
	return this->nombreP;
	}
	string getMarca()
	{
	return this->marca;
	}
	string getDescripcion()
	{
	return this->descripcion;
	}
	float getPrecio()
	{
	return this->precio;
	}
	int getStock()
	{
	return this->stock;
	}	
};


//CLASE VENTA

class Venta1
{
	private:
		int		codVenta;
		int 	codCliente;
		string	fecha;
		int		estado;
		double	total;
	public:
		Venta1(int codVen, int codCli, string fecha, int estado, double total)
		{
			this ->	codVenta 	= codVen;
			this -> codCliente 	= codCli;
			this -> fecha 		= fecha;
			this -> estado 		= estado;
			this -> total 		= total;
		}
		Venta1(){
		}
		//Destructor
		~Venta1(){
		}
		
		void setCodVen(int codVen)
		{
	        codVenta 	= codVen;
	    }	
	    
	    void setCodCli(int codCli)
		{
	        codCliente 	= codCli;
	    }
	    
	    void setFecha(string fecha)
		{
	        fecha = fecha;
	    }
	    
	    void setTotal(double total)
		{
	        total = total;
	    }
	    
	    void setEstado(int estado)
		{
	        estado = estado;
	    }
	    
	    
		int getCodVen() 
		{
        	return this -> codVenta;
	    }
	
	    int getCodCli()
		{
	        return this -> codCliente;
	    }
	
	    string getFecha()
		{
	        return this -> fecha;
	    }
	
	    double getTotal()
		{
	        return this -> total;
	    }
	
	    int getEstado()
		{
	        return this -> estado;
	    }
	  
};

//CLASE DETALLE

class DetalleVenta:public Venta1, public Producto, public Cliente{
	private:
		int numComprobante;
	public:
		
		DetalleVenta( int codigo, string nombreP, string marca, string descripcion, float precio, int stock, //padre product
		 
		int codVenta, int codCliente, string fecha, int estado, double total, //segundo padre venta
		
		int DNI, int telefono, string nombreC, //tercer padre cliente
		
		int numComprobante /* hijo*/):Producto(codigo, nombreP, marca, descripcion, precio, stock), 
		Venta1(codVenta, codCliente, fecha, estado, total), Cliente(DNI, telefono, nombreC){ //se llama a los padres con sus variables
			
		this->numComprobante=numComprobante;
		}
		DetalleVenta(){
			
		}
		~DetalleVenta(){
		}
		//SET Y GET de padres en cada archivo -> venta1, client.h y producto.h
		
		void setNumComprobante(int nCompr)
		{
			numComprobante = nCompr;
		}
		
		int getNumComprobante()
		{
			return this -> numComprobante;
		
		}
};




////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//INICIO DE VECTORES
///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////



//VECTOR VENDEDOR 


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



//VECTOR CLIENTE 

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
				objError.setNombreC("Error");
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
											cliente.getNombreC()  << ";" << endl;
						archivoCliente.close();			
					}
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro :/";
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
								cliente.setNombreC(temporal[2]);
								add(cliente);
							}
						}
					} 
					archivoCliente.close();	
				}
				catch(exception e)
				{
					cout<< "Ocurrio un error al grabar el registro :/";
				}
			}

	};
	
	//VECTOR PRODUCTO 
	
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
			objError.setNombreP("Error");
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
					vectorProducto[i].setNombreP(nom);
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
					archivoProducto<<producto.getCodigo()<<";"<<producto.getNombreP()<<";"<<producto.getMarca()<<";"<<producto.getDescripcion()<<";"<<producto.getPrecio()<<";"<<producto.getStock()<<";"<<endl;
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
						archivoProductos<<x.getCodigo()<<";"<<x.getNombreP()<<";"<<x.getMarca()<<";"<<x.getDescripcion()<<";"<<x.getPrecio()<<";"<<x.getStock()<<";"<<"\n";	
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
							producto.setNombreP(temporal[1]);
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

// VENTAVECTOR

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
					cout<< "Ocurrio un error al grabar el registro :/";
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
					cout<< "Ocurrio un error al grabar el registro :/";
				}
			}
	};
			
//VECTOR DETALLE

class DetalleVector{
	private:
		vector<DetalleVenta> vectorDetalle;
	public:
		DetalleVentaVector()
		{
			vector<DetalleVenta> vectorDetalle;
		}
		
		void add(DetalleVenta obj)
		{
			vectorDetalle.push_back(obj);
		}
		
		DetalleVenta get(int pos) // Entregar el objeto actual, segun la posicion pasada como parámetro
		{
			return vectorDetalle[pos];
		}
		
		int rows()
		{
			return vectorDetalle.size();
		}
		
		int getPostArray(DetalleVenta obj)
			{
				for (int i = 0; i < vectorDetalle.size(); i++)
				{
					if (obj.getNumComprobante() == vectorDetalle[i].getNumComprobante()) 
					{
						return i;	/*Retorna la posicion del elemento dentro del vector*/
					}
				}
				return -1;
		}

		
		int getCorrelativo()
			{
				if(vectorDetalle.size() == 0)
				{
					return 1;
				}
				else
				{
					return vectorDetalle[0].getNumComprobante() + 1;
				}
			}
		
			
		void grabarEnArchivoDetalleC(DetalleVenta detalleC)
		{
			try 
			{		
				fstream archivoDetalleC;
				archivoDetalleC.open("detalle.csv", ios::app);
				if (archivoDetalleC.is_open())
				{
					archivoDetalleC 
										<< "Num de comprobante:" << ";" << detalleC.getNumComprobante() << "\n"
										<< "Codigo" << ";" << detalleC.getCodigo() << "\n"
										<< "Cod de Cliente:" << ";" << detalleC.getCodCli() << "\n"
										<< "Cod de Vendedor:" << ";" << detalleC.getCodVen() << "\n"
										<< "Nombre de cliente:" << ";" << detalleC.getNombreC() << "\n"
										<< "DNI" << ";" << detalleC.getDni() << "\n"
										<< "Telefono:" << ";" << detalleC.getTelefono() << "\n"
										<< "Nom del producto" << ";" << detalleC.getNombreP() << "\n"
										<< "Stock:" << ";" << detalleC.getStock() << "\n"
										<< "Precio:" << ";" << detalleC.getPrecio() << "\n"
										<< "Descripcion:" << ";" << detalleC.getDescripcion() << "\n"
										<< "Marca" << ";" << detalleC.getMarca() << "\n"
										<< "Fecha" << ";" << detalleC.getFecha() << "\n";
										
										
					archivoDetalleC.close();			
				}
			}
			catch(exception e)
			{
				cout<< "Ocurrio un error al grabar el registro :/";
			}
		}
		
		void grabarEnArchivoDetalleBoleta(DetalleVenta detalleB)
		{
			try 
			{		
				fstream archivoDetalleP;
				archivoDetalleP.open("soloboletas.csv", ios::app);
				if (archivoDetalleP.is_open())
				{
					archivoDetalleP		<< "Detalle de boletas "<<endl<<
										detalleB.getCodVen() << ";" <<
										detalleB.getCodCli() << ";" <<
										detalleB.getFecha()  << ";" <<
										detalleB.getEstado() << ";" <<
										detalleB.getTotal()  << ";" 
										<< "Num de comprobante:" << ";" << detalleB.getNumComprobante() << "\n"
										<< "Codigo" << ";" << detalleB.getCodigo() << "\n"
										<< "Cod de Cliente:" << ";" << detalleB.getCodCli() << "\n"
										<< "Cod de Vendedor:" << ";" << detalleB.getCodVen() << "\n"
										<< "Nombre:" << ";" << detalleB.getNombreC() << "\n"
										<< "DNI" << ";" << detalleB.getDni() << "\n"
										<< "Telefono:" << ";" << detalleB.getTelefono() << "\n"
										<< "Nom del producto" << ";" << detalleB.getNombreP() << "\n"
										<< "Stock:" << ";" << detalleB.getStock() << "\n"
										<< "Precio:" << ";" << detalleB.getPrecio() << "\n"
										<< "Descripcion:" << ";" << detalleB.getDescripcion() << "\n"
										<< "Marca" << ";" << detalleB.getMarca() << "\n"
										<< "Fecha" << ";" << detalleB.getFecha() << "\n";
										
					archivoDetalleP.close();			
				}
			}
			catch(exception e)
			{
				cout<< "Ocurrio un error al grabar el registro :/";
			}
		}
		
		
		void grabarEnArchivoDetalleFactura(DetalleVenta detalleF)
		{
			try 
			{		
				fstream archivoDetalleP;
				archivoDetalleP.open("solofacturas.csv", ios::app);
				if (archivoDetalleP.is_open())
				{
					archivoDetalleP		<< "Detalle de facturas "<<endl<<
										detalleF.getCodVen() << ";" <<
										detalleF.getCodCli() << ";" <<
										detalleF.getFecha()  << ";" <<
										detalleF.getEstado() << ";" <<
										detalleF.getTotal()  << ";" 
										<< "Num de comprobante:" << ";" << detalleF.getNumComprobante() << "\n"
										<< "Codigo" << ";" << detalleF.getCodigo() << "\n"
										<< "Cod de Cliente:" << ";" << detalleF.getCodCli() << "\n"
										<< "Cod de Vendedor:" << ";" << detalleF.getCodVen() << "\n"
										<< "Nombre:" << ";" << detalleF.getNombreC() << "\n"
										<< "DNI" << ";" << detalleF.getDni() << "\n"
										<< "Telefono:" << ";" << detalleF.getTelefono() << "\n"
										<< "Nom del producto" << ";" << detalleF.getNombreP() << "\n"
										<< "Stock:" << ";" << detalleF.getStock() << "\n"
										<< "Precio:" << ";" << detalleF.getPrecio() << "\n"
										<< "Descripcion:" << ";" << detalleF.getDescripcion() << "\n"
										<< "Marca" << ";" << detalleF.getMarca() << "\n"
										<< "Fecha" << ";" << detalleF.getFecha() << "\n";
										
					archivoDetalleP.close();			
				}
			}
			catch(exception e)
			{
				cout<< "Ocurrio un error al grabar el registro :/";
			}
		}
		
};






////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//INICIO DE MAIN
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

//Crear un Objeto
VendedorVector vendedorvector; /*Instancia de la clase*/

ProductoVector productovector; /*Instancia de la clase*/


ClienteVector vectorCliente;
ProductoVector vectorProducto;
DetalleVector vectorDetalle;

//PrototiposVendedor
void menuDeOpcionesM();
void adicionarVendedor();
void listarVendedores();
void modificarVendedor();
void buscarVendedor();

//Prototipos producto
void menuDeOpcionesP();
void adicionarProducto();
void listarProductos();
void eliminarProducto();
void modificarProducto();
void buscarProducto();

//Prototipos
void menuDeOpciones();
void generarVenta();
void adicionarClientes();
void buscarClientes();

void generarBoleCli();
void generarBolePro();
void generarFactuCli();
void generarFactuPro();

void elegirUsuario();
void login();
void elAdmin();
void listarClientes();


/*Titulo del programa*/
void tituloPrincipal();

/*Titulo del programa Vendedor*/
void tituloPrincipalV();




//Login
struct Persona {
char nombre[8];
char edad[8];
};


int main()
{
	
	setlocale(LC_ALL,"spanish");  /*Permite imprimir caracteres con tilde*/
	
	elegirUsuario();
	
	
}

//FINAL DE MAIN

//VOIDS PRODUCTO






//inicio de voids
void menuDeOpcionesP()
{
	//Declarar Variables
	int cho;
	do
	{
		tituloPrincipal();
		cout<<"\n"<<endl;
 		cout<<"\t\t\t\t\tREGISTRO DE PRODUCTOS\n";
 		cout<<"\t\t\t***************************************************\n";
 		cout<<endl;
		cout<<"\t\t\t- Ingresar Producto 			[1]\n ";
		cout<<"\t\t\t- Eliminar los Productos		[2]\n ";
		cout<<"\t\t\t- Modificar Producto 			[3]\n ";
		cout<<"\t\t\t- Buscar Producto 			[4]\n ";
		cout<<"\t\t\t- Listar Producto  			[5]\n ";
		cout<<"\t\t\t- Salir del Sistema			[6]\n ";
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
					
					cout<<endl;
			case 6: cout <<"\t\t\t------------Muchas Gracias Por Tu Visita------------\n";
					exit(0);
					break;
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
		tituloPrincipal();
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
		producto.setNombreP(nom);
		producto.setMarca(mar);
		producto.setDescripcion(descri);
		producto.setPrecio(pre);
		producto.setStock(sto);
	
		productovector.add(producto); //Agregar el Objeto al Vector dinamico	
		productovector.grabarEnArchivo(producto);
		
		cout<<"\t\t\t*********************************************************\n";
		cout<<"\t\t\t- Si usted desea continuar debe pulsar (YES o yes) : ";
		cin>>rpta;
		cout<<"\t\t\t*********************************************************\n";
		system("cls"); //Limpiar	
	}
	while(rpta =="YES" || rpta =="yes");
}

void listarProductos()//Listado
	{
		for(int i=0;i<productovector.rows();i++)
		{
			cout<<"\n"<<endl;
			cout<<"\t\t\t- El Código : "<<productovector.get(i).getCodigo()<<"\n";
			cout<<"\t\t\t- El Nombre : "<<productovector.get(i).getNombreP()<<"\n";
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
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t\t- Ingresar el código a eliminar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;
	Producto objAEliminar = productovector.buscarPorCodigo1(cod);
		if(objAEliminar.getNombreP() != "Error")
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
		menuDeOpcionesP();
}

void modificarProducto()
{
	int cod;
		tituloPrincipal();
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
		cout<<"\t\t\t- El Nombre : "<<objAModificar.getNombreP()<<"\n";
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
				menuDeOpcionesP();
			}
		system("pause");
		system("cls");	
}

void buscarProducto()
{
	int cod;
		tituloPrincipal();
		cout<<"\n"<<endl;
		cout<<"\t\t\t***************************************************\n";
		cout<<"\t\t\t- Ingrese el código que usted desea buscar : ";
		cin>>cod;
		cout<<"\t\t\t***************************************************\n";
		cout<<endl;

	Producto pro = productovector.buscarPorCodigo1(cod);
	if(pro.getNombreP() != "Error")
		{
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t\t\tRegistro Encontrado\n";
			cout<<"\t\t\t**************************************************\n";
			cout<<"\t\t\t- Código : "<<pro.getCodigo()<<"\n";
			cout<<"\t\t\t- Nombre : "<<pro.getNombreP()<<"\n";
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
		menuDeOpcionesP();
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









//////////////////////////////////////////////////////////////////////////////////////////////


void elegirUsuario()
{	
	int rp3;
	
		cout<<"\t\t\t	"<<endl;
		cout<<"\t----------------------------------"<<endl;
		
		cout<<"\t\t\tEMPRESA VentaMas!"<<endl;
		cout<<"Creación, eliminación, actualización, búsqueda, lista y reportes"<<endl;
		cout<<"\t\t\tCopyright 2022"<<endl;
		
		cout<<"\t\t----------------------------------"<<endl;
		cout<<"\t\t\t¡BIENVENIDOS!"<<endl;
		
		cout<<"\t\t----------------------------------"<<endl;
		cout<<"\t\t -Administrador ....[1]"<<endl;
		cout<<"\t\t -Vendedor .........[2]"<<endl;
		cout<<"\t\t----------------------------------"<<endl;
		cout<<"\t\t -Ingrese una opcion...[1-2]"<<endl;
		cout<<"\t\t----------------------------------"<<endl;
		cout << "\t	-->";
		cin>>rp3;
		
		switch(rp3)
		{
			case 1 : 	system("cls");	
					login();
				break;
			case 2 :	system("cls");
					
					menuDeOpciones();
				break;
			case 3 : 	system("cls"); 
				cout<<"	* INGRESE UN OPCION CORRECTA [1-3] *"<<endl;	
				break; 
			default : cout<<"	* INGRESE UN OPCION CORRECTA [1-3] *"<<endl;
		}
}

void login(){
	ofstream salida;
	salida.open("data.bin", ios::binary);
	Persona p = {"Daniel","7" };
	salida.write((char*)&p, sizeof(Persona));
	Persona p1 = { "Karina","43" };
	salida.write((char*)&p1, sizeof(Persona));
	salida.close();
	
	
	string usuario;
	string password;
	int contador = 0;
	bool ingresa = false;
	do{
				
		system("cls");
	
		cout<<"\t\t\tLOGIN DE USUARIO"<<endl;
		cout<<"\t\t\t----------------"<<endl;
		
		cout<<"\tUsuario: ";
		getline(cin, usuario);
		
		cout<<"\tPassword: ";
		//getline(cin,password);
		char caracter;
		caracter = getch();
		password = "";
		
		while(caracter != 13){
			
			if(caracter != 8){
				password.push_back(caracter);
				cout<<"*";	
			}
			else{
				if(password.length()>0){
					cout<<"\b \b";
					password = password.substr(0, password.length()-1);
				}	
				
			}
			
			
			caracter = getch();
		}
		
		contador++;
		
		Persona p;
		ifstream entrada;
		entrada.open("data.bin", ios::binary);
		
		
	if(entrada.read((char*)&p, sizeof(Persona))){
		
		if((usuario == p.nombre && password == p.edad)||
		(usuario == p1.nombre && password == p1.edad)){
			cout<<"\nUsuario y Contrasena CORRECTOS"<<endl;
			ingresa = true;
		}else if(contador<3){
			cout<<"\nUsuario y/o Contrasena incorrectos"<<endl;
			Sleep (1000);
			//system("pause");
		}
	}
	
	salida.close();
	}while(contador <3 && ingresa ==false);
		
	if(ingresa == false){
		cout<<"\nNumero de intentos excedido.";
	}else{
		cout<<"\nTiene permiso para ingresar";
	}
	
	
	
	elAdmin();
}


void registroVentas(){
	
	DetalleVenta detalleVentas; //Crear obj
	
	return vectorDetalle.grabarEnArchivoDetalleC(detalleVentas);
	
}


void menuDeOpciones()
{
	int rp;
	
	do
	{
		cout << endl;
		cout <<"\t\t\t\t\t-------------VENTAS-------------\n";
		cout <<"\t\t\t\t\t================================\n";
		cout << "\t\t\t\t\tREALIZAR VENTA(S)		...[1]\n";
		cout << "\t\t\t\t\tREGISTRO VENTA(S)		...[2]\n";
		cout << "\t\t\t\t\tSALIR 			...[3]\n";
		cout <<"\t\t\t\t\tIngrese una opcion 	...[1-3]:" << endl;
		cout << "\t\t\t\t\t	-->";
		cin>>rp;
		
		switch(rp)
		{
			case 1 : 	system("cls");	
						buscarClientes();
				break;
			case 2 :	system("cls");
					
					//grabarEnArchivoDetalleC();
					registroVentas();
					
				break;	
			case 3 : 	cout<< "\t\t\t\t\t%%%%%%%%%%%%%%%%% %%%%%%%%%%%%%%%%%%\n"; 
				exit(0);
				break; 
			default : cout<<"\t\t\t\t\t	* INGRESE UN OPCION CORRECTA [1-2] *"<<endl;
		}
	}
	while(rp != 2);
}

void elAdmin(){
	int rp4;
	
		cout<<"\t\t\t	"<<endl;
		cout<<"\t----------------------------------"<<endl;
		
		cout<<"\t\t\tEMPRESA VentaMas!"<<endl;
		cout<<"Creación, eliminación, actualización, búsqueda, lista y reportes"<<endl;
		cout<<"\t\t\tCopyright 2022"<<endl;
		
		cout<<"\t\t----------------------------------"<<endl;
		cout<<"\t\t -REGISTRO DE CLIENTES .........[1]"<<endl;
		cout<<"\t\t -REGISTRO DE PRODUCTOS ........[2]"<<endl;
		cout<<"\t\t -REGISTRO DE VENDEDORES .......[3]"<<endl;
		cout<<"\t\t -REGISTRO DE FACTURAS .........[4]"<<endl;
		cout<<"\t\t -SALIR .........[5]"<<endl;
		cout<<"\t\t----------------------------------"<<endl;
		cout<<"\t\t -Ingrese una opcion...[1-5]"<<endl;
		cout<<"\t\t----------------------------------"<<endl;
		cout << "\t	-->";
		cin>>rp4;
		
		switch(rp4)
		{
			case 1 : 	system("cls");	
					listarClientes();
				break;
			case 2 :	system("cls");
					menuDeOpcionesP();
				break;
			case 3 :	system("cls");
					menuDeOpcionesM();
				break;
			case 4 :	system("cls");
					menuDeOpciones();
				break;
			case 5 : 	system("cls"); 
				
				break; 
			default : cout<<"	* INGRESE UN OPCION CORRECTA [1-3] *"<<endl;
		}
}











//inicio de voids Vendedor
void menuDeOpcionesM()
{
	//Declarar Variables
	int cho;
	do
	{
		tituloPrincipalV();
		cout<<"\n"<<endl;
 		cout<<"\t\t\t\t\tREGISTRO DE VENDEDORES\n";
 		cout<<"\t\t\t***************************************************\n";
 		cout<<endl;
		cout<<"\t\t\t- Ingresar Vendedor(a) 			[1]\n ";
		cout<<"\t\t\t- Modificar Vendedor(a) 		[2]\n ";
		cout<<"\t\t\t- Buscar Vendedor(a) 			[3]\n ";
		cout<<"\t\t\t- Listar Vendedores  			[4]\n ";
		cout<<"\t\t\t- Salir 		            	[5]\n ";
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
					listarVendedores();
					break;
					
					cout<<endl;
			case 5: cout <<"\t\t\t------------Muchas Gracias Por Tu Visita------------\n";
					exit(0);
					break;
			default:cout<<"\t\t\t---------Ingresar una opción correcta [1-6]---------\n"<<endl;}
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
		tituloPrincipalV();
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

void listarVendedores()//Listado
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
		tituloPrincipalV();
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
		tituloPrincipalV();
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

void tituloPrincipalV()
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















//Fin de voids vendedor - entra clientes 

void listarClientes(){
	
	ifstream archivoCliente;
	string texto;
	
	archivoCliente.open("cliente1.csv", ios::in); //Abrimos el archivo en modo lectura
	
	if(archivoCliente.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivoCliente.eof()){ //mientras no sea el final del archivo
		
		getline(archivoCliente,texto);
		cout<<texto<<endl;
		
	}
		
		archivoCliente.close();
		
}

void adicionarClientes()
{
	int 	dni;
	int 	telf;
	string 	nom;
	string 	rpta;

		cout << "\t\t\t\t\t ---REGISTRAR NUEVO CLIENTE---" << "\n";	
		cout << "DNI: "; cin >> dni;
		cin.ignore();
		cout << "\t\t\t\t\t Ingresar nombre: "; getline(cin, nom);
		cout << "\t\t\t\t\t Ingresar telefono: "; cin >> telf;
		cout << endl;
		
		Cliente cliente;
		
		cliente.setDNI(dni);
		cliente.setTelefono(telf);
		cliente.setNombreC(nom);	
			
		vectorCliente.add(cliente);
		
		vectorCliente.grabarEnArchivo(cliente);	
}

void buscarClientes()
{
	int dni;
	cout << "\t\t\t\t\t INGRESAR DNI: "; cin >> dni;
	Cliente client = vectorCliente.buscarPorDNI(dni);
	
	if(client.getNombreC() != "Error")
	{
		cout << "\t\t\t\t\t   ¡¡¡Registro encontrado!!!" << endl;
		cout << endl;
		cout << "\t\t\t\t\t ***** BIENVENIDO/A " << client.getNombreC() <<" *****";
		cout << endl;
		cout << endl;
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

//Void de Ed


void elegirVoucher()
{	
	int rp2;
	
		cout << "	=========================" << endl;
		cout << "	BOLETA		...[1]" << endl;
		cout << "	FACTURA		...[2]" << endl;
		cout << "	Regresar 	...[3]" << endl;
		cout << "	-->";
		cin >> rp2;
		
		switch(rp2)
		{
			case 1 : 	system("cls");	
						
					//generarBoletaVentaC();
					//generarBoletaVentaP(); borrar
						
						generarBoleCli();
						generarBolePro();
				break;
			case 2 :	system("cls");
						//grabarEnArchivoDetalleFactura();
					//generarFacturaVentaC();
					//generarFacturaVentaP(); borrar
					
						generarFactuCli(); 
						generarFactuPro();
				break;
			case 3 : 	system("cls"); 
						void menuDeOpciones();
				break; 
			default : cout<<"	* INGRESE UN OPCION CORRECTA [1-3] *"<<endl;
		}
}


//No Void de Ed

void generarVenta()
{
	int i;
	string rpta;
	int codProd;
	int codVent;
	int cant;
	float subTotal;
	float IGV;
	float Total;
	
	
	do{
		cout << "\t\t\t\t\t Ingresar codigo del producto: "; cin >> codProd;
		Producto prod = vectorProducto.buscarPorCodigo1(codProd);

		if(prod.getNombreP() !="Error")
		{
			cout << "\t\t\t\t\t -------------------------" << "\n";
			cout << "\t\t\t\t\t Nombre del producto: " <<	prod.getNombreP() << "\n";
			cout << "\t\t\t\t\t Marca del producto: " <<	prod.getMarca() << "\n";
			cout << "\t\t\t\t\t Descripcion del producto: " <<	prod.getDescripcion() << "\n";
			cout << "\t\t\t\t\t Precio del producto: S/." <<	prod.getPrecio() <<".0" << "\n";
			cout << "\t\t\t\t\t -------------------------" << "\n";
			cout << "\t\t\t\t\t Cantidad: "; cin >> cant;
			subTotal = cant * prod.getPrecio();
			
			cout << "\t\t\t\t\t Subtotal: S/." << subTotal <<".0" << endl;
			
			IGV = subTotal * 0.18;
			
			cout << "\t\t\t\t\t Impuesto IGV: S/." << IGV <<".0" << endl;
			
			Total = subTotal + IGV;
			
			cout << "\t\t\t\t\t Total: S/." << Total <<".0" << endl;
			
			
			
			///////////////////////////////////////////////////////////////////////////////////////////////////agregar total IGV
			
		}
		else
		{
			cout << "\t\t\t\t\t ¡¡¡No se encontró el registro :( !!!" << endl;
		}
		cout << "\t\t\t\t\t ¿Añadir más? (Y / N): "; cin >> rpta;
		cout << endl;
	}
	while(rpta == "y" || rpta == "Y");
			
			system ("pause");
			system("cls");
			elegirVoucher();
			
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//voids de edwin osiosi 



void generarBoleCli(){
	
	int nroCompr;
	int DNI;
	int telf;
	string nombreC;
	
		cout<<"============CLIENTE==============";
		
		cout<<endl;
		
		nroCompr = vectorDetalle.getCorrelativo();
		
		cout<< "Nro Comprobante: " <<nroCompr << endl;
		
		cout << "DNI: "; cin>> DNI;
		cin.ignore();
		
		//cout<<"Ingresar nombre: "; getline(cin, client);
		
		cout<<"Ingresar telefono: "; cin>>telf;
		
		DetalleVenta detalleBoleCli; //Crear obj 
		

		detalleBoleCli.setDNI(DNI);  //poner lo de adentro del ()
		detalleBoleCli.setNombreC(nombreC);
		detalleBoleCli.setTelefono(telf);
		
		//vectorDetalle.add(detalleBoleCLi); //agregar obj a la estruc
		vectorDetalle.grabarEnArchivoDetalleBoleta(detalleBoleCli);
		
}

void generarBolePro(){
	int cod;
	float precio;
	int stock;
	string rpta1;
	string rpta2;
	
		cout<<"============PRODUCTO==============";
		cout<<endl;
		
		do{
			cout << "Ingresar codigo: "; cin >> cod;
		
			cout << "Ingresar stock: "; cin >> stock;
				
			cout << "¿Desea añadir mas productos? (Y/N): "; cin >> rpta1;
		
			DetalleVenta detalleBolePro; //Crear obj
			
			// detalleBolePro.setNombreP(nom); //Poner()
			 detalleBolePro.setPrecio(precio);
			 detalleBolePro.setStock(stock);
			 
			 vectorDetalle.add(detalleBolePro);
			 vectorDetalle.grabarEnArchivoDetalleBoleta(detalleBolePro);
		}
		while(rpta1 == "Y" || rpta1 == "y");
		
		cout << "Compra finalizada" << endl;
		
			system("pause"); 
			system("cls");
			void menuDeOpciones();
}

void generarFactuCli(){
	int nroCompr;
	int DNI;
	int telefono;
	string nombreC;
	
		cout<<"============CLIENTE==============";
		cout<<endl;
		
		nroCompr = vectorDetalle.getCorrelativo();
		
		cout<< "Nro Comprobante: " <<nroCompr << endl;
		
		cout << "DNI: "; cin>> DNI;
		cin.ignore();
		
		//cout<<"Ingresar nombre: "; getline(cin, client);
		
		//cout<<"Ingresar telefono: "; cin>>telf;
		
		DetalleVenta detalleFactuCli; //Crear obj
		
		detalleFactuCli.getDni();
		detalleFactuCli.getNombreC();
		detalleFactuCli.getTelefono();
		
		vectorDetalle.add(detalleFactuCli);//agregar estructu
		vectorDetalle.grabarEnArchivoDetalleFactura(detalleFactuCli);
		
}

void generarFactuPro(){
	
	int cod;
	float precio;
	int stock;
	string rpta1;
	string rpta2;
	
		cout<<"============PRODUCTO==============";
		cout<<endl;
		
		do{
			cout << "Ingresar codigo: "; cin >> cod;
		
		
			cout << "Ingresar stock: "; cin >> stock;
				
			cout << "¿Desea añadir mas productos? (Y/N): "; cin >> rpta1;
		
			DetalleVenta detalleFactuPro; //Crear obj
			
			// detalleFactuPro.setNombreP(); //Poner()
			 detalleFactuPro.setPrecio(precio);
			 detalleFactuPro.setStock(stock);
			 
			 vectorDetalle.add(detalleFactuPro);
			 vectorDetalle.grabarEnArchivoDetalleBoleta(detalleFactuPro);
		}
		while(rpta1 == "Y" || rpta1 == "y");
		
		cout << "Compra finalizada" << endl;
		
			system("pause"); 
			system("cls");
			void menuDeOpciones();
	
}


