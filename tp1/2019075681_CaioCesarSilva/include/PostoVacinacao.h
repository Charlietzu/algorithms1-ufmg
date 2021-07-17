#ifndef POSTOVACINACAO_H
#define POSTOVACINACAO_H

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class PostoVacinacao
{
public:
    PostoVacinacao(int id, int numeroVagas, int coordX, int coordY);
    ~PostoVacinacao();

    void SetNumeroVagas(int idade);
    void SetCoordX(int x);
    void SetCoordY(int y);
    void SetId(int id);
    void CalcularDistancia(int pessoaX, int pessoaY);
    void AlocaPessoa(int pessoaId);

    int GetNumeroVagas();
    int GetCoordX();
    int GetCoordY();
    int GetId();
    int GetDistanciaTemp();
    int GetVagasDisponiveis();
    vector<int> GetPessoasAlocadasId();

private:
    int Id, NumeroVagas, CoordX, CoordY, DistanciaTemp;
    vector<int> PessoasAlocadasId;
};

#endif