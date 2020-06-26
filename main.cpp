#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

const int NotUsed = system( "color F4" );

double Foo(double x){ // ������� ���������
    return (1/(1 + exp(-x)));
}


class Neuron {
public:
    double output;
    int numb; // ���������� ������
    double *w; // ������� �����������
    double *data;
    double sum = 0.0;
    void changeWeight();
    double outputValue(double (*func)(double));
    void Set();
    Neuron(int Size, double (*func)(double)){ // �����������
        this->numb = Size;
        this->data = new double[numb]; // ��������
        this->w = new double[numb]; // ������� �����
    };

    Neuron(const Neuron &other){    // ����������� �����������
        this->numb = other.numb;
        this->data = new double[other.numb];
        this->w = new double[other.numb];
    };

    Neuron & operator = (const Neuron &other){ // ���������� ���������
        this->numb = other.numb;
        this->data = new double[other.numb];
        this->w = new double[other.numb];
        return *this;
    }

    ~Neuron(){ // ����������
        delete[] data;
        delete[] w;
    };
};

void Neuron::Set(){
    cout << "������� ������� ��������" << endl;
    for (int i = 0; i < numb; i++){
        cin >> data[i];
    }
    cout << "������� �������� �����" << endl;
    for (int i = 0; i < numb; i++){
        cin >> w[i];
    }
}

double Neuron::outputValue(double (*func)(double)){     // ������� ��� ������
    cout << "�����:" << endl;
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
    cout << "������� ���������� ������: " << endl;
    cin >> inputNumb;
    Neuron testingNeuron(inputNumb, Foo);
    testingNeuron.Set();
    cout << testingNeuron.outputValue(Foo) << endl;
    return 0;
}
