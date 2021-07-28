#include "Grafo.h"

Grafo::Grafo() {}

void Grafo::ProcessaEntrada(vector<int> &aeroportosId)
{
    string entrada = "";
    int qtdAeroportos = 0, qtdRotas = 0, rotaId = 1;

    cin >> qtdAeroportos >> qtdRotas;

    this->QtdAeroportos = qtdAeroportos;
    aeroportosId.push_back(0);

    CriaAeroportos(aeroportosId, qtdAeroportos);

    while (getline(cin, entrada) && rotaId <= qtdRotas)
    {
        int origemId = 0, destinoId = 0;

        cin >> origemId >> destinoId;

        AdicionaRota(origemId, destinoId);
    }
}

void Grafo::CriaAeroportos(vector<int> &aeroportosId, int qtdAeroportos)
{
    for (int i = 1; i <= qtdAeroportos; i++)
    {
        aeroportosId.push_back(i);
        this->ListaRotasAeroportosId.push_back({});
    }
}

void Grafo::AdicionaRota(int origemId, int destinoId)
{
    this->ListaRotasAeroportosId[origemId].push_back(destinoId);
}

void Grafo::Kosaraju(vector<int> &aeroportosId)
{
    stack<int> pilha;
    vector<bool> explorados;
    explorados.push_back(true);

    for (int aeroportoId = 1; aeroportoId <= this->QtdAeroportos; aeroportoId++)
    {
        explorados.push_back(false);
    }

    for (int aeroportoId = 1; aeroportoId <= this->QtdAeroportos; aeroportoId++)
    {
        if (explorados[aeroportoId] == false)
        {
            this->DFSNormal(explorados, pilha, aeroportoId);
        }
    }
}

void Grafo::DFSNormal(vector<bool> &explorados, stack<int> &pilha, int aeroportoId)
{
    explorados[aeroportoId] = true;
    cout << "aeroporto id " << aeroportoId << endl;
    for (unsigned int j = 0; j < this->ListaRotasAeroportosId[aeroportoId].size(); j++)
    {
        cout << this->ListaRotasAeroportosId[aeroportoId][j] << endl;
        if (explorados[this->ListaRotasAeroportosId[aeroportoId][j]] == false)
        {
            this->DFSNormal(explorados, pilha, this->ListaRotasAeroportosId[aeroportoId][j]);
        }
    }
    cout << "push na pilha " << aeroportoId << endl;
    pilha.push(aeroportoId);
}

void Grafo::ImprimirInfoAeroportos()
{
    for (unsigned int i = 1; i <= this->ListaRotasAeroportosId.size(); i++)
    {
        cout << "AEROPORTO ID" << i << endl;
        for (unsigned int j = 0; j < this->ListaRotasAeroportosId[i].size(); j++)
        {
            cout << i << " -> " << this->ListaRotasAeroportosId[i][j] << endl;
        }
    }
}

Grafo::~Grafo() {}