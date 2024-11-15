// this is a code that will show an array displayed in a  square box and will have a highlighted
// that can navigate through the complete array on the screen using w,s,d,a
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int getch(void) {
    struct termios oldt, newt;
    int ch;

    // Save the current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Read a single character
    ch = getchar();

    // Restore the old terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}


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
                    printf("\e[42m %c \e[0m", display[i][j]);
                }
                else
                {
                    printf(" %c ", display[i][j]);
                }
            }
        }
        printf("x>[%d] y>[%d]\n",x,y);
        buff = getch ();
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
            if (y >= cor_y) // if exceeds downwards
            {
                x++;
                y = 0;
            }
            if (x >= cor_x) // if exceeds right
            {
                y++;
                x = 0;
            }
            if (y <= 0) // if exceeds upwards
            {
                x++;
                y = cor_y - 1;
            }
            if (x <= 0) // if exceeds left
            {
                x = cor_x;
                y++;
            }
            // if(x>=cor_x&&y>=cor_y)//if exceeds down right
            // {
            //     x=0;
            //     y=0;
            // }
            // if (x<=0&&y<=0)//if exceeds upeer left
            // {
            //     x=cor_x;
            //     y=cor_y;
            // }
            // if(x<=cor_x)//if exceeds upper right
            // {
            //     x=0;
            //     y=cor_x;
            // }
            // if (x<=0&&y>=cor_y)
            // {
            //     x=cor_x;
            //     y=0;
            // }
            
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