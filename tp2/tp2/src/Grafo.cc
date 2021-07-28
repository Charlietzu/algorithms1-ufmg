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
        this->ListaRotasAeroportosIdTransposta.push_back({});
    }
}

void Grafo::AdicionaRota(int origemId, int destinoId)
{
    this->ListaRotasAeroportosId[origemId].push_back(destinoId);
}

void Grafo::AdicionaRotaTransposta(int origemId, int destinoId)
{
    this->ListaRotasAeroportosIdTransposta[origemId].push_back(destinoId);
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
        if (!explorados[aeroportoId])
        {
            this->DFSTempo(explorados, pilha, aeroportoId);
        }
    }

    TransporRotas();

    for (int aeroportoId = 1; aeroportoId <= this->QtdAeroportos; aeroportoId++)
    {
        explorados[aeroportoId] = false;
    }

    int count = 0;
    while (!pilha.empty())
    {
        int aeroportoId = pilha.top();
        pilha.pop();

        if (!explorados[aeroportoId])
        {
            this->ComponentesConectados.push_back({});
            this->GrauEntradaComponentes.push_back(0);
            this->GrauSaidaComponentes.push_back(0);
            DFSComponentesConectados(explorados, aeroportoId, count);
            count++;
        }
    }

    VerificaGrauSaidaComponentes();
    VerificaAdicaoMinima();
}

void Grafo::VerificaGrauSaidaComponentes()
{
    for (unsigned int i = 0; i < this->ComponentesConectados.size(); i++)
    {
        for (unsigned int j = 0; j < this->ComponentesConectados[i].size(); j++)
        {
            for (unsigned int k = 0; k < this->ListaRotasAeroportosId[this->ComponentesConectados[i][j]].size(); k++)
            {
                if (!EncontraItem(this->ComponentesConectados[i], this->ListaRotasAeroportosId[this->ComponentesConectados[i][j]][k]))
                {
                    this->GrauSaidaComponentes[i] = this->GrauSaidaComponentes[i] + 1;
                    VerificaGrauEntradaComponentes(this->ListaRotasAeroportosId[this->ComponentesConectados[i][j]][k]);
                }
            }
        }
    }
}

void Grafo::VerificaGrauEntradaComponentes(int destinoId)
{
    for (unsigned int i = 0; i < this->ComponentesConectados.size(); i++)
    {
        for (unsigned int j = 0; j < this->ComponentesConectados[i].size(); j++)
        {
            if (this->ComponentesConectados[i][j] == destinoId)
            {
                this->GrauEntradaComponentes[i] = this->GrauEntradaComponentes[i] + 1;
            }
        }
    }
}

bool Grafo::EncontraItem(vector<int> componente, int aeroportoId)
{
    for (unsigned int i = 0; i < componente.size(); i++)
    {
        if (componente[i] == aeroportoId)
        {
            return true;
        }
    }
    return false;
}

void Grafo::DFSTempo(vector<bool> &explorados, stack<int> &pilha, int aeroportoId)
{
    explorados[aeroportoId] = true;
    for (unsigned int j = 0; j < this->ListaRotasAeroportosId[aeroportoId].size(); j++)
    {
        if (!explorados[this->ListaRotasAeroportosId[aeroportoId][j]])
        {
            this->DFSTempo(explorados, pilha, this->ListaRotasAeroportosId[aeroportoId][j]);
        }
    }
    pilha.push(aeroportoId);
}

void Grafo::TransporRotas()
{
    for (unsigned int i = 1; i <= this->ListaRotasAeroportosId.size(); i++)
    {
        for (unsigned int j = 0; j < this->ListaRotasAeroportosId[i].size(); j++)
        {
            AdicionaRotaTransposta(this->ListaRotasAeroportosId[i][j], i);
        }
    }
}

void Grafo::DFSComponentesConectados(vector<bool> &explorados, int aeroportoId, int count)
{
    explorados[aeroportoId] = true;
    this->ComponentesConectados[count].push_back(aeroportoId);

    for (unsigned int j = 0; j < this->ListaRotasAeroportosIdTransposta[aeroportoId].size(); j++)
    {
        if (!explorados[this->ListaRotasAeroportosIdTransposta[aeroportoId][j]])
        {
            this->DFSComponentesConectados(explorados, this->ListaRotasAeroportosIdTransposta[aeroportoId][j], count);
        }
    }
}

void Grafo::VerificaAdicaoMinima()
{
    int totalGrauEntradaZero = 0, totalGrauSaidaZero = 0;
    for (unsigned int i = 0; i < this->GrauEntradaComponentes.size(); i++)
    {
        if (this->GrauEntradaComponentes[i] == 0)
        {
            totalGrauEntradaZero++;
        }

        if (this->GrauSaidaComponentes[i] == 0)
        {
            totalGrauSaidaZero++;
        }
    }

    if (totalGrauEntradaZero > totalGrauSaidaZero)
    {
        cout << totalGrauEntradaZero;
        cout << "\n";
    }
    else
    {
        cout << totalGrauSaidaZero;
        cout << "\n";
    }
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

void Grafo::ImprimirRotasTranspostas()
{
    for (unsigned int i = 1; i <= this->ListaRotasAeroportosIdTransposta.size(); i++)
    {
        cout << "AEROPORTO ID" << i << endl;
        for (unsigned int j = 0; j < this->ListaRotasAeroportosIdTransposta[i].size(); j++)
        {
            cout << i << " -> " << this->ListaRotasAeroportosIdTransposta[i][j] << endl;
        }
    }
}

void Grafo::ImprimirComponentes()
{
    for (unsigned int i = 0; i < this->ComponentesConectados.size(); i++)
    {
        cout << "COMPONENTE ID " << i << endl;
        for (unsigned int j = 0; j < this->ComponentesConectados[i].size(); j++)
        {
            cout << this->ComponentesConectados[i][j] << "  ";
        }
        cout << endl;
        cout << "GRAU DE SAIDA " << this->GrauSaidaComponentes[i] << endl;
        cout << "GRAU DE ENTRADA " << this->GrauEntradaComponentes[i] << endl;
        cout << "---------------" << endl;
    }
}

Grafo::~Grafo() {}