#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Grafo
{
public:
    Grafo();
    ~Grafo();

    void ProcessaEntrada(string tipoTarefa, string nomeEntrada);
    void AdicionaCaminho(int origemId, int destinoId);
    void CriaVilas(int qtdVilas);
    void VerificaNumeroDepositosTarefa2();
    void VerificaNumeroDepositosTarefa1();
    bool VerificaExistenciaArray(vector<int> depositos, int i);
    void DFS(int i, vector<int> &depositos, vector<bool> &explorados);

    //AUX
    void ImprimeVila();

private:
    vector<vector<int>> ListaCaminhosVilas;
    int qtdVilas, qtdRotas;
};

#endif