#include "Pessoa.h"

Pessoa::Pessoa(int id, int idade, int coordX, int coordY, bool indAlocada)
{
    this->SetId(id);
    this->SetIdade(idade);
    this->SetCoordX(coordX);
    this->SetCoordY(coordY);
    this->SetIndAlocada(indAlocada);
}

void Pessoa::SetIdade(int idade)
{
    this->Idade = idade;
}

void Pessoa::SetCoordX(int coordX)
{
    this->CoordX = coordX;
}

void Pessoa::SetCoordY(int coordY)
{
    this->CoordY = coordY;
}

void Pessoa::SetId(int id)
{
    this->Id = id;
}

int Pessoa::GetCoordX()
{
    return this->CoordX;
}

int Pessoa::GetCoordY()
{
    return this->CoordY;
}
int Pessoa::GetIdade()
{
    return this->Idade;
}

int Pessoa::GetId()
{
    return this->Id;
}

bool Pessoa::GetIndAlocada()
{
    return this->IndAlocada;
}

void Pessoa::SetIndAlocada(bool indicador)
{
    this->IndAlocada = indicador;
}

Pessoa::~Pessoa() {}