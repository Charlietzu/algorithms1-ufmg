#include "Dados.h"
#include "Aeroporto.h"
#include "Rota.h"

#include "Grafo.h"

#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc >= 1)
    {
        Grafo *grafo = new Grafo();
        vector<int> aeroportosId;
        grafo->ProcessaEntrada(aeroportosId);
        //grafo->ImprimirInfoAeroportos();
        grafo->Kosaraju(aeroportosId);

        delete grafo;
    }
    return 0;
}