#ifndef GRAFO_H
#define GRAFO_H

#include "Aeroporto.h"
#include "Rota.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

class Grafo
{
public:
    Grafo();
    ~Grafo();

    void ProcessaEntrada(vector<int> &aeroportosId);
    void CriaAeroportos(vector<int> &aeroportosId, int qtdAeroportos);
    void AdicionaRota(int origemId, int destinoId);
    void Kosaraju(vector<int> &aeroportosId);
    void DFSNormal(vector<bool> &explorados, stack<int> &pilha, int aeroportoId);

    void CriaRotasTranspostas(vector<Rota *> &rotas, vector<Rota *> &rotasT);

    //Aux
    void ImprimirInfoAeroportos();

private:
    vector<vector<int>> ListaRotasAeroportosId;
    int QtdAeroportos;
};

#endif