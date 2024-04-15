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

#ifndef SYMBOL_H
#define SYMBOL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


class Symbol {
 public:
  Symbol() { //Constructor por defecto
    //std::cout << "Ejecutando el constructor de simbolos por defecto..." << "\n";
    symbol_.clear(); 
  } 
  Symbol(const std::string& symbol) : symbol_{symbol} { //Constructor por parametro
    //std::cout << "Ejecutando el constructor de simbolos por parametro..." << "\n";
  } 
  //Sobrecarga del poperador de extraccion
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  bool operator==(const Symbol& other_symbol) const;
  bool operator<(const Symbol& other_symbol) const;

  //Getter
  std::string getSymbol() const { return symbol_; }

 private:
  std::string symbol_;
};

#endif  //SYMBOL_H