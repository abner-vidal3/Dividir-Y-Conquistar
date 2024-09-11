#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void QuickSort(vector<int> & arr, int l, int r){
    if (l >= r) 
        return;
    /*Elegimos pivote como el último elemento.*/
    int mn = l, pivot = arr[r];
    /*Colocamos a la izquierda los elementos menores.*/
    for (int i = l; i < r; i++)
        if (arr[i] <= pivot){
            swap(arr[mn],arr[i]);
            mn++;
        }
    /*Colocamos el pivote en la posición correcta.*/
    swap(arr[mn],arr[r]);
    /*Repetimos recursivamente*/
    QuickSort(arr,l,mn-1);
    QuickSort(arr,mn+1,r);
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
    QuickSort(arr,0,n-1);
    /*Resultados*/
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << duration << endl;
    return 0;
}