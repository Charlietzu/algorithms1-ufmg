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
    void VerificaNumeroDepositos1();
    void VerificaNumeroDepositos2();

    //AUX
    void ImprimeVila();

private:
    vector<vector<int>> ListaCaminhosVilas;
    int qtdVilas, qtdRotas;
};

#endif