#pragma once

// Nuestrea biblioteca formlib
// Inspirada en raylib.h https://www.raylib.com/index.html

namespace formlib { // Nuesto namespace
	
	struct Vec2 { // Vector 2D
		float x; // Posición en el eje x
		float y; // Posición en el eje y
	};

	struct Vec3 { // Vector 3D
		float x; // Posición en el eje x
		float y; // Posición en el eje y
		float z; // Posición en el eje z
	};

	struct ARGB { // Vector 4D para colores
		int a; // Valor de Alfa  [0 - 255];
		int r; // Valor de Rojo  [0 - 255];
		int g; // Valor de Verde [0 - 255];
		int b; // Valor de Azul  [0 - 255];
	};

	enum class Direcciones { // Direcciones
		Izquierda,
		Derecha,
		Arriba,
		Abajo,
		Ninguno
	};

	// Colores constantes

	constexpr ARGB Rojo =     { 255, 250,   0,  24 };
	constexpr ARGB Naranja =  { 255, 250, 165,  44 };
	constexpr ARGB Amarillo = { 255, 255, 255,  65 };
	constexpr ARGB Verde =    { 255,   0, 128,  24 };
	constexpr ARGB Azul =     { 255,   0,   0, 249 };
	constexpr ARGB Violeta =  { 255, 134,   0, 125 };
	constexpr ARGB Negro =    { 255,   0,   0,   0 };
	constexpr ARGB Blanco =   { 255, 255, 255, 255 };
}