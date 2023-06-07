#include "bank.h"

void handle_login(bank *head, char **name, int *password)
{
    *name = malloc(sizeof(char) * 50);

    printf("Enter your name: ");
    scanf("%s", *name);
    printf("Enter your password: ");
    scanf("%d", &(*password));

    if (check_acc(head, *name, *password))
    {
        printf("Logged in successfuly\n");
        return;
    }
    printf("Failed to log in, check your name or password.\n");
    free(*name);
    *name = NULL;
}

void handle_open_account(bank **head)
{
    char *name;
    int password;

    name = malloc(sizeof(char) * 50);
    printf("Enter the account name: ");
    scanf("%s", name);
    printf("Enter new password: ");
    scanf("%d", &password);
    open_account(head, name, password);
}

void handle_close_account(bank **head, char *name, int password)
{
    bank *curr = *head;

    while (curr->next)
    {
        if ((strcmp(curr->next->owner, name) == 0 ) && (curr->next->password == password))
        {
            bank *to_be_deleted = curr->next;
            curr->next = curr->next->next;
            free(to_be_deleted->owner);
            free(to_be_deleted);
            return;
        }
        curr = curr->next;
    }
}

void handle_withdraw(bank **head, char *name)
{
    int amount;
    bank *curr = *head;

    printf("Enter the amound to withdraw: ");
    scanf("%d", &amount);

    while (curr)
    {
        if (strcmp(curr->owner, name) == 0)
        {
            if (curr->balance < amount)
            {
                printf("You don't have enough funds...\n");
                return;
            }
            curr->balance -= amount;
            return;
        }
        curr = curr->next;
    }
}

void handle_deposit(bank **head, char *name)
{
    int amount;
    bank *curr = *head;

    printf("Enter the amound to withdraw: ");
    scanf("%d", &amount);

    while (curr)
    {
    if (strcmp(curr->owner, name) == 0)
    {
        curr->balance += amount;
        return;
    }
    curr = curr->next;
    }
}
