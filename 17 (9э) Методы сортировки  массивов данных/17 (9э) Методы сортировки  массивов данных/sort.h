void quickSort(int *array, int left, int right) {
    int pivot; // разрешающий элемент
    int l_hold = left; //левая граница
    int r_hold = right; // правая граница
    
    pivot = array[left];
    while (left < right) { // пока границы не сомкнутся
    
        while ((array[right] >= pivot) && (left < right))
            right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
        
        if (left != right) { // если границы не сомкнулись
            array[left] = array[right]; // перемещаем элемент [right] на место разрешающего
            left++; // сдвигаем левую границу вправо
        }
        
        while ((array[left] <= pivot) && (left < right))
            left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
        
        if (left != right) { // если границы не сомкнулись
            array[right] = array[left]; // перемещаем элемент [left] на место [right]
            right--; // сдвигаем правую границу вправо
        }
    }
    
    array[left] = pivot; // ставим разрешающий элемент на место
    pivot = left;
    left = l_hold;
    right = r_hold;
    
    if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
        quickSort(array, left, pivot - 1);
    if (right > pivot)
        quickSort(array, pivot + 1, right);
}


// Для сортировки подсчётом
void countingSort(int *array, int size) {
    int max = array[0], min = array[0];
    
    for (int i = 0; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    
    //Создаём массив и заполняем его нулями
    int* c = new int[max + 1 - min];
    for (int i = 0; i < max + 1 - min; i++) c[i] = 0;

    
    // Последовательно читаем элементы входного массива A, для каждого A[i] увеличиваем C[A[i]] на единицу
    for (int i = 0; i < size; i++) c[array[i] - min] = c[array[i] - min] + 1;
    
    int i = 0;
    for (int j = min; j < max + 1; j++) {
        while (c[j - min] != 0) {
            array[i] = j;
            c[j - min]--;
            i++;
        }
    }
}
