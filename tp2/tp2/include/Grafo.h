#ifndef GRAFO_H
#define GRAFO_H

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
    void AdicionaRotaTransposta(int origemId, int destinoId);
    void Kosaraju(vector<int> &aeroportosId);
    void DFSTempo(vector<bool> &explorados, stack<int> &pilha, int aeroportoId);
    void TransporRotas();
    void DFSComponentesConectados(vector<bool> &explorados, int aeroportoId, int count);
    bool EncontraItem(vector<int> componente, int aeroportoId);
    void VerificaGrauSaidaComponentes();
    void VerificaGrauEntradaComponentes(int destinoId);

    //Aux
    void ImprimirInfoAeroportos();
    void ImprimirRotasTranspostas();
    void ImprimirComponentes();

private:
    vector<vector<int>> ListaRotasAeroportosId, ListaRotasAeroportosIdTransposta, ComponentesConectados;

    vector<int> GrauEntradaComponentes, GrauSaidaComponentes;
    int QtdAeroportos;
};

#endif