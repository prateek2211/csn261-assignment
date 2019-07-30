#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/**
 * Raises error with error code 1
 * @param message Message to be printed to stdout
 */
void error(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
int lenOut;
/**
 * Encrypts the given input data
 * @param input Given Input Data
 */
char *encrypt(char *input, int n, int a, int b)
{
    char *buffer = (char *)calloc(n, sizeof(char));
    lenOut = (int)(strlen(input) / (double)n + 1) * n;
    char *output = (char *)calloc(lenOut, sizeof(char));
    char temp[n];
    for (int i = 0; i < strlen(input); i += n)
    {
        strncpy(buffer, input + i, n);
        for (int j = 0; j < n; j++)
            temp[j] = buffer[(a * j + b) % n];
        memcpy(output + i, temp, sizeof(temp));
    }
    free(buffer);
    return output;
}
int main(int argc, char const *argv[])
{
    if (argc < 5)
        error("Error: Missing arguments");
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    char *inputFile = strdup(argv[4]);
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob1/output.txt", "w");
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input))
    {
        char *enc = encrypt(buffer, n, a, b);
        fwrite(enc, sizeof(char), lenOut, output);
    }
    return 0;
}
