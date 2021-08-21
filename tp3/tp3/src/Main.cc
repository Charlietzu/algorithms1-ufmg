#include "Grafo.h"

#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        string tipoTarefa = argv[1];
        string nomeEntrada = argv[2];
        if(tipoTarefa == "tarefa1" || tipoTarefa == "tarefa2")
        {
            Grafo *grafo = new Grafo();
            grafo->ProcessaEntrada(tipoTarefa, nomeEntrada);
        }
    }
    return 0;
}