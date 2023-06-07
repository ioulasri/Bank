#include "bank.h"

/**
 * check_name - check if name is already in use
 * @head: head of the list
 * @name: name to check
 * Return: 1 if name is in use, 0 otherwise
 */

int check_name(bank *head, char *name)
{
    bank *curr = head;

    while (curr)
    {
        if (strcmp(curr->owner, name) == 0)
            return (1);
        curr = curr->next;
    }
    return (0);
}

/**
 * handle_send_money - handle send money to another account
 * @head: head of the list
 * @name: name of the account
 */

void handle_send_money(bank **head, char *name)
{
    char *to;
    int amount;
    bank *from = *head;
    bank *to_send = *head;

    to = malloc(sizeof(char) * 50);
    printf("Account name to send money: ");
    scanf("%s", to);
    if (!check_name(*head, to))
    {
        printf("Account not found\n");
        return;
    }
    printf("Amount to send: ");
    scanf("%d", &amount);

    while (from)
    {
        if (strcmp(from->owner, name) == 0)
            break;
        from = from->next;
    }
    while (to_send)
    {
        if (strcmp(to_send->owner, to) == 0)
            break;
        to_send = to_send->next;
    }

    if (from->balance < amount)
    {
        printf("You don't have enough funds\n");
        return;
    }
    from->balance -= amount;
    to_send->balance += amount;
}

/**
 * handle_check_balance - checks the balance
 * @head: head of the list
 * @name: name of the account
 */

void handle_check_balance(bank *head, char *name)
{
    bank *curr = head;

    while (curr)
    {
        if (strcmp(curr->owner, name) == 0)
        {
            printf("\n\n\nYour account balance is: %d$\n\n\n", curr->balance);
            return;
        }
        curr = curr->next;
    }
    printf("A problem happend, sorry we will fix it soon\n");
}

/**
 * handle_change_password - changes the password
 * @head: head of the list
 * @name: name of the account
 */

void handle_change_password(bank **head, char *name)
{
    bank *curr = *head;
    int password;
    while (curr)
    {
        if (strcmp(curr->owner, name) == 0)
        {
            do
            {
                printf("Enter your new password: ");
                scanf("%d", &password);
            } while (check_password(*head, password));
            curr->password = password;
            printf("Password changed Successfuly\n");
            return;
        }
        curr = curr->next;
    }
    printf("A problem happend, sorry we will fix it soon\n");
}

/**
 * handle_log_out - logs out the user
 * @name: name of the account
 * @password: password of the account
 */

void handle_log_out(char **name, int *password)
{
    free(*name);
    *name = NULL;
    password = 0;
}
