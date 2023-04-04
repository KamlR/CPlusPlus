#include "sorting_operations.h"
#include <iostream>
// Методы сортировок, которые измеряются по количеству элементарных операций
// В каждом методе есть счётчик, который потом выводится в результат

uint64_t selectionSortOp(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    int mini;
    for (int i = 0; i < n - 1; ++i) {
        mini = i;
        count += 4;
        for (int j = i + 1; j < n; ++j) {
            count += 3;
            count += 3;
            if (nums[j] < nums[mini]) {
                mini = j;
                count += 1;
            }
        }
        count += 1;
        if (mini != i) {
            int temper = nums[i];
            count += 2;
            nums[i] = nums[mini];
            count += 2;
            nums[mini] = temper;
            count += 2;
        }
    }
    return count;
}
uint64_t bubbleSortOp(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    for (int i = 0; i < n; ++i) {
        count += 3;
        for (int j = 0; j < n - i - 1; ++j) {
            count += 3;
            count += 3;
            if (nums[j] > nums[j + 1]) {
                int temper = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temper;
                count += 6;
            }
        }
    }
    return count;
}
uint64_t bubbleSortIverson1Op(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    bool flag;
    for (int i = 0; i < n; ++i) {
        count += 3;
        flag = false;
        count++;
        for (int j = 0; j < n - i - 1; ++j) {
            count += 3;
            count += 3;
            if (nums[j] > nums[j + 1]) {
                int temper = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temper;
                flag = true;
                count += 7;
            }
        }
        count += 1;
        if (!flag) {
            break;
        }
    }
    return count;
}
uint64_t bubbleSortIverson2Op(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    int index = n - 1;
    count += 2;
    int temper_index;
    for (int i = 0; i < n; ++i) {
        count += 3;
        temper_index = -1;
        count++;
        for (int j = 0; j < index; ++j) {
            count += 3;
            count += 3;
            if (nums[j] > nums[j + 1]) {
                int temper = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temper;
                temper_index = j;
                count += 5;
            }
        }
        count += 1;
        if (temper_index == -1) {
            break;
        }
        count += 1;
        index = temper_index;
    }
    return count;
}
uint64_t insertionSortOp(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    int current_num, j;
    for (int i = 1; i < n; ++i) {
        count += 3;
        current_num = nums[i];
        count++;
        j = i - 1;
        count += 2;
        count += 5;
        while (j >= 0 && nums[j] > current_num) {
            nums[j + 1] = nums[j];
            j -= 1;
            count += 4;
            count += 5;
        }
        nums[j + 1] = current_num;
        count += 2;
    }
    return count;
}

std::pair<int, uint64_t> binarySearch2(int element, int left, int right, std::vector<int> &nums) {
    uint64_t count = 0;
    int middle;
    count += 2;
    while (right - left > 1) {
        count += 2;
        middle = left + (right - left) / 2;
        count += 4;
        count += 2;
        if (nums[middle] < element) {
            left = middle;
            count++;
        } else {
            count++;
            right = middle;
        }
    }
    return std::make_pair(right, count);
}
uint64_t binaryInsertionSortOp(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    int current_num, j;
    for (int i = 1; i < n; ++i) {
        count += 3;
        current_num = nums[i];
        count += 2;
        j = i - 1;
        count += 2;
        int index_loc = binarySearch2(current_num, -1, j + 1, nums).first;
        count++;
        count += binarySearch2(current_num, -1, j + 1, nums).second;
        count++;
        while (j >= index_loc) {
            count++;
            count += 3;
            nums[j + 1] = nums[j];
            j--;
            count += 2;
        }
        nums[j + 1] = current_num;
        count += 2;
    }
    return count;
}
uint64_t countSortOp(std::vector<int> &a, int n) {
    uint64_t count = 0;
    count += 4101;
    std::vector<int> c(4101);
    for (int i = 0; i < n; ++i) {
        count += 3;
        c[a[i]] += 1;
        count += 4;
    }
    for (int i = 1; i < c.size(); ++i) {
        count += 3;
        c[i] = c[i] + c[i - 1];
        count += 5;
    }
    std::vector<int> b(n);
    for (int i = n - 1; i >= 0; --i) {
        count += 3;
        c[a[i]]--;
        count += 4;
        b[c[a[i]]] = a[i];
        count += 5;
    }
    return count;
}

uint64_t countingSort2(std::vector<int> &nums, int n, int byte) {
    uint64_t count = 0;
    count += n;
    count += 10;
    std::vector<int> result(n);
    std::vector<int> count_digits(10);
    for (int i = 0; i < n; ++i) {
        count += 3;
        count_digits[(nums[i] / byte) % 10] += 1;
        count += 5;
    }
    for (int i = 1; i < 10; ++i) {
        count += 3;
        count_digits[i] += count_digits[i - 1];
        count += 4;
    }
    for (int i = n - 1; i >= 0; i--) {
        count += 3;
        result[count_digits[(nums[i] / byte) % 10] - 1] = nums[i];
        count += 5;
        count_digits[(nums[i] / byte) % 10]--;
        count += 5;
    }
    for (int i = 0; i < n; i++) {
        count += 5;
        nums[i] = result[i];
        count += 3;
    }
    return count;
}
uint64_t radixSortOp(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    for (int byte = 1; 4100 / byte > 0; byte *= 10) {
        count += 3;
        count += countingSort2(nums, n, byte);
    }
    return count;
}

