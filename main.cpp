#include <iostream>
#include <string>
#include "Calculator.h"

using namespace std;
using namespace clc;


int main(){

string Sentense;

    cout << "Digite a operação: ";
    cin >> Sentense;

Calculator calculator(Sentense);


int res = calculator.operate();

cout << res << endl;

return 0;
}