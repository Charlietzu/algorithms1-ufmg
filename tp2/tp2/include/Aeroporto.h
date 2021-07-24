#ifndef AEROPORTO_H
#define AEROPORTO_H

#include <iostream>
#include <vector>

using namespace std;

class Aeroporto
{
public:
    Aeroporto(int id);
    ~Aeroporto();

    void AddRotaOrigemId(int id);
    void AddRotaDestinoId(int id);

    void AddAeroportoAdj(Aeroporto *aeroporto);

    int GetRotaOrigemId(int id);
    int GetRotaDestinoId(int id);
    int GetId();

    vector<int> GetRotasOrigem();
    vector<int> GetRotasDestino();
    vector<Aeroporto *> GetAeroportosAdj();

    //Auxiliares
    void ImprimeRotasAeroporto();

private:
    int Id;
    vector<int> RotasOrigemId, RotasDestinoId;
    vector<Aeroporto *> AeroportosAdj;
};

#endif