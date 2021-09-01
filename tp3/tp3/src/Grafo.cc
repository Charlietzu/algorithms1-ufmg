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
                CriaVilas(primeiroValor);
            }
            else
            {
                AdicionaCaminho(primeiroValor, segundoValor);
            }
            count++;
        }
        arquivo.close();
    }

    if (tipoTarefa == "tarefa1")
    {
        VerificaNumeroDepositos1();
    }
    else if (tipoTarefa == "tarefa2")
    {
        VerificaNumeroDepositos2();
    }
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

void Grafo::VerificaNumeroDepositos1()
{
    vector<bool> explorados;
    int numeroDepositos = 0;

    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        explorados.push_back(false);
    }

    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        if (!explorados[i] && this->ListaCaminhosVilas[i].size() > 0)
        {
            numeroDepositos++;
            explorados[i] = true;
            for (unsigned int j = 0; j < this->ListaCaminhosVilas[i].size(); j++)
            {
                if (!explorados[this->ListaCaminhosVilas[i][j]])
                {
                    explorados[this->ListaCaminhosVilas[i][j]] = true;
                    break;
                }
            }
        }
    }

    cout << numeroDepositos << endl;
}

void Grafo::VerificaNumeroDepositos2() {}

//AUX
void Grafo::ImprimeVila()
{
    cout << "Número de vilas: " << this->ListaCaminhosVilas.size() << endl;
    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        for (unsigned int j = 0; j < this->ListaCaminhosVilas[i].size(); j++)
        {
            cout << i << " - " << this->ListaCaminhosVilas[i][j] << endl;
        }
    }
}

Grafo::~Grafo() {}