uint64_t merge2(std::vector<int> &nums, int left, int middle, int right) {
    uint64_t count = 0;
    int sizeFirst = middle - left + 1;
    count += 2;
    int sizeSecond = right - middle;
    count += 2;
    std::vector<int> temperLeft(sizeFirst);
    std::vector<int> temperRight(sizeSecond);
    for (auto i = 0; i < sizeFirst; i++) {
        count += 3;
        temperLeft[i] = nums[left + i];
        count += 3;
    }
    for (auto j = 0; j < sizeSecond; j++) {
        count += 3;
        temperRight[j] = nums[middle + 1 + j];
        count += 3;
    }
    int indexFirst = 0;
    int indexSecond = 0;
    int indexMerge = left;
    count += 3;
    count += 3;
    while (indexFirst < sizeFirst && indexSecond < sizeSecond) {
        count += 3;
        count += 3;
        if (temperLeft[indexFirst] <= temperRight[indexSecond]) {
            nums[indexMerge] = temperLeft[indexFirst];
            indexFirst++;
            count += 4;
        } else {
            nums[indexMerge] = temperRight[indexSecond];
            indexSecond++;
            count += 4;
        }
        indexMerge++;
        count += 2;
    }
    count += 1;
    while (indexFirst < sizeFirst) {
        count += 1;
        nums[indexMerge] = temperLeft[indexFirst];
        indexFirst++;
        indexMerge++;
        count += 8;
    }
    count += 1;
    while (indexSecond < sizeSecond) {
        count += 1;
        nums[indexMerge] = temperRight[indexSecond];
        indexSecond++;
        indexMerge++;
        count += 8;
    }
    return count;
}
uint64_t count_merge = 0;
void mergeSort2(std::vector<int> &nums, int begin, int end) {
    count_merge += 1;
    if (begin >= end) {
        return;
    }
    int middle = begin + (end - begin) / 2;
    count_merge += 3;
    mergeSort2(nums, begin, middle);
    mergeSort2(nums, middle + 1, end);
    count_merge += merge2(nums, begin, middle, end);
}
uint64_t mergeSortSOp(std::vector<int> &nums, int n) {
    mergeSort2(nums, 0, n - 1);
    return count_merge;
}

uint64_t count_quick = 0;
void quickSort2(std::vector<int> &array, int low, int high) {
    count_quick += 1;
    if (high - low <= 1) {
        return;
    }
    int i = low;
    int j = high - 1;
    int pivot = array[i];
    int temp;
    count_quick += 4;
    count_quick += 1;
    while (i <= j) {
        count_quick += 1;
        count_quick += 2;
        while (array[i] < pivot) {
            count_quick += 4;
            i++;
        }
        count_quick += 2;
        while (array[j] > pivot) {
            j--;
            count_quick += 4;
        }
        count_quick += 1;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
            count_quick += 11;
        }
    }
    count_quick += 1;
    if (low < j) {
        quickSort2(array, low, j + 1);
    }
    count_quick += 1;
    if (i < high) {
        quickSort2(array, i, high);
    }
}
uint64_t quickSortQOp(std::vector<int> &nums, int n) {
    quickSort2(nums, 0, n - 1);
    return count_quick;
}

uint64_t count_heap = 0;
void buildHeap2(int index_maxi, int heap_size, std::vector<int> &nums) {
    int left = index_maxi * 2 + 1;
    int right = index_maxi * 2 + 2;
    int new_maxi = index_maxi;
    count_heap += 5;
    count_heap += 5;
    if (left < heap_size && nums[left] > nums[index_maxi]) {
        new_maxi = left;
        count_heap += 1;
    }
    count_heap += 5;
    if (right < heap_size && nums[right] > nums[new_maxi]) {
        new_maxi = right;
        count_heap += 1;
    }
    count_heap += 1;
    if (new_maxi != index_maxi) {
        std::swap(nums[index_maxi], nums[new_maxi]);
        count_heap += 6;
        buildHeap2(new_maxi, heap_size, nums);
    }
}
uint64_t heapSortOp(std::vector<int> &nums, int n) {
    for (int i = (n / 2) - 1; i >= 0; --i) {
        count_heap += 3;
        buildHeap2(i, n, nums);
    }
    for (int i = n - 1; i >= 0; --i) {
        count_heap += 3;
        std::swap(nums[0], nums[i]);
        count_heap += 6;
        buildHeap2(0, i, nums);
    }
    return count_heap;
}
uint64_t shellSortOp(std::vector<int> &nums, int n) {
    uint64_t count = 0;
    for (int i = n / 2; i > 0; i /= 2) {
        count += 3;
        for (int j = i; j < n; ++j) {
            count += 3;
            int temp = nums[j];
            count += 2;
            int k;
            for (k = j; k >= i && nums[k - i] > temp; k -= i) {
                count += 3;
                nums[k] = nums[k - i];
                count += 3;
            }
            nums[k] = temp;
            count += 2;
        }
    }
    return count;
}
uint64_t cyuSequenceSortOp(std::vector<int> &nums, int n) {
    std::vector<int> seq{1, 4, 10, 23, 57, 132, 301, 701, 1750};
    uint64_t count = 0;
    for (int i = 8; i >= 0; --i) {
        count += 3;
        for (int j = seq[i]; j < n; ++j) {
            count += 3;
            int temp = nums[j];
            count += 2;
            int k;
            for (k = j; k >= seq[i] && nums[k - seq[i]] > temp; k -= seq[i]) {
                count += 6;
                nums[k] = nums[k - seq[i]];
                count += 3;
            }
            nums[k] = temp;
            count += 2;
        }
    }
    return count;
}
