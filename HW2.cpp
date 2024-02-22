#include <iostream>
#include <chrono>
#include <fstream>
#include <random>

std::random_device rd;
std::mt19937 rng(rd());

// иницилизируем как глобальные значения, чтобы не привести к переполнению стека
const int kSize = 1000; // кол-во элементов массива
long long array[kSize] = {};
long long arrayQuickSort[kSize] = {};
long long arrayBubbleSort[kSize] = {};
long long arrayInsertionSort[kSize] = {};

template <typename T>
T GetRandomInRange(const T min, const T max)
{
    std::uniform_int_distribution<int> uid(min,max);
    return uid(rng);
}

template <typename T, typename Arr>
void FillArray(Arr * array, const T size, const T min, const T max) {
    for (int i = 0; i < size; i++) {
        array[i] = GetRandomInRange(min, max);
    }
}

template <typename T, typename Arr>
const void PrintArray(const Arr * array, const T size) {
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

// 1. Quick Sort

template <typename T, typename Arr>
T Partition(Arr  * array, const T low, const T high) {

    int i = low - 1;
    int j = high + 1;
    int pivot = array[low];

    while (true) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        std::swap(array[i], array[j]);
    }
}

template <typename T, typename Arr>
T PartionRandom(Arr * array, const T low, const T high) {
    int random = GetRandomInRange(low, high);
    
    std::swap(array[random], array[low]);

    return Partition(array, low, high);
}

template <typename T, typename Arr>
void QuickSort(Arr * array, const T low, const T high)
{
    if (low < high) {
        int pivot = PartionRandom(array, low, high);

        QuickSort(array, low, pivot);
        QuickSort(array, pivot + 1, high);
    }
}

// 2. Bubble Sort

template <typename T, typename Arr>
void BubbleSort(Arr * array, const T size) {
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
            {
                std::swap(array[j], array[j + 1]);
            }
    }
}

// 3. Insertion Sort

template <typename T, typename Arr>
void InsertionSort(Arr * array, const T size) {
    for (int i = 1; i < size; i++)
    {
        int tmp = array[i];
        int q = i - 1;

        while ((q >= 0) && (array[q] > tmp))
        {
            array[q + 1] = array[q];
            q--;
        }
        array[q + 1] = tmp;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    const int kMinValue = 0;
    const int kMaxValue = 32767; // макс. значение rand(); используем для ф-ии с равномер. распределением для заполнения массива
    
    // Заполняем массив
    FillArray(array, kSize, kMinValue, kMaxValue);

    // Копии массива для сортировок
    memcpy(arrayQuickSort, array, kSize * sizeof(long long));
    memcpy(arrayBubbleSort, array, kSize * sizeof(long long));
    memcpy(arrayInsertionSort, array, kSize * sizeof(long long));

    // Кол-во элементов
    std::cout << "Кол-во элементов: " << kSize << std::endl;

    // Выводим неупорядоченный массив
    std::cout << "Первоначальный массив" << std::endl;
    PrintArray(array, kSize);

    // Поток для записи результатов в файл
    std::ofstream out("results.txt", std::ios::app);

    // 1. Быстрая сортировка 
    std::cout << std::endl << "1. Быстрая сортировка" << std::endl;

    auto startTimeQuickSort = std::chrono::steady_clock::now();
    QuickSort(arrayQuickSort, 0, kSize - 1);
    auto endTimeQuickSort = std::chrono::steady_clock::now();

    auto runtimeQuickSort = std::chrono::duration<double>(endTimeQuickSort - startTimeQuickSort).count();

    // Быстрая сортировка. Отсортированный массив
    std::cout << std::endl;
    std::cout << "Быстрая сортировка. Остсортированный массив" << std::endl;
    PrintArray(arrayQuickSort, kSize);

    std::cout << std::endl;
    std::cout << "Быстрая сортировка. RuntimeExecute: " << runtimeQuickSort << " sec" << std::endl;
    out << runtimeQuickSort << std::endl;

    // 2. Сортировка пузырьком
    std::cout << std::endl << "2. Сортировка пузырьком" << std::endl;

    auto startTimeBubbleSort = std::chrono::steady_clock::now();
    BubbleSort(arrayBubbleSort, kSize);
    auto endTimeBubbleSort = std::chrono::steady_clock::now();

    auto runtimeBubbleSort = std::chrono::duration<double>(endTimeBubbleSort - startTimeBubbleSort).count();

    // Сортировка пузырьком. Отсортированный массив
    std::cout << std::endl;
    std::cout << "Сортировка пузырьком. Остсортированный массив" << std::endl;
    PrintArray(arrayBubbleSort, kSize);

    std::cout << std::endl;
    std::cout << "Сортировка пузырьком. RuntimeExecute: " << runtimeBubbleSort << " sec" << std::endl;
    out << runtimeBubbleSort << std::endl;

    // 3. Сортировка вставкой
    std::cout << std::endl << "3. Сортировка вставкой" << std::endl;

    auto startTimeInsertionSort = std::chrono::steady_clock::now();
    InsertionSort(arrayInsertionSort, kSize);
    auto endTimeInsertionSort = std::chrono::steady_clock::now();

    auto runtimeInsertionSort = std::chrono::duration<double>(endTimeInsertionSort - startTimeInsertionSort).count();

    // Сортировка вставкой. Отсортированный массив
    std::cout << std::endl;
    std::cout << "Сортировка вставкой. Остсортированный массив" << std::endl;
    PrintArray(arrayInsertionSort, kSize);

    std::cout << std::endl;
    std::cout << "Сортировка вставкой. RuntimeExecute: " << runtimeInsertionSort << " sec" << std::endl;
    out << runtimeInsertionSort << std::endl;

    // Закрываем запись в файл
    out.close();

    return 0;
}
