#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double ave,double val,int a)
{
    return(((a-1)*ave)/a + val/a);
}
extern double var_online(double val,double ave,double square_ave,int a)
{
    return((((a-1)*square_ave/a)+pow(val,2)/a)-pow(((a-1)*ave/a)+val/a,2));
}

int main(void)
{
    double val,ave,var,square_ave,ave2,var2;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int a;
    a=0;
    ave=0;
    var=0;
    square_ave=0;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%lf",&val);
        a++;
        square_ave=ave_online(square_ave,pow(val,2),a);
        ave=ave_online(ave,val,a);
        var=var_online(val,ave,square_ave,a);
    }
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    var2=a*var/(a-1);
    
    printf("sample mean=%lf\n",ave);
    printf("sample variance=%lf\n",var);
    printf("population mean=%lf\n",ave2);
    printf("population variance=%lf",var2);

    return 0;


}

