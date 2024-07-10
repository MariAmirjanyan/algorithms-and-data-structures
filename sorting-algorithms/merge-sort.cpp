#include <iostream>

void merge(int* arr, int f, int m, int e){
    int f1 = f;
    int e1 = m;
    int f2 = m + 1;
    int e2 = e;
    int s = e - f + 1;
    int *tmp = new int[s];
    int ind = 0;
    while(f1 <= e1 && f2 <= e2){
        if(arr[f1] <= arr[f2]){
            tmp[ind] = arr[f1];
            ++f1;
        }
        else {
            tmp[ind] = arr[f2];
            ++f2;
        }
        ++ind;
    }
    while(f1 <= e1){
        tmp[ind] = arr[f1];
        ++f1;
        ++ind;
    }
    while(f2 <= e2){
        tmp[ind] = arr[f2];
        ++f2;
        ++ind;
    }
    for(int i = 0; i < s; ++i){
        arr[f + i] = tmp[i];
    }
    delete[]tmp;
}

void merge_sort(int* arr, int f, int e){
    if(e > f){
        int m = f + (e - f) / 2;
        merge_sort(arr, f, m);
        merge_sort(arr, m + 1, e);
        merge(arr, f, m, e);
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

    int first{};
    merge_sort(arr,first, size - 1);
    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}