#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int nodeValue;
    struct nodeStruct *nextNode;
} Node;

Node *createList()
{
    Node *headNode = (Node *)malloc(sizeof(Node));

    if (headNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    int inputValue;
    printf("Please insert node value:");
    scanf("%d", &inputValue);

    headNode->nodeValue = inputValue;
    headNode->nextNode = NULL;
    return headNode;
}

void displayList(Node *headPointer)
{
    Node *currentNode = headPointer;
    if (headPointer == NULL)
        printf("The list is empty.\n");
    else
    {
        while (currentNode != NULL)
        {
            printf("%d -> ", currentNode->nodeValue);
            currentNode = currentNode->nextNode;
        }

        printf("NULL\n");
    }
    printf("\n");
}

void countNodes(Node *headPointer)
{
    Node *currentNode = headPointer;
    int nodeCounter = 0;

    while (currentNode != NULL)
    {
        currentNode = currentNode->nextNode;
        nodeCounter++;
    }

    if (nodeCounter == 1)
    {
        printf("The list has 1 node.");
    }
    else
        printf("The list has %d nodes.", nodeCounter);
}

void push_node(Node **headPointer)
{
    Node *headNode = (Node *)malloc(sizeof(Node));
    int input_data;

    if (headNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Insert node value:\n");
    scanf("%d", &input_data);

    headNode->node_data = input_data;
    headNode->next_node = *headPointer;

    *headPointer = headNode;
}

/*
void append_node(Node *headPointer)
{
    Node *headNode = (Node *)malloc(sizeof(Node));
    Node *currentNode = headPointer;
    int input_data;

    if (headNode == NULL)
    {
        printf("Memory allocation failed!");
    }

    printf("Insert node value:\n");
    scanf("%d", &input_data);

    headNode->node_data = input_data;
    headNode->next_node = NULL;

    while (currentNode->next_node != NULL)
    {
        currentNode = currentNode->next_node;
    }

    currentNode->next_node = headNode;
}

void insertNode(Node **headPointer)
{
    Node *headNode = (Node *)malloc(sizeof(Node));
    int input_data;
}

void searchNode() {}

void updateNode() {}

void deleteNode() {}

void reverseList() {}
*/

void printMenu()
{
    printf("╔═════════════════════╦═════════════════════╗\n");
    printf("║ 1 — Create a list.  ║  6 — Display list.  ║\n");
    printf("║ 2 — Insert a node.  ║  7 — Count nodes.   ║\n");
    printf("║ 3 — Search a node.  ║  8 — Reverse List   ║\n");
    printf("║ 4 — Update a node.  ║  9 — Show Menu      ║\n");
    printf("║ 5 — Delete a node.  ║  0 — Exit Program.  ║\n");
    printf("╚═════════════════════╩═════════════════════╝\n");
}

void main()
{
    Node *headPointer = NULL;
    int choice;
    do
    {
        if (choice == NULL)
        {
            printMenu();
        }

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            headPointer = createList();
            displayList(headPointer);
            break;

        case 2:
            displayList(headPointer);
            break;

        case 3:
            countNodes(headPointer);
            break;

        case 4:
            // insertNode(&headPointer);
            break;

        case 5:
            // searchNode(headPointer);
            break;

        case 6:
            // updateNode(headPointer);
            break;

        case 7:
            // deleteNode(&headPointer);
            break;

        case 8:
            // reverseList(&headPointer);
            break;

        case 9:
            printMenu();
            break;

        case 0:
            printf("EXITING PROGRAM!\n");
            break;

        default:
            break;
        }
    } while (choice != 0);
}