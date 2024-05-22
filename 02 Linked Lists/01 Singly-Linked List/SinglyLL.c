#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int node_data;
    struct node_struct *next_node;
} Node;

void create_list(Node **head_pointer);
void display_list(Node *head_pointer);
void insert_at_beginning(Node **head_pointer);
void insert_at_ending(Node *head_pointer);
// void countNodes();
// void insertAt();
// void insertBefore();
// void searchNode();
// void deleteFirst();
// void deleteLast();
// void deleteAny();
// void updateNode();
// void reverseList();

int main()
{
    Node *head_pointer = NULL;
    int choice;
    do
    {
        printf("\nPlease Insert a Valid Option:\n");
        printf("1...Create List.\n");
        printf("2...Display List.\n");
        printf("3...Insert at beginning.\n");
        printf("4...Insert at the end.\n");
        // printf("5...Count nodes.\n");
        // printf("6...Insert at specific position.\n");
        // printf("7...Insert before a given node.\n");
        // printf("8...Search an element.\n");
        // printf("9...Delete first element.\n");
        // printf("10...Delete last element.\n");
        // printf("11...Delete any element.\n");
        // printf("12...Update a node.\n");
        // printf("13...Reverse the List.\n");
        printf("0...EXIT.\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_list(&head_pointer);
            break;

        case 2:
            display_list(head_pointer);
            break;

        case 3:
            insert_at_beginning(&head_pointer);
            break;

        case 4:
            insert_at_ending(head_pointer);
            break;

        case 0:
            printf("EXITING PROGRAM!\n");
            break;

        default:
            break;
        }

    } while (choice != 0);

    return 0;
}

void create_list(Node **head_pointer)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    int input_data;

    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Insert node value:\n");
    scanf("%d", &(input_data));

    new_node -> node_data = input_data;
    new_node -> next_node = *head_pointer;
    *head_pointer = new_node;

    printf("List Created!\n");
}

void display_list(Node *head_pointer)
{
    Node *current_node = head_pointer;
    if (head_pointer == NULL)
    {
        printf("Empty List!\n");
    }

    while (current_node != NULL)
    {
        printf("%d -> ", current_node -> node_data);
        current_node = current_node -> next_node;
    }

    printf("NULL\n");
}

void insert_at_beginning(Node **head_pointer)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    int input_data;

    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Insert node value:\n");
    scanf("%d", &input_data);

    new_node -> node_data = input_data;
    new_node -> next_node = *head_pointer;
    
    *head_pointer = new_node;
}

void insert_at_ending(Node *head_pointer)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    Node *current_node = head_pointer;
    int input_data;

    if (new_node == NULL)
    {
        printf("Memory allocation failed!");
    }
    
    printf("Insert node value:\n");
    scanf("%d", &input_data);

    new_node -> node_data = input_data;
    new_node -> next_node = NULL;

    while (current_node -> next_node != NULL)
    {
        current_node = current_node -> next_node;
    }
    
    current_node -> next_node = new_node;
}