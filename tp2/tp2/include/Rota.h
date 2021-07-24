#ifndef ROTA_H
#define ROTA_H

#include <vector>

using namespace std;

class Rota
{
public:
    Rota(int id, int origemId, int destinoId);
    ~Rota();

    void SetAeroportoOrigemId(int id);
    void SetAeroportoDestinoId(int id);

    int GetId();
    int GetAeroportoOrigemId();
    int GetAeroportoDestinoId();

private:
    int Id, AeroportoOrigemId, AeroportoDestinoId;
};

#endif