#include <bits/stdc++.h>
using namespace std;
int main(){
    /*Lectura del input*/
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    /*Ordenamiento*/
    /*Implementación de la librería estándar*/
    sort(arr.begin(),arr.end());
    /*Resultados*/
    for (int c : arr)
        cout << c << " ";
    cout << endl;
    return 0;
}