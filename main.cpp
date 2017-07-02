#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <locale.h>
#include <time.h>

using namespace std;




struct sfuncionario
{


    int codigo;
    string nome;
    string idade;
    string area;
    string sexo;
    int codamigo1;
    int codamigo2;
    int codamigo3;

};

/// BUBBLE SORT

void bubble(sfuncionario  funcionario[])
{
    int  ind = 1;
    int tim;


    for(int i = 0; (i <= 7) && ind; i++)
    {
        ind = 0;
        for (int j=7; j >= 0; j--)
        {
            if (funcionario[j].codigo > funcionario[j].codigo)
            {
                tim = funcionario[j].codigo;
                funcionario[j].codigo = funcionario[j+1].codigo;
                funcionario[j+1].codigo = tim;
                ind = 1;
            }
        }
    }
}

///SELECTION SORT

void selecao(sfuncionario funcionario[])
{
    for(int i=0; i<8-1; i++)
    {

        int minimo =i;

        for(int j=i+1; j<8; j++)
        {

            if (funcionario[i].codigo < funcionario[minimo].codigo)
            {

                minimo = j;
            }

            int x= funcionario[minimo].codigo;
            funcionario[minimo].codigo = funcionario[i].codigo;
            funcionario[i].codigo=x;
        }


    }
}

///INSERTION SORT

void insercao(sfuncionario  funcionario[])
{
    int  j, tmp;
    for (int i = 1; i < 8; i++)
    {
        j = i;
        while (j > 0 && funcionario[j - 1].codigo > funcionario[j].codigo)
        {
            tmp = funcionario[j].codigo;
            funcionario[j].codigo = funcionario[j - 1].codigo;
            funcionario[j - 1].codigo = tmp;
            j--;
        }
    }
}

/// QUICK SORT

