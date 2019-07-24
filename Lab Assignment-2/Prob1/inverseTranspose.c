#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *file = fopen("/home/prateek/Documents/csn261-assignment/Lab Assignment-2/Prob1/output.txt", "rb");
    char *enc = calloc(15, sizeof(char));
    fread(enc, sizeof(char), 15, file);
    printf("%s\n", enc);
    return 0;
}
