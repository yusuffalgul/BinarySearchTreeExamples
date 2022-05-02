#include <stdio.h>
#include <stdlib.h>

typedef struct tagBST {
    int data;
    struct tagBST* left;
    struct tagBST* right;
}NODE;


NODE * add(NODE *tree,int x){ //Function used to add elements to the search tree
        if(tree == NULL){
            NODE * root = (NODE*) malloc(sizeof(NODE));
            root->left = NULL;
            root->right = NULL;
            root->data = x;
            return root;
        }
        if(tree->data < x){
            tree->right = add(tree->right,x);
            return tree;
        }
        tree->left = add(tree->left,x);
        return tree;

}


void printTree(NODE * tree){// Print from small to large with LNR(left-node-right)
    if(tree == NULL){
        return;
    }
    printTree(tree->left);
    printf("%d ",tree->data);
    printTree(tree->right);
}
void printTree2(NODE * tree){ // Print from large to small with RNL(right-node-left)
        if(tree == NULL){
            return;
        }
        printTree2(tree->right);
        printf("%d ",tree->data);
        printTree2(tree->left);

}

int findValue(NODE * tree,int searchingValue){//Find value in BST

     if(tree == NULL){
            return -1;
        }
        if(tree->data == searchingValue){//if value found at root
            return 1;
        }
        if(findValue(tree->right,searchingValue) == 1){//if value found at rigth leafs
            return 1;
        }
        if(findValue(tree->left,searchingValue) == 1){ //if value found at left leafs
            return 1;
        }
        return -1;//if value not found


}
NODE* findValue2(NODE* tree,int searchingValue){//Find value in BST
        if(tree != NULL){
            printf("Checking value : %d \n",tree->data);//Checking root value
            if(tree->data == searchingValue)
                printf("Found! : %d\n",tree->data);
        }

        if(tree->data == searchingValue || tree == NULL){//if value is found, return tree and finish search
            printf("Search is over");
            return tree;
        }
        if(searchingValue < tree->data){//move left if searched value is less than data
            findValue2(tree->left,searchingValue);
        }else{//move right if searched value is bigger than data
            findValue2(tree->right,searchingValue);

        }
}


int max(NODE * tree){//goes to the far right of the tree and finds the maximum
    while(tree->right != NULL){
        tree = tree ->right;
    }
    return tree->data;
}
int min(NODE * tree){//goes to the far left of the tree and finds the minimum
    while(tree->left != NULL){
        tree = tree ->left;
    }
    return tree->data;
}



int main()
{
    NODE * tree = NULL;
    tree = add(tree,4);
    tree = add(tree,2);
    tree = add(tree,1);
    tree = add(tree,3);
    tree = add(tree,6);
    tree = add(tree,5);
    tree = add(tree,7);
    tree = add(tree,8);
    tree = add(tree,9);
    tree = add(tree,10);




    printf("Small to Large with LNR \n");
    printTree(tree);
    printf("\n\n");


    printf("Large to Small with RNL\n");
    printTree2(tree);
    printf("\n\n");


    printf("Search Value\n");
    printf("Search result = %d \n",findValue(tree,9));
    printf("\n\n");


    printf("Search Value\n");
    findValue2(tree,5);
    printf("\n\n");



    printf("max : %d min : %d \n" , max(tree),min(tree));
    printf("\n\n");












    return 0;
}

