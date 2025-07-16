#pragma once

#include <iostream>                  
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib> 

using namespace std;

struct Token { //para mandar un token a otra clase 
    std::string lexema;
    std::string gramema;
};

class Lexico {

public:
    const int matriz[26][31] = {
        {  1,   2,   3,   2, 500, 500,  20,  19,  14,  15,  17, 127,  13,  12,   9,  11,  10, 121, 122, 119, 120, 124, 123, 134, 128,  21,  25, 506,   0,   0,   0}, //0
        {  1,   2,   2,   2, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100}, //1
        {  2,   2,   2,   2, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101}, //2
        {102, 102,   3, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102, 102,   4, 102, 102, 102, 102, 102, 102, 102}, //3
        {500, 500,   5, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500, 500}, //4
        {103, 103,   5, 103,   6,   6, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103}, //5
        {501, 501,   8, 501, 501, 501,   7,   7, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501, 501}, //6
        {502, 502,   8, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502, 502}, //7
        {104, 104,   8, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104, 104}, //8
        {109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 110, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109}, //9
        {111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 112, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111}, //10
        {113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 114, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113, 113}, //11
        {116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 115, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116, 116}, //12
        {503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 117, 503, 113, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503, 503}, //13
        {504, 504, 504, 504, 504, 504, 504, 504, 118, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504, 504}, //14
        { 16,  16,  16,  16,  16,  16,  16,  16,  16, 505,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16}, //15
        {507, 507, 507, 507, 507, 507, 507, 507, 507, 125, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507, 507}, //16
        { 17,  17,  17,  17, 17,   17,  17,  17,  17,  17,  18,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17}, //17
        {126, 126, 126, 126, 126, 126, 126, 126, 126, 126,  17, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126}, //18
        {105, 105, 105, 105, 105, 105, 105, 129, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105, 105}, //19
        {106, 106, 106, 106, 106, 106, 130, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106, 106}, //20
        {108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108, 108,  22,  23, 108, 108, 108, 108}, //21 
        { 22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22,  22, 131,  22,  22}, //22 
        { 23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  24,  23,  23,  23,  23}, //23
        { 23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23,  23, 132,  24,  23,  23,  23,  23}, //24
        {107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 107, 133, 107, 107, 107, 107}  //25
    };

    const std::vector<std::string> palabrasReservadas = {
        "include", "library", "endlib", "class", "endclass", "int", "float", "char", "string",
        "if", "elseif", "else", "endif", "do", "enddo", "while", "endwhile",
        "read", "write", "def", "const", "of", "dowhile", "for", "endfor",
        "function", "endfunction"
    };

    //para mandar el token al an alizador sintactico 1x1///////////////////////////////////////////////////////////////

    char* entrada;
    char* actual;
    char* inicio;
    int estado;

    Lexico() {
        entrada = strdup(Contenido());
        actual = entrada;
        inicio = entrada;
        estado = 0;
    }

