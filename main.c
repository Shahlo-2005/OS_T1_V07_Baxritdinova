
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 200

int palindrom(char s[]) {
    char *chap = s;
    char *ong = s + strlen(s);

    if (ong == chap) {
        return 1;
    }

    ong--;

    while (chap < ong) {
        while (chap < ong &&
               !isalnum((unsigned char)*chap)) {
            chap++;
        }

        while (chap < ong &&
               !isalnum((unsigned char)*ong)) {
            ong--;
        }

        if (tolower((unsigned char)*chap) !=
            tolower((unsigned char)*ong)) {
            return 0;
        }

        chap++;
        ong--;
    }

    return 1;
}

int palindrom_pointer(char *s) {
    char *chap = s;
    char *ong = s + strlen(s);

    if (ong == chap) {
        return 1;
    }

    ong--;

    while (chap < ong) {
        while (chap < ong &&
               !isalnum((unsigned char)*chap)) {
            chap++;
        }

        while (chap < ong &&
               !isalnum((unsigned char)*ong)) {
            ong--;
        }

        if (tolower((unsigned char)*chap) !=
            tolower((unsigned char)*ong)) {
            return 0;
        }

        chap++;
        ong--;
    }

    return 1;
}

int main(void) {
    char s[MAX];

    printf("Satr kiriting: ");

    if (fgets(s, sizeof(s), stdin) == NULL) {
        printf("Kiritishda xatolik!\n");
        return 1;
    }

    s[strcspn(s, "\n")] = '\0';

    if (strlen(s) == MAX - 1 && s[MAX - 2] != '\n') {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        printf("Satr juda uzun!\n");
        return 1;
    }

    printf("1-masala: %s\n",
           palindrom(s) ? "Palindrom" : "Palindrom emas");

    printf("2-masala: %s\n",
           palindrom_pointer(s) ?
           "Palindrom" : "Palindrom emas");

    return 0;
}
