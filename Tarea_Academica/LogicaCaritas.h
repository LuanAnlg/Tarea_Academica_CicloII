#pragma once

#include "CaraBase.h"

#include <vector>

class LogicaCaritas {

private:


	// --- Cara y Milticador de Velocidad ---
	CaraBase* carita;
	std::vector<int> multiplicadorVelocidad;
	// --------------------------------------


public:


	// --------------------------------------------------------- Constructor y Descrutor ---------------------------------------------------------
	LogicaCaritas(System::Drawing::Graphics^ gr, short tipoCara) {
		// Declaramos e iniciamos nuestros punteros
		System::Random^ random = gcnew System::Random;

		// Rellenamos nuestro vector encargado de la direccion inicial de la cara
		this->multiplicadorVelocidad.push_back(-1); this->multiplicadorVelocidad.push_back(1);

		// Inicalizamos nuestra carita
		this->carita = new CaraBase({ ((float)gr->VisibleClipBounds.Width - 60) / 2, ((float)gr->VisibleClipBounds.Height - 60) / 2 },
			{ 5 * (float)this->multiplicadorVelocidad[random->Next(0,2)], 5 * (float)this->multiplicadorVelocidad[random->Next(0,2)] }, tipoCara);

		// Libreramos nuestra memoria
		delete random;
	}
	~LogicaCaritas() = default;
	// -------------------------------------------------------------------------------------------------------------------------------------------



	// ---------------------------------------------------------------- Metodos ----------------------------------------------------------------
	void dibujar(System::Drawing::Graphics^ gr) {
		this->carita->dibujar(gr);
	}

	void actualizar(System::Drawing::Graphics^ gr) {
		if (this->carita->getPosicion().x + this->carita->getVelocidad().x < 0 ||
			this->carita->getPosicion().x + this->carita->getVelocidad().x + this->carita->getCanvas().Width > gr->VisibleClipBounds.Width) {
			this->carita->setVelocidad({ this->carita->getVelocidad().x * -1, this->carita->getVelocidad().y });
		}
		if (this->carita->getPosicion().y + this->carita->getVelocidad().y < 0 ||
			this->carita->getPosicion().y + this->carita->getVelocidad().y + this->carita->getCanvas().Height > gr->VisibleClipBounds.Height) {
			this->carita->setVelocidad({ this->carita->getVelocidad().x, this->carita->getVelocidad().y * -1 });
		}
		this->carita->actualizar();
	}
	// ------------------------------------------------------------------------------------------------------------------------------------------
};