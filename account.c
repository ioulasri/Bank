#include "bank.h"

int check_password(bank *head, int password)
{
    bank *curr = head;

    while (curr)
    {
        if (curr->password == password)
            return (1);
        curr = curr->next;
    }
    return (0);
}

int check_acc(bank *head, char *name, int password)
{
    bank *curr = head;

    while (curr)
    {
        if (strcmp(curr->owner, name) == 0 && curr->password == password)
            return (1);
        curr = curr->next;
    }
    return (0);
}

void open_account(bank **head, char *name, int password)
{
    bank *check = *head;
    if (check_acc(check, name, password))
    {
        printf("Account already exists..\n");
        return;
    }
    if (check_password(check, password))
    {
        printf("Password is being used by another user please try another password...\n");
        return;
    }

    bank *new_account = malloc(sizeof(bank));
    new_account->owner = strdup(name);
    new_account->password = password;
    new_account->balance = 0;

    new_account->next = *head;
    *head = new_account;
}

void display_account(bank *head)
{
    bank *curr = head;
    int i = 1;

    while (curr)
    {
        printf("%d -> Account owner: %s | Account balance: %d$\n", i, curr->owner, curr->balance);
        curr = curr->next;
        i++;
    }
}
