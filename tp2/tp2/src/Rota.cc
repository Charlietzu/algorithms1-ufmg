#include "Rota.h"

Rota::Rota(int id, int origemId, int destinoId)
{
    this->Id = id;
    this->SetAeroportoOrigemId(origemId);
    this->SetAeroportoDestinoId(destinoId);

}

void Rota::SetAeroportoOrigemId(int id)
{
    this->AeroportoOrigemId = id;
}

void Rota::SetAeroportoDestinoId(int id)
{
    this->AeroportoDestinoId = id;
}

int Rota::GetId()
{
    return this->Id;
}

int Rota::GetAeroportoOrigemId()
{
    return this->AeroportoOrigemId;
}

int Rota::GetAeroportoDestinoId()
{
    return this->AeroportoDestinoId;
}

Rota::~Rota(){}