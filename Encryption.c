#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesar_shift(char *str, int key) {
    // Normalize key to [0, 25]
    int k = key % 26;
    if (k < 0) {
        k += 26;
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char base = isupper(str[i]) ? 'A' : 'a';
            str[i] = (str[i] - base + k) % 26 + base;
        }
        // Non-alphabetic characters remain unchanged
    }
}

void encrypt(char *str, int key) {
    caesar_shift(str, key);
}

void decrypt(char *str, int key) {
    // Decryption is encryption with negative key
    caesar_shift(str, -key);
}

int main() {
    char input[1000];
    int key;
    
    printf("Enter a string to encrypt: ");
    fgets(input, sizeof(input), stdin);
    // Remove trailing newline
    input[strcspn(input, "\n")] = 0;
    
    printf("Enter encryption key (integer): ");
    scanf("%d", &key);
    
    printf("\nOriginal: %s\n", input);
    
    char encrypted[1000];
    strcpy(encrypted, input);
    encrypt(encrypted, key);
    printf("Encrypted: %s\n", encrypted);
    
    char decrypted[1000];
    strcpy(decrypted, encrypted);
    decrypt(decrypted, key);
    printf("Decrypted: %s\n", decrypted);
    
    return 0;
}