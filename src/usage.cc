
#include <iostream>
#include "usage.h"

void Usage(int argc, char* argv[]) {
    
  if (argc != 4) {  
    if (argc == 2) {
      std::string ayuda = "--help";
      if (ayuda == argv[1]) {
        std::cerr << "Modo de empleo: ./p06_automata_simulator input.fa input.txt" <<std:: endl
            << std::endl << "Reportar fallos a: alu0101391663@ull.edu.es" << std::endl;
        exit(EXIT_SUCCESS);
      } else {
        std::cerr << "No se reconoce la opción introducida" << std::endl
             << "Modo de empleo: ./p06_automata_simulator input.fa input.txt" << std::endl
             << "Pruebe ./p06_automata_simulator --help’ para más información." << std::endl;
        exit(EXIT_SUCCESS);
      }
    } else {
      std::cerr << "Número erroneo de parámetros..." << std::endl
           << "Modo de empleo: ./p06_automata_simulator input.fa input.txt" << std::endl
           << "Pruebe ‘./p06_automata_simulator --help’ para más información." << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}