#ifndef DADOS_H
#define DADOS_H

#include "Aeroporto.h"
#include "Rota.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class Dados
{
public:
    Dados();
    ~Dados();

    void ProcessaEntrada(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas);
    void CriaAeroportos(vector<Aeroporto *> &aeroportos, int qtdAeroportos);
    void AdicionaRotaAeroportos(vector<Aeroporto *> &aeroportos, int rotaId, int origemId, int destinoId);
    void Kosaraju(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas);
    void PreencheOrdem(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas, stack<Aeroporto *> pilha, vector<bool> explorados, int i);

    //Aux
    void ImprimirInfoAeroportos(vector<Aeroporto *> &aeroportos);
};

#endif