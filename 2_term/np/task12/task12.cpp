#include <iostream>
#include <fstream>
#include "consumer_op.h"

using namespace std;

void BubbleSort(Consumer*, int);

int main()
{
    ifstream fin("D:\\Study\\Programming\\C++\\2_term\\np\\task12\\input.txt");
    ofstream fout("D:\\Study\\Programming\\C++\\2_term\\np\\task12\\output.txt");
    
    int n;
    cout << "Enter size of arrey: "; cin >> n;

    Consumer* con = new Consumer[n];
    for (size_t i = 0; i < n; i++)
        fin >> con[i];

    BubbleSort(con, n);
    for (size_t i = 0; i < n; i++)
    {
        fout << "Consumer " << i + 1 << endl;
        fout << con[i];
        con[i].ChangeDebt(20);
        int debt = con[i].GetDebt();
        fout << "Changed debt: " << debt << "\n\n";
    }

    fin.close();
    fout.close();
}

void BubbleSort(Consumer* con, int n)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n - 1; j++)
            if (con[j] < con[j + 1])
            {
                Consumer temp = con[j];
                con[j] = con[j + 1];
                con[j + 1] = temp;
                cout << temp;
            }
}
