#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * Stores length of input file
 */
unsigned long fileLen;
/**
 * Decrypts the given input
 * @param a decyption key
 * @param b decyption key
 */
char *decrypt(char *input, int n, int a, int b)
{
    char buffer[n];
    char *output = malloc(fileLen);
    for (int i = 0; i < fileLen; i += n)
    {
        memcpy(buffer, input + i, n);
        char temp[n];
        for (int j = 0; j < n; j++)
            temp[(a * j + b) % n] = buffer[j];
        memcpy(output + i, temp, n);
    }
    return output;
}
/**
 * Writes printable character of buffer to a file
 * @param name Name of output file
 * @param buffer Buffer to be written to the file
 */
void writeFile(char *name, char *buffer)
{
    FILE *output = fopen(name, "w");
    for (int i = 0; i <= fileLen; i++)
    {
        if (isprint(buffer[i]) || buffer[i] == '\n')
            fputc(buffer[i], output);
    }
}
/**
 * Return the character array by reading the file
 * @param name Name of the file
 */
char *readFile(char *name)
{
    FILE *file = fopen(name, "rb");
    char *buffer;

    fseek(file, 0, SEEK_END);
    fileLen = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (char *)malloc(fileLen + 1);
    fread(buffer, fileLen, 1, file);
    fclose(file);
    return buffer;
}
int main(int argc, char const *argv[])
{
    char *buffer = readFile("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob1/output.txt");
    char *dec = decrypt(buffer, 5, 3, 2);
    writeFile("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob1/decryptedOutputfile.txt", dec);
    free(buffer);
    return 0;
}
