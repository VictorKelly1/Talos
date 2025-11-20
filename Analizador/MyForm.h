#pragma once
#include "Lexico.h"
#include "Sintactico.h"
#include <iostream>
#include <sstream>

namespace Analizador {

	using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		// Extraer el texto del TextBox
		

	public:
		MyForm(void)
		{
			InitializeComponent();
			System::String^ ruta = System::Environment::GetFolderPath(System::Environment::SpecialFolder::Desktop) + "\\base.tls";

			if (System::IO::File::Exists(ruta)) {
				// Leer el contenido
				System::String^ contenido = System::IO::File::ReadAllText(ruta);

				
				txtAreaCodigo->Text = contenido;
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::RichTextBox^ txtAreaCodigo;
	private: System::Windows::Forms::RichTextBox^ txtSintaxis;


	private: System::Windows::Forms::RichTextBox^ txtToken;
	private: System::Windows::Forms::RichTextBox^ txtError;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::RichTextBox^ txtSemantica;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::ComponentModel::IContainer^ components;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->txtAreaCodigo = (gcnew System::Windows::Forms::RichTextBox());
			this->txtSintaxis = (gcnew System::Windows::Forms::RichTextBox());
			this->txtToken = (gcnew System::Windows::Forms::RichTextBox());
			this->txtError = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->txtSemantica = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(10, 622);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 38);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Clean";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(122, 622);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 38);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Save";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(243, 622);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(111, 38);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Analyze";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(358, 622);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(109, 38);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Close";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// txtAreaCodigo
			// 
			this->txtAreaCodigo->Location = System::Drawing::Point(9, 19);
			this->txtAreaCodigo->Margin = System::Windows::Forms::Padding(2);
			this->txtAreaCodigo->Name = L"txtAreaCodigo";
			this->txtAreaCodigo->Size = System::Drawing::Size(458, 599);
			this->txtAreaCodigo->TabIndex = 5;
			this->txtAreaCodigo->Text = L"";
			this->txtAreaCodigo->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// txtSintaxis
			// 
			this->txtSintaxis->Location = System::Drawing::Point(481, 19);
			this->txtSintaxis->Margin = System::Windows::Forms::Padding(2);
			this->txtSintaxis->Name = L"txtSintaxis";
			this->txtSintaxis->Size = System::Drawing::Size(574, 32);
			this->txtSintaxis->TabIndex = 6;
			this->txtSintaxis->Text = L"";
			// 
			// txtToken
			// 
			this->txtToken->Location = System::Drawing::Point(481, 68);
			this->txtToken->Margin = System::Windows::Forms::Padding(2);
			this->txtToken->Name = L"txtToken";
			this->txtToken->Size = System::Drawing::Size(574, 76);
			this->txtToken->TabIndex = 7;
			this->txtToken->Text = L"";
			// 
			// txtError
			// 
			this->txtError->Location = System::Drawing::Point(481, 622);
			this->txtError->Margin = System::Windows::Forms::Padding(2);
			this->txtError->Name = L"txtError";
			this->txtError->Size = System::Drawing::Size(574, 38);
			this->txtError->TabIndex = 8;
			this->txtError->Text = L"";
			this->txtError->TextChanged += gcnew System::EventHandler(this, &MyForm::txtError_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(481, 3);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Sintax";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(481, 53);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Tokens";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(481, 605);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Errors";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(481, 146);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Semantic";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// txtSemantica
			// 
			this->txtSemantica->Location = System::Drawing::Point(481, 161);
			this->txtSemantica->Margin = System::Windows::Forms::Padding(2);
			this->txtSemantica->Name = L"txtSemantica";
			this->txtSemantica->Size = System::Drawing::Size(574, 81);
			this->txtSemantica->TabIndex = 14;
			this->txtSemantica->Text = L"";
			this->txtSemantica->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged_1);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(478, 244);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(140, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Intermediate Representation";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 4);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Source Code";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(481, 260);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(576, 342);
			this->dataGridView1->TabIndex = 17;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1069, 671);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtSemantica);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtError);
			this->Controls->Add(this->txtToken);
			this->Controls->Add(this->txtSintaxis);
			this->Controls->Add(this->txtAreaCodigo);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Obtener el contenido del TextBox
		String^ contenido = txtAreaCodigo->Text;

		// Obtener ruta al escritorio
		String^ rutaArchivo = Environment::GetFolderPath(Environment::SpecialFolder::Desktop) + "\\base.tls";

		// Guardar el archivo
		System::IO::File::WriteAllText(rutaArchivo, contenido);

		MessageBox::Show("Texto guardado exitosamente en: " + rutaArchivo);

		txtToken->Text = "";
		txtError->Text = "";
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al guardar el archivo: " + ex->Message);
	}

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	txtAreaCodigo->Text = "";
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	// Configuración para capturar la salida de analizar()
	std::ostringstream sintaxisStream;
	std::streambuf* originalCout = std::cout.rdbuf();

	// Redirigir cout
	std::cout.rdbuf(sintaxisStream.rdbuf());

	// Ejecutar análisis sintáctico
	Lexico lexico2;
	Token token2 = lexico2.siguienteToken();

	Sintactico sintactico;
	sintactico.analizar(token2.lexema, token2.gramema);

	// Restaurar cout
	std::cout.rdbuf(originalCout);

	// Mostrar resultados en la caja de texto
	txtSintaxis->Text = gcnew System::String(sintaxisStream.str().c_str());

	// El resto de tu código existente para los otros análisis
	std::ostringstream stream;        // Para salida normal (tokens, gramemas)
	std::ostringstream errorStream;   // Para errores

	std::cout.rdbuf(stream.rdbuf());
	std::cerr.rdbuf(errorStream.rdbuf());

	Lexico lexico;
	lexico.analizar();

	std::cout.rdbuf(originalCout);
	std::cerr.rdbuf(errorStream.rdbuf());

	txtToken->Text = gcnew System::String(stream.str().c_str());
	txtError->Text = gcnew System::String(errorStream.str().c_str());

	// NUEVO: Mostrar contenido semántico
	txtSemantica->Clear();
	txtSemantica->AppendText("Declaraciones:\n");

	for (const auto& d : Semantico::declaraciones)
	{
		std::string linea = "[Declaración añadida] Variable: " + d.first + " | Tipo: " + d.second;
		txtSemantica->AppendText(gcnew System::String(linea.c_str()) + "\n");
	}

	txtSemantica->AppendText("\nErrores semánticos:\n");

	for (const auto& e : Semantico::erroresSemanticos)
	{
		std::string linea = "[Error semántico] " + e;
		txtSemantica->AppendText(gcnew System::String(linea.c_str()) + "\n");
	}
}


private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtError_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void richTextBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
