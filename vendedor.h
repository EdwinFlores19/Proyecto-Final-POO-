#include<string>
using namespace std;

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
