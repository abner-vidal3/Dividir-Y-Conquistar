#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
// Función para la suma de matrices
vector<vector<int>> add(const vector<vector<int>>& A,const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            res[i][j] = A[i][j] + B[i][j];
    return res;
}
// Función para la resta de matrices
vector<vector<int>> subtract(const vector<vector<int>>& A,const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            res[i][j] = A[i][j]-B[i][j];
    return res;
}
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    if (n == 1) 
        return {{A[0][0] * B[0][0]}};
    // Dividir las matrices en submatrices
    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Aplicar las siete multiplicaciones de Strassen
    vector<vector<int>> M1 = strassen(add(A11, A22), add(B11, B22));  // M1 = (A11 + A22) * (B11 + B22)
    vector<vector<int>> M2 = strassen(add(A21, A22), B11);            // M2 = (A21 + A22) * B11
    vector<vector<int>> M3 = strassen(A11, subtract(B12, B22));       // M3 = A11 * (B12 - B22)
    vector<vector<int>> M4 = strassen(A22, subtract(B21, B11));       // M4 = A22 * (B21 - B11)
    vector<vector<int>> M5 = strassen(add(A11, A12), B22);            // M5 = (A11 + A12) * B22
    vector<vector<int>> M6 = strassen(subtract(A21, A11), add(B11, B12));  // M6 = (A21 - A11) * (B11 + B12)
    vector<vector<int>> M7 = strassen(subtract(A12, A22), add(B21, B22));  // M7 = (A12 - A22) * (B21 + B22)

    // Calcular las submatrices de la matriz resultante
    vector<vector<int>> C11 = add(subtract(add(M1, M4), M5), M7);  // C11 = M1 + M4 - M5 + M7
    vector<vector<int>> C12 = add(M3, M5);                         // C12 = M3 + M5
    vector<vector<int>> C21 = add(M2, M4);                         // C21 = M2 + M4
    vector<vector<int>> C22 = add(subtract(add(M1, M3), M2), M6);  // C22 = M1 + M3 - M2 + M6

    // Combinar las submatrices en la matriz resultante
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    return C;
}

int main() {
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
    auto start = high_resolution_clock::now();
    vector<vector<int>> C = strassen(A, B);
    /*Resultados*/
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << duration << endl;
    return 0;
}