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
}

void Dados::PreencheOrdem(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas, stack<Aeroporto *> pilha, vector<bool> explorados, int i)
{
    explorados[i] = true;

    if (aeroportos[i]->GetId() - 1 == i)
    {
        //Pra cada rota de destino
        //Recuperar esta rota no vetor de rotas
        //Verificar pra qual aeroporto ela vai
        //Recuperar este aeroporto e repetir o processo
        
        //cout << "AEROPORTO ID " << aeroportos[i]->GetId() << endl;

        for (unsigned int j = 0; j < aeroportos[i]->GetRotasDestino().size(); j++)
        {
            for (auto rota = rotas.begin(), end = rotas.end(); rota != end; ++rota)
            {
                if ((*rota)->GetId() == aeroportos[i]->GetRotasDestino()[j])
                {
                    //cout << (*rota)->GetAeroportoDestinoId() << endl;
                    cout << aeroportos[(*rota)->GetAeroportoDestinoId() - 1]->GetId() << endl;
                }
            }
        }
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