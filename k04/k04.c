#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct DATE{double ID;int gender;double height;};

int main(void)
{
    int i,gender,n,x;
    double val,id,ID;
    char fname1[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    FILE* fp1,*fp2;
    char buf1[256];
    char buf2[256];
    struct DATE date[14];
       
    printf("input the filename of sample height:");
    fgets(fname1,sizeof(fname1),stdin);
    fname1[strlen(fname1)-1]='\0';
    printf("the filename oe sample: %s\n",fname1);

    printf("input the filename of sample ID:");
    fgets(fname2,sizeof(fname2),stdin);
    fname2[strlen(fname2)-1]='\0';
    printf("the filename oe sample: %s\n",fname2);

    fp1 = fopen(fname1,"r");
    if(fp1==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    fp2 = fopen(fname2,"r");
    if(fp2==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
     while(fgets(buf1,sizeof(buf1),fp1) != NULL)
     {
        sscanf(buf1,"%d""%lf",&gender,&val);
        date[i].gender=gender;
        date[i].height=val;
        i++;
        n++;
     }
     i=0;
     while(fgets(buf2,sizeof(buf2),fp2) != NULL)
     {
        sscanf(buf2,"%lf",&id);
        date[i].ID=id;
        i++;
     }
     printf("which ID`s date do you want?:");
     scanf("%lf",&ID);
     printf("---\n");
     for(i=0;i<=n;i++)
     {
         if(date[i].ID==ID)
         {   
             printf("ID:%.0lf",date[i].ID);
             printf("gender");
             if(date[i].gender==1)
             {
                printf("male\n");
             }
             else
             {
                printf("female\n");
             }
             printf("height:%.1lf\n",date[i].height);
             x++;
         }
     }    
    if(x==0)
    {
        printf("No date");
    }
    printf("---");
}


























































