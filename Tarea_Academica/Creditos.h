#pragma once

namespace TareaAcademica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Creditos : public System::Windows::Forms::Form {

	public:

		Creditos(void)
		{
			InitializeComponent();
		}

	protected:

		~Creditos()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

		System::Windows::Forms::Label^ lbl_creditos;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->lbl_creditos = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_creditos
			// 
			this->lbl_creditos->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_creditos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_creditos->Location = System::Drawing::Point(12, 9);
			this->lbl_creditos->Name = L"lbl_creditos";
			this->lbl_creditos->Size = System::Drawing::Size(600, 400);
			this->lbl_creditos->TabIndex = 0;
			this->lbl_creditos->TextAlign = System::Drawing::ContentAlignment::MiddleCenter; // Funcion para centrar el texto
			// 
			// Creditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 441);
			this->Controls->Add(this->lbl_creditos);
			this->Name = L"Creditos";
			this->Text = L"Creditos";
			this->Load += gcnew System::EventHandler(this, &Creditos::Creditos_Load);
			this->ResumeLayout(false);

		}

#pragma endregion

	private: System::Void Creditos_Load(System::Object^ sender, System::EventArgs^ e) {
		// String de los Creditos
		lbl_creditos->Text =
			" - Sean Bienvenidos a nuestra tarea academica - \n\n" +
			"Creditos:\n" +
			"Almeida Aguilar, Ivan Antonio: u20231b249\n" +
			"Montoya Torres, Alexander Gabriel: u20231b424\n" +
			"Rafael Sosa, Mariana Alexa: u202315231";
	}
	};
}