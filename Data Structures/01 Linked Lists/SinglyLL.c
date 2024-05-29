#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int nodeValue;
    struct nodeStruct *nextNodePtr;
} Node;

Node *createList()
{
    Node *headNode = (Node *)malloc(sizeof(Node));
    if (headNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    printf("Please insert node value:");
    scanf("%d", &headNode->nodeValue);

    headNode->nextNodePtr = NULL;
    return headNode;
}

void displayList(Node *headPtr)
{
    Node *currentNode = headPtr;
    if (headPtr == NULL)
        printf("The list is empty.\n");
    else
    {
        while (currentNode != NULL)
        {
            printf("%d -> ", currentNode->nodeValue);
            currentNode = currentNode->nextNodePtr;
        }

        printf("NULL\n");
    }
    printf("\n");
}

void countNodes(Node *headPtr)
{
    Node *currentNode = headPtr;
    int nodeCounter = 0;
    
    while (currentNode != NULL)
    {
        currentNode = currentNode->nextNodePtr;
        nodeCounter++;
    }

    if (nodeCounter == 1)
    {
        printf("The list has 1 node.");
    }
    else
        printf("The list has %d nodes.", nodeCounter);
}

void pushNode(Node **headPtr)
{
    Node *newHeadPtr = (Node *)malloc(sizeof(Node));
    if (newHeadPtr == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    printf("Insert node value:\n");
    scanf("%d", &newHeadPtr->nodeValue);

    newHeadPtr->nextNodePtr = *headPtr;
    *headPtr = newHeadPtr;
}

void appendNode(Node **headPtr)
{
    Node *curNodePtr = *headPtr;
    Node *newNodePtr = (Node *)malloc(sizeof(Node));
    if (newNodePtr == NULL)
    {
        printf("Memory allocation failed!");
    }
    printf("Insert node value:\n");
    scanf("%d", &newNodePtr->nodeValue);

    newNodePtr->nextNodePtr = NULL;

    while (curNodePtr->nextNodePtr != NULL)
    {
        curNodePtr = curNodePtr->nextNodePtr;
    }

    curNodePtr->nextNodePtr = newNodePtr;
}

void insertNode(Node **headPtr)
{
    Node *curNodePtr = *headPtr;
    Node *newNodePtr = (Node *)malloc(sizeof(Node));
    if (newNodePtr == NULL)
    {
        printf("Memory allocation failed!");
    }
    printf("Insert node value:\n");
    scanf("%d", &newNodePtr->nodeValue);
}

/*
void searchNode() {}

void updateNode() {}

void deleteNode() {}

void reverseList() {}
*/

void insertNodeChoice(Node **headPtr)
{
    printf("╔════════════════════════════════╗\n");
    printf("║ 1 — Insert at list beginning   ║\n");
    printf("║ 2 — Insert at list ending      ║\n");
    printf("║ 3 — Insert at specific index   ║\n");
    printf("║ 4 — Insert before a value      ║\n");
    printf("╚════════════════════════════════╝\n");

    int insChoice;
    scanf("%d", &insChoice);

    switch (insChoice)
    {
    case 1:
        pushNode(headPtr);
        break;
    
    case 2:
        appendNode(headPtr);
        break;

    default:
        break;
    }
}

void printMenu()
{
    printf("╔═════════════════════╦════════════════════╗\n");
    printf("║ 1 — Create a list   ║ 6 — Display list   ║\n");
    printf("║ 2 — Insert a node   ║ 7 — Count nodes    ║\n");
    printf("║ 3 — Search a node   ║ 8 — Reverse List   ║\n");
    printf("║ 4 — Update a node   ║ 9 — Show Menu      ║\n");
    printf("║ 5 — Delete a node   ║ 0 — Exit Program   ║\n");
    printf("╚═════════════════════╩════════════════════╝\n");
}

void main()
{
    Node *headPtr = NULL;
    int choice = -1;
    do
    {
        printMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            headPtr = createList();
            displayList(headPtr);
            break;

        case 2:
            displayList(headPtr);
            break;

        case 3:
            insertNodeChoice(&headPtr);
            choice = -1;
            break;

        case 4:
            // insertNode(&headPtr);
            break;

        case 5:
            // searchNode(headPtr);
            break;

        case 6:
            // updateNode(headPtr);
            break;

        case 7:
            // deleteNode(&headPtr);
            break;

        case 8:
            // reverseList(&headPtr);
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