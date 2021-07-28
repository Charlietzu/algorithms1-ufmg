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
        grafo->Kosaraju(aeroportosId);
/* 
        grafo->ImprimirInfoAeroportos();
        cout << "-------------------------------------" << endl;
        grafo->ImprimirRotasTranspostas(); */

        aeroportosId.clear();
        aeroportosId.shrink_to_fit();
        delete grafo;
    }
    return 0;
}