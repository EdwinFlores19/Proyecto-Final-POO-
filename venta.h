#include <iostream>
using namespace std;
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
