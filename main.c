// this is a code that will show an array displayed in a  square box and will have a highlighted
// that can navigate through the complete array on the screen using w,s,d,a
#include <stdio.h>
#include <termios.h>
#include <termios.h>

void display(int cor_x, int cor_y, char display[20][21]) // code to display the display in the terminal
{
    char buff = 'o';
    int x = 0, y = 0;
    while (buff != 'q')
    {
        putchar(' ');
        for (int i = 0; i < cor_y; i++) // loop to iteratete into y cordinate or the height of display
        {
            for (int j = 0; j < cor_x; j++) // loop to iterate into x cordinate or width of the display
            {
                if (i == y && j == x)
                {
                    printf("\e[42m %c \e[0m",display[i][j]);
                }
                else
                {
                    printf(" %c ",display[i][j]);
                  
                }
            }
        }
        buff =getchar();
        switch (buff)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'd':
            x++;
            break;
        case 'a':
            x--;
            break;
       case 'e':
            x++;
            y--;
            break;
       case 'z':
            x--;
            y++;
            break;
        default:
            if(y>=cor_y) 
            {
                x++;
                y=0;
            }
            else if(x>=cor_x)
            {
                y++;
                x=0;
            }
        }
         printf("\033[H\033[J");
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