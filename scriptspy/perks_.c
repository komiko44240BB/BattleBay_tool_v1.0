#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <xlsxio_read.h>
#include <dirent.h>

#define MAX_PATH 260
#define MAX_BONUS_NAME 100

typedef struct {
    char object_name[MAX_PATH];
    char rarity[MAX_PATH];
    char first_bonus_value[MAX_PATH];
    char first_bonus_name[MAX_BONUS_NAME];
    char second_bonus_value[MAX_PATH];
    char second_bonus_name[MAX_BONUS_NAME];
} Item;

typedef struct ItemNode {
    Item item;
    struct ItemNode* next;
} ItemNode;

void process_xlsx_file(const char *filename);
void parse_bonus(const char *bonus, char *value, char *name);
void write_to_csv(const char *filename, ItemNode* head);

int main() {
    const char *folder_path = "../Perk_data/data";
    struct dirent *entry;
    DIR *dp = opendir(folder_path);

    if (dp == NULL) {
        perror("opendir");
        return 1;
    }

    while ((entry = readdir(dp))) {
        if (strstr(entry->d_name, ".xlsx")) {
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", folder_path, entry->d_name);
            process_xlsx_file(filepath);
        }
    }

    closedir(dp);
    return 0;
}

void process_xlsx_file(const char *filename) {
    xlsxioreader xlsxioread;
    xlsxioreadersheet sheet;
    const char *value;

    if ((xlsxioread = xlsxioread_open(filename)) == NULL) {
        fprintf(stderr, "Error opening .xlsx file: %s\n", filename);
        return;
    }

    if ((sheet = xlsxioread_sheet_open(xlsxioread, NULL, XLSXIOREAD_SKIP_EMPTY_ROWS)) == NULL) {
        fprintf(stderr, "Error opening sheet in .xlsx file: %s\n", filename);
        xlsxioread_close(xlsxioread);
        return;
    }

    ItemNode* head = NULL;
    ItemNode* current = NULL;

    while (xlsxioread_sheet_next_row(sheet)) {
        Item item;
        memset(&item, 0, sizeof(Item));

        xlsxioread_sheet_next_cell_string(sheet, &value);
        strncpy(item.object_name, value, MAX_PATH);

        xlsxioread_sheet_next_cell_string(sheet, &value);
        // Skip the perk column as it's not used in the structure

        xlsxioread_sheet_next_cell_string(sheet, &value);
        parse_bonus(value, item.first_bonus_value, item.first_bonus_name);

        xlsxioread_sheet_next_cell_string(sheet, &value);
        parse_bonus(value, item.second_bonus_value, item.second_bonus_name);
        xlsxioread_sheet_next_cell_string(sheet, &value);
        strncpy(item.rarity, value, MAX_PATH);

        // Create a new ItemNode and add it to the list
        ItemNode* newNode = malloc(sizeof(ItemNode));
        newNode->item = item;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    xlsxioread_sheet_close(sheet);
    xlsxioread_close(xlsxioread);

    // Write the items to CSV files
    write_to_csv("../Perk_data/", head);

    // Free the list
    current = head;
    while (current != NULL) {
        ItemNode* temp = current;
        current = current->next;
        free(temp);
    }
}

void parse_bonus(const char *bonus, char *value, char *name) {
    const char *separator = strchr(bonus, '-');
    if (separator) {
        size_t value_len = separator - bonus;
        char temp_value[MAX_PATH];
        strncpy(temp_value, bonus, value_len);
        temp_value[value_len] = '\0';

        // Check if the value ends with '%'
        if (temp_value[value_len - 1] == '%') {
            // Convert percentage to decimal
            float percentage = atof(temp_value);
            sprintf(value, "%.2f", percentage / 100.0);
        } else {
            strncpy(value, temp_value, MAX_PATH);
        }

        strncpy(name, separator + 1, MAX_BONUS_NAME);
    } else {
        char temp_value[MAX_PATH];
        strncpy(temp_value , bonus, MAX_PATH);

        // Check if the value ends with '%'
        if (temp_value[strlen(temp_value) - 1] == '%') {
            // Convert percentage to decimal
            float percentage = atof(temp_value);
            sprintf(value, "%.2f", percentage / 100.0);
        } else {
            strncpy(value, temp_value, MAX_PATH);
        }

        name[0] = '\0';
    }
}

void write_to_csv(const char *output_path, ItemNode* head) {
    ItemNode* current = head;
    char filename[MAX_PATH];
    char current_filename[MAX_PATH] = "";
    FILE *fp = NULL;

    while (current != NULL) {
        snprintf(filename, sizeof(filename), "%sevent_%s_%s.csv", output_path, current->item.rarity, current->item.object_name);

        if (strcmp(filename, current_filename) != 0) {
            if (fp != NULL) {
                fclose(fp);
            }
            strcpy(current_filename, filename);
            fp = fopen(filename, "a");
            if (fp == NULL) {
                perror("fopen");
                return;
            }
        }

        if (ftell(fp) == 0) {
            // File is empty, don't write newline
            fprintf(fp, "%s,%s,%s,%s", current->item.first_bonus_value, current->item.first_bonus_name, current->item.second_bonus_value, current->item.second_bonus_name);
        } else {
            // File is not empty, write newline
            fprintf(fp, "\n%s,%s,%s,%s", current->item.first_bonus_value, current->item.first_bonus_name, current->item.second_bonus_value, current->item.second_bonus_name);
        }

        current = current->next;
    }

    if (fp != NULL) {
        fclose(fp);
    }
}