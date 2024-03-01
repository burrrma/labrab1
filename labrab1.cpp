
#include <iostream>
#include <vector>

//quick sort
//сначала функция для разделения массива на две части
template <typename T>
int partition(std::vector<T>& arr, int left, int right) {
    T pivot = arr[left + rand() % (right - left + 1)];
    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        T k = arr[i];
        arr[i] = arr[j];
        arr[j] = k;
    }
}
//сама функция quicksort
template <typename T>
void quicksort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        T pivot = partition(arr, left, right);
        quicksort(arr, left, pivot);
        quicksort(arr, pivot + 1, right);
    }
}



//bubble sort
template <typename T>
void bubble(std::vector <T>& arr, int dlina) {
    for (int i = 0; i < dlina; i++) {
        for (int j = 0; j < dlina - 1; j++) {
            if (arr[j] <= arr[j + 1]) { //ничего не делаем, если элемент i меньше элемента  i + 1
                continue;
            }
            if (arr[j] > arr[j + 1]) { //меняем элементы местами в случае, если j+1 < j
                T k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
}



// поиск наибольшего элемента - для сортировки выбором
template <typename T>
int find_max(std::vector <T>& arr, int dl) {
    T max = 0;
    int max_ind = 0;
    for (int i = 0; i < dl; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_ind = i; //для дальнейших действий нам нужен именно индекс
        }
    }
    return max_ind;
};




//selection (max) sort
template <typename T>
void selection(std::vector <T>& arr, int dlina) {
    T max = 0;
    int dl = dlina;
    for (int i = 1; i < dlina; i++) {
        max = find_max(arr, dl); //ищем максимальный элемент, каждый раз dl меньше на 1

        T k = arr[max]; //swap последний элемент в неотсортированном участке массива и наибольший элемент
        arr[max] = arr[dlina - i];
        arr[dlina - i] = k;
        dl--;
    }

}



int main() {
    int dlina;
    std::cout << "Введите длину массива: ";
    std::cin >> dlina;

    std::vector <int> arr = {};
    std::vector <int> arr_2 = {};
    std::vector <int> arr_3 = {};

    std::cout << "Массив для bubble sort: " << std::endl;
    for (int i = 0; i < dlina; i++) {
        int a = rand() % 90 + 1; //заполняем массив числами от 1 до 90
        arr.push_back(a);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив для selection sort: " << std::endl;
    for (int i = 0; i < dlina; i++) {
        int a = rand() % 90 + 1; //заполняем массив числами от 1 до 90
        arr_2.push_back(a);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Массив для quick sort: " << std::endl;
    for (int i = 0; i < dlina; i++) {
        int a = rand() % 90 + 1; //заполняем массив числами от 1 до 90
        arr_3.push_back(a);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl << "bubble sort: ";
    bubble(arr, dlina);
    for (int k = 0; k < dlina; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << std::endl << "selection sort: ";
    selection(arr_2, dlina);
    for (int k = 0; k < dlina; k++) {
        std::cout << arr_2[k] << " ";
    }
    std::cout << std::endl << "quick sort: ";
    quicksort(arr_3, 0, dlina - 1);
    for (int k = 0; k < dlina; k++) {
        std::cout << arr_3[k] << " ";
    }


}