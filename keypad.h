#include <reg51.h>
sbit R1=P1^0;
sbit R2=P1^1;
sbit R3=P1^2;
sbit R4=P1^3;
sbit C1=P1^4;
sbit C2=P1^5;
sbit C3=P1^6;
sbit C4=P1^7;
unsigned int z=0;
unsigned char input[5];

void lcd_keypad()
{
    z = 0;                 // ? VERY IMPORTANT RESET

    while(z < 4)
    {
        R1=0; R2=1; R3=1; R4=1;
        if(C1==0){ lcd_data('7'); input[z++]='7'; while(C1==0); }
        if(C2==0){ lcd_data('8'); input[z++]='8'; while(C2==0); }
        if(C3==0){ lcd_data('9'); input[z++]='9'; while(C3==0); }

        R1=1; R2=0; R3=1; R4=1;
        if(C1==0){ lcd_data('4'); input[z++]='4'; while(C1==0); }
        if(C2==0){ lcd_data('5'); input[z++]='5'; while(C2==0); }
        if(C3==0){ lcd_data('6'); input[z++]='6'; while(C3==0); }

        R1=1; R2=1; R3=0; R4=1;
        if(C1==0){ lcd_data('1'); input[z++]='1'; while(C1==0); }
        if(C2==0){ lcd_data('2'); input[z++]='2'; while(C2==0); }
        if(C3==0){ lcd_data('3'); input[z++]='3'; while(C3==0); }

        R1=1; R2=1; R3=1; R4=0;
        if(C2==0){ lcd_data('0'); input[z++]='0'; while(C2==0); }
    }

    input[4] = '\0';      // ? STRING TERMINATE (OUTSIDE LOOP)
}
