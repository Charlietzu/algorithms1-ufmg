#include "Aeroporto.h"

Aeroporto::Aeroporto(int id)
{
    this->Id = id;
}

void Aeroporto::AddRotaOrigemId(int id)
{
    this->RotasOrigemId.push_back(id);
}

void Aeroporto::AddRotaDestinoId(int id)
{
    this->RotasDestinoId.push_back(id);
}

int Aeroporto::GetRotaOrigemId(int id)
{
    for (unsigned int i = 0; i < this->RotasOrigemId.size(); i++)
    {
        if (this->RotasOrigemId[i] == id)
        {
            return this->RotasOrigemId[i];
        }
    }

    return -1;
}

int Aeroporto::GetRotaDestinoId(int id)
{
    for (unsigned int i = 0; i < this->RotasDestinoId.size(); i++)
    {
        if (this->RotasDestinoId[i] == id)
        {
            return this->RotasDestinoId[i];
        }
    }

    return -1;
}

int Aeroporto::GetId()
{
    return this->Id;
}

void Aeroporto::ImprimeRotasAeroporto()
{
    cout << "AEROPORTO ID: " << this->GetId() << endl;
    cout << "ROTAS DE ORIGEM:" << endl;

    for (unsigned int i = 0; i < this->RotasOrigemId.size(); i++)
    {
        cout << this->RotasOrigemId[i] << endl;
    }

    cout << "ROTAS DE DESTINO:" << endl;
    for (unsigned int i = 0; i < this->RotasDestinoId.size(); i++)
    {
        cout << this->RotasDestinoId[i] << endl;
    }
}

vector<int> Aeroporto::GetRotasDestino()
{
    return this->RotasDestinoId;
}

vector<int> Aeroporto::GetRotasOrigem()
{
    return this->RotasOrigemId;
}

Aeroporto::~Aeroporto() {}