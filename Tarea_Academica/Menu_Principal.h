#pragma once

#include "Carrera.h"
#include "Caritas.h"

namespace TareaAcademica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Menu_Principal : public System::Windows::Forms::Form {

	public:

		Menu_Principal(void)
		{
			InitializeComponent();
		}

	protected:

		~Menu_Principal()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Label^ lbl_menu;
		System::Windows::Forms::Button^ btn_carrera;
		System::Windows::Forms::Button^ btn_caritas;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lbl_menu = (gcnew System::Windows::Forms::Label());
			this->btn_carrera = (gcnew System::Windows::Forms::Button());
			this->btn_caritas = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_menu
			// 
			this->lbl_menu->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_menu->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_menu->Location = System::Drawing::Point(12, 150);
			this->lbl_menu->Name = L"lbl_menu";
			this->lbl_menu->Size = System::Drawing::Size(600, 50);
			this->lbl_menu->TabIndex = 0;
			this->lbl_menu->Text = L"Menu Principal";
			this->lbl_menu->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_carrera
			// 
			this->btn_carrera->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_carrera->Location = System::Drawing::Point(175, 250);
			this->btn_carrera->Name = L"btn_carrera";
			this->btn_carrera->Size = System::Drawing::Size(100, 40);
			this->btn_carrera->TabIndex = 1;
			this->btn_carrera->Text = L"Inicio de Carrera";
			this->btn_carrera->UseVisualStyleBackColor = true;
			this->btn_carrera->Click += gcnew System::EventHandler(this, &Menu_Principal::btn_carrera_Click);
			// 
			// btn_caritas
			// 
			this->btn_caritas->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btn_caritas->Location = System::Drawing::Point(350, 250);
			this->btn_caritas->Name = L"btn_caritas";
			this->btn_caritas->Size = System::Drawing::Size(100, 40);
			this->btn_caritas->TabIndex = 2;
			this->btn_caritas->Text = L"Cambio de Caritas";
			this->btn_caritas->UseVisualStyleBackColor = true;
			this->btn_caritas->Click += gcnew System::EventHandler(this, &Menu_Principal::btn_caritas_Click);
			// 
			// Menu_Principal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->btn_caritas);
			this->Controls->Add(this->btn_carrera);
			this->Controls->Add(this->lbl_menu);
			this->Name = L"Menu_Principal";
			this->Text = L"Menu_Principal";
			this->ResumeLayout(false);

		}

#pragma endregion

	// -------------------------------------- Eventos --------------------------------------
	private: System::Void btn_carrera_Click(System::Object^ sender, System::EventArgs^ e) {
		Carrera^ carreraForm = gcnew Carrera(); carreraForm->Show();
	}
	private: System::Void btn_caritas_Click(System::Object^ sender, System::EventArgs^ e) {
		Caritas^ caritasForm = gcnew Caritas(); caritasForm->Show();
	}
	// -------------------------------------------------------------------------------------
};
}
