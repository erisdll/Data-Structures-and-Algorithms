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
    // Handle null head pointer
    if (headPtr == NULL)
    {
        printf("List not yet initialized.\n\n");
        return;
    }

    // Declarations
    Node *curNodePtr = headPtr;

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
    // Handle null head pointer
    if (headPtr == NULL)
    {
        printf("List not yet initialized.\n\n");
        return;
    }

    // Declarations
    int counter = 0;
    Node *curNodePtr = headPtr;

    // List traversal for couting
    while (curNodePtr != NULL && headPtr != NULL)
    {
        curNodePtr = curNodePtr->nextNodePtr;
        counter++;
    }

    // Console operations
    (counter == 1)
        ? printf("The list has 1 node.\n\n")
        : printf("The list has %d nodes.\n\n", counter);
}

void pushNode(Node **headPtr)
{
    // Memory allocation
    Node *newHeadPtr = (Node *)malloc(sizeof(Node));
    if (newHeadPtr == NULL)
    {
        printf("Memory allocation failure!\n");
    }

    // Console operations
    system("clear");
    printf("Insert node value:");
    scanf("%d", &newHeadPtr->nodeValue);

    // Node push
    newHeadPtr->nextNodePtr = *headPtr;
    *headPtr = newHeadPtr;
}

void appendNode(Node **headPtr)
{
    // Declarations and allocation
    Node *curNodePtr = *headPtr;
    Node *newNodePtr = (Node *)malloc(sizeof(Node));

    if (newNodePtr == NULL)
    {
        printf("Memory allocation failed!");
    }

    // Console operations
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
        system("clear");
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
    system("clear");

    // Handle negative index and null head pointer
    if (index < 0)
    {
        system("clear");
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
        printf("Index out of bounds.\n\n");
        return;
    }

    // Node retrieval
    system("clear");
    printf("Node at index %d has value of %d.\n\n", index, curNodePtr->nodeValue);
}

void searchNodeByValue(Node *headPtr)
{
    // Declarations
    Node *curNodePtr = headPtr;
    int index = 0;
    int queriedValue;

    // Console operations
    system("clear");
    printf("Enter desired node value:");
    scanf("%d", &queriedValue);

    // List traversal to node with desired value
    while (curNodePtr->nodeValue != queriedValue && headPtr != NULL)
    {
        curNodePtr = curNodePtr->nextNodePtr;
        index++;

        if (curNodePtr == NULL)
        {
            system("clear");
            printf("No nodes with value %d in the list.\n\n", queriedValue);
            return;
        }
    }

    system("clear");
    printf("First occurance of value %d is at index %d.\n\n", queriedValue, index);
}

/*
void updateNode() {}

void deleteNode() {}

void reverseList() {}
*/

void insertNodeSubmenu(Node **headPtr)
{
    if (*headPtr == NULL)
    {
        printf("List not yet initialized.\n\n");
        return;
    }

    printf("╔═════════════════════════════════╗\n");
    printf("║  1 — Insert at list beginning   ║\n");
    printf("║  2 — Insert at list ending      ║\n");
    printf("║  3 — Insert at specific index   ║\n");
    printf("║  4 — Insert before a value      ║\n");
    printf("║  5 — Cancel                     ║\n");
    printf("╚═════════════════════════════════╝\n");

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

    case 3:
        insertNode(headPtr);
        break;

    case 4:

        break;

    case 5:
        break;

    default:
        break;
    }
}

void searchNodeSubmenu(Node *headPtr)
{
    if (headPtr == NULL)
    {
        printf("List not yet initialized.\n\n");
        return;
    }

    printf("╔═════════════════════════════╗\n");
    printf("║  1 — Search node by index   ║\n");
    printf("║  2 — Search node by value   ║\n");
    printf("║  3 — Cancel                 ║\n");
    printf("╚═════════════════════════════╝\n");

    int srcChoice;
    scanf("%d", &srcChoice);

    switch (srcChoice)
    {
    case 1:
        searchNodeByIndex(headPtr);
        break;

    case 2:
        searchNodeByValue(headPtr);
        break;

    case 3:
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
            printf("EXITING PROGRAM!\n\n");
            break;

        default:
            break;
        }
    } while (choice != 0);
}