// this is a code that will show an array displayed in a  square box and will have a highlighted 
//that can navigate through the complete array on the screen using w,s,d,a
#include <stdio.h>


int main()
{
    char display[20][20];
    int cordinate_x = sizeof(display)/sizeof(display[0]);
    int cordinate_y = sizeof(display[0])/sizeof(display[0][0]);
    //code to fill the character array with desired character
    for(int y=0;y<cordinate_y;y++)//main loop to add characters to the y cordinate
    {
        for(int x=0;x<cordinate_x;x++)
        {
            display[x][y]='#';
        }
    }
    printf("%s ",display);
    return 0;
}