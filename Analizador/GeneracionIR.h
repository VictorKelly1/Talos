#pragma once

#include <stack>
#include <string>
#include <vector>
#include <array>


using namespace std;

class GeneracionIR
{
	public:

	~GeneracionIR() {}

    //Variables
	//Tabla de cuadruplos 
	static std::vector<std::array<std::string, 4>> tablaCuadruplosIR;
	static int Rn, indiceCuadruplo;  

	//Acciones Comunes---------------------------------------------------------------------------
	//1------------------------------------------------------------------------------------------
	static void insertarOperando(string Lexema, string Gramema, stack<string>& pilaOperandos) {
		pilaOperandos.push(Lexema);
	}
	//2------------------------------------------------------------------------------------------
	static void insertarOperador(string Lexema, string Gramema, stack<string>& pilaOperadores) {
		pilaOperadores.push(Lexema);  
	}
	//3------------------------------------------------------------------------------------------
	static void generarCuadruploExpresion(string Lexema, string Gramema, stack<string>& pilaOperandos, stack<string>& pilaOperadores) {
		if (!pilaOperadores.empty() && pilaOperandos.size() >= 2)
		{
			string op = pilaOperadores.top();

			if (op == "*" || op == "/" || op == "%" || op == "**" || op == "&&")
			{
				string Op2 = pilaOperandos.top(); pilaOperandos.pop();
				string Op1 = pilaOperandos.top(); pilaOperandos.pop();
				string Oper = pilaOperadores.top(); pilaOperadores.pop();

				string Res = "R" + to_string(++Rn);

				array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };
				tablaCuadruplosIR.push_back(cuadruplo);

				pilaOperandos.push(Res);
				
			}
		}
	}
	static void accionCuadruploExpresion2(string Lexema, string Gramema, stack<string>& pilaOperandos, stack<string>& pilaOperadores) 
	{
		if (!pilaOperadores.empty() && pilaOperandos.size() >= 2) 
		{
			string op = pilaOperadores.top();

			if (op == "+" || op == "-" || op == "||")
			{
				string Op2 = pilaOperandos.top(); pilaOperandos.pop();
				string Op1 = pilaOperandos.top(); pilaOperandos.pop();
				string Oper = pilaOperadores.top(); pilaOperadores.pop();

				string Res = "R" + to_string(++Rn);

				array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };
				tablaCuadruplosIR.push_back(cuadruplo);

				pilaOperandos.push(Res);
			}
		}
	}
	//4------------------------------------------------------------------------------------------
	static void generarCuadruploAsignacion(string Lexema, string Gramema, stack<string>& pilaOperandos, stack<string>& pilaOperadores) {
		if (pilaOperandos.size() < 2 || pilaOperadores.empty())
		{
			return;
		}
		 
		string Oper = pilaOperadores.top(); pilaOperadores.pop();
		string Res = pilaOperandos.top(); pilaOperandos.pop();
		string Op1 = pilaOperandos.top(); pilaOperandos.pop(); 

		string Op2 = "NULL";

		array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };

		tablaCuadruplosIR.push_back(cuadruplo);
	}

    //Acciones if--------------------------------------------------------------------------------
	//5------------------------------------------------------------------------------------------
	static void accionIf(stack<string>& pilaOperadores) {
		pilaOperadores.push("MFF"); 
	} 

	//6------------------------------------------------------------------------------------------
	static void accionExpresionIf(stack<string>& pilaOperadores, stack<string>& pilaOperandos) {
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
	static void accionThen(stack<string>& pilaOperandos, stack<int>& pilaSaltos) {
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
	static void accionElse(stack<int>& pilaSaltos) {

		//Generar cuadruplo SI NULL NULL NULL
		array<string, 4> cuadruplo = { "SI", "NULL", "NULL", "NULL" };
		tablaCuadruplosIR.push_back(cuadruplo);

		int nuevaDireccion = tablaCuadruplosIR.size() - 1;
		pilaSaltos.push(nuevaDireccion);

		if (pilaSaltos.size() >= 2){                //Obtenemos Tope pila saltos - 1
			int top = pilaSaltos.top();				//guardamos top 
			pilaSaltos.pop();						//lo sacamos 
			int topMenosUno = pilaSaltos.top();		//guardamos top - 1
			pilaSaltos.pop();						//lo sacamos    
			pilaSaltos.push(top);					//restauramos    

			rellenar(topMenosUno, nuevaDireccion + 1);
		}
	}

	//9------------------------------------------------------------------------------------------
	static void accionEstatutosIf(stack<int>& pilaSaltos) {

		int indice = pilaSaltos.top();   

		int valor = tablaCuadruplosIR.size();  // cont + 1

		rellenar(indice, valor);
		pilaSaltos.pop(); // Se libera el salto ya rellenado
	}

	//10-----------------------------------------------------------------------------------------
	static void accionEndif(stack<string>& pilaOperadores) {  
		if (pilaOperadores.empty())
			return;

		if (pilaOperadores.top() == "MFF")
		{
			pilaOperadores.pop();
		}
	}

	//Acciones do while--------------------------------------------------------------------------
	//11-----------------------------------------------------------------------------------------
	static void insertarSaltoDo(stack<int>& pilaSaltos) {
		//contador actual
		int cont = GeneracionIR::tablaCuadruplosIR.size();
		pilaSaltos.push(cont);
	}
	//12-----------------------------------------------------------------------------------------
	static void generarCuadruploDoWhile(string Lexema, string Gramema, stack<string>& pilaOperandos, stack<string>& pilaOperadores, stack<int>& pilaSaltos) {

		if (pilaOperadores.empty() || pilaOperandos.size() < 2)
			return;

		string Oper1 = pilaOperadores.top();
		pilaOperadores.pop();

		string Op21 = pilaOperandos.top();
		pilaOperandos.pop();

		string Op11 = pilaOperandos.top();
		pilaOperandos.pop();

		Rn++;
		string Res1 = "R" + std::to_string(Rn);

		pilaOperandos.push(Res1);
		//
		array<string, 4> cuad1 = { Oper1, Op11, Op21, Res1 };
		tablaCuadruplosIR.push_back(cuad1);

		string Oper2 = "SF";

		string Op12 = pilaOperandos.top();
		pilaOperandos.pop();

		string Op22 = "NULL";

		string Res2 = std::to_string(pilaSaltos.top());

		array<string, 4> cuad2 = { Oper2, Op12, Op22, Res2 };
		tablaCuadruplosIR.push_back(cuad2);
	}

	//Acciones while ----------------------------------------------------------------------------
	//13-----------------------------------------------------------------------------------------
	static void accionWhile(stack<int>& pilaSaltos) {
		//
		int siguiente = GeneracionIR::tablaCuadruplosIR.size();
		pilaSaltos.push(siguiente);
	} 
	//14-----------------------------------------------------------------------------------------
	static void accionExprecionWhile(string Lexema, string Gramema, stack<string>& pilaOperandos, stack<string>& pilaOperadores) { 
		if (pilaOperandos.size() < 2 || pilaOperadores.empty())
			return;

		string Op2 = pilaOperandos.top(); pilaOperandos.pop();
		string Op1 = pilaOperandos.top(); pilaOperandos.pop();
		string Oper = pilaOperadores.top(); pilaOperadores.pop();

		Rn++; 
		string Res = "R" + to_string(Rn);

		pilaOperandos.push(Res);

		array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };
		tablaCuadruplosIR.push_back(cuadruplo); 
	}
	//15-----------------------------------------------------------------------------------------
	static void accionEstatutos(stack<string>& pilaOperandos, stack<int>& pilaSaltos) { 
		// 
		string Op1 = pilaOperandos.top();
		pilaOperandos.pop();

		string Oper = "SF";
		string Op2 = "NULL";
		string Res = "NULL";

		// Crear cuadruplo
		array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };
		tablaCuadruplosIR.push_back(cuadruplo); 

		int direccion = tablaCuadruplosIR.size() - 1; 
		pilaSaltos.push(direccion);
	}
	//16-----------------------------------------------------------------------------------------
	static void accionEndDo(stack<int>& pilaSaltos) {
		//
		int direccionRetorno = pilaSaltos.top();
		pilaSaltos.pop();
		int inicio = pilaSaltos.top();

		string Oper = "SI";
		string Op1 = "NULL"; 
		string Op2 = "NULL"; 
		string Res = std::to_string(inicio);  

		array<string, 4> cuadruploSI = { Oper, Op1, Op2, Res };
		tablaCuadruplosIR.push_back(cuadruploSI);

		int nuevaDireccion = tablaCuadruplosIR.size();
		rellenar(direccionRetorno, nuevaDireccion);
	}
	//Acciones for-------------------------------------------------------------------------------
	//18-----------------------------------------------------------------------------------------
	static void accionFor(string Lexema, stack<string>& pilaOperandos, stack<string>& pilaOperadores) { 
		pilaOperandos.push(Lexema); 
		pilaOperandos.push(Lexema);  
		pilaOperadores.push("=");  
	}
	//19-----------------------------------------------------------------------------------------
	static void expresionFor1(string Lexema, stack<string>& pilaOperandos, stack<string>& pilaOperadores){ 
		string Res = pilaOperandos.top(); pilaOperandos.pop(); 
		string Op1 = pilaOperandos.top(); pilaOperandos.pop();
		string Op2 = "NULL"; 
		string Oper = pilaOperadores.top(); pilaOperadores.pop(); 

		array<string, 4> cuadruplo = { Oper, Op1, Op2, Res }; 
		tablaCuadruplosIR.push_back(cuadruplo);  
	}
	//13-----------------------------------------------------------------------------------------
	    //Reutilizo accion 13 
	//20-----------------------------------------------------------------------------------------
	static void expresionFor2(string Lexema, stack<string>& pilaOperandos, stack<string>& pilaOperadores) {

		string Oper = ">"; 
		string Op2 = pilaOperandos.top(); pilaOperandos.pop();
		string Op1 = pilaOperandos.top(); pilaOperandos.pop();

		Rn++;
		string Res = "R" + to_string(Rn); 

		array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };
		tablaCuadruplosIR.push_back(cuadruplo);  

		pilaOperandos.push(Res);
	}
	//21-----------------------------------------------------------------------------------------
	static void accionEstatutosFor(stack<string>& pilaOperandos, stack<int>& pilaSaltos) {
		string Oper = "SV";
		string Op1 = pilaOperandos.top(); pilaOperandos.pop(); 
		string Op2 = "NULL"; 
		string Res = "NULL";

		array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };
		tablaCuadruplosIR.push_back(cuadruplo); 

		int direccion = tablaCuadruplosIR.size() - 1;
		pilaSaltos.push(direccion);
	}
	//22-----------------------------------------------------------------------------------------
	static void accionEndfor(stack<int>& pilaSaltos) { 

		int top1 = pilaSaltos.top(); pilaSaltos.pop(); 

		int top2 = pilaSaltos.top(); pilaSaltos.push(top1); 

		string Oper = "SI"; 
		string Op1 = "NULL"; 
		string Op2 = "NULL"; 
		string Res = std::to_string(top2); 

		array<string, 4> cuadruplo = { Oper, Op1, Op2, Res };  
		tablaCuadruplosIR.push_back(cuadruplo); 

		int nuevaDireccion = tablaCuadruplosIR.size();  
		rellenar(top1, nuevaDireccion);  

		pilaSaltos.pop();  
	}
	//Acciones auxiliares------------------------------------------------------------------------

	static void rellenar(int salto, int valor) {
		if (salto < 0 || salto >= tablaCuadruplosIR.size())
		{
			return;
		}
		
		// Convertir el valor a string
		std::string valorStr = std::to_string(valor);
		tablaCuadruplosIR[salto][3] = valorStr; 
	}

	static void Reset()
	{
		tablaCuadruplosIR.clear(); 
		Rn = 0; 
		indiceCuadruplo = 0; 
	}

};

/*
funciones?
elseif?
*/