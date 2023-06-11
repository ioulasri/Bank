#include "bank.h"

/**
 * save_nodes - save the nodes to a file
 * @head: head of the list
 * @name: name of the account
 * @password: password of the account
 */

void save_nodes(bank **head, char **name, int *password)
{
    FILE *fp;
    bank *tmp = *head;

    fp = fopen("bank.txt", "w");
    if (!fp)
    {
        printf("Failed to open file\n");
        exit(1);
    }
    while (tmp)
    {
        fprintf(fp, "%s %d %d\n", tmp->owner, tmp->password, tmp->balance);
        tmp = tmp->next;
    }
    fclose(fp);
}

/**
 * load_nodes - load the nodes from a file
 * @head: head of the list
 * @name: name of the account
 * @password: password of the account
 * @op: operation to perform
 */

void load_nodes(bank **head, char **name, int *password)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    bank *new_node;

    fp = fopen("bank.txt", "r");
    if (!fp)
    {
        printf("Failed to open file\n");
        exit(1);
    }
    while ((read = getline(&line, &len, fp)) != -1)
    {
        new_node = malloc(sizeof(bank));
        if (!new_node)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }
        token = strtok(line, " ");
        new_node->owner = malloc(sizeof(char) * 50);
        if (!new_node->owner)
        {
            printf("Failed to allocate memory\n");
            exit(1);
        }
        strcpy(new_node->owner, token);
        token = strtok(NULL, " ");
        new_node->password = atoi(token);
        token = strtok(NULL, " ");
        new_node->balance = atoi(token);
        new_node->next = *head;
        *head = new_node;
    }
    fclose(fp);
    if (line)
        free(line);
}

