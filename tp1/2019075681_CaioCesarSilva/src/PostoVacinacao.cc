#include "PostoVacinacao.h"

PostoVacinacao::PostoVacinacao(int id, int numeroVagas, int coordX, int coordY)
{
    this->SetId(id);
    this->SetNumeroVagas(numeroVagas);
    this->SetCoordX(coordX);
    this->SetCoordY(coordY);
    this->DistanciaTemp = 0;
}

void PostoVacinacao::SetNumeroVagas(int numeroVagas)
{
    this->NumeroVagas = numeroVagas;
}

void PostoVacinacao::SetCoordX(int coordX)
{
    this->CoordX = coordX;
}

void PostoVacinacao::SetCoordY(int coordY)
{
    this->CoordY = coordY;
}

void PostoVacinacao::SetId(int id)
{
    this->Id = id;
}

int PostoVacinacao::GetCoordX()
{
    return this->CoordX;
}

int PostoVacinacao::GetCoordY()
{
    return this->CoordY;
}

int PostoVacinacao::GetId()
{
    return this->Id;
}

int PostoVacinacao::GetNumeroVagas()
{
    return this->NumeroVagas;
}

int PostoVacinacao::GetDistanciaTemp()
{
    return this->DistanciaTemp;
}

void PostoVacinacao::CalcularDistancia(int pessoaX, int pessoaY)
{
    //Nota: Por algum motivo a fórmula de distância euclidiana não está funcionando corretamente com o uso da
    //raiz quadrada, portanto, como ela para fins de comparação final ela já não faz diferença, irei usar
    //sem a função sqrt()

    //this->DistanciaTemp = sqrt(pow(this->GetCoordX() - pessoaX, 2) + pow(this->GetCoordY() - pessoaY, 2));
    this->DistanciaTemp = pow(this->GetCoordX() - pessoaX, 2) + pow(this->GetCoordY() - pessoaY, 2);
}

vector<int> PostoVacinacao::GetPessoasAlocadasId()
{
    return this->PessoasAlocadasId;
}
void PostoVacinacao::AlocaPessoa(int pessoaId)
{
    this->PessoasAlocadasId.push_back(pessoaId);
}

int PostoVacinacao::GetVagasDisponiveis()
{
    return this->GetNumeroVagas() - this->GetPessoasAlocadasId().size();
}

PostoVacinacao::~PostoVacinacao() {}