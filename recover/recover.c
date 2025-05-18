#include <cs50.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc > 2 || argc == 1)
    {
        printf("Please enter the name of the forensic image from which to recover JPEGs\n");
        return 1;
    }
    FILE *memory_card = fopen(argv[1], "rb");
    if (memory_card != NULL)
    {
        FILE *output_file = NULL;
        char filename[8];
        unsigned char x[512];
        int i = 0;
        while (fread(x, sizeof(x), 1, memory_card) == 1)
        {
            if (x[0] == 255 && x[1] == 216 && x[2] == 255 && (x[3] >= 224 && x[3] <= 239))
            {
                if (output_file != NULL)
                {
                    fclose(output_file);
                }
                sprintf(filename, "%03i.jpg", i);
                output_file = fopen(filename, "wb");
                i++;
            }
            if (output_file != NULL)
            {
                fwrite(x, sizeof(x), 1, output_file);
            }
        }
        if (output_file != NULL)
        {
            fclose(output_file);
        }
        fclose(memory_card);
    }
    else
    {
        printf("error!\n");
    }
}
