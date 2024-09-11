#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void SelectionSort(vector<int> & arr){
    int n = arr.size();
    /* iteramos sobre n veces sobre el arreglo */
    for (int i = 0; i < n; i++){
        int mn = i;
        /*buscamos el elemento más pequeño*/
        for (int j = i+1; j < n; j++)
            if (arr[mn] > arr[j])
                mn = j;
        /*Lo reemplazamos al inicio*/
        swap(arr[i],arr[mn]);
    }
    return;
}
int main(){
    /*Lectura del input*/
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    /*Ordenamiento*/
    auto start = high_resolution_clock::now();
    SelectionSort(arr);
    /*Resultados*/
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << duration << endl;
    return 0;
}