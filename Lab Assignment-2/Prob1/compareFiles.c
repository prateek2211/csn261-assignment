#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * Check if given strings are equal
 */
bool buffEqual(char *a, char *b)
{
    if (strlen(a) != strlen(b))
        return false;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    FILE *f1 = fopen("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob1/decryptedOutputfile.txt", "r");
    FILE *f2 = fopen("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob1/input.txt", "r");
    char b1[1024], b2[1024];
    bool fileSame = false;
    while (fgets(b1, sizeof(b1), f1))
    {
        fgets(b2, sizeof(b2), f2);
        if (buffEqual(b1, b2))
            fileSame = true;
        else
        {
            fileSame = false;
            break;
        }
    }
    if (fileSame)
        printf("Files are same\n");
    else
        printf("Files are different\n");
    return 0;
}
