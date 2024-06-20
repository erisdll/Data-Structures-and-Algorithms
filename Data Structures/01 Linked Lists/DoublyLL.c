#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLLNode
{
    int nodeValue;
    struct DoublyLLNode *nextNodePtr;
    struct DoublyLLNode *prevNodePtr;
} Node;

Node *createList()
{
    // Memory allocation
    Node *headNode = (Node *)malloc(sizeof(Node));
    if (headNode == NULL)
    {
        printf("Memory allocation failure!\n");
    }

    // Console operations
    system("clear");
    printf("Please insert node value:");
    scanf("%d", &headNode->nodeValue);
    system("clear");
    printf("List created successfully!\n\n");

    headNode->nextNodePtr = NULL;
    headNode->prevNodePtr = NULL;
    return headNode;
}

void displayList(Node *headPtr)
{
    if (headPtr == NULL)
    {
        printf("List not yet initialized.\n\n");
        return;
    }

    Node *curNodePtr = headPtr;

    while (curNodePtr != NULL)
    {
        printf("%d", curNodePtr->nodeValue);
        if (curNodePtr->nextNodePtr != NULL)
            printf(" -> ");
        curNodePtr = curNodePtr->nextNodePtr;
    }
    printf("\n\n");
}

void insertNodeAtBeginning(Node **headPtr)
{
    // Allocation
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Console Ops
    printf("Insert node value:");
    scanf("%d", &newNode->nodeValue);
    system("clear");

    // Node Insertion
    newNode->nextNodePtr = *headPtr;    
    newNode->prevNodePtr = NULL;
    (*headPtr)->prevNodePtr = newNode;
    *headPtr = newNode;
}

void printMenu()
{
    printf("╔══════════════════════╦═════════════════════╗\n");
    printf("║  1 — Create List     ║  6 — Update a Node  ║\n");
    printf("║  2 — Display List    ║  7 — Delete a Node  ║\n");
    printf("║  3 — Count Nodes     ║  8 — Reverse List   ║\n");
    printf("║  4 — Insert a Node   ║                     ║\n");
    printf("║  5 — Search a Node   ║  0 — Exit Program   ║\n");
    printf("╚══════════════════════╩═════════════════════╝\n");
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
            break;

        case 2:
            system("clear");
            displayList(headPtr);
            break;

        case 3:
            system("clear");
            // countNodes(headPtr);
            break;

        case 4:
            system("clear");
            insertNodeAtBeginning(&headPtr);
            // insertNodeSubmenu(&headPtr);
            break;

        case 5:
            system("clear");
            // searchNodeSubmenu(headPtr);
            break;

        case 6:
            system("clear");
            // updateNodeSubmenu(headPtr);
            break;

        case 7:
            system("clear");
            // deleteNodeSubmenu(&headPtr);
            break;

        case 8:
            system("clear");
            // reverseList(&headPtr);
            break;

        case 0:
            printf("EXITING PROGRAM!\n\n");
            break;

        default:
            break;
        }
    } while (choice != 0);
}