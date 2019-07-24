#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int x = 953;
int y = 1268;
int red[953][1268];
int green[953][1268];
int blue[953][1268];
void removeBlue()
{

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (blue[i][j] > red[i][j] && blue[i][j] > green[i][j])
                blue[i][j] = 0;
        }
    }
}
void removeRed()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (red[i][j] > blue[i][j] && red[i][j] > green[i][j])
                red[i][j] = 0;
        }
    }
}
void removeGreen()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (green[i][j] > red[i][j] && green[i][j] > blue[i][j])
                green[i][j] = 0;
        }
    }
}
void preserveBlue()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (green[i][j] > blue[i][j] && green[i][j] > red[i][j])
                green[i][j] = 0;
            else if (red[i][j] > blue[i][j] && red[i][j] > green[i][j])
                red[i][j] = 0;
        }
    }
}
void preserveRed()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (green[i][j] > blue[i][j] && green[i][j] > red[i][j])
                green[i][j] = 0;
            else if (blue[i][j] > red[i][j] && blue[i][j] > green[i][j])
                blue[i][j] = 0;
        }
    }
}
void preserveGreen()
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (blue[i][j] > red[i][j] && blue[i][j] > green[i][j])
                blue[i][j] = 0;
            else if (red[i][j] > blue[i][j] && red[i][j] > green[i][j])
                red[i][j] = 0;
        }
    }
}
void inputFile(char *name, int arr[x][y])
{
    FILE *file = fopen(name, "r");
    char buffer[51200];
    int x = 0;
    while (fgets(buffer, 51200, file))
    {
        int y = 0;
        for (char *tok = strtok(buffer, ","); tok; tok = strtok(NULL, ",\n"))
        {
            arr[x][y++] = atoi(tok);
        }
        x++;
    }
    fclose(file);
}
void pixelValue(int x, int y)
{
    printf("Pixel Value at (%d,%d) :Blue = %d Red = %d Green = %d\n", x, y, blue[x][y], red[x][y], green[x][y]);
}
int main(int argc, char const *argv[])
{
    inputFile("/home/prateek/Downloads/2019_CSN-261_L1_Q3_SampleTestcases/Q3_Input/Q3_ip_Green.dat", green);
    inputFile("/home/prateek/Downloads/2019_CSN-261_L1_Q3_SampleTestcases/Q3_Input/Q3_ip_Red.dat", red);
    inputFile("/home/prateek/Downloads/2019_CSN-261_L1_Q3_SampleTestcases/Q3_Input/Q3_ip_Blue.dat", blue);
    printf("Before removing green\n");
    pixelValue(1, 2);
    pixelValue(16, 12);
    pixelValue(500, 600);
    removeGreen();
    FILE *writer = fopen("/tmp/program.txt", "w");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y - 1; j++)
            fprintf(writer, "%d,", green[i][j]);
        fprintf(writer, "%d", green[x - 1][y - 1]);
        fprintf(writer, "\n");
    }
    printf("After removing green\n");
    pixelValue(1, 2);
    pixelValue(16, 12);
    pixelValue(500, 600);
    fclose(writer);
    return 0;
}