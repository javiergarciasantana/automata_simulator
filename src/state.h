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
#include <string>

#include "symbol.h"

#ifndef STATE_H
#define STATE_H

using std::vector;

class State {
  public:
    State();
    State(int);

    void setEstado(int);
    int getEstado();

    void setNumTransiciones(int);
    int getNumTransiciones();

    void setEsEstadoAceptacion(bool);
    bool getEsEstadoAceptacion();

    void setEsEstadoMuerte(bool);
    bool getEsEstadoMuerte();


    void setSimbolo(Symbol);
    vector<Symbol> getSimbolos();

    void setTransicion(int);
    vector<int> getTransiciones();

    int getSiguienteEstado(Symbol);

    vector<int> getSiguientesEstados(Symbol entrada);

  private:
    int estado_, num_transiciones_;
    bool es_estado_aceptacion_;
    bool es_estado_muerte_;
    vector<Symbol> simbolos_;
    vector<int> transiciones_;
};

#endif