#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct
{
    int node_data;
    struct node_struct *next_node;
} Node;

void create_list_case(Node **head_pointer);
void display_list_case(Node *head_pointer);
void count_nodes_case(Node *head_pointer);
void insert_node_case(Node **head_pointer);
void search_node_case(Node *head_pointer);
void update_node_case(Node *head_pointer);
void delete_node_case(Node **head_pointer);
void reverse_list_case(Node **head_pointer);

int main()
{
    Node *head_pointer = NULL;
    int choice;
    do
    {
        printf("\nPlease Insert a Valid Option:\n");
        printf("1 — Create List.\n");
        printf("2 — Display List.\n");
        printf("3 — Count nodes.\n");
        printf("4 — Insert a node.\n");
        printf("5 — Search an element.\n");
        printf("6 — Update a node.\n");
        printf("7 — Delete a node.\n");
        printf("8 — Reverse list.\n");
        printf("0 — EXIT.\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_list_case(&head_pointer);
            break;

        case 2:
            display_list_case(head_pointer);
            break;

        case 3:
            count_nodes_case(head_pointer);
            break;

        case 4:
            insert_node_case(&head_pointer);
            break;

        case 5:
            search_node_case(head_pointer);
            break;

        case 6:
            update_node_case(head_pointer);
            break;

        case 7:
            delete_node_case(&head_pointer);
            break;

        case 8:
            reverse_list_case(&head_pointer);
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

////////////////////////////////////////////////////////////////////////////////////////////////

void create_list(Node **head_pointer, int new_data);
void display_list(Node *head_pointer);
void count_nodes(Node *head_pointer);
void push_node(Node **head_pointer);
void append_node(Node *head_pointer);
void insert_node(Node **head_pointer);
// void insertBefore();
// void searchNode();
// void deleteFirst();
// void deleteLast();
// void deleteAny();
// void updateNode();
// void reverseList();

////////////////////////////////////////////////////////////////////////////////////////////////

void create_list_case(Node **head_pointer)
{
    int input_data;
    printf("Insert node value:\n");
    if (scanf("%d", &input_data) != 1)
    {
        printf("Invalid input. Please enter an integer.\n");
        return;
    }

    create_list(head_pointer, input_data);

    printf("List Created!\n");
}

void display_list_case(Node *head_pointer)
{
}

void count_nodes_case(Node *head_pointer)
{
}

void insert_node_case(Node **head_pointer)
{
}

void search_node_case(Node *head_pointer)
{
}

void update_node_case(Node *head_pointer)
{
}

void delete_node_case(Node **head_pointer)
{
}

void reverse_list_case(Node **head_pointer)
{
}

////////////////////////////////////////////////////////////////////////////////////////////////

void create_list(Node **head_pointer, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    new_node->node_data = new_data;
    new_node->next_node = *head_pointer;
    *head_pointer = new_node;
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
        printf("%d -> ", current_node->node_data);
        current_node = current_node->next_node;
    }

    printf("NULL\n");
}

void push_node(Node **head_pointer)
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

    new_node->node_data = input_data;
    new_node->next_node = *head_pointer;

    *head_pointer = new_node;
}

void append_node(Node *head_pointer)
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

    new_node->node_data = input_data;
    new_node->next_node = NULL;

    while (current_node->next_node != NULL)
    {
        current_node = current_node->next_node;
    }

    current_node->next_node = new_node;
}

void insert_node(Node **head_pointer)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    int input_data;
}

void count_nodes(Node *head_pointer)
{
    Node *current_node = head_pointer;
    int node_counter = 0;

    while (current_node != NULL)
    {
        current_node = current_node->next_node;
        node_counter++;
    }

    if (node_counter == 1)
    {
        printf("The list has %d node.\n", node_counter);
    }
    else
    {
        printf("The list has %d nodes.\n", node_counter);
    }
}