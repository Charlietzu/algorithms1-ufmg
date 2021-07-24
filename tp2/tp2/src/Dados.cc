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
    vector<bool> explorados;

    for (unsigned int i = 0; i < aeroportos.size(); i++)
    {
        explorados.push_back(false);
    }

    for (unsigned int i = 0; i < aeroportos.size(); i++)
    {
        if (!explorados[i])
        {
            PreencheOrdem(aeroportos, rotas, pilha, explorados, i);
        }
    }

    vector<Rota *> rotasT;
    CriaRotasTranspostas(rotas, rotasT);

    for (auto rota = rotasT.begin(), end = rotasT.end(); rota != end; ++rota)
    {
        cout << (*rota)->GetAeroportoOrigemId() << " -> " << (*rota)->GetAeroportoDestinoId() << endl;
    }
}

void Dados::PreencheOrdem(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas, stack<Aeroporto *> pilha, vector<bool> explorados, int i)
{
    if (aeroportos[i]->GetId() - 1 == i)
    {
        /*         cout << "AEROPORTO ID "<< aeroportos[i]->GetId() << endl;
        cout << "aeroportos adjacentes" << endl; */
        for (unsigned int j = 0; j < aeroportos[i]->GetRotasDestino().size(); j++)
        {
            int indAeroportoAdj = rotas[aeroportos[i]->GetRotasDestino()[j] - 1]->GetAeroportoDestinoId() - 1;
            // cout << aeroportos[indAeroportoAdj]->GetId() << endl;
        }
        /*         cout << "PUSH NA PILHA" << endl;
        cout << aeroportos[i]->GetId() << endl;
        cout << "-----------------------------" << endl; */
        pilha.push(aeroportos[i]);
        explorados[i] = true;
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