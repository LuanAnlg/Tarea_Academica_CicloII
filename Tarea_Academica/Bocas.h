#pragma once

#include "Forma.h"

class BocaA : public Forma { //-> Clase polimorfa de Forma

public:


	// ------------------------------- Constructor y Desctructor -------------------------------

	BocaA(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 30, 3 }, nuevoColor) {};
	~BocaA() = default;

	// -----------------------------------------------------------------------------------------


	// ----------------------------------------------------------------------------------- Metodo sobrescrito -----------------------------------------------------------------------------------

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(this->color.a, this->color.r, this->color.g, this->color.b), 3), this->canvas);
	}

	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};

class BocaB : public Forma { //-> Clase polimorfa de Forma

public:


	// ------------------------------- Constructor y Desctructor -------------------------------

	BocaB(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 30, 15 }, nuevoColor) {};
	~BocaB() = default;

	// -----------------------------------------------------------------------------------------


	// ----------------------------------------------------------------------------------- Metodo sobrescrito -----------------------------------------------------------------------------------

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawEllipse(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(this->color.a, this->color.r, this->color.g, this->color.b), 3), this->canvas);
	}

	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};

class BocaC : public Forma { //-> Clase polimorfa de Forma

public:


	// ------------------------------- Constructor y Desctructor -------------------------------

	BocaC(formlib::Vec2 nuevaPosicion, formlib::Vec2 nuevaVelocidad, formlib::ARGB nuevoColor) :
		Forma(nuevaPosicion, nuevaVelocidad, { 30, 15 }, nuevoColor) {};
	~BocaC() = default;

	// -----------------------------------------------------------------------------------------


	// ----------------------------------------------------------------------------------- Metodo sobrescrito -----------------------------------------------------------------------------------

	void dibujar(System::Drawing::Graphics^ gr) override {
		gr->System::Drawing::Graphics::DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(this->color.a, this->color.r, this->color.g, this->color.b), 3), this->canvas);
	}

	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};