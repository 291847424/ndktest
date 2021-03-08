#include <jni.h>
#include <string>
#include <android/log.h>
#include "ArrayUtil.cpp"

#define TAG "TAG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

using namespace std;

void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        LOGE("%d", arr[i]);
    }
}

void bubbleSort(int arr[], int len) {

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void optimizeBubbleSort(int arr[], int len) {

    int n = len;
    do {
        int newn = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                newn = i;
            }
        }
        n = newn;
    } while (n > 0);
}

void selectSort(int arr[], int len) {

    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

}

void insertSort(int arr[], int len) {

    for (int i = 1; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }

}

void optimizeInsertSort(int arr[], int len) {
    int j, tem;
    for (int i = 1; i < len; i++) {
        tem = arr[i];
        for (j = i; j > 0 && arr[j-1] > tem; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tem;
    }
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_ndktest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    int len = 100;
    int *arr = ArrayUtil::create_random_array(len, 100, 200);
    int *arr2 = ArrayUtil::copy_random_array(arr, len);
    int *arr3 = ArrayUtil::copy_random_array(arr, len);
    int *arr4 = ArrayUtil::copy_random_array(arr, len);

    ArrayUtil::sort_array("selectSort", selectSort, arr, len);
    ArrayUtil::sort_array("bubbleSort", bubbleSort, arr2, len);
    ArrayUtil::sort_array("insertSort", insertSort, arr3, len);
    ArrayUtil::sort_array("optimizeInsertSort", optimizeInsertSort, arr4, len);

    delete[] (arr);
    delete[] (arr2);
    delete[] (arr3);
    delete[] (arr4);

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}