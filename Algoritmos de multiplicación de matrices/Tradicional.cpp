#include <bits/stdc++.h>
using namespace std;
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
    vector<vector<int>> B(n2,vector<int>(m2));
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < m2; j++)
            cin >> B[i][j];
    /*Correr el algoritmo*/
    vector<vector<int>> C(n1,vector<int>(m2));
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
            for (int k = 0; k < m1; k++)
                C[i][j] += A[i][k]*B[k][j];
    /*Resultados*/
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < m2; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
}