    Token siguienteToken() {
        while (*inicio == ' ' || *inicio == '\n') {
            inicio++;
            actual++;
        }

        while (*actual != '\0') {
            int fila = determinar(estado);
            int columna = relacionar(*actual, estado);
            estado = nuevoEstado(fila, columna);
            actual++;

            if (estado >= 100 && estado <= 199) {
                if (estado <= 109 || estado > 134) {
                    actual--;
                }

                int idxInicio = inicio - entrada;
                int idxActual = actual - entrada;
                std::string lexema = token(entrada, idxInicio, idxActual);
                std::string gramema;

                if (std::find(palabrasReservadas.begin(), palabrasReservadas.end(), lexema) != palabrasReservadas.end()) {
                    gramema = token(100);
                }
                else {
                    if (estado == 100) gramema = token(101);
                    else gramema = token(estado);
                }

                estado = 0;
                inicio = actual;

                return { lexema, gramema };
            }
            else if (estado >= 500) {
                std::cerr << "Error: " << error(estado) << std::endl;
                estado = 0;
                inicio = actual;
            }
        }

        // Si ya no hay mas caracteres
        return { "", "" };  // Token vacio indica fin
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void analizar() { //Funcion de complejidad lineal: O(n)?
        //Inicializo 
        int caracter = 0;
        int estado = 0;
        int fila = 0;
        int columna = 0;

        char* entrada = Contenido();
        char* inicio = entrada;
        char* actual = entrada;
        
        //do while, recorro cadena 1x1
        do {
            //si apuntador de inicio es espacio o salto de linea se lo salta(si los analiza como token)
            while (*inicio == ' ' || *inicio == '\n') {
                inicio++;
            }

            //relaciono el caracter con la columna y determino el estado con la fila( 0 inicialmente) y la columna
            columna = relacionar(*actual, estado);
            fila = determinar(estado);
            estado = nuevoEstado(fila, columna);

            //avanza al siguiente caracter
            actual++;

            //analiza si el estado es deterministico sino retgresa el error, en caso de ser estado no deteministico salta
            if (estado >= 100 && estado <=199) {
                /*
                si el estado esta entre este rango quiere decir que el caracter anterior no es deterministico, porque 
                la unica via a estos estados es pasar por la fila 0 y no salta una pocision atras ya que la manera en determino 
                un lexema es el conjunto de caracteres - 1 ya que para determinar un lexema es a partrir del caracter que 
                sigue de el.
                */
                if (estado <= 109 || estado > 134 ) {
                    actual--;
                }
                
                int idxInicio = inicio - entrada;
                int idxActual = actual - entrada;
                //Lexema
                std::cout << "Lexema:  " << token(entrada, idxInicio, idxActual) << std::endl;
                //Gramema (con validacion de si es palabra reservada)
                std::string gramema = token(estado);
                
                if (std::find(palabrasReservadas.begin(), palabrasReservadas.end(), token(entrada, idxInicio, idxActual)) != palabrasReservadas.end()) {
                    std::cout << "Gramema: " << token(100) << std::endl;
                }
                else {
                    if (estado == 100) {
                        gramema = token(101); //validacion si la palabra no esta en mi lista de reservadas cambia a identificador
                    }
                    std::cout << "Gramema: " << gramema << std::endl;
                }
                std::cout << "" << std::endl;
                
                //Muevo los punteros y regreso al estado inicial
                estado = 0;
                inicio = actual;

            }
            else {
       
                //en caso de que el estado actual sea de error lo retorna y sale(retornando el primero error encontrado)
                if (estado >= 500) {
                    std::cerr << "Error: " << error(estado) << std::endl;
                    //break;
                }   
            }   
        } while (*actual != '\0');
        std::cout << "--------------------------------------------FIN------------------------------------------------";
    }

    int relacionar(char c, int estado) {
        //
        if (c >= 'a' && c <= 'z' && estado != 5) {  //minusculas
            return 0;
        }else if (c >= 'A' && c <= 'Z' && estado != 5) {  // mayusculas
            return 1;
        }else if (c >= '0' && c <= '9') { //digitos
            return 2;
        }

        switch (c) { //otros
        case '_':
            return 3;
           
        case 'E':
            return 4;

        case 'e':
            return 5;

        case '-':
            return 6;

        case '+':
            return 7;

        case '|':
            return 8;

        case '\'':
            return 9;

        case '\"':
            return 10;

        case '#':
            return 11;
            
        case '&':
            return 12;

        case '!':
            return 13;

        case '=':
            return 14;

        case '>':
            return 15;

        case '<':
            return 16;

        case '[':
            return 17;

        case ']':
            return 18;

        case '(':
            return 19;

        case ')':
            return 20;

        case ',':
            return 21;

        case ';':
            return 22;

        case '.':
            return 23;

        case '%':
            return 24;

        case '/':
            return 25;

        case '*':
            return 26;

        case '\n':
            return 28;

        case '\t':
            return 29;

        case ' ':
            return 30;

        default:
            return 27;
        }
       
    }

    int nuevoEstado(int fila, int columna) {
        if(fila >= 26){
            return fila;  
        }
        if (fila < 0 || fila >= 26 || columna < 0 || columna >= 32) {
            return -1; 
        }
        return matriz[fila][columna];
    }

    int determinar(int estado) {
        return estado;
    }

    string token(int c) {

        switch (c) {
        case 100:
            return "Palabra reservada";

        case 101:
            return "Identificador";

        case 102:
            return "Cteentera";

        case 103:
            return "Ctereal";

        case 104:
            return "Ctenotacion";

        case 105:
            return "Suma";

        case 106:
            return "Resta";

        case 107:
            return "Multiplicacion";

        case 108:
            return "Divicion";

        case 109:
            return "Asigna";

        case 110:
            return "Igual";

        case 111:
            return "Menor";

        case 112:
            return "Menor igual";

        case 113:
            return "Mayor";

        case 114:
            return "Mayor igual";

        case 115:
            return "Diferente";

        case 116:
            return "Not";

        case 117:
            return "And";

        case 118:
            return "Or";

        case 119:
            return "Parentesis apertura";

        case 120:
            return "Parentesis cierre";

        case 121:
            return "Corchete apertura";

        case 122:
            return "Corchete cierre";

        case 123:
            return "Punto y coma";

        case 124:
            return "Coma";

        case 125:
            return "Ctecaracter";

        case 126:
            return "Ctestring";

        case 127:
            return "Hashtag";

        case 128:
            return "Modulus";

        case 129:
            return "Incremento unitario";

        case 130:
            return "Decremento unitario";

        case 131:
            return "Cometario de linea";

        case 132:
            return "Comentario de bloque";

        case 133:
            return "Potencia";

        case 134:
            return "Punto";

        default:
            return "error en funcion token";
        }
        
    }

    string token(string entrada, int inicio, int final) {
        
        std::string nueva = "";
        
        for (int i = inicio; i < final; ++i) {
            nueva += entrada[i];
        }

        return nueva;

    }

    string error(int c) {
        // 
        switch (c) {
        case 500:
            return "Caracter desconocido";

        case 501:
            return "Esperaba un digito o +/-";

        case 502:
            return "Esperaba un digito";

        case 503:
            return "Eperaba &";

        case 504:
            return "esperaba |";

        case 505:
            return "No esperaba comilla";

        case 506:
            return "Caracter desconocido";

        case 507:
            return "Esperaba comilla";

        default:
            return "estado";
        }
    }

    //funcion para obtener el contenido del archivo 
    char* Contenido()
    {
        using namespace System;
        using namespace System::Runtime::InteropServices;

        // Obtener la ruta del archivo
        String^ ruta = Environment::GetFolderPath(Environment::SpecialFolder::Desktop) + "\\base.tls";

        // Leer todo el contenido 
        String^ contenido = IO::File::ReadAllText(ruta);
        contenido = contenido->Replace("\r\n", "\n");

        // Convertir a char
        const char* temp = (const char*)(Marshal::StringToHGlobalAnsi(contenido)).ToPointer();
        char* entrada = _strdup(temp);
        Marshal::FreeHGlobal(IntPtr((void*)temp));

        return entrada;
    }
    
};














