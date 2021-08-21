#include "Grafo.h"

Grafo::Grafo()
{
}

void Grafo::ProcessaEntrada(string tipoTarefa, string nomeEntrada)
{
    ifstream arquivo;
    arquivo.open(nomeEntrada, ios::in);

    int primeiroValor = 0, segundoValor = 0, count = 0;

    if (arquivo.is_open())
    {
        while (!arquivo.eof())
        {
            arquivo >> primeiroValor >> segundoValor;
            if (count == 0)
            {
                CriaVilas(segundoValor);
            }
            else
            {
                AdicionaCaminho(primeiroValor, segundoValor);
            }
            count++;
        }
        arquivo.close();
    }

    ImprimeVila();
}

void Grafo::AdicionaCaminho(int origemId, int destinoId)
{
    this->ListaCaminhosVilas[origemId].push_back(destinoId);
}

void Grafo::CriaVilas(int qtdVilas)
{
    for (int i = 0; i < qtdVilas; i++)
    {
        this->ListaCaminhosVilas.push_back({});
    }
}

//AUX
void Grafo::ImprimeVila()
{
    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        for (unsigned int j = 0; j < this->ListaCaminhosVilas[i].size(); j++)
        {
            cout << i << " - " << this->ListaCaminhosVilas[i][j] << endl;
        }
    }
}

Grafo::~Grafo() {}