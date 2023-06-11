#include "bank.h"

/**
 * welcome_bank - welcome the user to the bank
 * @head: head of the list
 * @name: name of the account
 * @password: password of the account
 * @op: operation to perform
 */

void welcome_bank(bank **head, char **name, int *password, int *op)
{
    while (!(*name))
    {
        printf("Welcome to your bank\n");
        printf("Choose an operation:\n1-Log in\n2-Sign in\n");
        scanf("%d", &(*op));
        if (*op == 1)
            handle_login(*head, name, password);
        if (*op == 2)
        {
            printf("Enter your name: ");
            *name = malloc(sizeof(char) * 50);
            scanf("%s", *name);
            printf("Enter your password: ");
            scanf("%d", password);
            if (!open_account(head, *name, *password))
            {
                printf("Failed to open account, try again.\n");
                free(*name);
                *name = NULL;
            }
        }
    }
}

/**
 * main - entry point
 * Return: 0 on success
 */

int main()
{
    bank *head = NULL;
    int op;
    char *name = NULL;
    int password;
    load_nodes(&head, &name, &password);
    welcome_bank(&head, &name, &password, &op);
    while (name)
    {
        printf("Current user %s\n", name);
        printf("Choose an operation:\n1-Open account for family\n2-Close account\n3-Withdraw money\n4-Deposit money\n5-Send money\n6-Check balance\n7-Change password\n8-Log out\nOR press '0' to exit.\n>>");
        scanf("%d", &op);
        if (op == 0)
        {
            printf("Exiting...\n");
            save_nodes(&head, &name, &password);
            exit(1);
        }
        else if (op == 1)
            handle_open_account(&head);
        else if (op == 2)
            handle_close_account(&head, name, password);
        else if (op == 3)
            handle_withdraw(&head, name);
        else if (op == 4)
            handle_deposit(&head, name);
        else if (op == 5)
            handle_send_money(&head, name);
        else if (op == 6)
            handle_check_balance(head, name);
        else if (op == 7)
            handle_change_password(&head, name);
        else if (op == 8)
        {
            handle_log_out(&name, &password);
            welcome_bank(&head, &name, &password, &op);
        }
        else
            printf("Invalid operation\n");
    }
    return (0);
}
