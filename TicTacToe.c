#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
    {
        

        char p1[1000],p2[1000];
        int i,j,x=0,y=0,m=0,n=0,c=1,checker=0,pos,winner=0,draw=0;
        char A[3][3];
        char B[]={'1','2','3','4','5','6','7','8','9'};
        int C[3][3];
        int flag1=0,flag2=0;
        C[0][0]=1;C[0][1]=2;C[0][2]=3;
        C[1][0]=4;C[1][1]=5;C[1][2]=6;
        C[2][0]=7;C[2][1]=8;C[2][2]=9;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                A[i][j]='_';
        }

        printf("  Welcome\n");
        do
        {
		printf("  Please Enter your Names \n");
        printf("  Player 1:  ");
        gets(p1);
        printf("  Player 2:  ");
        gets(p2);
        if(strcmp(p1,"")==0||strcmp(p2,"")==0)
        {
		printf("\n  Names cannot be empty\n\n");
        checker=1;
   	    }
   	    else
   	    checker=0;
    	}
   	    while(checker==1);
       
        printf("\n  %s gets X \n  %s gets O\n",p1,p2);
        printf("\n  Please enter your moves according to this grid: \n\n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                printf("       %d",C[i][j]);
            printf("\n\n");
           
        }
        printf("  Let's Begin\n");
        printf("---------------------------------------------------------------------------\n");

        do
        {
            if(c%2!=0)
                printf("Player 1:    %s's Turn : \n",p1);
            else
                printf("Player 2:    %s's Turn : \n",p2);
            printf("\n");
            printf("  Available Positions : \n   '_' means the position is unavaliable \n\t\t");
            for( i=0;i<9;i++)
                printf(" %c ",B[i]);
            printf("\n\n");
          
            printf("  Enter your move : ");
            scanf("%d",&pos);
            fflush(stdin);
            if(pos<1 ||pos>9)
                printf("   Invalid Move!!!\n  Select between 1 to 9 \n\n");
            else if(B[pos-1]=='_')
                printf("   Invalid Move!!!\n  Select a different position \n\n");
            else 
            {
                if(pos==1){x=0;y=0;}
                if(pos==2){x=0;y=1;}
                if(pos==3){x=0;y=2;}

                if(pos==4){x=1;y=0;}
                if(pos==5){x=1;y=1;}
                if(pos==6){x=1;y=2;}

                if(pos==7){x=2;y=0;}
                if(pos==8){x=2;y=1;}
                if(pos==9){x=2;y=2;}

                if(c%2==0)
                    A[x][y]='O';
                else
                    A[x][y]='X';
                B[pos-1]='_';
                c++;
                for(i=0;i<9;i++)
                {
                    if(B[i]=='_')
                        flag2++;
                }
                if(flag2==9)              
                {						
                    draw=1;
                    flag1=1;
            	}
                
                else
                    flag2=0;
                    
				printf("\n\n");
                for(i=0;i<3;i++)
                {
                    for(j=0;j<3;j++)
                        printf("\t \t %c  ",A[i][j]);
                    printf("\n\n\n");
                  
                }
            }
           
			int a;
            for(a=0;a<3;a++)
            {
                if((A[m][0]=='X'&& A[m][1]=='X'&& A[m][2]=='X')||(A[m][0]=='O'&& A[m][1]=='O'&& A[m][2]=='O'))
                {
                    flag1++;
                    if(c%2!=0) winner=2;
                    else winner=1;
                    break;
                }
                else m++;
            }
            m=0;

            for( a=0;a<3;a++)
            {
                if((A[0][n]=='X'&& A[1][n]=='X' && A[2][n]=='X')||(A[0][n]=='O'&& A[1][n]=='O'&& A[2][n]=='O'))
                {
                    flag1++;
                    if(c%2!=0) winner=2;
                    else winner=1;
                    break;
                }
                else n++;
            }
            n=0;

            if((A[0][0]=='X'&& A[1][1]=='X' && A[2][2]=='X')||(A[0][0]=='O'&& A[1][1]=='O'&& A[2][2]=='O'))
            {
                flag1++;
                if(c%2!=0) winner=2;
                else winner=1;
                break;
            }

            if((A[0][2]=='X'&& A[1][1]=='X' && A[2][0]=='X')||(A[0][2]=='O'&& A[1][1]=='O'&& A[2][0]=='O'))
            {
                flag1++;
                if(c%2!=0) winner=2;
                else winner=1;
                break;
            }

        }while(flag1==0);
        if(draw==1&&winner==0)
            printf("  It's a Tie! ");

        else if(winner==1)
            printf("  %s Wins!! Congrats!",p1);
        else
            printf("  %s Wins!! Congrats!",p2);
        printf("\n  Thank you for playing");
        getch();
    }
