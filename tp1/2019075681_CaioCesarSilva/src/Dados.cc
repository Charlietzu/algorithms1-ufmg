#include "Dados.h"

Dados::Dados() {}

bool ComparacaoDistancia(PostoVacinacao *p1, PostoVacinacao *p2)
{
    if (p1->GetDistanciaTemp() < p2->GetDistanciaTemp())
    {
        return true;
    }
    else if (p1->GetDistanciaTemp() == p2->GetDistanciaTemp())
    {
        return p1->GetId() < p2->GetId();
    }
    else
    {
        return false;
    }
}

bool ComparacaoId(PostoVacinacao *p1, PostoVacinacao *p2)
{
    if (p1->GetId() < p2->GetId())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ComparacaoIdade(Pessoa *p1, Pessoa *p2)
{
    if (p1->GetIdade() > p2->GetIdade())
    {
        return true;
    }
    else if (p1->GetIdade() == p2->GetIdade())
    {
        return p1->GetId() < p2->GetId();
    }
    else
    {
        return false;
    }
}

void Dados::ProcessaPostosVacinacao(vector<PostoVacinacao *> &postos)
{
    string entrada = "", valor = "";
    int i = 0, qtdPostosVacinacao = 0, numeroVagas = 0, postoX = 0, postoY = 0;

    getline(cin, entrada);
    qtdPostosVacinacao = stoi(entrada);

    while (i < qtdPostosVacinacao)
    {
        int qtdEspacos = 0;
        getline(cin, entrada);
        for (unsigned int j = 0; j <= entrada.size(); j++)
        {
            if (isdigit(entrada[j]))
            {
                valor.push_back(entrada[j]);
            }
            if (j == entrada.size())
            {
                postoY = stoi(valor);
                valor = "";
            }
            if (isspace(entrada[j]))
            {
                if (qtdEspacos == 0)
                {
                    numeroVagas = stoi(valor);
                }
                else if (qtdEspacos == 1)
                {
                    postoX = stoi(valor);
                }
                valor = "";
                qtdEspacos++;
            }
        }
        PostoVacinacao *posto = new PostoVacinacao(i, numeroVagas, postoX, postoY);
        postos.push_back(posto);
        i++;
    }
}

void Dados::ProcessaPessoas(vector<Pessoa *> &pessoas)
{
    string entrada = "", valor = "";
    int i = 0, qtdPessoas = 0, idade = 0, pessoaX = 0, pessoaY = 0;

    getline(cin, entrada);
    qtdPessoas = stoi(entrada);

    while (i < qtdPessoas)
    {
        int qtdEspacos = 0;
        getline(cin, entrada);
        for (unsigned int j = 0; j <= entrada.size(); j++)
        {
            if (isdigit(entrada[j]))
            {
                valor.push_back(entrada[j]);
            }
            if (j == entrada.size())
            {
                pessoaY = stoi(valor);
                valor = "";
            }
            if (isspace(entrada[j]))
            {
                if (qtdEspacos == 0)
                {
                    idade = stoi(valor);
                }
                else if (qtdEspacos == 1)
                {
                    pessoaX = stoi(valor);
                }
                valor = "";
                qtdEspacos++;
            }
        }
        Pessoa *pessoa = new Pessoa(i, idade, pessoaX, pessoaY);
        pessoas.push_back(pessoa);
        i++;
    }
}

void Dados::ProcessaEntrada(vector<PostoVacinacao *> &postos, vector<Pessoa *> &pessoas)
{
    ProcessaPostosVacinacao(postos);
    ProcessaPessoas(pessoas);
}

void Dados::AlocaPessoasPostosVacinacao(vector<PostoVacinacao *> &postos, vector<Pessoa *> &pessoas)
{
    sort(pessoas.begin(), pessoas.end(), ComparacaoIdade);
    for (auto pessoa = pessoas.begin(), end = pessoas.end(); pessoa != end; ++pessoa)
    {
        for (auto posto = postos.begin(), end = postos.end(); posto != end; ++posto)
        {
            (*posto)->CalcularDistancia((*pessoa)->GetCoordX(), (*pessoa)->GetCoordY());
        }
        sort(postos.begin(), postos.end(), ComparacaoDistancia);
        for (auto posto = postos.begin(), end = postos.end(); posto != end; ++posto)
        {
            if ((*posto)->GetVagasDisponiveis() > 0 && !(*pessoa)->GetIndAlocada())
            {
                (*posto)->AlocaPessoa((*pessoa)->GetId());
                (*pessoa)->SetIndAlocada(true);
            }
        }
    }
}

void Dados::ImprimirRelatorioAlocacao(vector<PostoVacinacao *> &postos)
{
    sort(postos.begin(), postos.end(), ComparacaoId);
    for (auto posto = postos.begin(), end = postos.end(); posto != end; ++posto)
    {
        if ((*posto)->GetPessoasAlocadasId().size() > 0)
        {
            cout << (*posto)->GetId() << endl;
            for (unsigned int i = 0; i < (*posto)->GetPessoasAlocadasId().size(); i++)
            {
                if (i == (*posto)->GetPessoasAlocadasId().size() - 1)
                {
                    cout << (*posto)->GetPessoasAlocadasId()[i];
                }
                else
                {
                    cout << (*posto)->GetPessoasAlocadasId()[i] << " ";
                }
            }
            cout << endl;
        }
    }
}

Dados::~Dados() {}