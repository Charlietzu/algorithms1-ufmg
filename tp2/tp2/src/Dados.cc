#include "Dados.h"

Dados::Dados() {}

Dados::~Dados() {}

void Dados::ProcessaEntrada(vector<Aeroporto *> &aeroportos, vector<Rota *> &rotas)
{
    string entrada = "";
    int qtdAeroportos = 0, qtdRotas = 0, rotaId = 1;

    cin >> qtdAeroportos >> qtdRotas;

    CriarAeroportos(aeroportos, qtdAeroportos);

    while (getline(cin, entrada) && rotaId <= qtdRotas)
    {
        int origemId = 0, destinoId = 0;

        cin >> origemId >> destinoId;

        Rota *rota = new Rota(rotaId, origemId, destinoId);

        rotas.push_back(rota);
        AdicionaRotaAeroportos(aeroportos, rotaId, origemId, destinoId);
        
        rotaId++;
    }

    for (auto aeroporto = aeroportos.begin(), end = aeroportos.end(); aeroporto != end; ++aeroporto)
    {
        (*aeroporto)->ImprimeRotasAeroporto();
    }
}

void Dados::CriarAeroportos(vector<Aeroporto *> &aeroportos, int qtdAeroportos)
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
            (*aeroporto)->AddRotaOrigemId(rotaId);
        }

        if ((*aeroporto)->GetId() == destinoId)
        {
            (*aeroporto)->AddRotaDestinoId(rotaId);
        }
    }
}