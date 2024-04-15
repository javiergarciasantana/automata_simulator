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

#include "nfa.h"

Nfa::Nfa(std::vector<std::string>& input) {
  std::vector<Symbol> symbols;
  std::string aux;
  std::string alfabeto = input.at(0);
  for (unsigned i = 0; i < input.size(); i++) {
    std::vector<std::string> palabras_nfa;
    std::stringstream ss_linea_nfa(input.at(i));
    std::string palabra;
    while (getline(ss_linea_nfa, palabra, ' ')) {
      palabras_nfa.push_back(palabra);
    }
    switch (i) {
      case 0:
        for (int i = 0; i < alfabeto.size(); ++i) {
          aux += alfabeto.at(i);
          symbols.push_back(Symbol(aux));
          aux.clear();
        }
        alfabeto_ = symbols;
        break;
      case 1:
        if (input.at(1).size() == 1) {
          if (input.size() - 2 < atoi(input.at(1).c_str())) {
            std::cout << std::endl << "ERROR: Faltan estados por definir en el fichero de entrada" << std::endl;
            exit(EXIT_SUCCESS);
          }
        } else {
          std::cout << std::endl << "ERROR: Demasiados argumentos indicados" << std::endl;
          exit(EXIT_SUCCESS);
        }
        break;
      
      case 2:
        if (input.at(2).size() == 1) {
          setEstadoInicial(atoi(input.at(2).c_str()));
        } else {
          std::cout << std::endl << "ERROR: Sólo puede haber un estado inicial..." << std::endl;
          exit(EXIT_SUCCESS);
        }
        break;
      
      default:
        if (i > 1) {
          State estado;
          int aux = 0;

          for (unsigned j = 0; j < palabras_nfa.size(); j++) {
            switch (j) {
              case 0:
                estado.setEstado(atoi(palabras_nfa[j].c_str()));
                break;

              case 1:
                estado.setEsEstadoAceptacion(atoi(palabras_nfa[j].c_str()));
                break;

              case 2:
                estado.setNumTransiciones(atoi(palabras_nfa[j].c_str()));
                break;
        
              default:
                if (aux == 0) {
                  aux++;
                  estado.setSimbolo(Symbol(palabras_nfa[j]));
                } else {
                  aux = 0;
                  estado.setTransicion(atoi(palabras_nfa[j].c_str()));
                }
                break;
            }
          } 
          if (aux) {
            std::cout << std::endl << "El formato del fichero no es correcto..." << std::endl;
            exit(EXIT_SUCCESS);
          }
          if (aux == 3) {
            estado.setEsEstadoMuerte(true);
          }
          anadirEstado(estado);
          if (estado.getEsEstadoAceptacion()) {
            anadirEstadoAceptacion(estado);
          }
          if (i != input.size() - 1) {
            palabras_nfa[palabras_nfa.size() - 1].erase(palabras_nfa[palabras_nfa.size() - 1].size() - 1);
          }
        }
        break;
    }
  }
}


void Nfa::setEstadoInicial(const State& estado_inicial) {
  estado_inicial_ = estado_inicial;
}

bool Nfa::comprobarCadena(const Chain& cadena) {
  State estado_actual;
  std::string cadena_aux;
  for (int i = 0; i < cadena.getChain().size(); ++i) {
    cadena_aux += cadena.getChain().at(i).getSymbol();
  }
  
  estado_actual = estados_.at(estado_inicial_.getEstado());

  if (recorrerEstados(cadena_aux, estado_actual)) { 
    return true;
  }
  return false;

}

bool Nfa::recorrerEstados(std::string cadena, State estado_actual) {
  vector<int> estados_siguientes;
  std::string simbolo = "";
  simbolo.push_back(cadena[0]);
  //std::cout << cadena[0] << std::endl;
  Symbol entrada(simbolo);

  if (cadena.length() > 1) {
    cadena = cadena.substr(1, cadena.length() - 1);
  } else {
    cadena = "";
  }
  estados_siguientes = estado_actual.getSiguientesEstados(entrada);


  for (unsigned j = 0; j < estados_siguientes.size(); j++) {
    estado_actual = estados_.at(estados_siguientes.at(j));

    if (recorrerEstados(cadena, estado_actual)) {
      return true;
    }
  }
  if (estado_actual.getEsEstadoAceptacion()) {
    return true;
   
  } 
  return false;
}

void Nfa::anadirEstado(const State& estado) {
  estados_.push_back(estado);
}

void Nfa::anadirEstadoAceptacion(const State& estado_aceptacion) {
  estados_aceptacion_.push_back(estado_aceptacion);
}

// estados_actuales = {0}
// simbolo = 0
// estados_actuales = {0}
// simbolo = 1

// estados_actuales = {0, 1}
// simbolo = 0

// estados_actuales = {0, 2}
// simbolo = 1
// estados_actuales = {0, 1, 3}
// simbolo = 0

// estados_actuales = {0, 2}