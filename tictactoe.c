#include<stdio.h>
#include<stdlib.h>
void printcell(int n,int arr[][4]);
int check(int n,int arr[][4]);
void printwin(int n);
int main()
{
    int n=3,p,t;
    int arr[4][4];
    int num,x,y;
    flag:
    num=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[i][j]=-1;
        }
    }
    printcell(n,arr);
    while(num<=9)
    {
        printf("\n\n");
        if(num%2!=0)
        {
            flag1:
            printf("\tPlayer 1 turn (X). ");
            printf("Enter row & column: ");
            scanf("%d %d",&x,&y);
            if(arr[x][y]==-1)arr[x][y]=1;
            else
            {
                printf("\tInvalid cell. Try again! \n");
                goto flag1;
            }
        }
        else
        {
            flag2:
            printf("\tPlayer 2 turn (O). ");
            printf("Enter row & column: ");
            scanf("%d %d",&x,&y);
            if(arr[x][y]==-1)arr[x][y]=2;
            else
            {
                printf("\tInvalid cell. Try again! \n");
                goto flag2;
            }
        }

        {//print cell & check
            printcell(n,arr);
            if(check(n,arr))
            {
               printwin(check(n,arr));
               t=0;
                break;
            }
            else t=1;
        }
        num++;
    }
    if(t==1)printf("\n\n\tMatch tie!!\n");
    printf("\n\tWant to play again?\n");
    printf("\tYes: press 1.\n");
    printf("\tNo: press 2.\n\t");
    scanf("%d",&p);
    if(p==1)
    {
        system("cls");
        goto flag;
    }
    else
    {
        printf("\n\tThank You!\n");
    }


}

void printcell(int n,int arr[][4])
{
    for(int i=1;i<=n;i++)
    {
        printf("\t _________________________________________________");
        printf("\n");
        for(int j=1;j<=n;j++)
        {
            printf("\t | \t");
            if(arr[i][j]==-1)printf(" ");
            if(arr[i][j]==1)printf("X");
            if(arr[i][j]==2)printf("O");
            if(j==n)printf("\t | \t");
        }
        printf("\n");
        if(i==n)printf("\t _________________________________________________");
    }
}

int check(int n,int arr[][4])
{
   for(int i=1;i<=n;i++)
   {
       if(arr[i][1]==arr[i][2]&&arr[i][2]==arr[i][3]&&arr[i][3]!=-1)
       {
           return arr[i][1];
       }
       if(arr[1][i]==arr[2][i]&&arr[2][i]==arr[3][i]&&arr[3][i]!=-1)
       {
           return arr[1][i];
       }
   }
   if(arr[1][1]==arr[2][2]&&arr[2][2]==arr[3][3]&&arr[3][3]!=-1)return(arr[1][1]);
   if(arr[1][3]==arr[2][2]&&arr[2][2]==arr[3][1]&&arr[3][1]!=-1)return(arr[1][3]);
   return 0;
}


void printwin(int n)
{
    if(n==1)
    {
       printf("\n\n\tPlayer 1 Won!\n");
    }
    else
    {
        printf("\n\n\tPlayer 2 Won!\n");
    }
}



