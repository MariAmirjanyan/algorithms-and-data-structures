#include <iostream>

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void bubble_sort(int* arr, int n){
    for(int i = 0; i < n - 1; ++i){
        bool flag = false;
        for(int j = 0; j < n - 1 - i; ++j){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
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

    bubble_sort(arr, size);
    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}