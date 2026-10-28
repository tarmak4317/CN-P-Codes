#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char in[100];
char out[100];
char in2[100];
char poly[] = "10001000000100001"; // Length is 17

void crc_div(char num[], int n, int m) {
    for(int i = 0; i < n; i++) {
        if(num[i] == '1') {
            for(int j = 0; j < m; j++) {
                num[i + j] = (((num[i + j] - '0') ^ (poly[j] - '0')) + '0');
            }
        }
    }
}

int main() {
    int poly_len = strlen(poly);

    printf("\nEnter string: ");
    scanf("%s", in);
    int n = strlen(in);

    // Copy message and pad with 16 zeros
    for(int i = 0; i < n + 16; i++) {
        if(i < n && (in[i] != '1' && in[i] != '0')) {
            printf("\nInvalid Input\n");
            exit(0);
        }
        
        if(i < n) {
            out[i] = in[i];
        } else {
            out[i] = '0';
        }
    }
    out[n + 16] = '\0'; // Null-terminate

    // Run encoder division
    crc_div(out, n, poly_len);
    printf("The transmitted message is: %s\n", out);

    // Receiver side (skipping validation for in2 just like the original)
    printf("\nEnter received string: ");
    scanf("%s", in2);

    // Run decoder division using original message length 'n'
    crc_div(in2, n, poly_len);

    // Check remainder (the last 16 bits)
    int n2 = strlen(in2);
    for(int j = n; j < n2; j++) {
        if(in2[j] == '1') {
            printf("\nError detected\n");
            return 0;
        }
    }
    
    printf("\nNo error detected\n");
    return 0;
}
