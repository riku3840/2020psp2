#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define U_A 170.8
#define U_B 169.7
#define SIGMA_A 5.43
#define SIGMA_B 5.5

extern double p_stdnorm(double z);

int main(void)
{
    double val,sigma_a,sigma_b,u_a,u_b,z_a,z_b,x_a,x_b;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L_a=1,L_b=1;
    u_a=U_A;
    u_b=U_B;
    sigma_a=SIGMA_A;
    sigma_b=SIGMA_B;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
        z_a=(val-u_a)/sigma_a;
        z_b=(val-u_b)/sigma_b;
        x_a=p_stdnorm(z_a); 
        x_b=p_stdnorm(z_b);
        L_a=L_a*x_a;
        L_b=L_b*x_b;

    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",L_a);
    printf("L_B: %f\n",L_b);

    return 0;


}

double p_stdnorm(double z)
{
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

