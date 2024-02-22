import matplotlib.pyplot as plt

file = open('results.txt', 'r')

arrayNumber = [100, 300, 500, 1000, 2000, 3000, 5000, 8000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000]
arrayQuickSort = []
arrayBubbleSort = []
arrayInsertionSort = []

arrayResults = file.read().split('\n')

for line in range(0, len(arrayResults), 3):
    arrayQuickSort.append(float(arrayResults[line]))

for line in range(1, len(arrayResults), 3):
    arrayBubbleSort.append(float(arrayResults[line]))

for line in range(2, len(arrayResults), 3):
    arrayInsertionSort.append(float(arrayResults[line]))

# Графики целиком
plt.plot(arrayNumber, arrayQuickSort, color='green', marker='o', markersize=3, label='Quick Sort')
plt.plot(arrayNumber, arrayBubbleSort, color='red', marker='o', markersize=3, label='Bubble Sort')
plt.plot(arrayNumber, arrayInsertionSort, color='pink', marker='o', markersize=3, label='Insertion Sort')

plt.xlabel('Количество элементов')
plt.ylabel('Время сортировки, сек')
plt.title('Графики целиком')
plt.legend(title='Вид сортировки:')
plt.show()

# Графики на малых значениях
plt.plot(arrayNumber[0:9], arrayQuickSort[0:9], color='green', marker='o', markersize=3, label='Quick Sort')
plt.plot( arrayNumber[0:9], arrayBubbleSort[0:9], color='red', marker='o', markersize=3, label='Bubble Sort')
plt.plot(arrayNumber[0:9], arrayInsertionSort[0:9], color='pink', marker='o', markersize=3, label='Insertion Sort')

plt.xlabel('Количество элементов')
plt.ylabel('Время сортировки, сек')
plt.title('Графики на малых значениях')
plt.legend(title='Вид сортировки:')
plt.show()

# Графики на больших значениях
plt.plot(arrayNumber[9:], arrayQuickSort[9:], color='green', marker='o', markersize=3, label='Quick Sort')
plt.plot( arrayNumber[9:], arrayBubbleSort[9:], color='red', marker='o', markersize=3, label='Bubble Sort')
plt.plot(arrayNumber[9:], arrayInsertionSort[9:], color='pink', marker='o', markersize=3, label='Insertion Sort')

plt.xlabel('Количество элементов')
plt.ylabel('Время сортировки, сек')
plt.title('Графики на больших значениях')
plt.legend(title='Вид сортировки:')
plt.show()
