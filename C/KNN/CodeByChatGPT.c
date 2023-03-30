#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_SAMPLES 669
#define NUM_FEATURES 8
#define K 9

typedef struct {
    double features[NUM_FEATURES];
    int label;
} Sample;

Sample samples[MAX_SAMPLES];
int num_samples = 0;

double normalize(double value, double min, double max) {
    return (value - min) / (max - min);
}

void load_samples(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* token = strtok(line, ",");
        Sample sample;
        int i = 0;
        while (token != NULL) {
            double value = atof(token);
            if (i < NUM_FEATURES) {
                double min = i == 1 ? 0 : 1;
                double max = i == 1 ? 200 : 122;
                sample.features[i] = normalize(value, min, max);
            } else {
                sample.label = (int)value;
            }
            token = strtok(NULL, ",");
            i++;
        }
        samples[num_samples] = sample;
        num_samples++;
    }
    fclose(fp);
}

double euclidean_distance(double* features1, double* features2) {
    double sum = 0.0;
    for (int i = 0; i < NUM_FEATURES; i++) {
        double diff = features1[i] - features2[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

int predict(Sample* test_sample) {
    int counts[2] = {0};
    double distances[num_samples];
    for (int i = 0; i < num_samples; i++) {
        distances[i] =
            euclidean_distance(samples[i].features, test_sample->features);
    }
    for (int i = 0; i < K; i++) {
        int min_index = 0;
        for (int j = 0; j < num_samples; j++) {
            if (distances[j] < distances[min_index]) {
                min_index = j;
            }
        }
        counts[samples[min_index].label]++;
        distances[min_index] = INFINITY;
    }
    return counts[0] > counts[1] ? 0 : 1;
}

int main(int argc, char** argv) {
    int num_tests = 0;
    int true_positive = 0, false_positive = 0, false_negative = 0,
        true_negative = 0;
    float precision = 0, recall = 0;
    char line[MAX_LINE_LENGTH];

    load_samples(argv[1]);

    FILE* fp = fopen(argv[2], "r");

    if (fp == NULL) {
        printf("Failed to open file %s\n", argv[2]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* token = strtok(line, ",");

        Sample test_sample;

        int i = 0;

        while (token != NULL) {
            double value = atof(token);
            if (i < NUM_FEATURES) {
                double min = i == 1 ? 0 : 1;
                double max = i == 1 ? 200 : 122;
                test_sample.features[i] = normalize(value, min, max);
            } else {
                test_sample.label = (int)value;
            }
            token = strtok(NULL, ",");
            i++;
        }

        int prediction = predict(&test_sample);

        if (prediction)
            if (test_sample.label)
                true_positive += 1;
            else
                false_positive += 1;
        else if (test_sample.label)
            false_negative += 1;
        else
            true_negative += 1;

        printf("Predicted label: %d | Test label: %d | Correct: %d\n",
               prediction, test_sample.label,
               (prediction == test_sample.label) ? 1 : 0);
        num_tests++;
    }
    fclose(fp);

    // Calculate percision and recall
    precision = (float)true_positive / (true_positive + false_positive);
    recall = (float)true_positive / (true_positive + false_negative);

    // Output
    printf("===================================\n");
    printf("Accuracy: %f\n",
           (float)(true_positive + true_negative) / num_tests);
    printf("Precision: %f\n", precision);
    printf("Recall: %f\n", recall);
    printf("F1: %f\n", 2 * precision * recall / (precision + recall));

    printf("===================================\n");
    printf("%-16s | %-14s | %s\n", "", "True Positive", "True Negative");
    printf("%-16s | %-14d | %d\n", "Predict Positive", true_positive,
           false_negative);
    printf("%-16s | %-14d | %d\n", "Predict Negative", false_positive,
           true_negative);
    printf("===================================\n");
    printf("Train Set Size: %d, Test Set Size: %d\n", num_samples, num_tests);

    return 0;
}
