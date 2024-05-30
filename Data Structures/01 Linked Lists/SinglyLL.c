#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int nodeValue;
    struct nodeStruct *nextNodePtr;
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

    // Node insertion
    headNode->nextNodePtr = NULL;
    return headNode;
}

void displayList(Node *headPtr)
{
    // Declarations
    Node *curNodePtr = headPtr;

    // Handle edge case
    if (headPtr == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }

    // List traversal and printing
    while (curNodePtr != NULL)
    {
        printf("%d -> ", curNodePtr->nodeValue);
        curNodePtr = curNodePtr->nextNodePtr;
    }
    printf("NULL\n\n");
}

void countNodes(Node *headPtr)
{
    // Declarations
    int counter = 0;
    Node *curNodePtr = headPtr;

    // List traversal for couting
    while (curNodePtr != NULL && headPtr != NULL)
    {
        curNodePtr = curNodePtr->nextNodePtr;
        counter++;
    }

    // Console Operations
    if (headPtr == NULL)
    {
        printf("The list is empty.\n\n");
        return;
    }
    (counter == 1)
        ? printf("The list has 1 node.\n\n")
        : printf("The list has %d nodes.\n\n", counter);
}

void pushNode(Node **headPtr)
{
    // Memory Allocation
    Node *newHeadPtr = (Node *)malloc(sizeof(Node));
    if (newHeadPtr == NULL)
    {
        printf("Memory allocation failure!\n");
    }

    // Console Operations
    system("clear");
    printf("Insert node value:");
    scanf("%d", &newHeadPtr->nodeValue);

    // Node push
    newHeadPtr->nextNodePtr = *headPtr;
    *headPtr = newHeadPtr;
}

void appendNode(Node **headPtr)
{
    // Declarations and Allocation
    Node *curNodePtr = *headPtr;
    Node *newNodePtr = (Node *)malloc(sizeof(Node));

    if (newNodePtr == NULL)
    {
        printf("Memory allocation failed!");
    }

    // Console Operations
    system("clear");
    printf("Insert node value:");
    scanf("%d", &newNodePtr->nodeValue);

    // List traversal to list end
    while (curNodePtr->nextNodePtr != NULL)
    {
        curNodePtr = curNodePtr->nextNodePtr;
    }

    // Node appendal
    curNodePtr->nextNodePtr = newNodePtr;
}

void insertNode(Node **headPtr)
{
    // Declarations & allocation
    int index;
    int counter = 0;
    Node *curNodePtr = *headPtr;
    Node *newNodePtr = (Node *)malloc(sizeof(Node));

    if (newNodePtr == NULL)
    {
        printf("Memory allocation failure.");
    }

    // Console operations
    system("clear");
    printf("Enter index to insert into:");
    scanf("%d", &index);
    system("clear");
    printf("Insert node value:");
    scanf("%d", &newNodePtr->nodeValue);

    // Handle insertion at beginning
    if (index == 0)
    {
        newNodePtr->nextNodePtr = *headPtr;
        *headPtr = newNodePtr;
    }

    // List traversal to desired node
    while (curNodePtr != NULL && counter < index - 1)
    {
        curNodePtr = curNodePtr->nextNodePtr;
        counter++;
    }

    // Handle out of bounds exception
    if (curNodePtr == NULL)
    {
        printf("Index out of bounds!\n");
        free(newNodePtr);
        return;
    }

    // Node insertion
    newNodePtr->nextNodePtr = curNodePtr->nextNodePtr;
    curNodePtr->nextNodePtr = newNodePtr;
}

void searchNodeByIndex(Node *headPtr)
{
    // Declarations
    int index;
    int counter = 0;
    Node *curNodePtr = headPtr;

    // Console Operations
    system("clear");
    printf("Enter desired index:");
    scanf("%d", &index);

    // Handle negative index
    if (index < 0) {
        printf("Invalid index. Index must be non-negative.\n\n");
        return;
    }

    // List traversal to desired node
    while (counter < index && curNodePtr != NULL)
    {
        curNodePtr = curNodePtr->nextNodePtr;
        counter++;
    }

    // Handle out of bounds exception
    if (curNodePtr == NULL)
    {
        system("clear");
        printf("Index out of bounds.\nCurrent length is %d nodes.\n\n", counter - 1);
        return;
    }

    // Node retrieval
    system("clear");
    printf("Index: %d\nValue: %d\n\n", index, curNodePtr->nodeValue);
}

/*
void updateNode() {}

void deleteNode() {}

void reverseList() {}
*/

void insertNodeSubmenu(Node **headPtr)
{
    printf("╔═════════════════════════════════╗\n");
    printf("║  1 — Insert at list beginning   ║\n");
    printf("║  2 — Insert at list ending      ║\n");
    printf("║  3 — Insert at specific index   ║\n");
    printf("║  4 — Insert before a value      ║\n");
    printf("╚═════════════════════════════════╝\n");

    int insChoice;
    scanf("%d", &insChoice);

    switch (insChoice)
    {
    case 1:
        pushNode(headPtr);
        system("clear");
        displayList(*headPtr);
        break;

    case 2:
        appendNode(headPtr);
        system("clear");
        displayList(*headPtr);
        break;

    case 3:
        insertNode(headPtr);
        system("clear");
        displayList(*headPtr);
        break;

    default:
        break;
    }
}

void searchNodeSubmenu(Node *headPointer)
{
    printf("╔═════════════════════════════╗\n");
    printf("║  1 — Search node by index   ║\n");
    printf("║  2 — Search node by value   ║\n");
    printf("╚═════════════════════════════╝\n");

    int srcChoice;
    scanf("%d", &srcChoice);

    switch (srcChoice)
    {
    case 1:
        searchNodeByIndex(headPointer);
        break;

    case 2:
        // searchNodeByIndex();
        break;

    default:
        break;
    }
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
            displayList(headPtr);
            break;

        case 2:
            system("clear");
            displayList(headPtr);
            break;

        case 3:
            system("clear");
            countNodes(headPtr);
            break;

        case 4:
            system("clear");
            displayList(headPtr);
            insertNodeSubmenu(&headPtr);
            break;

        case 5:
            system("clear");
            searchNodeSubmenu(headPtr);
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

        case 0:
            printf("EXITING PROGRAM!\n");
            break;

        default:
            break;
        }
    } while (choice != 0);
}