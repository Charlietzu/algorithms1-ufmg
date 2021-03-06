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
        VerificaNumeroDepositosTarefa1();
    }
    else if (tipoTarefa == "tarefa2")
    {
        VerificaDepositosTarefa2();
    }
}

void Grafo::AdicionaCaminho(int origemId, int destinoId)
{
    this->ListaCaminhosVilas[origemId].push_back(destinoId);
    this->ListaCaminhosVilas[destinoId].push_back(origemId);
}

void Grafo::CriaVilas(int qtdVilas)
{
    for (int i = 0; i < qtdVilas; i++)
    {
        this->ListaCaminhosVilas.push_back({});
    }
}

void Grafo::VerificaNumeroDepositosTarefa1()
{
    vector<int> depositos;
    vector<bool> explorados;

    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        explorados.push_back(false);
    }

    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        DFS(i, depositos, explorados);
    }

    cout << depositos.size() << endl;
}

void Grafo::DFS(int i, vector<int> &depositos, vector<bool> &explorados)
{
    explorados[i] = true;
    for (unsigned int j = 0; j < this->ListaCaminhosVilas[i].size(); j++)
    {
        if (!explorados[this->ListaCaminhosVilas[i][j]])
        {
            DFS(this->ListaCaminhosVilas[i][j], depositos, explorados);
            if (!VerificaExistenciaArray(depositos, this->ListaCaminhosVilas[i][j]) && !VerificaExistenciaArray(depositos, i))
            {
                depositos.push_back(i);
            }
        }
    }
}

bool Grafo::VerificaExistenciaArray(vector<int> depositos, int i)
{
    for (unsigned int j = 0; j < depositos.size(); j++)
    {
        if (depositos[j] == i)
        {
            return true;
        }
    }
    return false;
}

void Grafo::VerificaDepositosTarefa2()
{
    vector<bool> explorados;
    vector<int> depositos;

    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        explorados.push_back(false);
    }

    for (unsigned int i = 0; i < this->ListaCaminhosVilas.size(); i++)
    {
        if (!explorados[i])
        {
            explorados[i] = true;
            for (unsigned int j = 0; j < this->ListaCaminhosVilas[i].size(); j++)
            {
                if (!explorados[this->ListaCaminhosVilas[i][j]])
                {
                    explorados[this->ListaCaminhosVilas[i][j]] = true;
                    depositos.push_back(this->ListaCaminhosVilas[i][j]);
                }
            }
        }
    }

    cout << depositos.size() << endl;
    for (unsigned int i = 0; i < depositos.size(); i++)
    {
        cout << depositos[i] << endl;
    }
}

Grafo::~Grafo() {}