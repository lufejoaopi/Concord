#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // Para rand()
#include <algorithm>  // Para std::sort

// Função para gerar um array aleatório
std::vector<int> generate_random_array(int size) {
    std::vector<int> array(size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;  // Gera números aleatórios entre 0 e 99
    }
    return array;
}

// 1. Acesso a um elemento de um array
int access_element(const std::vector<int>& array, int index) {
    return array[index];
}

// 2. Soma dos elementos de um array
long long sum_array(const std::vector<int>& array) {
    long long total = 0;
    for (int element : array) {
        total += element;
    }
    return total;
}

// 3. Busca binária
int binary_search(const std::vector<int>& array, int x) {
    int low = 0, high = array.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (array[mid] == x)
            return mid;
        else if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // Elemento não encontrado
}

// 4. Selection sort
void selection_sort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx])
                min_idx = j;
        }
        std::swap(array[i], array[min_idx]);
    }
}

// 5. Multiplicação de matrizes
std::vector<std::vector<int>> multiply_matrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, int m, int n, int p) {
    std::vector<std::vector<int>> result(m, std::vector<int>(p, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

int main() {
    // Tamanhos para testar
    std::vector<int> sizes = {100, 1000, 10000, 100000, 1000000};

    for (int size : sizes) {
        std::vector<int> array = generate_random_array(size);

        // 1. Acesso a um elemento de um array
        auto start = std::chrono::high_resolution_clock::now();
        access_element(array, size / 2);  // Acessa o elemento do meio
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Acesso ao elemento (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;

        // 2. Soma dos elementos de um array
        start = std::chrono::high_resolution_clock::now();
        sum_array(array);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Soma dos elementos (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;

        // 3. Busca binária (garantir que o array esteja ordenado)
        std::sort(array.begin(), array.end());
        start = std::chrono::high_resolution_clock::now();
        binary_search(array, array[size / 2]);  // Busca o elemento do meio
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Busca binária (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;

        // 4. Ordenação Selection Sort
        std::vector<int> array_copy = array;  // Fazer uma cópia para não usar o array já ordenado
        start = std::chrono::high_resolution_clock::now();
        selection_sort(array_copy);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "Selection sort (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;
    }

    // Testar multiplicação de matrizes com tamanhos específicos
    std::vector<int> matrix_sizes = {100, 200};  // Tamanhos menores para multiplicação de matrizes
    for (int size : matrix_sizes) {
        std::vector<std::vector<int>> A(size, std::vector<int>(size));
        std::vector<std::vector<int>> B(size, std::vector<int>(size));
        
        // Inicializa as matrizes com valores aleatórios
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                A[i][j] = rand() % 100;
                B[i][j] = rand() % 100;
            }
        }

        // Medir o tempo de execução da multiplicação de matrizes
        auto start = std::chrono::high_resolution_clock::now();
        multiply_matrices(A, B, size, size, size);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Multiplicação de matrizes (tamanho " << size << "x" << size << "): " << duration.count() << " segundos" << std::endl;
    }

    return 0;
}

