// this is a code that will show an array displayed in a  square box and will have a highlighted
// that can navigate through the complete array on the screen using w,s,d,a
#include <stdio.h>
void display(int cor_x, int cor_y, char display[20][21]) // code to display the display in the terminal
{putchar(' ');
    for (int i = 0; i < cor_y; i++) // loop to iteratete into y cordinate or the height of display
    {
        for (int j = 0; j < cor_x; j++) // loop to iterate into x cordinate or width of the display
        {
                putchar(display[i][j]);
                putchar(' ');
        }
    }
}

int main()
{
    char page[20][21];
    int cordinate_y = sizeof(page) / sizeof(page[0]);
    int cordinate_x = sizeof(page[0]) / sizeof(page[0][0]);
    // code to fill the character array with desired character
    for (int y = 0; y < cordinate_y; y++) // main loop to add characters to the y cordinate
    {
        for (int x = 0; x < cordinate_x; x++)
        {
            if (x == 20)
            {
                page[y][x] = '\n';  
            }
            else
                page[y][x] = '#';
        }
    }
    display(21, 20, page);

    return 0;
}