void quicksort(sfuncionario funcionario[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = funcionario[(left + right) / 2].codigo;


    while (i <= j)
    {
        while (funcionario[i].codigo < pivot)
            i++;
        while (funcionario[j].codigo > pivot)
            j--;
        if (i <= j)
        {
            tmp = funcionario[i].codigo;
            funcionario[i].codigo = funcionario[j].codigo;
            funcionario[j].codigo = tmp;
            i++;
            j--;
        }
    };


    if (left < j)
        quicksort(funcionario, left, j);
    if (i < right)
        quicksort(funcionario, i, right);
}


///SHELL SORT

void shellsort(sfuncionario  funcionario[])
{
    int j;
    for (int salto = 8/2; salto > 0; salto /= 2)
    {
        for (int i = salto; i < 8; ++i)
        {
            int tempo = funcionario[i].codigo;
            for (j = i; j >= salto && tempo < funcionario[j - salto].codigo; j -= salto)
            {
                funcionario[j].codigo = funcionario[j - salto].codigo;
            }
            funcionario[j].codigo = tempo;
        }
    }
}

void Trabalho()
{
    string linha;
    string temp;

//Leitura do arquivo "dados.txt"

    ifstream arq("dados.txt");
    int i, numfuncionario = 0;
    sfuncionario funcionario[8];

    if(arq.is_open())
    {

        while(getline(arq, linha))
        {

            temp = "";
            for(i=0; i< linha.size(); i++)
            {

                if(linha[i]!= ';')
                {
                    temp = temp + linha[i];
                }
                else
                {
                    break;
                }
            }

            stringstream sscodigo(temp);
            sscodigo>>funcionario[numfuncionario].codigo;

            temp="";

            for(i = i+1; i< linha.size(); i++)
            {
                if(linha[i]!= ';')
                {
                    temp = temp + linha[i];
                }
                else
                {
                    break;
                }
            }

            funcionario[numfuncionario].nome = temp;
            temp="";


            for(i = i+1; i< linha.size(); i++)
            {
                if(linha[i]!= ';')
                {
                    temp = temp + linha[i];
                }
                else
                {
                    break;
                }
            }

            funcionario[numfuncionario].idade = temp;
            temp="";


            for(i = i+1; i< linha.size(); i++)
            {

                if(linha[i]!= ';')
                {
                    temp = temp + linha[i];
                }
                else
                {
                    break;
                }
            }

            funcionario[numfuncionario].area = temp;
            temp="";



            for(i = i+1; i< linha.size(); i++)
            {
                if(linha[i]!= ';')
                {
                    temp = temp + linha[i];
                }
                else
                {
                    break;
                }
            }


            funcionario[numfuncionario].sexo = temp;
            temp="";
            numfuncionario++;

        }

    }
    else
    {
        cout<<"Arquivo inválido";
    }
    arq.close();

    //Informação dos funcionários

    for(i=0; i<8; i++)
    {

        cout<<"Codigo: "<<funcionario[i].codigo<<endl;
        cout<<"Nome: "<<funcionario[i].nome<<endl;
        cout<<"Idade: "<<funcionario[i].idade<<endl;
        cout<<"Área de atuação: "<<funcionario[i].area<<endl;
        cout<<"Sexo: "<<funcionario[i].sexo<<endl;
        cout<<"-----------------------"<<endl;



    }


    int mesa[8];

    for (i=0; i<8; i++)
    {

        cout<<"\n\nInsira o codigo de um funcionario com quem "<<funcionario[i].nome<<" quer sentar ";
        cin>>funcionario[i].codamigo1;
        cout<<"Insira o codigo de outro funcionario com quem "<<funcionario[i].nome<<" quer sentar ";
        cin>>funcionario[i].codamigo2;
        cout<<"Insira o codigo de outro funcionario com quem "<<funcionario[i].nome<<" quer sentar ";
        cin>>funcionario[i].codamigo3;

        while(funcionario[i].codamigo1==funcionario[i].codigo || funcionario[i].codamigo2==funcionario[i].codigo || funcionario[i].codamigo3==funcionario[i].codigo || funcionario[i].codamigo1==funcionario[i].codamigo2 || funcionario[i].codamigo1==funcionario[i].codamigo3 || funcionario[i].codamigo2==funcionario[i].codamigo3)
        {
            cout<<"----------------------------------------------------------------------\n\n O funcionario não pode inserir o seu próprio codigo ou codigos iguais\n\n insira novamente CORRETAMENTE \n\n---------------------------------------------------------------------- \n\n"<<endl;
            cout<<"Insira o codigo de um funcionario com quem "<<funcionario[i].nome<<" quer sentar ";
            cin>>funcionario[i].codamigo1;
            cout<<"Insira o codigo de outro funcionario com quem "<<funcionario[i].nome<<" quer sentar ";
            cin>>funcionario[i].codamigo2;
            cout<<"Insira o codigo de outro funcionario com quem "<<funcionario[i].nome<<" quer sentar ";
            cin>>funcionario[i].codamigo3;

        }
    }

//Inserção dos códigos das pessoas com quem o funcionário quer sentar


    cout<<"\n\n\n";


//Resultado da escolha dos funcionarios


    for (int i=0; i<8; i++)
    {

        cout<<" \n O funcionário "<<funcionario[i].nome<<" gostaria de se sentar com os funcionários de codigo: "<<funcionario[i].codamigo1<<" ;"<<funcionario[i].codamigo2<<" ;"<<funcionario[i].codamigo3<<" ;"<<endl;

    }

    for (int i=0; i<8; i++)
    {
        mesa[i]=0;
    }


//Divisão dos funcionários nas mesas


    for( i=0; i<8; i++)
    {

        for(int j=7; j>=0; j--)
        {




            if((funcionario[i].codamigo1==funcionario[j].codigo && funcionario[j].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo1==funcionario[j].codigo && funcionario[j].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo1==funcionario[j].codigo && funcionario[j].codamigo3==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j].codigo && funcionario[j].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j].codigo && funcionario[j].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j].codigo && funcionario[j].codamigo3==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j].codigo && funcionario[j].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j].codigo && funcionario[j].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j].codigo && funcionario[j].codamigo3==funcionario[i].codigo))
            {
                mesa[i] = funcionario[i].codigo;
                mesa[i+1] = funcionario[i].codamigo1;

            }


            if((funcionario[i].codamigo1==funcionario[j+1].codigo && funcionario[j+1].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo1==funcionario[j+1].codigo && funcionario[j+1].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo1==funcionario[j+1].codigo && funcionario[j+1].codamigo3==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j+1].codigo && funcionario[j+1].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j+1].codigo && funcionario[j+1].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j+1].codigo && funcionario[j+1].codamigo3==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j+1].codigo && funcionario[j+1].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j+1].codigo && funcionario[j+1].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j+1].codigo && funcionario[j+1].codamigo3==funcionario[i].codigo))
            {
                mesa[i] = funcionario[i].codigo;
                mesa[i+2] = funcionario[j].codamigo2;

            }



            if((funcionario[i].codamigo1==funcionario[j+2].codigo && funcionario[j+2].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo1==funcionario[j+2].codigo && funcionario[j+2].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo1==funcionario[j+2].codigo && funcionario[j+2].codamigo3==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j+2].codigo && funcionario[j+2].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j+2].codigo && funcionario[j+2].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo2==funcionario[j+2].codigo && funcionario[j+2].codamigo3==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j+2].codigo && funcionario[j+2].codamigo1==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j+2].codigo && funcionario[j+2].codamigo2==funcionario[i].codigo) || (funcionario[i].codamigo3==funcionario[j+2].codigo && funcionario[j+2].codamigo3==funcionario[i].codigo))
            {
                mesa[i] = funcionario[i].codigo;
                mesa[i+3] = funcionario[j].codamigo3;

            }


            for(int k=0; k<j; k++)
            {

                if(mesa[k]==mesa[j])
                {


                    mesa[j] = funcionario[i].codigo;

                }
            }



        }

        if(mesa[i]==0)
        {
            mesa[i] = funcionario[i].codigo;
        }

    }


    //Informação das mesas

    for(int i = 0; i<4; i++)
    {
        cout<<"\n\n O funcionário na posição "<<i+1<<" da mesa 1 é o funcionário";

        if(funcionario[i].codigo==mesa[i])
            cout<<" o numero é "<<funcionario[i].nome;


    }
    for(int i = 4; i<8; i++)
    {
        cout<<"\n\n O funcionario na posição "<<i+1<<" da mesa 2 é o funcionário";

        if(funcionario[i].codigo==mesa[i])
            cout<<" o numero é "<<funcionario[i].nome;


    }


