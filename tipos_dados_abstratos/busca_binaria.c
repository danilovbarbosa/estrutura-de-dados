/*
 * Henrique Felipe (GitHub: HenriqueIni)
 * https://www.blogcyberini.com/
 *
 * Código sob licença MIT
 */
#include <stdio.h>
#include <stdlib.h>
 
/*
 * Tenta encontra o elemento no array especificado (iterativamente). 
 * Complexidade no tempo: O(log n) 
 */
int binarySearchIterative(int a[], int size, int key) {
    int begin = 0;
    int end = size - 1;
    while (begin <= end) {
        int middle = (begin + end) / 2; //calcula o meio
        if (key == a[middle]) {
            //o elemento foi encontrado
            return middle;
        } else {
            if (key > a[middle]) {
                //a busca continuará no subarray à direira
                begin = middle + 1;
            } else {
                //a busca continuará no subarray à esquerda
                end = middle - 1;
            }
        }
    }
    //o elemento não está no array
    return -1;
}
/*
 * Tenta encontra o elemento no array especificado (recursivamente). 
 * Complexidade no tempo: O(log n) 
 */
int binarySearchRecursive(int a[], int begin, int end, int key) {
    if (begin <= end) {                    
        int middle = (begin + end) / 2; //calcula o meio
        if (key == a[middle]) {
            //o elemento foi encontrado
            return middle;
        } else {
            if (key > a[middle]) {
                //a busca continuará no subarray à direira
                return binarySearchRecursive(a, middle + 1, end, key);
            } else {
                //a busca continuará no subarray à esquerda
                return binarySearchRecursive(a, begin, middle - 1, key);
            }
        }
    } else {
        //o elemento não está no array
        return -1;
    }
}
/*
 * Função de testes
 */
int main() {
    int test[] = {1, 3, 4, 55, 104, 222, 229, 300};
    int n = sizeof(test)/sizeof(int);
    int key = 55;
    printf("%d\n%d\n", binarySearchRecursive(test, 0, n - 1, key), binarySearchIterative(test, n, key));
    return 0;
}
