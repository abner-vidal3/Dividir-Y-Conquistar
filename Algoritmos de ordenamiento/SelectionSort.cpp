#include <bits/stdc++.h>
using namespace std;
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
    SelectionSort(arr);
    /*Resultados*/
    for (int c : arr)
        cout << c << " ";
    cout << endl;
    return 0;
}