//Criação do arquivo "saida.txt"

    ofstream saida("saida.txt");


    if(saida.is_open())
    {


        for(int i=0; i<4; i++)
        {

            saida<<'0'<<funcionario[i].codigo<<';';

        }

        saida.put('\n');

        for(int i=4; i<8; i++)
        {

            saida<<'0'<<funcionario[i].codigo<<';';

        }

        saida.close();
    }

//Implementação dos métodos de ordenação

    bubble(funcionario);
    cout<<"\n \n Bubble Sort # \n\n";
    selecao(funcionario);
    cout<<"Selection Sort # \n\n";
    insercao(funcionario);
    cout<<"Insertion Sort # \n\n";
    quicksort(funcionario, funcionario[0].codigo, funcionario[7].codigo);
    cout<<"QuickSort # \n\n";
    shellsort(funcionario);
    cout<<"ShellSort # \n\n";



//// FINAL TRABALHO ///////////
}


int main()
{

    clock_t tempoInicial, tempoFinal;
   float tempoGasto;
   tempoInicial = clock();

    setlocale(LC_ALL, "Portuguese");


    Trabalho();


   tempoFinal = clock();

   tempoGasto = (tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
   cout<<"\n\n\n\n\n Tempo em segundos: "<< tempoGasto;

    return 0;
}
