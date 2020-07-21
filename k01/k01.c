#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double ave,double val,int i)
{
    return(((i-1)*ave)/i + val/i);
}
extern double var_online(double ave,double square_ave,int i,double val)
{
    return((i-1)*square_ave/i+pow(val,2)/i-pow((i-1)*ave/i+val/i,2));
}

int main(void)
{
    double val,ave,var,square_ave,ave2,ave3,var2,gosa;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    int i;
    i=0;
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
        i++;
        var=var_online(ave,square_ave,i,val);
        square_ave=ave_online(square_ave,pow(val,2),i);
        ave=ave_online(ave,val,i);
    }
    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }
    var2=i*var/(i-1);
    gosa=sqrt(var2/i);
    ave2=ave+gosa;
    ave3=ave-gosa;
    printf("sample mean=%lf\n",ave);
    printf("sample variance=%lf\n",var);
    printf("population mean=%lf~%lf\n",ave3 ,ave2);
    printf("population variance=%lf",var2);

    return 0;


}

