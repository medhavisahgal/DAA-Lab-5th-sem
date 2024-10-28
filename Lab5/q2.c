#include <stdio.h>
#include <stdlib.h>

struct Node {
    char alphabet;
    int frequency;
    struct Node *left;
    struct Node *right;
};

struct SYMBOL {
    char alphabet;
    int frequency;
};

struct MinPQ {
    int size;
    int capacity;
    struct Node **array;
};

struct Node* newNode(char alphabet, int frequency) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->left = temp->right = NULL;
    temp->alphabet = alphabet;
    temp->frequency = frequency;
    return temp;
}

struct MinPQ* createMinPQ(int capacity) {
    struct MinPQ* minPQ = (struct MinPQ*)malloc(sizeof(struct MinPQ));
    minPQ->size = 0;
    minPQ->capacity = capacity;
    minPQ->array = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return minPQ;
}

void swapNode(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinPQ* minPQ, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minPQ->size && minPQ->array[left]->frequency < minPQ->array[smallest]->frequency)
        smallest = left;

    if (right < minPQ->size && minPQ->array[right]->frequency < minPQ->array[smallest]->frequency)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minPQ->array[smallest], &minPQ->array[idx]);
        minHeapify(minPQ, smallest);
    }
}

void insertMinPQ(struct MinPQ* minPQ, struct Node* node) {
    ++minPQ->size;
    int i = minPQ->size - 1;

    while (i && node->frequency < minPQ->array[(i - 1) / 2]->frequency) {
        minPQ->array[i] = minPQ->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minPQ->array[i] = node;
}

struct Node* extractMin(struct MinPQ* minPQ) {
    struct Node* temp = minPQ->array[0];
    minPQ->array[0] = minPQ->array[minPQ->size - 1];
    --minPQ->size;
    minHeapify(minPQ, 0);
    return temp;
}

struct Node* buildHuffmanTree(struct SYMBOL symbols[], int n) {
    struct Node *left, *right, *top;
    struct MinPQ* minPQ = createMinPQ(n);

    for (int i = 0; i < n; ++i)
        minPQ->array[i] = newNode(symbols[i].alphabet, symbols[i].frequency);

    minPQ->size = n;

    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minPQ, i);

    while (minPQ->size != 1) {
        left = extractMin(minPQ);
        right = extractMin(minPQ);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinPQ(minPQ, top);
    }

    return extractMin(minPQ);
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        if (root->alphabet != '$')
            printf("%c ", root->alphabet);
        inorder(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL* symbols = (struct SYMBOL*)malloc(n * sizeof(struct SYMBOL));

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    struct Node* root = buildHuffmanTree(symbols, n);

    printf("\nIn-order traversal of the tree (Huffman): ");
    inorder(root);
    printf("\n");

    free(symbols);
    return 0;
}

