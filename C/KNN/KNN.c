#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  // 讀取行上限
#define MAX_SAMPLES 1000      // 最大樣本數
#define NUM_ATTRIBUTES 8      // 特徵數
#define MAX_K 11              // 最大測試 K 值

typedef struct {
    double attribute[NUM_ATTRIBUTES];  // 儲存特徵值
    int outcome;                       // 結果
    int prediction;                    // 預測
} Sample;

/* ### 載入資料集 ###
   filename : 檔案名稱
   sample_list : 樣本集 */
int load_sample(const char* filename, Sample sample_list[]) {
    FILE* loaded_file;
    char read_line[MAX_LINE_LENGTH];
    int counter = 0;

    // 檢測檔案室否正常載入
    if ((loaded_file = fopen(filename, "r")) == NULL) {
        printf("無法開啟檔案: %s", filename);
        exit(1);
    }

    // 逐行讀取檔案
    while (fgets(read_line, MAX_LINE_LENGTH, loaded_file) != NULL) {
        char* token = strtok(read_line, ",");  // 以逗號分開
        Sample sample;                         // 儲存用樣本

        // 存取特徵
        for (int i = 0; i < NUM_ATTRIBUTES; i++) {
            if (counter != 0)
                sample.attribute[i] = atof(token);
            token = strtok(NULL, ",");
        }

        // 存取結果
        if (counter != 0)
            sample.outcome = atoi(token);
        token = strtok(NULL, ",");

        // 寫入資料表
        if (counter != 0)
            sample_list[counter - 1] = sample;
        counter++;
    }

    fclose(loaded_file);

    return counter - 1;
}

/* ### 計算距離 ###
   公式 : D= (Σ|i=1 to n| |xi-yi|^p)^(1/p)
   feature : 特徵值 array
   p : 名氏距離常數
   n : 項數 */
double minkowski_distance(double* feature1, double* feature2, int p, int n) {
    double sum = 0.0;

    for (int i = 0; i < n; i++)
        sum += pow(feature2[i] - feature1[i], p);

    return pow(sum, 1.0 / p);
}

/* ### 高斯加權函數 ###
   公式 a * exp^(-(distance - b)^2 / (2 * c^2)) */
double weighting(double distance, double a, double b, double c) {
    return a * exp(-pow((distance - b), 2) / (2 * pow(c, 2)));
}

/* ### 找尋 K 個最近距離的數字及其位置 ###
   arr : 找尋目標 array
   arr_len : 目標 array 長度
   close_point[][0] : 最近點位置
   close_point[][1] : 最近點數值
   k : 找尋目標數
 */
void find_k_close(double arr[], int arr_len, double close_point[][2], int k) {
    int index, temp;
    for (int i = 0; i < k; i++) {
        index = i;

        // 踢出前 i 個之後，從剩下中找尋最小值
        for (int j = i + 1; j < arr_len; j++)
            if (arr[j] < arr[index])
                index = j;

        // 儲存最小值資訊並加權
        close_point[i][0] = index;
        close_point[i][1] = weighting(arr[index], 1, 0, 0.3);  // <--- 權重

        // 將最小值送到最前面
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}

/* ### 預測資料集 ###
   train_set : 訓練資料表
   test_set : 測試資料表
   row_length : 資料表 row 數量
   k : K值
   p : 名氏距離常數 */
void predict_sample(Sample train_set[],
                    Sample test_set[],
                    int train_row_length,
                    int test_row_length,
                    int k,
                    int p) {
    for (int i = 0; i < test_row_length; i++) {
        double distance[MAX_SAMPLES] = {0};  // 與 train_set 每點距離
        double close_point_set[MAX_K][2] = {
            {0}};              // 最近的 K 個最短距離點，及其位置
        double vote[2] = {0};  // 投票統計

        for (int j = 0; j < train_row_length; j++) {
            distance[j] =
                minkowski_distance(test_set[i].attribute,
                                   train_set[j].attribute, p, NUM_ATTRIBUTES);
        }

        find_k_close(distance, train_row_length, close_point_set, k);

        for (int m = 0; m < k; m++)
            vote[train_set[(int)close_point_set[m][0]].outcome] +=
                close_point_set[m][1];

        test_set[i].prediction = vote[0] > vote[1] ? 0 : 1;
    }
}

/* ### 顯示資料集 ###
   set : 資料表
   row_length : 資料表 row 數量 */
void print_sample_list(Sample set[], int row_length) {
    for (int i = 0; i < row_length; i++) {
        for (int j = 0; j < NUM_ATTRIBUTES; j++) {
            printf("%-8.3f ", set[i].attribute[j]);
        }
        printf("%-5d", set[i].outcome);
        printf("%-5d\n", set[i].prediction);
    }
}

/* ### 顯示測試參數 ###
   test_set : 資料表
   row_length : 資料表 row 數量 */
void print_sample_score(Sample test_set[], int row_length) {
    int true_positive = 0, false_positive = 0, false_negative = 0,
        true_negative = 0;
    double precision = 0, recall = 0;

    for (int i = 0; i < row_length; i++) {
        if (test_set[i].prediction)
            if (test_set[i].outcome)
                true_positive += 1;
            else
                false_positive += 1;
        else if (test_set[i].outcome)
            false_negative += 1;
        else
            true_negative += 1;
    }

    // 計算 percision 及 recall
    precision = (double)true_positive / (true_positive + false_positive);
    recall = (double)true_positive / (true_positive + false_negative);

    // 顯示
    printf("====================================================\n");
    printf("Accuracy: %f\n",
           (double)(true_positive + true_negative) / row_length);
    printf("Precision: %f\n", precision);
    printf("Recall: %f\n", recall);
    printf("F1: %f\n", 2 * precision * recall / (precision + recall));

    printf("====================================================\n");
    printf("%-16s | %-14s | %s\n", "", "True Positive", "True Negative");
    printf("%-16s | %-14d | %d\n", "Predict Positive", true_positive,
           false_positive);
    printf("%-16s | %-14d | %d\n", "Predict Negative", false_negative,
           true_negative);
}

/* ### 主函數 ###
   args[1] : training set csv 檔案路徑
   args[2] : test set csv 檔案路徑 */
int main(int argc, char** argv) {
    Sample training_set[MAX_SAMPLES], test_set[MAX_SAMPLES];

    int train_count = load_sample(argv[1], training_set);
    int test_count = load_sample(argv[2], test_set);

    predict_sample(training_set, test_set, train_count, test_count, 7, 2);

    print_sample_list(test_set, test_count);
    print_sample_score(test_set, test_count);

    printf("====================================================\n");
    printf("Train Set Size: %d, Test Set Size: %d\n", train_count, test_count);

    return 0;
}