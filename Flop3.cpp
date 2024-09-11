#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // Para rand()
#include <algorithm>  // Para std::sort
#include <limits> // Para std::numeric_limits

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

// Função para o seletor de operações
// Função para o seletor de operações
void execute_operation(int operation, int size) {
    std::vector<int> array = generate_random_array(size);

    switch (operation) {
        case 1: {
            // 1. Acesso a um elemento
            auto start = std::chrono::high_resolution_clock::now();
            access_element(array, size / 2);  // Acessa o elemento do meio
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Acesso ao elemento (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;
            break;
        }
        case 2: {
            // 2. Soma dos elementos
            auto start = std::chrono::high_resolution_clock::now();
            sum_array(array);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Soma dos elementos (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;
            break;
        }
        case 3: {
            // 3. Busca binária
            std::sort(array.begin(), array.end());  // Garantir que o array esteja ordenado
            auto start = std::chrono::high_resolution_clock::now();
            binary_search(array, array[size / 2]);  // Busca o elemento do meio
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Busca binária (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;
            break;
        }
        case 4: {
            // 4. Selection sort
            auto start = std::chrono::high_resolution_clock::now();
            selection_sort(array);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Selection sort (tamanho " << size << "): " << duration.count() << " segundos" << std::endl;
            break;
        }
        case 5: {
            // 5. Multiplicação de matrizes
            std::vector<std::vector<int>> A(size, std::vector<int>(size));
            std::vector<std::vector<int>> B(size, std::vector<int>(size));
            // Inicializa as matrizes com valores aleatórios
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    A[i][j] = rand() % 100;
                    B[i][j] = rand() % 100;
                }
            }

            auto start = std::chrono::high_resolution_clock::now();
            multiply_matrices(A, B, size, size, size);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Multiplicação de matrizes (tamanho " << size << "x" << size << "): " << duration.count() << " segundos" << std::endl;
            break;
        }
        default: {
            std::cout << "Operação inválida!" << std::endl;
            break;
        }
    }
}


#include <iostream>

int main() {
    int operation, size;

    do {
        // Exibe o menu de operações
        std::cout << "Selecione a operação a ser executada:\n";
        std::cout << "1. Acesso a um elemento de um array\n";
        std::cout << "2. Soma dos elementos de um array\n";
        std::cout << "3. Busca binária\n";
        std::cout << "4. Ordenação selection sort\n";
        std::cout << "5. Multiplicação de matrizes\n";
        std::cout << "6. Para sair digite qualquer outra coisa\n";
        std::cout << "Digite o número da operação: ";
        std::cin >> operation;

        // Verifica se a entrada foi inválida
        if (std::cin.fail()) {
            std::cin.clear();  // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignora a entrada inválida
            std::cout << "Saindo do programa.\n";
            break;
        }

        // Se o usuário digitar um número entre 1 e 5, ele continua
        if (operation >= 1 && operation <= 5) {
            std::cout << "Escolha o tamanho da entrada (100, 1000, 10000, 100000, 1000000 para arrays; 100 ou 200 para matrizes): ";
            std::cin >> size;

            // Verifica se o tamanho inserido é válido
            if (std::cin.fail()) {
                std::cin.clear();  // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignora a entrada inválida
                std::cout << "Entrada inválida para o tamanho. Saindo do programa.\n";
                break;
            }

            // Executa a operação selecionada
            execute_operation(operation, size);
        } else {
            // Se o número digitado for diferente de 1 a 5, o programa sairá do loop
            std::cout << "Saindo do programa.\n";
            break;
        }
    } while (true);  // O loop continua até que uma operação inválida seja digitada

    return 0;
}
