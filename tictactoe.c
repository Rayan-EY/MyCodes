#include <stdio.h>
#include <stdlib.h>

int vert_line(char a[][3]);
int hori_line(char a[][3]);
int diag_line(char a[][3]);
void main()
{   
    printf("\nWelcome to TICTACTOE!\n");
    
    int diagonal,horizontal,vertical,choice;
    int ch,p;
    char x='X';
    L1:
    {
    char a[3][3]={32,32,32,32,32,32,32,32,32};
    int b[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};
    
    printf(" __________________________ \n");
    printf("|       |         |        |\n");
    printf("|   1   |    2    |    3   |\n");
    printf("|_______|_________|________|\n");
    printf("|       |         |        |\n");
    printf("|   4   |    5    |    6   |\n");
    printf("|_______|_________|________|\n");
    printf("|       |         |        |\n");
    printf("|   7   |    8    |    9   |\n");
    printf("|_______|_________|________|\n");

    printf("The positions you can enter are given above\n");
    for(int i=1,h=0;i<=9,h<9;i++,h++)
    {
        
        if(i%2!=0)
            {
                x='X';
                p=1;
            }
        else
            {
                x='O';
                p=2;
            }
            L:
        {
            printf("Enter the position you want to put %c for player %d\n",x,p);
            scanf("%d",&ch);
            
            for(int j=0;j<9;j++)
            {
                if(b[j]==ch)
                    {
                        printf("The number you entered is already registered with an X or O, Try again\n");
                        goto L;
                    }
            }

            b[h]=ch;
            switch(ch)
        {
            case 1: a[0][0]=x;
                    break;

            case 2: a[0][1]=x;
                    break;

            case 3: a[0][2]=x;
                    break;
                
            case 4: a[1][0]=x;
                    break;

            case 5: a[1][1]=x;
                    break;

            case 6: a[1][2]=x;
                    break;

            case 7: a[2][0]=x;
                    break;

            case 8: a[2][1]=x;
                    break;

            case 9: a[2][2]=x;
                    break;

            default: printf("Invalid no.\n");
                     goto L;
                     break;
        
        }
               printf(" __________________________ \n");
               printf("|       |         |        |\n");
               printf("|  %c    |    %c    |    %c   |\n",a[0][0],a[0][1],a[0][2]);
               printf("|_______|_________|________|\n");
               printf("|       |         |        |\n");
               printf("|  %c    |    %c    |    %c   |\n",a[1][0],a[1][1],a[1][2]);
               printf("|_______|_________|________|\n");
               printf("|       |         |        |\n");
               printf("|  %c    |    %c    |    %c   |\n",a[2][0],a[2][1],a[2][2]);
               printf("|_______|_________|________|\n");

            vertical=vert_line(a);
            horizontal=hori_line(a);
            diagonal=diag_line(a);

            if(vertical == 1)
                {
                    printf("Player %d wins! Congrats!!\n",p);
                    L2:
                    {
                    printf("Enter 1 to exit\nEnter 2 to play again\n");
                    scanf("%d",&choice);
                    if(choice == 1)
                    {
                        exit(0);
                    }
                    else
                        if(choice==2)
                        {
                            goto L1;
                        }
                        else
                        {
                            printf("Invalid choice\n");
                            goto L2;
                        }
                    }}
            if(horizontal == 1)
                {
                    printf("Player %d wins! Congrats!!\n",p);
                    goto L2;
                }
            
            if(diagonal == 1)
                {
                    printf("Player %d wins! Congrats!!\n",p);
                    goto L2;          
                }

        }}

        }

    printf("Its a DRAW!\n");
    goto L2;

}



int vert_line(char a[3][3])
{
    int j;
    for(j=0;j<3;j++)
    {
        int i=0;
        
            if((a[i][j]==a[i+1][j] && a[i+1][j]==a[i+2][j]) && (a[i][j]!=32 && a[i+1][j]!=32 && a[i+2][j]!=32))
            {
                return 1;
            }
        
    }
    return 0;

}

int hori_line(char a[3][3])
{
    int i;
    for(i=0;i<3;i++)
    {
       int j=0;
        
            if((a[i][j]==a[i][j+1] && a[i][j+1]==a[i][j+2]) && (a[i][j]!=32 && a[i][j+1]!=32 && a[i][j+2]!=32) )
            {
                return 1;
                
            }

    }
    
    return 0;

}

int diag_line(char a[3][3])
{
    if((a[0][0]==a[1][1] && a[1][1]==a[2][2]) && (a[0][0]!=32 && a[1][1]!=32 && a[2][2]!=32))
        return 1;
    else
        if((a[0][2]==a[1][1] && a[1][1]==a[2][0]) && (a[0][2]!=32 && a[1][1]!=32 && a[2][0]!=32))
       return 1;
    
    return 0;
}
