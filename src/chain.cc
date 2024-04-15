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
#include <string>
#include <vector>
#include <cassert>

#include "chain.h"

Chain::Chain() {
  //std::cout << "Ejecutando el constructor de cadenas por defecto..." << "\n";
  workload_.clear();
  chain_.clear();
  alphabet_.getSymbols().clear();
  Symbol empty_symbol{"&"};
  empty_chain_.push_back(empty_symbol);
}

Chain::Chain(std::string workload) {
  //std::cout << "Ejecutando el constructor de cadenas por parametro..." << std::endl;
  std::string aux;
  Symbol empty_symbol{"&"};
  empty_chain_.push_back(empty_symbol);

  for (int i = 0; i < workload.size(); ++i) { 
    aux = workload[i];
    workload_.push_back(aux);
    aux.clear();
  }
  chain_ = workload_;
  alphabet_ = workload_;
}

std::ostream& operator<<(std::ostream& out, const Chain& desired_chain) {
  for (int i = 0; i < desired_chain.getChain().size(); ++i) {
    out << desired_chain.getChain().at(i).getSymbol();
  }
  out << " ";
  return out;
}

Chain Chain::operator+(const Chain& chain) const {
  Chain result, aux;
  aux.chain_.push_back(empty_chain_.at(0));
  if (*this == aux) {
    return chain;
  } else if (chain == aux) {
    return *this;
  } else {
    for (int i = 0; i < chain_.size(); ++i) {
      result.chain_.push_back(chain_.at(i));
    }
    for (int i = 0; i < chain.chain_.size(); ++i) {
      result.chain_.push_back(chain.chain_.at(i));
    }
    return result;
  }
}

bool Chain::operator==(const Chain& other_chain) const{
  bool result;
  if (getChain().size() != other_chain.getChain().size()) {
    return false;
  } else {
    result = true;
    for (int i = 0; i < getChain().size(); ++i) {
      if (getChain().at(i).getSymbol() != other_chain.getChain().at(i).getSymbol()) {
        result = false;
      }
    }
  }
  return result;
}

bool Chain::operator<(const Chain& other_chain) const {
  if (chain_.size() == other_chain.chain_.size()) {
    for (int i = 0; i < chain_.size(); i++) {
      if (chain_.at(i).getSymbol() != other_chain.chain_.at(i).getSymbol()) {
        return chain_.at(i).getSymbol() < other_chain.chain_.at(i).getSymbol();
      }
    }
  } else if (chain_.size() > other_chain.chain_.size()) {
    return false;
  } else {
  return true;
  }
}

bool Chain::operator!=(const Chain& other_chain) const {
  bool result;
  if (getChain().size() != other_chain.getChain().size()) {
    return true;
  } else {
    result = false;
    for (int i = 0; i < getChain().size(); ++i) {
      if (getChain().at(i).getSymbol() != other_chain.getChain().at(i).getSymbol()) {
        result = true;
      }
    }
  }
  return result;
}