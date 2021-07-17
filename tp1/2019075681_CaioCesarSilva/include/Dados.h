#ifndef DADOS_H
#define DADOS_H

#include "Pessoa.h"
#include "PostoVacinacao.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class Dados
{
public:
    Dados();
    ~Dados();

    void ProcessaEntrada(vector<PostoVacinacao *> &postos, vector<Pessoa *> &pessoas);
    void ProcessaPessoas(vector<Pessoa *> &pessoas);
    void ProcessaPostosVacinacao(vector<PostoVacinacao *> &postos);
    void AlocaPessoasPostosVacinacao(vector<PostoVacinacao *> &postos, vector<Pessoa *> &pessoas);
    void ImprimirRelatorioAlocacao(vector<PostoVacinacao *> &postos);
};

#endif