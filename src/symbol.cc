// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia // Curso: 2o
// Practica 6: Simulador Automatas
// Autor: Javier Garcia Santana
// Correo: alu0101391663@ull.edu.es
// Fecha: 04/11/2022
//
// Archivo cya-P06-automate-simulator: programa cliente.
// Contienelafunci ́onmaindelproyectoqueusalasclases
//         X e Y para ... (indicar brevemente el objetivo)
// Descripcion otras funcionalidades //
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 04/11/2022 - Creacion (primera version) del codigo

#include "symbol.h"

std::ostream& operator<<(std::ostream& out, const Symbol& symbol) {
  out << symbol.symbol_;
  return out;
}
bool Symbol::operator==(const Symbol& other_symbol) const {
  if (symbol_ == other_symbol.symbol_) {
    return true;
  } else {
    return false;
  }
}

bool Symbol::operator<(const Symbol& other_symbol) const {
  if (symbol_ < other_symbol.symbol_) {
    return true;
  } else {
    return false;
  }
}