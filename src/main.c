#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define GOST_IMPLEMENTATION
#include "gost.h"

int main(void) {
    printf("GOST R 34.12-2015 implementation\n");

    uint8_t key[32] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F
    };
    uint8_t plaintext[8] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77};
    uint8_t ciphertext[8];
    uint8_t decrypted[8];

    gost_context_t ctx;
    if (gost_init(&ctx, key, sizeof(key), 32) != GOST_NO_ERROR) {
        printf("Error initializing GOST context\n");
        return 1;
    }

    if (gost_encrypt(&ctx, plaintext, ciphertext) != GOST_NO_ERROR) {
        printf("Error encrypting data\n");
        return 1;
    }

    printf("Plaintext:  ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", plaintext[i]);
    }
    printf("\n");

    printf("Ciphertext: ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    if (gost_decrypt(&ctx, ciphertext, decrypted) != GOST_NO_ERROR) {
        printf("Error decrypting data\n");
        return 1;
    }

    printf("Decrypted:  ");
    for (int i = 0; i < 8; i++) {
        printf("%02X ", decrypted[i]);
    }
    printf("\n");
    
    return 0;
}

