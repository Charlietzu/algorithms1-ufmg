#include "Pessoa.h"
#include "PostoVacinacao.h"
#include "Dados.h"

#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc >= 1)
    {
        cin >> noskipws;
        Dados *dados = new Dados();
        vector<PostoVacinacao *> postos;
        vector<Pessoa *> pessoas;

        dados->ProcessaEntrada(postos, pessoas);
        dados->AlocaPessoasPostosVacinacao(postos, pessoas);
        dados->ImprimirRelatorioAlocacao(postos);

        for (auto pessoa = pessoas.begin(), end = pessoas.end(); pessoa != end; ++pessoa)
        {
            delete (*pessoa);
        }
        for (auto posto = postos.begin(), end = postos.end(); posto != end; ++posto)
        {
            delete (*posto);
        }

        delete dados;
    }
    return 0;
}