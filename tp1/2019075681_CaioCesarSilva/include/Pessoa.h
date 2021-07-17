#ifndef PESSOA_H
#define PESSOA_H

#include "PostoVacinacao.h"

#include <iostream>
#include <vector>

using namespace std;

class Pessoa
{
public:
    Pessoa(int id, int idade, int coordX, int coordY, bool indAlocada = false);
    ~Pessoa();

    void SetIdade(int idade);
    void SetCoordX(int x);
    void SetCoordY(int y);
    void SetId(int id);
    void SetIndAlocada(bool indicador);

    int GetIdade();
    int GetCoordX();
    int GetCoordY();
    int GetId();
    bool GetIndAlocada();

private:
    int Id, Idade, CoordX, CoordY;
    bool IndAlocada;
};

#endif