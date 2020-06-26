#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

const int NotUsed = system( "color F4" );

double Foo(double x){ // функция активации
    return (1/(1 + exp(-x)));
}


class Neuron {
public:
    double output;
    int numb; // количество входов
    double *w; // весовой коэффициент
    double *data;
    double sum = 0.0;
    void changeWeight();
    double outputValue(double (*func)(double));
    void Set();
    Neuron(int Size, double (*func)(double)){ // конструктор
        this->numb = Size;
        this->data = new double[numb]; // значения
        this->w = new double[numb]; // весовые коэфф
    };

    Neuron(const Neuron &other){    // конструктор копирования
        this->numb = other.numb;
        this->data = new double[other.numb];
        this->w = new double[other.numb];
    };

    Neuron & operator = (const Neuron &other){ // перегрузка оператора
        this->numb = other.numb;
        this->data = new double[other.numb];
        this->w = new double[other.numb];
        return *this;
    }

    ~Neuron(){ // деструктор
        delete[] data;
        delete[] w;
    };
};

void Neuron::Set(){
    cout << "Введите главные значения" << endl;
    for (int i = 0; i < numb; i++){
        cin >> data[i];
    }
    cout << "Введите значения весов" << endl;
    for (int i = 0; i < numb; i++){
        cin >> w[i];
    }
}

double Neuron::outputValue(double (*func)(double)){     // функция для вывода
    cout << "Вывод:" << endl;
    double sumf = 0.0;
    for (unsigned int i = 0; i < numb; i++){
        sumf += data[i] * w[i];
    }
    output = func(sumf);
    return output;
}

int main()
{
    setlocale(0, "rus");
    int inputNumb;
    cout << "Введите количество входов: " << endl;
    cin >> inputNumb;
    Neuron testingNeuron(inputNumb, Foo);
    testingNeuron.Set();
    cout << testingNeuron.outputValue(Foo) << endl;
    return 0;
}
