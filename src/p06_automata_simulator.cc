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

#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <cstdlib>


#include "dfa.h"
#include "nfa.h"
#include "chain.h"
#include "usage.h"
#include "judge.h"


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  
  std::ifstream fa_file_1, fa_file_2, chains_file;
  fa_file_1.open(argv[1], std::ios_base::in);
  fa_file_2.open(argv[2], std::ios_base::in);
  chains_file.open(argv[3], std::ios_base::in);

  if (fa_file_1.is_open() && fa_file_2.is_open() && chains_file.is_open()) {
    std::string line;
    std::vector<std::string> every_line_1, every_line_2;

    while(getline(fa_file_1, line)) {
      every_line_1.push_back(line);
    }
    line.clear();
    while(getline(fa_file_2, line)) {
      every_line_2.push_back(line);
    }

    std::vector<Chain> cadenas;
    std::string linea_cadena;

    while (getline(chains_file, linea_cadena)) {
      Chain cadena_index(linea_cadena);
      cadenas.push_back(cadena_index);
    }
    std::vector<std::string> palabras_cadena;
    std::string result_1, result_2;

    
    Nfa nfa(every_line_1);
    for (unsigned i = 0; i < cadenas.size(); i++) {
      
      if (!nfa.comprobarCadena(cadenas.at(i))) {
        result_1 += "-- Rejected \n";
      } else {
        result_1 += "-- Accepted \n";
      }
    }

    Dfa dfa(every_line_2);
    for (unsigned i = 0; i < cadenas.size(); i++) {
      if (!dfa.comprobarCadena(cadenas.at(i))) {
        result_2 += "-- Rejected \n";
      } else {
        result_2 += "-- Accepted \n";
      }
    }
    if (result_1 == result_2) {
      std::cout << "Los automatas son equivalentes" << std::endl;
    } else {
      std::cout << "Los automatas no son equivalentes" << std::endl;
    }

    
  } else {
    std::cout << std::endl << "Error al abrir el fichero de entrada..." << std::endl << std::endl;
  }
  return 0;
}