#include<string>
using namespace std;
class Cliente
{
	private:
		int DNI;
		int telefono;
		string nombre;
	public:
		Cliente(int dni, int telf, string nom)
		{
			this -> DNI = dni;
			this -> telefono = telf;
			this -> nombre = nom;
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
		void setNombre(string nom)
		{
			nombre = nom;
		}
		
		int getDni()
		{
			return this -> DNI;
		}
		int getTelefono()
		{
			return this -> telefono;
		}
		string getNombre()
		{
			return this -> nombre;
		}
};
