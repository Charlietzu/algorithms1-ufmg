#include "Dados.h"
#include "Aeroporto.h"
#include "Rota.h"

#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc >= 1)
    {
        Dados *dados = new Dados();
        vector<Aeroporto *> aeroportos;
        vector<Rota *> rotas;

        dados->ProcessaEntrada(aeroportos, rotas);

        for (auto aeroporto = aeroportos.begin(), end = aeroportos.end(); aeroporto != end; ++aeroporto)
        {
            delete (*aeroporto);
        }
        for (auto rota = rotas.begin(), end = rotas.end(); rota != end; ++rota)
        {
            delete (*rota);
        }

        delete dados;
    }
    return 0;
}