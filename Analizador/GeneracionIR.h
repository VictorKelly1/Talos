#pragma once

#include <stack>
#include <string>
#include <vector>
#include <array>


using namespace std;

class GeneracionIR
{
	public:
    //Variables
	//Tabla de cuadruplos 
	static std::vector<std::array<std::string, 4>> tablaCuadruplosIR;
	static int Rn;

	//Acciones Comunes--------------------------------------------------------------------------
	void insertarPilaOperando(string Lexema, string Gramema) {

	}
	void insertarPilaOperador(string Lexema, string Gramema) {

	}
	void generarCuadruploExpresion(string Lexema, string Gramema) {

	}
	void generarCuadruploAsignacion(string Lexema, string Gramema) {

	}

    //Acciones if--------------------------------------------------------------------------------
	//5------------------------------------------------------------------------------------------
	void accionIf(stack<string>& pilaOperadores) {  
		pilaOperadores.push("MFF"); 
	} 

	//6------------------------------------------------------------------------------------------
	void accionExpresionIf(stack<string>& pilaOperadores, stack<string>& pilaOperandos) { 
		//Asegurar que hay suficientes elementos
		if (pilaOperadores.empty() || pilaOperandos.size() < 2)
			return;

		//Extraer operandos y operador (en orden correcto)
		string Op2 = pilaOperandos.top();
		pilaOperandos.pop();
		string Op1 = pilaOperandos.top();
		pilaOperandos.pop();
		string Oper = pilaOperadores.top();
		pilaOperadores.pop();

		//Generar nuevo temporal Rn += 1
		Rn++;
		string Res = "R" + to_string(Rn);

		//Insertar el cuadruplo en la tabla
		std::array<std::string, 4> fila = { Oper, Op1, Op2, Res }; 
		tablaCuadruplosIR.push_back(fila);

		//Insertar el resultado en la pila de operandos
		pilaOperandos.push(Res);
	}

	//7------------------------------------------------------------------------------------------
	void accionThen(stack<string>& pilaOperandos, stack<int>& pilaSaltos) { 
		if (pilaOperandos.empty())
			return; 

		// Obtener Rn
		string Rn = pilaOperandos.top();
		pilaOperandos.pop();  

		// Crear cuadruplo -----------> SFF   Rn   NULL    NULL
		array<string, 4> cuadruplo = { "SFF", Rn, "NULL", "NULL" };
		tablaCuadruplosIR.push_back(cuadruplo); 

		// Guardar la posicion donde se inserto el salto en falso
		int direccion = tablaCuadruplosIR.size() - 1; 

		pilaSaltos.push(direccion);
	}

	//8------------------------------------------------------------------------------------------
	void accionElse(stack<int>& pilaSaltos) {
		if (pilaSaltos.empty())
			return;

		//Generar cuadruplo SI NULL NULL NULL
		array<string, 4> cuadruplo = { "SI", "NULL", "NULL", "NULL" };

		//Insertar en la tabla
		tablaCuadruplosIR.push_back(cuadruplo);

		int nuevaDireccion = tablaCuadruplosIR.size() - 1;
		pilaSaltos.push(nuevaDireccion);

		if (pilaSaltos.size() >= 2)
		{   //Obtenemos Tope pila saltos - 1
			int top = pilaSaltos.top();				//guardamos top 
			pilaSaltos.pop();						//lo sacamos 
			int topMenosUno = pilaSaltos.top();		//guardamos top - 1
			pilaSaltos.pop();						//lo sacamos   
			pilaSaltos.push(top);					//restauramos    

			rellenar(topMenosUno, nuevaDireccion + 1);
		}
	}

	//9------------------------------------------------------------------------------------------
	void accionEstatutosIf(stack<int>& pilaSaltos) {
		if (pilaSaltos.empty())
			return;

		int indice = pilaSaltos.top();   

		int valor = tablaCuadruplosIR.size();  // cont + 1

		rellenar(indice, valor);
		pilaSaltos.pop(); // Se libera el salto ya rellenado
	}

	//10-----------------------------------------------------------------------------------------
	void accionEndif(stack<string>& pilaOperadores) {
		if (pilaOperadores.empty())
			return;

		if (pilaOperadores.top() == "MFF")
		{
			pilaOperadores.pop();
		}
	}

	//Acciones do while--------------------------------------------------------------------------
	
	//Acciones for-------------------------------------------------------------------------------
	
	//Acciones while ----------------------------------------------------------------------------

	//Acciones auxiliares------------------------------------------------------------------------
	void rellenar(int salto, int valor) {
		//
	}
};

