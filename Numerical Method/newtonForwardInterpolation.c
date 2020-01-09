#include<stdio.h>
#include<math.h>

int main(){
    int n;
    float xp,p=1;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    float s,h,v,x[n],fx[n],fd[n];
    printf("Enter the value at which interpolation is needed: ");
    scanf("%f",&xp);
    printf("Enter the valus of x and y simultaneously: ");
    for (float i=0; i<n;i++){
        scanf("%f %f",&x[i],&fx[i]);
    }
    h=x[1]-x[0];
    s=(xp-x[0]/h);
    for(float i=0; i<n; i++){
        fd[i]=fx[i];
    }
    for(float i=0; i<n; i++){
        for(float j=0; j<n; j++){
            fd[j]=fd[j-1];
        }
    }
    v=fd[0];
    for(float i=1;i<n;i++){
        for(float j=1; j<i;j++){
            p=p*(s-j+1);
        }
        v=v+((fd[i]*p)/fact(i));
        p=1;
    }
    printf("%f",v);
    return 0;
}

int fact(int n){
    if ( n==1 )
		return 1;
	else
		return n* fact(n-1);
}