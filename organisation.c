#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10
#define MAX_DEPARTMENTS 20
#define NAME_LENGTH 30

typedef struct Node {
    char name[NAME_LENGTH];
    int childCount;
    struct Node *children[MAX_CHILDREN];
} Node;

/* Create a new tree node */
Node *createNode(const char *name) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newNode->name, name);
    newNode->childCount = 0;

    for (int i = 0; i < MAX_CHILDREN; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

/* Add a child to a parent node */
void addChild(Node *parent, Node *child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount] = child;
        parent->childCount++;
    }
}

/* Level-order traversal using a queue */
void levelOrderTraversal(Node *root) {
    Node *queue[MAX_DEPARTMENTS];

    int front = 0;
    int rear = 0;

    if (root == NULL)
        return;

    queue[rear++] = root;

    printf("\nLevel-order traversal:\n");

    while (front < rear) {
        Node *current = queue[front++];

        printf("%s ", current->name);

        for (int i = 0; i < current->childCount; i++) {
            queue[rear++] = current->children[i];
        }
    }

    printf("\n");
}

/* Calculate tree height in levels */
int calculateHeight(Node *root) {
    if (root == NULL) {
        return 0;
    }

    int maximumHeight = 0;

    for (int i = 0; i < root->childCount; i++) {
        int childHeight = calculateHeight(root->children[i]);

        if (childHeight > maximumHeight) {
            maximumHeight = childHeight;
        }
    }

    return maximumHeight + 1;
}

/* Linear Search */
void linearSearch(char departments[][NAME_LENGTH],
                  int count,
                  const char *target) {

    int comparisons = 0;
    int found = -1;

    for (int i = 0; i < count; i++) {
        comparisons++;

        if (strcmp(departments[i], target) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Linear Search: %s found at position %d\n",
               target, found + 1);
    } else {
        printf("Linear Search: %s not found\n", target);
    }

    printf("Linear Search comparisons: %d\n", comparisons);
}

/* Binary Search */
void binarySearch(char departments[][NAME_LENGTH],
                  int count,
                  const char *target) {

    int low = 0;
    int high = count - 1;
    int comparisons = 0;
    int found = -1;

    while (low <= high) {

        int middle = (low + high) / 2;

        comparisons++;

        int result = strcmp(departments[middle], target);

        if (result == 0) {
            found = middle;
            break;
        } else if (result < 0) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    if (found != -1) {
        printf("Binary Search: %s found at position %d\n",
               target, found + 1);
    } else {
        printf("Binary Search: %s not found\n", target);
    }

    printf("Binary Search comparisons: %d\n", comparisons);
}

/* Free memory allocated for the tree */
void freeTree(Node *root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < root->childCount; i++) {
        freeTree(root->children[i]);
    }

    free(root);
}

int main() {

    /* Create nodes */
    Node *CEO = createNode("CEO");
    Node *HR = createNode("HR");
    Node *Finance = createNode("Finance");
    Node *IT = createNode("IT");
    Node *Development = createNode("Development");
    Node *Testing = createNode("Testing");
    Node *Frontend = createNode("Frontend");
    Node *Backend = createNode("Backend");

    /* Construct organisational hierarchy */
    addChild(CEO, HR);
    addChild(CEO, Finance);
    addChild(CEO, IT);

    addChild(IT, Development);
    addChild(IT, Testing);

    addChild(Development, Frontend);
    addChild(Development, Backend);

    printf("Organisational hierarchy constructed successfully.\n");

    /* Display hierarchy */
    levelOrderTraversal(CEO);

    /* Display tree height */
    int height = calculateHeight(CEO);

    printf("\nTree height: %d levels\n", height);
    printf("Tree height in edges: %d\n", height - 1);

    /* Sorted department array */
    char departments[MAX_DEPARTMENTS][NAME_LENGTH] = {
        "Backend",
        "CEO",
        "Development",
        "Finance",
        "Frontend",
        "HR",
        "IT",
        "Testing"
    };

    int departmentCount = 8;

    /* Search targets */
    char searches[3][NAME_LENGTH] = {
        "CEO",
        "Frontend",
        "Testing"
    };

    printf("\nDepartment searches:\n");

    for (int i = 0; i < 3; i++) {

        printf("\nSearching for: %s\n", searches[i]);

        linearSearch(departments,
                     departmentCount,
                     searches[i]);

        binarySearch(departments,
                     departmentCount,
                     searches[i]);
    }

    /* Free allocated memory */
    freeTree(CEO);

    return 0;
}
