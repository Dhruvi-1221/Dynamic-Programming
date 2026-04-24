#include<stdio.h>
#include<limits.h>


int MultiplicationCost(int *arr,int n){
    int m[n][n];
    for(int i=0;i<n;i++){
        m[i][i]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j+i<n;j++){
            m[j][j+i]=INT_MAX;
            for(int k=j;k<i+j;k++){
                int p1=arr[j];
                int p2=arr[k+1];
                int p3=arr[i+j+1];
                int cost=m[j][k]+m[k+1][i+j]+(p1*p2*p3);
                if(cost<m[j][j+i]){
                    m[j][j+i]=cost;
                }
            }

        }
    }
    return m[0][n-1];
}

int main(){
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n+1];
    printf("Enter the %d dimensions: ", n+1);
    for(int i=0;i<=n;i++){
        scanf("%d",&p[i]);
    }
    int cost=MultiplicationCost(&p[0],3);
    printf("cost: %d",cost);
    return 0;
}
