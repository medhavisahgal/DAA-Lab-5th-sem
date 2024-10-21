#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256

typedef struct Node {
    char data;
    int freq;
    struct Node *left, *right;
} Node;

Node* createNode(char data, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node* nodes[MAX_CHARS] = {NULL};
    int count = 0;

    for (int i = 0; i < size; i++) {
        nodes[count++] = createNode(data[i], freq[i]);
    }

    while (count > 1) {
        int min1 = 0, min2 = 1;

        for (int i = 2; i < count; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        Node* internal = createNode('$', nodes[min1]->freq + nodes[min2]->freq);
        internal->left = nodes[min1];
        internal->right = nodes[min2];

        nodes[min1] = internal;
        nodes[min2] = nodes[--count];
    }

    return nodes[0];
}

void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        if (!root->left && !root->right) {
            printf("%c ", root->data);
        }
        inorderTraversal(root->right);
    }
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    char data[MAX_CHARS];
    int freq[MAX_CHARS];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &data[i]);
    }

    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    Node* root = buildHuffmanTree(data, freq, n);

    int arr[100], top = 0;
    printf("\nHuffman Codes:\n");
    printCodes(root, arr, top);

    printf("\nIn-order traversal of the tree (Huffman): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
