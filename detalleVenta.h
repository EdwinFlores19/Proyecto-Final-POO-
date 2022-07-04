#include <iostream>
using namespace std;
class DetalleVenta
{
	private:
		//prpducto 
		int codigoDV, stockDV, cantidadDV;
		string nombreDV, marcaDV, descripcionDV, tipoDV, fechaDV;
		float precioDV, subtotalDV, totalDV;
		//cliente	
		int DNIDV;
		int telefonoDV; 
		string nombreCDV;
	public:
	DetalleVenta(int cod, string nom, string mar, int cant, string descri, string tipo, string fecha, float pre, float tot, float subtot, int sto, int dni1, int telf1, string nomc)
	{
		this -> codigoDV = cod;
		this -> nombreDV = nom;
		this -> marcaDV = mar;
		this -> descripcionDV = descri;
		this -> tipoDV = tipo;
		this -> fechaDV = fecha;
		this -> cantidadDV = cant;
		this -> precioDV = pre;
		this -> totalDV = tot;
		this -> subtotalDV = subtot;
		this -> stockDV = sto;
		this -> DNIDV = dni1;
		this -> telefonoDV = telf1;
		this -> nombreCDV = nomc;
	}
	DetalleVenta()
	{
	}
	~DetalleVenta()
	{
	}
	
	//SET PRODUCTO **********************************
	void setCodigoDV(int cod)
	{
		codigoDV = cod;
	}
	void setNombreDV(string nom)
	{
		nombreDV = nom;
	}
	void setMarcaDV(string mar)
	{
		marcaDV = mar;
	}
	void setCantidadDV(int cant)
	{
		cantidadDV = cant;
	}
	void setDescripcionDV(string descri)
	{
		descripcionDV = descri;
	}
	void setTipoDV(string tipo)
	{
		tipoDV = tipo;
	}
	void setFechaDV(string fecha)
	{
		fechaDV = fecha;
	}
	void setPrecioDV(float pre)
	{
		precioDV = pre;
	}
	void setsubTotalDV(float subtot)
	{
		subtotalDV = subtot;
	}
	void setTotalDV(float tot)
	{
		totalDV = tot;
	}
	void setStockDV(int sto)
	{
		stockDV = sto;
	}
	//SET CLIENTE
	void setDNIDV(int dni1)
	{
		DNIDV = dni1;
	}
	void setTelefonoDV(int telf1)
	{
		telefonoDV = telf1;
	}
	void setNombreCDV(string nomc)
	{
		nombreCDV = nomc;
	}
	
	// GET PRODUCTO **********************************
	int getCodigoDV()
	{
		return this->codigoDV;
	}
	string getNombreDV()
	{
		return this->nombreDV;
	}
	string getMarcaDV()
	{
		return this->marcaDV;
	}
	int getCantidadDV()
	{
		return this->cantidadDV;
	}
	string getDescripcionDV()
	{
		return this->descripcionDV;
	}
	string getTipoDV()
	{
		return this->tipoDV;
	}
	string getFechaDV()
	{
		return this->fechaDV;
	}
	float getPrecioDV()
	{
		return this->precioDV;
	}
	float getSubTotalDV()
	{
		return this->subtotalDV;
	}
	float getTotalDV()
	{
		return this->totalDV;
	}
	int getStockDV()
	{
		return this->stockDV;
	}	
	
	// GET CLIENTE
	int getDniDV()
	{
		return this -> DNIDV;
	}
	int getTelefonoDV()
	{
		return this -> telefonoDV;
	}
	string getNombreCDV()
	{
		return this -> nombreCDV;
	}
	
};
