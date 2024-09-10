int binary_search(int array[], int n, int x) {
    int low = 0, high = n - 1;

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
