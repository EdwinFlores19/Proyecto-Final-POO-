#include<string>
using namespace std;

class Producto
{
	private:
	int codigo;
	string nombre, marca, descripcion;
	float precio;
	int stock;
	
	public:
	Producto(int cod, string nom, string mar, string descri, float pre, int sto)
	{
		this -> codigo = cod;
		this -> nombre = nom;
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
	void setNombre(string nom)
	{
		nombre = nom;
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
	string getNombre()
	{
	return this->nombre;
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
