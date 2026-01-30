#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open card.raw.\n");
        return 1;
    }
    unsigned char buffer[512];

    FILE *outptr = NULL;
    int file_count = 0;
    char filename[8];

    while (fread(buffer, 512, 1, inptr) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            sprintf(filename, "%03i.jpg", file_count);
            file_count++;
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                printf("Could not create %s.\n", filename);
                fclose(inptr);
                return 2;
            }
        }

        if (outptr != NULL)
        {
            fwrite(buffer, 512, 1, outptr);
        }
    }
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    fclose(inptr);

    return 0;
}
