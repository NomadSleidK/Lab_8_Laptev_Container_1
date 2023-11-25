#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

vector <double> GrowingConvertation(double *staticArray, int size) //конвертация из статического в динамический контейнер
{
    vector <double> dinamicArray;
    
    for (int i = 0; i < size; i++)
    {
        dinamicArray.push_back(staticArray[i]);
    }
    return dinamicArray;
}

double SumElements(vector <double> dinamicArray) //получаем сумму
{
    double sum = 0;
    
    for (int i = 0; i < dinamicArray.size(); i++)
    {
        sum += dinamicArray[i];
    }
    return sum;
}

double MeanArithmetic(vector <double> dinamicArray) //получаем среднее арифметическое
{
    double sum = SumElements(dinamicArray);
    int size = int(dinamicArray.size());
    double res = sum/size;
    return res;
}

double FirstMineElem(vector <double> dinamicArray) //получаем первый отрицательный элемент
{
    double element = 0;
    
    for (int i = 0; i < dinamicArray.size(); i++)
    {
        if (dinamicArray[i] < 0)
        {
            element = dinamicArray[i];
            break;
        }
    }
    
    return element;
}

void DispleyVector(vector <double> dinamicArray)
{
    for (int i = 0; i < dinamicArray.size(); i++)
    {
        if (int(dinamicArray[i]) == 133){dinamicArray[i] += 0.0006;}
        cout << fixed << setprecision(3) << dinamicArray[i] << "  ";
    }
    cout << endl;
}

void FirstOperation(vector <double>& dinamicArray) //добавляет сумму и среднее арифметическое
{
    double meanArithmetic = MeanArithmetic(dinamicArray);
    double sum = SumElements(dinamicArray);
    
    dinamicArray.push_back(sum);
    dinamicArray.push_back(meanArithmetic);
    DispleyVector(dinamicArray);
}

void SecondOperation(vector <double>& dinamicArray) //показать кмноженный на первый отрицательный элемент вектор
{
    double mineElem = FirstMineElem(dinamicArray);
    
    for (int i = 0; i < dinamicArray.size(); i++)
    {
        if (int(dinamicArray[i]) % 2 == 0 || fabs(dinamicArray[i]) < 1)
        {
            dinamicArray[i] = mineElem * (dinamicArray[i]);
        }
    }
    
    DispleyVector(dinamicArray);
}

void AppendElement(vector <double>& dinamicArray, double element) //добавить элемент в вектор
{
    dinamicArray.push_back(element);
}

void DeleteElement(vector <double>& dinamicArray) //кдалить элемент из вектора
{
    dinamicArray.pop_back();
}

void Control(double *staticArray, int size) //контроль команд для операций
{
    int comand = 0;
    double element = 0;
    vector <double> dinamicArray;
    dinamicArray = GrowingConvertation(staticArray, size);
    
    cout << size << endl;
    DispleyVector(dinamicArray);
    FirstOperation(dinamicArray);
    SecondOperation(dinamicArray);
    
    do
    {
        cin >> comand;
        switch (comand) {
            case 1:
                cin >> element;
                AppendElement(dinamicArray, element);
                cout << "+: " << dinamicArray.size() << endl;
                DispleyVector(dinamicArray);
                FirstOperation(dinamicArray);
                SecondOperation(dinamicArray);
                break;
            case 2:
                size--;
                DeleteElement(dinamicArray);
                cout << "-: " << dinamicArray.size() << endl;
                DispleyVector(dinamicArray);
                FirstOperation(dinamicArray);
                SecondOperation(dinamicArray);
                break;
        }
    }
    while(comand != 0);
}

int main() //главная функция
{
    int size = 0;
    cin >> size;
    double staticArray[size];
    
    for (int i = 0; i < size; i++)
    {
        cin >> staticArray[i];
    }
    
    Control(staticArray, size);
    return 0;
}

