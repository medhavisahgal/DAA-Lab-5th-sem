#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float profit;
    float weight;
    float ratio;
} ITEM;

int compare(const void *a, const void *b) {
    ITEM *itemA = (ITEM *)a;
    ITEM *itemB = (ITEM *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

float fractionalKnapsack(ITEM items[], int n, float capacity) {
    qsort(items, n, sizeof(ITEM), compare);

    float totalProfit = 0.0;
    float currentWeight = 0.0;

    printf("\nOutput:\n");
    printf("Item No\tprofit\t\tWeight\t\tAmount to be taken\n");

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("%d\t%.6f\t%.6f\t1.000000\n", items[i].id, items[i].profit, items[i].weight);
        } else {
            float remainingCapacity = capacity - currentWeight;
            float fraction = remainingCapacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            printf("%d\t%.6f\t%.6f\t%.6f\n", items[i].id, items[i].profit, items[i].weight, fraction);
            break;
        }
    }

    printf("Maximum profit: %.6f\n", totalProfit);
    return totalProfit;
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];

    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].profit, &items[i].weight);
        items[i].ratio = items[i].profit / items[i].weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    fractionalKnapsack(items, n, capacity);

    return 0;
}