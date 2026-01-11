#include <iostream>
#include <vector>

using namespace std;

// Función de búsqueda binaria estandar

int busquedaBinaria(vector<int>& v, int dato){
    
    int min = 0; // T(n) += 1
    int max = v.size()-1; // T(n) += 1

    // el rango [min, max] se reduce a la mitad en cada iteración
    // el ciclo se ejecuta n veces por ello n aproxima a log2(n)
    while(min<= max){   // se ejecuta T(log n) veces o sea T(n) += 1*log2 n

        //caluculo de medio
        int m = min + (max - min)/2; // T(n) += 1*log2 n

        //comparacion
        if(dato == v[m]){ 

            return m; // T(n) += 1

        }
        else if(dato > v[m]){ 

            // se descarta la mitad izquierda
            min = m + 1; // T(n) += 1*log2 n

        }
        else{

            // se descarta la mitad derecha
            max = m - 1;// T(n) += 1*log2 n
        }

    }
    // si no se encuentra el elemento
    return -1; // T(n) += 1

}
// ----------Análisis de complejidad general------------
// sumando todas las T(n) tenemos:
// T(n) = 3 + 4*log2 n
// Por lo tanto, la complejidad asintotica es "O(log n)"

// -------------mejor caso--------------
// el elemento está en la mitad del vector por ello no depende de n
// t(n) = 3 
// complejidad asintotica es "O(1)"

// -------------peor caso--------------
// el elemento no está en el vector o está en un extremo
// t(n) = 3 + 4*log2 n
// complejidad asintotica es "O(log n)"









int main() {
    vector<int> v = {1,3,5,7,9,11,13,15,17,19};// Vector ordenado de ejemplo
    int dato = 1; // Elemento a buscar

    int resultado = busquedaBinaria(v, dato); // Llamada a la función de búsqueda binaria
    
    if(resultado != -1){ // Elemento encontrado
        cout << "Elemento encontrado en el índice: " << resultado << endl;
    }else{// Elemento no encontrado
        cout << "Elemento no encontrado." << endl;
    }
    return 0;
}