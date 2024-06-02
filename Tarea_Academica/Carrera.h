#pragma once

#include "LogicaCarrera.h"

#include <iostream>

namespace TareaAcademica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Carrera : public System::Windows::Forms::Form {

	public:

		Carrera(void)
		{
			InitializeComponent();
			gr = this->CreateGraphics();
			buffer = BufferedGraphicsManager::Current->Allocate(gr, this->ClientRectangle);
			carrera = new LogicaCarrera;
			continuar = true;
			tiempo = 0;
			tiempoDelta->Start();
		}

	protected:

		~Carrera()
		{
			if (components)
			{
				delete components;
			}
			delete carrera;
		}

	private:

		System::ComponentModel::IContainer^ components;

		// ------ Graficos ------
		Graphics^ gr;
		BufferedGraphics^ buffer;
		// ----------------------

		// ------ Logica ------
		LogicaCarrera* carrera;
		bool continuar;
		int tiempo;
		// --------------------

		// -------------- Formulario --------------
		System::Windows::Forms::Timer^ tiempoDelta;
		System::Windows::Forms::Label^ lbl_timer;
		// ----------------------------------------
		   
#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->tiempoDelta = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_timer = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tiempoDelta
			// 
			this->tiempoDelta->Tick += gcnew System::EventHandler(this, &Carrera::tiempoDelta_Tick);
			// 
			// lbl_timer
			// 
			this->lbl_timer->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_timer->AutoSize = true;
			this->lbl_timer->BackColor = System::Drawing::Color::White;
			this->lbl_timer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_timer->Location = System::Drawing::Point(12, 9);
			this->lbl_timer->Name = L"lbl_timer";
			this->lbl_timer->Size = System::Drawing::Size(65, 20);
			this->lbl_timer->TabIndex = 0;
			this->lbl_timer->Text = L"Timer: 0";
			// 
			// Carrera
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->lbl_timer);
			this->Name = L"Carrera";
			this->Text = L"Carrera";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void tiempoDelta_Tick(System::Object^ sender, System::EventArgs^ e) {

		
		// -------------- UPDATE --------------
		if (continuar) {
			continuar = !carrera->actualizar();
			tiempo++;
		}
		// ------------------------------------

		// ------------------------------------------------------ DRAW ------------------------------------------------------
		buffer->Graphics->Clear(Color::FromArgb(formlib::Blanco.a, formlib::Blanco.r, formlib::Blanco.g, formlib::Blanco.b));
		lbl_timer->Text = "Timer: " + tiempo / 10; 
		carrera->dibujar(buffer->Graphics);
		buffer->Render();
		// ------------------------------------------------------------------------------------------------------------------
	}
	};
}
