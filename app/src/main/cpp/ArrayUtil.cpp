//
// Created by 29184 on 2021/3/7.
//

#include <stdlib.h>
#include <android/log.h>
#include <iostream>
#include <assert.h>
#include <time.h>

#define TAG "TAG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

namespace ArrayUtil {

    int *create_random_array(int len, int low, int high) {
        int *arr = new int[len];
        for (int i = 0; i < len; i++) {
            arr[i] = rand() % (high - low) + low;
        }
        return arr;
    }

    int *create_nearly_ordered_array(int len, int swapNums) {
        int *arr = new int[len];

        for (int i = 0; i < len; ++i) {
            arr[i] = i;
        }

        for (int i = 0; i < swapNums; ++i) {
            int randomX = rand() % (len - 1);
            int randomY = rand() % (len - 1);
            std::swap(arr[randomX], arr[randomY]);
        }
        return arr;
    }

    int *copy_random_array(int *arr, int len) {
        int *copy_arr = new int[len];
        memcpy(copy_arr, arr, sizeof(int) * len);
        return copy_arr;
    }

    void sort_array(char *sortName, void (*sort)(int *, int), int *arr, int len) {
        size_t start_time = clock();
        sort(arr, len);
        size_t end_time = clock();

        double time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        LOGE("%s的执行时间：%lf", sortName, time);

        for (int i = 0; i < len - 1; i++) {
            assert(arr[i] <= arr[i + 1]);
        }
    }

}

