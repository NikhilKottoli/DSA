#include <stdio.h>


int solve(int e,int v,int arr[e][2],int val[v],int X){
    int count[v+1];for(int i=0;i<=v;i++) count[i] = 0;

    for(int i=0;i<e;i++){
        if(arr[i][0] == -1 || arr[i][1] == -1) continue;
        count[arr[i][0]]++;
        count[arr[i][1]]++;
    }
    
    for(int i = 1;i<=v;i++){
        if(count[i] == 1 && val[i-1] == X){
            val[i-1] = -1;
            printf("Deleting %d\n",i);
            for(int j=0;j<e;j++){
                if(arr[j][0] == i || arr[j][1] == i){
                    arr[j][0] = -1;arr[j][1] = -1;
                    printf("Changing");
                    return 1;
                }
            }
            
        }
    }

    return 0;
}

int main(){
    printf("Enter number of verices and edges");
    int v,e;scanf("%d%d",&v,&e);

    printf("Enter Vertices: ");
    int val[v];
    for(int i=0;i<v;i++) scanf("%d",&val[i]);

    int arr[e][2];
    
    for(int i=0;i<e;i++){
        int a,b;scanf("%d%d",&a,&b);
        arr[i][0]=a;
        arr[i][1]=b;
    }//Input ready

    printf("Enter X: ");
    int X;scanf("%d",&X);


    while(solve(e,v,arr,val,X)){
        printf("\n");
    }

    for(int i=0;i<v;i++){
        if(val[i] != -1){
            printf("%d ",val[i]);
        }
    }

    return 0;
}


// Mistakes Made:
// Not making count val+1;
// not checking if arr[i][0] == i