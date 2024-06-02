#pragma once

#include "CaraBase.h"

#include <windows.h>

class LogicaCarrera { //-> Clase controladora para hacer una Carrera

private:


	// - Vector, velocidad y canvas de la meta -
	std::vector<CaraBase*> caras;
	std::vector<bool> velocidadesUsadas;
	System::Drawing::Rectangle meta_canvas;
	// -----------------------------------------


public:


	// ------------------------------------------------------ Constructor y Desctructor ------------------------------------------------------

	LogicaCarrera() {

		// Declaramos e iniciamos nuestros punteros
		System::Random^ random = gcnew System::Random;
		int* indiceVelocidad = new int;

		// Inicamos el canvas de la meta
		this->meta_canvas = System::Drawing::Rectangle(600, 0, 3, 480);

		// Rellenamos nuestro vector
		for (int i = 0; i < 3; i++) { this->velocidadesUsadas.push_back(false); }

		// Logica para que no se repitan las velocidades
		for (int i = 0; i < 3; i++) {
			do { *indiceVelocidad = random->Next(0, 3); } while (this->velocidadesUsadas[*indiceVelocidad]);
			this->caras.push_back(new CaraBase({ 12, ((float)i * 100) + 36 }, { ((float)*indiceVelocidad + 1) * 2, 0 }, random->Next(0, 3)));
			this->velocidadesUsadas[*indiceVelocidad] = true;
			Sleep(1);
		}

		// Liberamos nuestra memoria
		delete indiceVelocidad;
		delete random;
	}

	~LogicaCarrera() {
		for (auto cara : this->caras) { delete cara; }
		this->caras.clear();
	}

	// ---------------------------------------------------------------------------------------------------------------------------------------



	// ------------------------------------------------------------------------------------- Metodos --------------------------------------------------------------------------------------

	void dibujar(System::Drawing::Graphics^ gr) {
		for (auto cara : this->caras) { cara->dibujar(gr); }
		gr->FillRectangle(gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(formlib::Negro.a, formlib::Negro.r, formlib::Negro.g, formlib::Negro.b)), this->meta_canvas);
	}

	bool actualizar() {
		for (auto cara : this->caras) {
			cara->actualizar();
			if (cara->getCanvas().IntersectsWith(this->meta_canvas)) { return true; }
		}
		return false;
	}

	// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
};
