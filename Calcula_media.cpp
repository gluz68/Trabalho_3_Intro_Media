#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <locale.h>
using namespace std;
float calculaMedia(vector <float> notas,int base, int i)
{
    float media = (notas.at(base) + notas.at(base + 1) + notas.at(base + 2)) / 3.0;
    return media;
}
int main()
{
    setlocale(LC_ALL, "Portuguese"); //localização portuguesa
    vector <string> alunos; //variaveis iniciais
    vector <float> notas;
    int qtdAlunos;
    float notaTemp;
    string nomeTemp;
    cout << "Insira o número de alunos a serem cadastrados (1 a 5): "; //entrada inicial
    cin >> qtdAlunos;
    while (qtdAlunos <=0 || qtdAlunos >5) //loop até o usuário inserir uma quantidade válida de alunos.
    {
        if (cin.fail()) 
        {
            cin.clear();
            cin.ignore();
            qtdAlunos = 0;
        }
        cout << "Valor inválido, tente novamente." 
             << "\nInsira o número de alunos a serem cadastrados: ";
        cin >> qtdAlunos;
    }
    for (int i = 1; i <= qtdAlunos; i++) // loop de entrada para alunos, com base no número de alunos.
    {
        cin.ignore();
        cout << "Insira o nome completo do aluno " << i << ": ";
        getline(cin, nomeTemp);
        alunos.push_back(nomeTemp);
        for (size_t j = 1; j <= 3; j++) //loop de entrada para notas, com base no número de notas.
        {
        cout << "Insira a nota " << j << " do aluno " << i << ": ";
        cin >> notaTemp;
        while (notaTemp < 0 || notaTemp > 10) //valida se a nota é válida
        {
            cout << "Valor inválido, tente novamente.\n"
                 << "Insira a nota " << j << " do aluno " << i << ": ";
            cin >> notaTemp;
        }
        notas.push_back(notaTemp);
        }
        int base = (i - 1) * 3; //calcula média das notas (n1+n2+n3 / 3).
        cout << "Aluno " << alunos.at(i-1) << ", cadastrado com as notas: "
             << "[" << notas.at(base)     << "] "
             << "[" << notas.at(base + 1) << "] "
             << "[" << notas.at(base + 2) << "] "
             << "| Média: " << calculaMedia(notas, base, i) << endl;
    }
    cout << "\nResultado:\n"; //tabela de resultados: cabeçalho.
    cout << string(90, '-') << "\n";
    cout << left
         << setw(40) << "Nome"
         << setw(10) << "Nota 1"
         << setw(10) << "Nota 2"
         << setw(10) << "Nota 3"
         << setw(10) << "Média"
         << setw(10) << "Situação"
         << "\n";
    cout << string(90, '-') << "\n";
    for (int i = 1; i <= qtdAlunos; i++) { //tabela de resultados: dados.
        int base = (i - 1) * 3;
        string resultado;
        if (calculaMedia(notas, base, i) >=7)
        {
            resultado = "Aprovado";
        } 
        else
        {
            resultado = "Reprovado";
        }
        cout << left
             << setw(40) << alunos.at(i-1)
             << setw(10) << notas.at(base)
             << setw(10) << notas.at(base + 1)
             << setw(10) << notas.at(base + 2)
             << setw(10) << calculaMedia(notas, base, i)
             << setw(10) << resultado
             << "\n";
    }
    cout << string(90, '-') << "\n";
    return 0;
}