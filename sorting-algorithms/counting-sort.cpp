#include <iostream>

int maxin(int* arr, int n){
    int max = arr[0];
    for(int i = 0; i < n; ++i){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void counting_sort(int* arr, int n){
    int max = maxin(arr, n);
    int* tmp = new int[max + 1];
    int* res = new int[n];
    for(int i = 0; i < n; ++i){
        ++tmp[arr[i]];
    }
    for(int i = 1; i < max + 1; ++i){
        tmp[i] += tmp[i - 1];
    }
    for(int i = 0; i < n; ++i){
        res[tmp[arr[i]] - 1] = arr[i];
        --tmp[arr[i]];
    }
    for(int i = 0; i < n; ++i){
        arr[i] = res[i];
    }
    delete[]tmp;
    delete[]res;
}

int main(){
    const int size = 8;
    int arr[size];
    for(int i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    
    std::cout << "Original array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    counting_sort(arr, size);
    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}