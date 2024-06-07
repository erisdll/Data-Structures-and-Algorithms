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
        printf("%d ", curNodePtr->nodeValue);
        if (curNodePtr->nextNodePtr != NULL)
            printf(" -> ");
        curNodePtr = curNodePtr->nextNodePtr;
    }
    printf("\n\n");
}

void main()
{
    Node *headNode = createList();
    displayList(headNode);
}