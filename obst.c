#include <stdio.h>
#include <stdlib.h>


/**
 * data structure to store the binary search tree
 */
typedef struct Node{
    int root;                               //to store the data in the root node
    int Depth;                              //to store the depth of the node
    struct Node *left;                      //to store the left sub tree
    struct Node *right;                     //to store the right sub tree
}Node;

static int dpt=0;                           //variable to store the maximum depth value
Node *node;                                 //creating a node structure variable



struct node *tree(int left, int right, int depth, int size, int r[][size]){
    struct Node *nd;
    if(left==right){
        nd = (Node*) malloc(sizeof(Node));
        nd->root=0;
    }else{
        nd = (Node*) malloc(sizeof(Node));
        nd->root = r[left+1][right];
        nd->Depth = depth;
        dpt++;
        nd->left = tree(left, r[left+1][right]-1,depth+1, size, r);
        nd->right = tree(r[left+1][right], right,depth+1, size, r);
    }
    return nd;
}



 
void display(Node *node,int i){
    if(node==NULL){
        return 0;
    }
    else {
        if(i==1){
            printf("%d, ",node->root);
        }
        else if(i>1){
            display(node->left,i-1);
            display(node->right,i-1);
        }
    }
}


int main(int argv, char *argc[])
{   
    //store the command line arguments in the p matrix 
    int n=argv-2;
    float p[n];
    for(int i=2; i<argv; i++){
        p[i-2]=atof(argc[i]);
    }

    float a[n+2][n+1];              //matrix to store the propabilities
    int r[n+2][n+1];                //matrix to store the root nodes 
    
    
    //intializing the a matrix with all zeros
    for(int i=0; i<=n+1; i++){
        for(int j=0;j<=n;j++){
            a[i][j]=0;
        }
    }
    
    //intializing the all r matrix values with zeros
    for(int i=0; i<=n+1; i++){
        for(int j=0;j<=n;j++){
            r[i][j]=0;
        }
    }
    
    //storing the p matrix values in the a matrix and r matrix
    for(int i=1;i<=n;i++){
        a[i][i-1]= 0;
        r[i][i-1]= 0;
        a[i][i]=p[i-1];
        r[i][i]= i;
    }
    
    
    int j;
    
    for(int d=1;d<=n-1; d++){                       // diaognal loop 
        for(int i=1; i<= n-d; i++){                 // diaognal element loop
            j=i+d;
            float m[j-i];
			int kvalue[j-i];
            int l=0;
            
            
            //calculating the sigma of p in the matrix
            for(int k = i; k<=j; k++){
                m[l]=a[i][k-1]+a[k+1][j];
                kvalue[l]=k;
                float s = 0;
                for(int c=i;c<=j;c++){
                    s = s + p[c-1];
                    
                }
                m[l] = m[l] + s;
                l++;
            }
            float pmin;
            int kmin;
            
            //storeing the intial values to find the minimun values of p and k
            pmin= m[0];
            kmin= kvalue[0];
			
            
            for(int q=1; q<l; q++){
                
                if(pmin>m[q]){
                    pmin = m[q];
                    kmin = kvalue[q];
                }
                
            }
            a[i][j] = pmin;
            r[i][j] = kmin;
            
            
    }
    
}

    
    node = tree(0, n, 0, n+1, r);                           //calling tree function to construc the binary search tree
    
    //dispaly the function according to the depth wise
    for(int i=1; i<dpt; i++){
        printf("depth %d: ",i-1);
        display(node,i); 
    }
	printf("\n");
    

    return 0;
}





