#pragma once

#include "MyForm.h"
#include "Lexico.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
    //Configuracion de ventana
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Analizador::MyForm^ form = gcnew Analizador::MyForm();
    //muestra la ventana
    Application::Run(form);

    return 0;
}

