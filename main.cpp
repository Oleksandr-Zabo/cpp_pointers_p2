#include <iostream>
#include <ctime>
using namespace std;

enum Choice_odd_even {
    ODD = 1,
    EVEN = 2
};

template<typename T>
bool pointer_is_null(T* pointer)
{
    return (pointer == nullptr);
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
        arr[i] = rand() % 5;
    }
    return arr;
}

template<typename T>
void print_array(T* arr, int* size)
{
    if (pointer_is_null(arr) || pointer_is_null(size))
    {
        cout << "Pointer is null" << endl;
        return;
    }
    for (int i = 0; i < *size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
void new_arr(int*& M, T*& A, Choice_odd_even action = Choice_odd_even::EVEN)
{
    if (pointer_is_null(M) || pointer_is_null(A))
    {
        cout << "Pointer is null" << endl;
        return;
    }

    T* arr = new T[*M];
    int size_1 = 0;

    switch (action)
    {
    case ODD:
        for (int i = 0; i < *M; i++)
        {
            if (A[i] % 2 != 0)
            {
                arr[size_1] = A[i];
                size_1++;
            }
        }
        break;

    case EVEN:
        for (int i = 0; i < *M; i++)
        {
            if (A[i] % 2 == 0)
            {
                arr[size_1] = A[i];
                size_1++;
            }
        }
        break;
    }

    delete[] A;
    A = arr;
    *M = size_1;
}

int main()
{
    srand(time(0));

    int* M = new int;
    cout << "Enter size A (M): ";
    cin >> *M;

    int* A = init_array<int>(M);
    cout << "Original array: ";
    print_array<int>(A, M);

    int* action = new int;
    do
    {
        cout << "What type you want to delete? (Even-1, Odd-2): ";
        cin >> *action;
    } while (*action < 1 || *action > 2);

    new_arr(M, A, static_cast<Choice_odd_even>(*action));
    cout << "Modified array: ";
    print_array<int>(A, M);

    delete M;
    delete[] A;

    system("pause");
    return 0;
}
