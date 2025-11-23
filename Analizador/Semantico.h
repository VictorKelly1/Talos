#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Semantico
{
public:

    ~Semantico() {} 

    static const char matrizCompatibilidad[21][14];


    static vector<pair<string, string>> declaraciones;
    static vector<string> erroresSemanticos;

    //accion cero
    static void declarar(string& Lexema, string& Gramema, int tipoNumero)
    {
        auto it = find_if(declaraciones.begin(), declaraciones.end(),
            [&Lexema](const pair<string, string>& p) { return p.first == Lexema; });

        if (it != declaraciones.end())
        {
            erroresSemanticos.push_back("Doble declaracion: " + Lexema);
            return;
        }

        // Mapear el número al carácter de tipo
        char tipo;
        switch (tipoNumero)
        {
        case 2035: tipo = 'E'; break;
        case 2036: tipo = 'R'; break;
        case 2037: tipo = 'C'; break;
        case 2038: tipo = 'S'; break;
        case 2039: tipo = 'B'; break;
        case 2040: tipo = 'V'; break;
        default: tipo = 'X'; break; // valor desconocido 
        }

        declaraciones.push_back({ Lexema, string(1, tipo) });
    }

    //accion uno
    static void insertarTipo(string& Lexema, string& Gramema, stack<char>& pila)   //accion uno

    {
        //cout << "entra 1: " << endl;
        auto it = find_if(declaraciones.begin(), declaraciones.end(),
            [&Lexema](const pair<string, string>& p) { return p.first == Lexema; });

        if (it != declaraciones.end())
        {
            
            char tipo = it->second[0];  // El tipo esta en el segundo campo (como string)
            //cout << "inserta: " << tipo << endl;
            pila.push(tipo);
        }
        else
        {
            erroresSemanticos.push_back("Variable no declarada: " + Lexema);
            declarar(Lexema, Gramema, 2036);
            pila.push('R');
        }
    }

    //accion dos
    static void insertarOperador(string& Lexema, string& Gramema, stack<string>& pila)
    {
        //cout << "entra en 2: " << Lexema << endl;
        if (Lexema == "=")
        {
            //cout << "INSERTA: " << Lexema << endl;
            pila.push(Lexema); 
        }
        else {
            //cout << "entra 5 pero no hace nada: " << endl;
        }
        
    }

    //accion tres
    static void accionTres(stack<char>& pilaTipos, stack<string>& pilaOperadores)
    {
        //cout << "entra 3: " << endl;
        if (!pilaOperadores.empty() && pilaTipos.size() >= 2)
        {
            
            string op = pilaOperadores.top();

            if (op == "*" || op == "/" || op == "%" || op == "**" || op == "&&") 
            {
                //cout << "entra 3: "  << endl;
                char tipo2 = pilaTipos.top(); pilaTipos.pop();
                char tipo1 = pilaTipos.top(); pilaTipos.pop();

                // Consultar la matriz de compatibilidad
                char resultado = obtenerResultado(tipo1, tipo2, op);

                if (resultado != 'X')
                { 
                    //cout << "inserta: " << resultado << endl; 
                    pilaTipos.push(resultado);
                    pilaOperadores.pop();
                }
                else
                {
                    erroresSemanticos.push_back(
                        "Error semántico: tipos incompatibles (" +
                        std::string(1, tipo1) + ", " +
                        std::string(1, tipo2) + ") con operador " +
                        op
                    );
                    //cout << "inserta: " << "R" << endl;
                    pilaTipos.push('R');
                    pilaOperadores.pop();
                }
            }
            else {
                // << "entra 3 pero no hace nada: " << endl;
            }
            // Si el operador no es *, / o %, no hace nada
        }
    }

    static void accionCuatro(stack<char>& pilaTipos, stack<string>& pilaOperadores)
    {
        if (!pilaOperadores.empty() && pilaTipos.size() >= 2)
        {
            string op = pilaOperadores.top();

            if (op == "+" || op == "-" || op == "||")
            {
                //cout << "entra 4: " << endl;
                char tipo2 = pilaTipos.top(); pilaTipos.pop();
                char tipo1 = pilaTipos.top(); pilaTipos.pop();

                char resultado = obtenerResultado(tipo1, tipo2, op);

                if (resultado != 'X')
                {
                    //cout << "inserta: " << resultado << endl; 
                    pilaTipos.push(resultado);
                    pilaOperadores.pop();
                }
                else
                {
                    erroresSemanticos.push_back(
                        "Error semántico: tipos incompatibles (" +
                        std::string(1, tipo1) + ", " +
                        std::string(1, tipo2) + ") con operador " +
                        op
                    );
                    //cout << "inserta: " << "R" << endl;
                    pilaTipos.push('R');
                    pilaOperadores.pop();
                }
            }else {
                //cout << "entra 4 pero no hace nada: " << endl;
            }
            // Si el operador no es +, - ni ||, no hace nada
        }
    }

    static void accionCinco(string& Lexema, string& Gramema, stack<string>& pilaOperadores)
    {
        //cout << "entra en 6: " << Lexema << endl;
        if (Lexema == "+" || Lexema == "-" ||
            Lexema == "*" || Lexema == "**" ||
            Lexema == "%" || Lexema == "/" ||
            Lexema == "||" || Lexema == "&&")
        {
            //cout << "INSERTA: "<< Lexema << endl; 
            pilaOperadores.push(Lexema);
        }
        else {
            //cout << "entra 5 pero no hace nada: " << endl;
        }
    }


    static void accionSiete(stack<string>& pilaOperadores)
    {
        pilaOperadores.push("MFF"); // Marca de fondo falso 
    }

    static void accionOcho(stack<string>& pilaOperadores)
    {
        if (!pilaOperadores.empty() && pilaOperadores.top() == "MFF") 
        {
            pilaOperadores.pop(); // Elimina la marca 
        }
    }

    static void accionNueve(stack<char>& pilaTipos, stack<string>& pilaOperadores)
    {
        if (!pilaOperadores.empty())
        {
           
            string op = pilaOperadores.top();
            //cout << "el tope: " << op << endl; 

            // Verificar si el operador es de asignación
            if (op == "=")
            {
                if (pilaTipos.size() >= 2)
                {
                    char tipo2 = pilaTipos.top(); pilaTipos.pop();
                    char tipo1 = pilaTipos.top(); pilaTipos.pop();

                    // Por ahora no marcamos error, solo comparamos
                    if (tipo1 == tipo2)
                    {
                        //cout << "Asignacion correcta" << endl; 
                        pilaOperadores.pop();
                    }
                    else
                    {
                        //error
                        erroresSemanticos.push_back(
                            "Error semántico: asignacion incompatible (" +
                            std::string(1, tipo1) + ", " +
                            std::string(1, tipo2) + ")"
                        );

                    }
                }
            }
        }
    }

    // Funciones auxiliares

    static char obtenerResultado(char tipo1, char tipo2, const string& operador)
    {

        vector<pair<char, char>> combinaciones =
        {
            {'E','E'},{'E','R'},{'E','N'},{'E','C'},{'E','S'},{'E','B'},
            {'R','R'},{'R','N'},{'R','C'},{'R','S'},{'R','B'},
            {'N','N'},{'N','C'},{'N','S'},{'N','B'},
            {'C','C'},{'C','S'},{'C','B'},
            {'S','S'},{'S','B'},
            {'B','B'}
        };

        int fila = -1;
        for (size_t i = 0; i < combinaciones.size(); ++i)
        {
            if ((combinaciones[i].first == tipo1 && combinaciones[i].second == tipo2) ||
                (combinaciones[i].first == tipo2 && combinaciones[i].second == tipo1)) // chequea el orden inverso
            {
                fila = static_cast<int>(i);
                break;
            }
        }

        if (fila == -1)
        {
            return 'X';
        }


        vector<string> operadores = {
            "+", "-", "*", "/", "==", "!=", "<", "<=", ">", ">=", "%", "**", "&&", "||"
        };

        int columna = -1;
        for (size_t i = 0; i < operadores.size(); ++i)
        {
            if (operador == operadores[i])
            {
                columna = static_cast<int>(i);
                break;
            }
        }

        if (columna == -1)
        {
            cout << "Error: operador no reconocido (" << operador << ")\n";
            return 'X';
        }


        return matrizCompatibilidad[fila][columna];
    }
    static void Reset()
    {
        declaraciones.clear();
        erroresSemanticos.clear();
    } 


}; 

/*
funciones
postincunarios

include math.lib;

        def E of int;
        def R of float;
        def C of char;
        def E of float;

class
    A = A + A;
    R = R + R + R / C;
    R = X + X;
    E = E * (E + C);
    C = R + C * E ;
    R = R * R;
    X = X + 1;
endclass


*/
