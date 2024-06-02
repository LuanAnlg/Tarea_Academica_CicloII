#pragma once

#include "LogicaCaritas.h"

namespace TareaAcademica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Caritas : public System::Windows::Forms::Form
	{
	public:
		Caritas(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(gr, this->ClientRectangle);
			caritas = new LogicaCaritas(gr, 0);
			tiempoDelta->Start();
		}

	protected:
		~Caritas()
		{
			if (components)
			{
				delete components;
			}
			delete caritas;
		}
	private:
		System::ComponentModel::IContainer^ components;

		// ------ Graficos ------
		Graphics^ gr;
		BufferedGraphics^ buffer;
		// ----------------------

		// ------ Logica ------
		LogicaCaritas* caritas;
		// --------------------

		// -------------- Formulario --------------
		System::Windows::Forms::Button^ btn_cara1;
		System::Windows::Forms::Button^ btn_cara2;
		System::Windows::Forms::Button^ btn_cara3;
		System::Windows::Forms::Timer^ tiempoDelta;
		// ----------------------------------------


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tiempoDelta = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_cara1 = (gcnew System::Windows::Forms::Button());
			this->btn_cara2 = (gcnew System::Windows::Forms::Button());
			this->btn_cara3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// tiempoDelta
			// 
			this->tiempoDelta->Tick += gcnew System::EventHandler(this, &Caritas::tiempoDelta_Tick);
			// 
			// btn_cara1
			// 
			this->btn_cara1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_cara1->Location = System::Drawing::Point(150, 348);
			this->btn_cara1->Name = L"btn_cara1";
			this->btn_cara1->Size = System::Drawing::Size(75, 23);
			this->btn_cara1->TabIndex = 0;
			this->btn_cara1->Text = L"Cara 1";
			this->btn_cara1->UseVisualStyleBackColor = true;
			this->btn_cara1->Click += gcnew System::EventHandler(this, &Caritas::btn_cara1_Click);
			// 
			// btn_cara2
			// 
			this->btn_cara2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_cara2->Location = System::Drawing::Point(275, 348);
			this->btn_cara2->Name = L"btn_cara2";
			this->btn_cara2->Size = System::Drawing::Size(75, 23);
			this->btn_cara2->TabIndex = 1;
			this->btn_cara2->Text = L"Cara 2";
			this->btn_cara2->UseVisualStyleBackColor = true;
			this->btn_cara2->Click += gcnew System::EventHandler(this, &Caritas::btn_cara2_Click);
			// 
			// btn_cara3
			// 
			this->btn_cara3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_cara3->Location = System::Drawing::Point(400, 348);
			this->btn_cara3->Name = L"btn_cara3";
			this->btn_cara3->Size = System::Drawing::Size(75, 23);
			this->btn_cara3->TabIndex = 2;
			this->btn_cara3->Text = L"Cara 3";
			this->btn_cara3->UseVisualStyleBackColor = true;
			this->btn_cara3->Click += gcnew System::EventHandler(this, &Caritas::btn_cara3_Click);
			// 
			// Caritas
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->btn_cara3);
			this->Controls->Add(this->btn_cara2);
			this->Controls->Add(this->btn_cara1);
			this->Name = L"Caritas";
			this->Text = L"Caritas";
			this->ResumeLayout(false);

		}

#pragma endregion

	private: System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {

		// ------- UPDATE -------
		caritas->actualizar(gr);
		// ----------------------
		 
		// ------------------------------------------------------ DRAW ------------------------------------------------------
		buffer->Graphics->Clear(Color::FromArgb(formlib::Blanco.a, formlib::Blanco.r, formlib::Blanco.g, formlib::Blanco.b));
		caritas->dibujar(buffer->Graphics);
		buffer->Render();
		// ------------------------------------------------------------------------------------------------------------------
	}

	// ------------------------------------- Eventos -------------------------------------
	private: System::Void btn_cara1_Click(System::Object^ sender, System::EventArgs^ e) {
		delete caritas; caritas = new LogicaCaritas(gr, 0);
	}
	private: System::Void btn_cara2_Click(System::Object^ sender, System::EventArgs^ e) {
		delete caritas; caritas = new LogicaCaritas(gr, 1);
	}
	private: System::Void btn_cara3_Click(System::Object^ sender, System::EventArgs^ e) {
		delete caritas; caritas = new LogicaCaritas(gr, 2);
	}
	// -----------------------------------------------------------------------------------
};
}