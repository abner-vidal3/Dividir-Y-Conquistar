#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
int main(){
    /*Lectura del input*/
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    /*Ordenamiento*/
    /*Implementación de la librería estándar*/
    auto start = high_resolution_clock::now();
    sort(arr.begin(),arr.end());
    /*Resultados*/
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << duration << endl;
    return 0;
}