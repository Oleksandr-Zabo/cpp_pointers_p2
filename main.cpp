#include <iostream>
#include <ctime>
using namespace std;



enum PointerError
{
    IS_NULL,
    IS_NOT_NULL,
    DEFAULT
};

enum PointerType
{
    ARRAY,
    POINTER
};

template<typename T>
bool pointer_is_null(T* pointer)
{
    return (pointer == nullptr) ? true : false;
}




template<typename T>
T* init_array(int*& size)
{
    if (size == nullptr)
    {
        size = new int{ 10 };
    }
    T* arr = new T[*size];
    for (int i = 0; i < *size; i++)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}

template<typename T>
PointerError print_array(T* arr, int* size)
{
    if (pointer_is_null(arr) || pointer_is_null(size))
    {
        return IS_NULL;
    }
    for (int i = 0; i < *size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}

template<typename T>
PointerError delete_pointer(T*& pointer, PointerType pointer_type = PointerType::POINTER)
{
    if (pointer_is_null(pointer))
    {
        return IS_NULL;
    }
    switch (pointer_type)
    {
    case PointerType::ARRAY:
    {
        delete[] pointer;
    }break;
    case PointerType::POINTER:
    {
        delete pointer;
    }break;
    }
    pointer = nullptr;
    return PointerError::DEFAULT;
}

void check_error(PointerError error)
{
    switch (error)
    {
    case PointerError::IS_NULL:
    {
        cout << "Pointer is null" << endl;
    }break;
    case PointerError::IS_NOT_NULL:
    {
        cout << "Pointer is not null" << endl;
    }break;
    }
}

template<typename T>
PointerError check_ptr(T*& pointer)
{
    if (pointer_is_null(pointer))
    {
        return IS_NULL;
    }
    return PointerError::DEFAULT;
}

PointerError size_third(int* &size, int* M, int* N) {
    if (pointer_is_null(M))
    {
        return IS_NULL;
    }
    if (pointer_is_null(N))
    {
        return IS_NULL;
    }
    *size = *M + *N;
}

template<typename T>
T* init_third_array(int* &size, int* M, int* N, int* A, int* B)
{
    check_ptr(A);
    check_ptr(B);
    size_third(size, M, N);
    T* arr = new T[*size];
    for (int i = 0; i < *M; i++)
    {
        arr[i] = A[i];
    }
    for (int i = 0; i < *N; i++)
    {
        arr[i + *M] = B[i];
    }
    return arr;
   
}


int main()
{
    srand(time(0));
    PointerError error = PointerError::DEFAULT;

    int* M = new int;
    cout << "Enter size A (M): ";
    cin >> *M;
    int* A = init_array<int>(M);
    check_error(print_array<int>(A, M));

    int* N = new int;
    cout << "Enter size B (N): ";
    cin >> *N;
    int* B = init_array<int>(N);
    check_error(print_array<int>(B, N));

    int* size = new int;
    
    cout << "The third aaray: ";
    int* C = init_third_array<int>(size, M, N, A, B);
    check_error(print_array<int>(C, size));


    check_error(delete_pointer(M));
    check_error(delete_pointer(A, PointerType::ARRAY));

    check_error(delete_pointer(N));
    check_error(delete_pointer(B, PointerType::ARRAY));

    check_error(delete_pointer(size));
    check_error(delete_pointer(C, PointerType::ARRAY));

    system("pause");
    return 0;
}