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

#include <iostream>
#include <vector>
#include <string.h>

#include "alphabet.h"
#include "state.h"
#include "symbol.h"
#include "chain.h"

#ifndef DFA_H
#define DFA_H

class Dfa{
 public:
  Dfa(std::vector<std::string>& input);

  void setDfa();
  std::string getDfa();

  void anadirEstado(const State&);
  void anadirEstadoAceptacion(const State&);
  bool comprobarCadena(const Chain&);

 private:
  Alphabet alfabeto_;
  std::vector<State> estados_;
  State estado_inicial_;
  std::vector<State> estados_aceptacion_;
};

#endif