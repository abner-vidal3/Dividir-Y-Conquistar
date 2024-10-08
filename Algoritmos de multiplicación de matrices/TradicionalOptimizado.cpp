#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main(){
    /*Lectura del input*/
    int n1,m1;
    cin >> n1 >> m1;
    vector<vector<int>> A(n1,vector<int>(m1));
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            cin >> A[i][j];
    int n2,m2;
    cin >> n2 >> m2;
    /*ingresamos los datos transpuestos*/
    vector<vector<int>> B(m2,vector<int>(n2));
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < m2; j++)
            cin >> B[j][i];
    auto start = high_resolution_clock::now();
    /*Correr el algoritmo*/
    vector<vector<int>> C(n1,vector<int>(m2));
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < m1; k++)
                C[i][j] += A[i][k]*B[j][k];
    /*Resultados*/
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << duration << endl;
}