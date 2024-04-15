// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia // Curso: 2o
// Practica 6: Simulador Automatas
// Autor: Javier Garcia Santana
// Correo: alu0101391663@ull.edu.es
// Fecha: 04/11/2022
//
// Archivo cya-P06-automata-simulator: programa cliente.
// Contienelafunci ́onmaindelproyectoqueusalasclases
//         X e Y para ... (indicar brevemente el objetivo)
// Descripcion otras funcionalidades //
// Referencias:
// Enlaces de interes
//
// Historial de revisiones
// 04/11/2022 - Creacion (primera version) del codigo

#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>

#include "judge.h"


Judge::Judge(std::vector<std::string> input) {
  std::vector<char> comparables;
  std::string index;
  type_ = false;
  for (int i = 3; i < input.size(); ++i) {
    index = input[i];
    for (int j = 6; j < index.size(); ++j) {
      comparables.push_back(index[j]);
      j += 3;
    }
    
    for (int k = 0; k < comparables.size(); ++k) {
      for (int l = k + 1; l < comparables.size(); ++l) {
        if (comparables[k] == comparables[l]) {
          type_ = true;
        }
      }
    }
    comparables.clear();
  }
}

bool Judge::getType() {
  return type_;
}