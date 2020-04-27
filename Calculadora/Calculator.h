#include <iostream>
#include <string.h>
#include <vector>


using namespace std;


namespace clc
{

typedef struct
{
    int valor;
    char operador;
    int type;

}Date;



class Calculator
{
private:

    string Sentense;
    vector<Date> UtilizatedVector;
    string Aux_sentece = "";
    
    void Convert(){

        for (int i = 0; i < Sentense.size(); i++)
        {


            if((Sentense[i] != '+' && Sentense[i] != '/' && Sentense[i] != '*' && Sentense[i] != '-') && i < Sentense.size()){
                Aux_sentece.push_back(Sentense[i]);
            }
            else
            {
                Date Aux;
                Aux.valor = stoi(Aux_sentece);
                Aux_sentece = "";
                Aux.type = 0;
                UtilizatedVector.push_back(Aux);
                Aux.operador = Sentense[i];
                Aux.type = 1;
                UtilizatedVector.push_back(Aux);
            }
            

        }

        Date Aux;
        Aux.valor = stoi(Aux_sentece);
        Aux_sentece = "";
        Aux.type = 0;
        UtilizatedVector.push_back(Aux);
        
    }

public:



    Calculator(string sentese){
        Sentense = sentese;
        Convert();
    };

    void ShowElements(){
        
        cout << "Sentese: " << Sentense << endl;
        cout << "Aux_Sentese: " << Aux_sentece << endl;
        cout << "Vector Size: " << UtilizatedVector.size() << endl;

        for(size_t i = 0; i < UtilizatedVector.size(); i++)
        {
            if(UtilizatedVector[i].type == 0)
                cout << ':' << UtilizatedVector[i].valor;


            else if(UtilizatedVector[i].type == 1)
                cout << ':' << UtilizatedVector[i].operador;
        }
        


        cout << endl;
        
    }

    int operate(){

        int AtualSizeVector = UtilizatedVector.size();

        for(size_t i = 0; i < AtualSizeVector; i++){

            if(UtilizatedVector[i].type == 1 && (UtilizatedVector[i].operador == '*' || UtilizatedVector[i].operador == '/' ))
            {

                if(UtilizatedVector[i].operador == '*')
                    UtilizatedVector[i].valor = UtilizatedVector[i-1].valor * UtilizatedVector[i+1].valor;

                else if(UtilizatedVector[i].operador == '/')
                    UtilizatedVector[i].valor = UtilizatedVector[i-1].valor / UtilizatedVector[i+1].valor;

                //aqui da erro no codigo!!

                UtilizatedVector[i].type = 0;
                UtilizatedVector.erase(UtilizatedVector.begin() + (i - 1));
                UtilizatedVector.erase(UtilizatedVector.begin() + i);


                AtualSizeVector -= 2;
                i = 0;
            }
        }
  
        for(size_t i = 0; i < AtualSizeVector; i++){

            if(UtilizatedVector[i].type == 1 && (UtilizatedVector[i].operador == '+' || UtilizatedVector[i].operador == '-' ))
            {

                if(UtilizatedVector[i].operador == '+')
                    UtilizatedVector[i].valor = UtilizatedVector[i-1].valor + UtilizatedVector[i+1].valor;

                else if(UtilizatedVector[i].operador == '-')
                    UtilizatedVector[i].valor = UtilizatedVector[i-1].valor - UtilizatedVector[i+1].valor;

                //aqui da erro no codigo!!

                UtilizatedVector[i].type = 0;
                UtilizatedVector.erase(UtilizatedVector.begin() + (i - 1));
                UtilizatedVector.erase(UtilizatedVector.begin() + i);


                AtualSizeVector -= 2;
                i = 0;
            }
        }

    return UtilizatedVector[0].valor;
    }

};

}