#include "Dados.h"

Dados::Dados() {}

Dados::~Dados() {}

void Dados::ProcessaEntrada(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas)
{
    string entrada = "";
    int qtdAeroportos = 0, qtdRotas = 0, rotaId = 1;

    cin >> qtdAeroportos >> qtdRotas;

    CriaAeroportos(aeroportos, qtdAeroportos);

    while (getline(cin, entrada) && rotaId <= qtdRotas)
    {
        int origemId = 0, destinoId = 0;

        cin >> origemId >> destinoId;

        Rota *rota = new Rota(rotaId, origemId, destinoId);

        aeroportos[origemId - 1]->AddAeroportoAdj(aeroportos[destinoId - 1]);

        rotas.push_back(rota);
        AdicionaRotaAeroportos(aeroportos, rotaId, origemId, destinoId);

        rotaId++;
    }
}

void Dados::CriaAeroportos(vector<Aeroporto *> &aeroportos, int qtdAeroportos)
{
    for (int i = 1; i <= qtdAeroportos; i++)
    {
        Aeroporto *aeroporto = new Aeroporto(i);
        aeroportos.push_back(aeroporto);
    }
}

void Dados::AdicionaRotaAeroportos(vector<Aeroporto *> &aeroportos, int rotaId, int origemId, int destinoId)
{
    for (auto aeroporto = aeroportos.begin(), end = aeroportos.end(); aeroporto != end; ++aeroporto)
    {
        if ((*aeroporto)->GetId() == origemId)
        {
            (*aeroporto)->AddRotaDestinoId(rotaId);
        }

        if ((*aeroporto)->GetId() == destinoId)
        {
            (*aeroporto)->AddRotaOrigemId(rotaId);
        }
    }
}

void Dados::Kosaraju(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas)
{
    stack<Aeroporto *> pilha;
    vector<bool> IdExplorados;

    for (unsigned int i = 1; i <= aeroportos.size(); i++)
    {
        IdExplorados.push_back(false);
    }

    for (unsigned int i = 1; i <= aeroportos.size(); i++)
    {
        if (!IdExplorados[i])
        {
            cout << "chamada fora da recursao " << aeroportos[i - 1]->GetId() << endl;
            PreencheOrdem(aeroportos, rotas, pilha, IdExplorados, i - 1);
        }
    }

    /*     vector<Rota *> rotasT;
    CriaRotasTranspostas(rotas, rotasT); */

    /*     for (auto rota = rotasT.begin(), end = rotasT.end(); rota != end; ++rota)
    {
        cout << (*rota)->GetAeroportoOrigemId() << " -> " << (*rota)->GetAeroportoDestinoId() << endl;
    } */
}

void Dados::PreencheOrdem(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas, stack<Aeroporto *> pilha, vector<bool> IdExplorados, int i)
{
    IdExplorados[aeroportos[i]->GetId()] = true;
    cout << "AEROPORTO ID - " << aeroportos[i]->GetId() << endl;
    for (unsigned int j = 0; j < aeroportos[i]->GetAeroportosAdj().size(); j++)
    {
        if (!IdExplorados[aeroportos[i]->GetAeroportosAdj()[j]->GetId()])
        {
            PreencheOrdem(aeroportos, rotas, pilha, IdExplorados, aeroportos[i]->GetAeroportosAdj()[j]->GetId() - 1);
        }

        cout << "ID - " << aeroportos[i]->GetId() << endl;
    }
}

void Dados::CriaRotasTranspostas(vector<Rota *> &rotas, vector<Rota *> &rotasT)
{
    for (auto rota = rotas.begin(), end = rotas.end(); rota != end; ++rota)
    {
        Rota *rotaT = new Rota((*rota)->GetId(), (*rota)->GetAeroportoDestinoId(), (*rota)->GetAeroportoOrigemId());
        rotasT.push_back(rotaT);
    }
}

//aux
void Dados::ImprimirInfoAeroportos(vector<Aeroporto *> &aeroportos)
{
    for (auto aeroporto = aeroportos.begin(), end = aeroportos.end(); aeroporto != end; ++aeroporto)
    {
        (*aeroporto)->ImprimeRotasAeroporto();
    }
}