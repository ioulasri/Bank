#ifndef BANK_H
#define BANK_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct bank
{
    char *owner;
    int password;
    int balance;
    struct bank *next;
} bank;

int open_account(bank **head, char *name, int password);
int check_password(bank *head, int password);
int check_acc(bank *head, char *name, int password);
void display_account(bank *head);
void handle_open_account(bank **head);
void handle_close_account(bank **head, char *name, int password);
void handle_withdraw(bank **head, char *name);
void handle_deposit(bank **head, char *name);
void handle_send_money(bank **head, char *name);
void handle_check_balance(bank *head, char *name);
void handle_change_password(bank **head, char *name);
void handle_login(bank *head, char **name, int *password);
void handle_log_out(char **name, int *password);
void admin_prompt(bank *head);
void load_nodes(bank **head, char **name, int *password);
void save_nodes(bank **head, char **name, int *password);

#endif /* BANK_H */
