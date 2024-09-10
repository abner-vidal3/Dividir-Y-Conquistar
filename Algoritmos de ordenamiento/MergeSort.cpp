#include <bits/stdc++.h>
using namespace std;
vector<int> MergeSort(vector<int> & arr, int l, int r){
    if (l == r) 
        return {arr[l]};
    int mid = (l+r)/2;
    /*Obtenemos los arreglos ordenados de cada hijo del árbol*/
    vector<int> izq = MergeSort(arr,l,mid);
    vector<int> der = MergeSort(arr,mid+1,r);
    vector<int> res;
    /*Dependiendo de quien tenga disponible números elegimos el menor de ambos arreglos izq y der*/
    int izq_i = 0, der_i = 0, izq_n = izq.size(), der_n = der.size();
    while (der_i < der_n && izq_i < izq_n){
        if (der[der_i] < izq[izq_i]){
            res.push_back(der[der_i]);
            der_i++;
        } else {
            res.push_back(izq[izq_i]);
            izq_i++;
        }
    }
    while (der_i < der_n){
        res.push_back(der[der_i]);
        der_i++;
    }
    while (izq_i < izq_n){
        res.push_back(izq[izq_i]);
        izq_i++;
    }
    return res;
}
int main(){
    /*Lectura del input*/
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    /*Ordenamiento*/
    vector<int> res = MergeSort(arr, 0, n-1);
    /*Resultados*/
    for (int c : res)
        cout << c << " ";
    cout << endl;
    return 0;
}