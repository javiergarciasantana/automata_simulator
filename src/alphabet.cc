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

#include <fstream>
#include <vector>

#include "alphabet.h"

Alphabet::Alphabet() {
  //std::cout << "Ejecutando el constructor de alfabetos por defecto..." << "\n";
  symbols_.clear();
}

Alphabet::Alphabet(const std::vector<Symbol>& input){
  //std::cout << "Ejecutando el constructor de alfabetos por parametro..." << "\n";
   std::string empty_chain_symbol = "&";
   empty_chain_symbol_ = empty_chain_symbol;
  for (int i = 0; i < input.size(); ++i) {
    if (input[i] == empty_chain_symbol_) {
      ++i;
    } else {
      symbols_.insert(input[i]);
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet) {
  for (auto i = alphabet.symbols_.begin(); i != alphabet.symbols_.end(); ++i) {
    out << *i << " ";  
  }
  return out;
}
Alphabet Alphabet::operator+(const Alphabet& alphabet) {
  Alphabet result;
  if (symbols_.empty()) {
    result.symbols_ = alphabet.symbols_;
    return result;
  } else if (alphabet.symbols_.empty()) {
    result.symbols_ = symbols_;
    return result;
  } else {
    result.symbols_ = symbols_;
    for (auto i = alphabet.symbols_.begin(); i != alphabet.symbols_.begin(); ++i) {
      result.symbols_.insert(*i);
    }
    return result;
  }
}

bool Alphabet::operator==(const Alphabet& alphabet_1) {
  for (auto i = alphabet_1.symbols_.begin(); i != alphabet_1.symbols_.begin(); ++i) {
    for (auto j = symbols_.begin(); j != symbols_.begin(); ++j) {
      if (*i == *j) {
        return true;
      }
    }
  }
  return false;
}