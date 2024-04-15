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

#include <sstream>
#include <string>

#include "dfa.h"

Dfa::Dfa(std::vector<std::string>& input) {
  std::vector<Symbol> symbols;
  for (unsigned i = 0; i < input.size(); i++) {
    std::vector<std::string> palabras_dfa;
    std::stringstream ss_linea_dfa(input.at(i));
    std::string palabra;
    while (getline(ss_linea_dfa, palabra, ' ')) {
      palabras_dfa.push_back(palabra);
    }
  
    switch (i) {

      case 0:
        for (int i = 0; i < input.at(0).size(); ++i) {
          Symbol aux;(input.at(0).at(i));
          symbols.push_back(aux);
        }
        alfabeto_ = symbols;
        break;
      case 1:
        if (input.at(1).size() < 1) {
          std::cout << std::endl << "ERROR: Faltan estados por definir en el fichero de entrada" << std::endl;
          exit(EXIT_SUCCESS);
          
        } else if (input.at(1).size() > 1) {
          std::cout << std::endl << "ERROR: Demasiados argumentos indicados" << std::endl;
          exit(EXIT_SUCCESS);
        }
        break;
          
      case 2:
        if (input.at(2).size() == 1) {
          estado_inicial_ = atoi(input.at(2).c_str());
        } else {
          std::cout << std::endl << "ERROR: Sólo puede haber un estado inicial..." << std::endl;
          exit(EXIT_SUCCESS);
        }
        break;

      default:
        if (i > 1) {
          State estado;
          int aux = 0;

          for (unsigned j = 0; j < palabras_dfa.size(); j++) {
            switch (j) {
              case 0:
                estado.setEstado(atoi(palabras_dfa[j].c_str()));
                break;

              case 1:
                estado.setEsEstadoAceptacion(atoi(palabras_dfa[j].c_str()));
                break;

              case 2:
                estado.setNumTransiciones(atoi(palabras_dfa[j].c_str()));
                break;
            
              default:
                if (aux == 0) {
                  aux++;
                  estado.setSimbolo(Symbol(palabras_dfa[j]));
                } else {
                  aux = 0;
                  estado.setTransicion(atoi(palabras_dfa[j].c_str()));
                }
                break;
            }
          } 
          if (aux) {
            std::cout << std::endl << "El formato del fichero no es correcto..." << std::endl;
            exit(EXIT_SUCCESS);
          }
          anadirEstado(estado);
          if (estado.getEsEstadoAceptacion()) {
            anadirEstadoAceptacion(estado);
          }
          if (i != input.size() - 1) {
            palabras_dfa[palabras_dfa.size() - 1].erase(palabras_dfa[palabras_dfa.size() - 1].size() - 1);
          }
        }
        break;
    }
  }
}

bool Dfa::comprobarCadena(const Chain& cadena) {
  State estado_actual;
  estado_actual = estados_.at(estado_inicial_.getEstado());
  for (unsigned i = 0; i < cadena.getChain().size(); i++) {
    Symbol entrada(cadena.getChain().at(i));
    if (estado_actual.getSiguienteEstado(entrada) == -1) {
      return false;
    }
    estado_actual = estados_.at(estado_actual.getSiguienteEstado(entrada));
  }
  if (estado_actual.getEsEstadoAceptacion()) {
    return true;
  }
  return false;
}

void Dfa::anadirEstado(const State& estado) {
  estados_.push_back(estado);
}

void Dfa::anadirEstadoAceptacion(const State& estado_aceptacion) {
  estados_aceptacion_.push_back(estado_aceptacion);
}
