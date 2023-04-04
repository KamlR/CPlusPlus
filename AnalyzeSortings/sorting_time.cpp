#include "sorting_time.h"
#include <iostream>

// Методы сортировок, которые измеряются по времени
// В каждом методе есть счётчик, который потом выводится в результат
void selectionSort(std::vector<int> &nums, int n) {
    int mini;
    for (int i = 0; i < n - 1; ++i) {
        mini = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[mini]) {
                mini = j;
            }
        }
        if (mini != i) {
            int temper = nums[i];
            nums[i] = nums[mini];
            nums[mini] = temper;
        }
    }
}
void bubbleSort(std::vector<int> &nums, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                int temper = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temper;
            }
        }
    }
}
void bubbleSortIverson1(std::vector<int> &nums, int n) {
    bool flag;
    for (int i = 0; i < n; ++i) {
        flag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                int temper = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temper;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}
void bubbleSortIverson2(std::vector<int> &nums, int n) {
    int index = n - 1;
    int temper_index;
    for (int i = 0; i < n; ++i) {
        temper_index = -1;
        for (int j = 0; j < index; ++j) {
            if (nums[j] > nums[j + 1]) {
                int temper = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temper;
                temper_index = j;
            }
        }
        if (temper_index == -1) {
            break;
        }
        index = temper_index;
    }
}
void insertionSort(std::vector<int> &nums, int n) {
    int current_num, j;
    for (int i = 1; i < n; ++i) {
        current_num = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > current_num) {
            nums[j + 1] = nums[j];
            j -= 1;
        }
        nums[j + 1] = current_num;
    }
}
int binarySearch(int element, int left, int right, std::vector<int> &nums) {
    int middle;
    while (right - left > 1) {
        middle = left + (right - left) / 2;
        if (nums[middle] < element) {
            left = middle;
        } else {
            right = middle;
        }
    }
    return right;
}
void binaryInsertionSort(std::vector<int> &nums, int n) {
    int current_num, j;
    for (int i = 1; i < n; ++i) {
        current_num = nums[i];
        j = i - 1;
        int index_loc = binarySearch(current_num, -1, j + 1, nums);
        while (j >= index_loc) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = current_num;
    }
}
void countSort(std::vector<int> &a, int n) {
    std::vector<int> c(4101);
    for (int i = 0; i < n; ++i) {
        c[a[i]] += 1;
    }
    for (size_t i = 1; i < c.size(); ++i) {
        c[i] = c[i] + c[i - 1];
    }
    std::vector<int> b(n);
    for (int i = n - 1; i >= 0; --i) {
        c[a[i]]--;
        b[c[a[i]]] = a[i];
    }
}

void countingSort(std::vector<int> &nums, int n, int byte) {
    std::vector<int> result(n);
    std::vector<int> count_digits(10);
    for (int i = 0; i < n; ++i) {
        count_digits[(nums[i] / byte) % 10] += 1;
    }
    for (int i = 1; i < 10; ++i) {
        count_digits[i] += count_digits[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        result[count_digits[(nums[i] / byte) % 10] - 1] = nums[i];
        count_digits[(nums[i] / byte) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        nums[i] = result[i];
    }
}
void radixSort(std::vector<int> &nums, int n) {
    for (int byte = 1; 4100 / byte > 0; byte *= 10) {
        countingSort(nums, n, byte);
    }
}

void merge(std::vector<int> &nums, int left, int middle, int right) {
    int sizeFirst = middle - left + 1;
    int sizeSecond = right - middle;
    std::vector<int> temperLeft(sizeFirst);
    std::vector<int> temperRight(sizeSecond);
    for (auto i = 0; i < sizeFirst; i++) {
        temperLeft[i] = nums[left + i];
    }
    for (auto j = 0; j < sizeSecond; j++) {
        temperRight[j] = nums[middle + 1 + j];
    }
    int indexFirst = 0;
    int indexSecond = 0;
    int indexMerge = left;
    while (indexFirst < sizeFirst && indexSecond < sizeSecond) {
        if (temperLeft[indexFirst] <= temperRight[indexSecond]) {
            nums[indexMerge] = temperLeft[indexFirst];
            indexFirst++;
        } else {
            nums[indexMerge] = temperRight[indexSecond];
            indexSecond++;
        }
        indexMerge++;
    }
    while (indexFirst < sizeFirst) {
        nums[indexMerge] = temperLeft[indexFirst];
        indexFirst++;
        indexMerge++;
    }
    while (indexSecond < sizeSecond) {
        nums[indexMerge] = temperRight[indexSecond];
        indexSecond++;
        indexMerge++;
    }
}
void mergeSort(std::vector<int> &nums, int begin, int end) {
    if (begin >= end) {
        return;
    }
    int middle = begin + (end - begin) / 2;
    mergeSort(nums, begin, middle);
    mergeSort(nums, middle + 1, end);
    merge(nums, begin, middle, end);
}

void mergeSortS(std::vector<int> &nums, int n) {
    mergeSort(nums, 0, n - 1);
}

void quickSort(std::vector<int> &array, int low, int high) {
    if (high - low <= 1) {
        return;
    }
    int i = low;
    int j = high - 1;
    int pivot = array[i];
    int temp;

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (low < j) {
        quickSort(array, low, j + 1);
    }
    if (i < high) {
        quickSort(array, i, high);
    }
}
void quickSortQ(std::vector<int> &nums, int n) {
    quickSort(nums, 0, n - 1);
}

void buildHeap(int index_maxi, int heap_size, std::vector<int> &nums) {
    int left = index_maxi * 2 + 1;
    int right = index_maxi * 2 + 2;
    int new_maxi = index_maxi;
    if (left < heap_size && nums[left] > nums[index_maxi]) {
        new_maxi = left;
    }
    if (right < heap_size && nums[right] > nums[new_maxi]) {
        new_maxi = right;
    }
    if (new_maxi != index_maxi) {
        std::swap(nums[index_maxi], nums[new_maxi]);
        buildHeap(new_maxi, heap_size, nums);
    }
}
void heapSort(std::vector<int> &nums, int n) {
    for (int i = (n / 2) - 1; i >= 0; --i) {
        buildHeap(i, n, nums);
    }
    for (int i = n - 1; i >= 0; --i) {
        std::swap(nums[0], nums[i]);
        buildHeap(0, i, nums);
    }
}
void shellSort(std::vector<int> &nums, int n) {
    for (int i = n / 2; i > 0; i /= 2) {
        for (int j = i; j < n; ++j) {
            int temp = nums[j];
            int k;
            for (k = j; k >= i && nums[k - i] > temp; k -= i) {
                nums[k] = nums[k - i];
            }
            nums[k] = temp;
        }
    }
}
void cyuSequenceSort(std::vector<int> &nums, int n) {
    std::vector<int> seq{1, 4, 10, 23, 57, 132, 301, 701, 1750};
    for (int i = 8; i >= 0; --i) {
        for (int j = seq[i]; j < n; ++j) {
            int temp = nums[j];
            int k;
            for (k = j; k >= seq[i] && nums[k - seq[i]] > temp; k -= seq[i]) {
                nums[k] = nums[k - seq[i]];
            }
            nums[k] = temp;
        }
    }
}
