#ifndef DADOS_H
#define DADOS_H

#include "Aeroporto.h"
#include "Rota.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Dados
{
public:
    Dados();
    ~Dados();

    void ProcessaEntrada(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas);
    void CriarAeroportos(vector<Aeroporto *> &aeroportos, int qtdAeroportos);
    void AdicionaRotaAeroportos(vector<Aeroporto *> &aeroportos, int rotaId, int origemId, int destinoId);
};

#endif