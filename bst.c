#include <stdio.h>
#include <stdlib.h>
struct BSTNode{
int info;
struct BSTNode *left;
struct BSTNode *right;
};
struct BSTNode *root=NULL;

void insert()
{
    struct BSTNode *par;
    struct BSTNode *n=(struct BSTNode *)malloc(sizeof(struct BSTNode));
    printf("\n Enter element to insert : ");
    scanf("%d",&n->info);
    n->left=NULL;
    n->right=NULL;
    if(root==NULL)
        root=n;
        else
        {
            par=root;
            while(par)
            {
                if(par->info>n->info)
                {
                    if(par->left==NULL)
                        par->left=n;
                    par=par->left;
                }
                else if(par->info<n->info)
                {
                    if(par->right==NULL)
                        par->right=n;
                    par=par->right;
                }
                else par=par->left;
            }//while
        } //else
}//end_function


int delet(struct BSTNode *trav,int data)
{
    struct BSTNode *temp;
    printf("\n Enter the element for delete : ");
    scanf("%d",&data);
    if(root==NULL)
        printf("\n no such element exixt !!!");
    else if(data<trav->info)
        trav->left=delet(trav->left,data);
    else if(data>trav-info)
        trav->right=delet(trav->right,data);

        else   //data found
        {
            if(root->left&&root->right)  //both children
            {
                temp=find_max(root);
                root->info=temp->info;
                root->left=delet(root->left,root->info);
            }
            else // one or zero child
            {

            }
        }



}
int search()
{
    int data;
    struct BSTNode *del;
    printf("\n Enter element for search : ");
    scanf("%d",&data);
    if(root==NULL)
        printf("\n Tree is empty!!!element not found");
    else
    {
        del=root;
        while(del!=NULL)
        {
            if(del->info>data)
                del=del->left;
            else
                if(del->info<data)
                    del=del->right;
            else
            {
                printf(" Element found....");
                del=del->left;
                return 0;
            }
            if(del==NULL)
                printf("\n Element not found!!!");
        }
    }
return 0;
}

void inOrder(struct BSTNode *trav)
{
    if(trav)
    {
        if(trav->left!=NULL)
            inOrder(trav->left);
        printf("\t%d",trav->info);
        if(trav->right!=NULL)
            inOrder(trav->right);
    }

}
void preOrder(struct BSTNode *trav)
{
    if(trav)
    {
        printf("\t%d",trav->info);
        if(trav->left!=NULL)
            preOrder(trav->left);
        if(trav->right!=NULL)
            preOrder(trav->right);
    }
}

void postOrder(struct BSTNode *trav)
{
    if(trav)
    {
        if(trav->left!=NULL)
            postOrder(trav->left);
        if(trav->right!=NULL)
            postOrder(trav->right);
        printf("\t%d",trav->info);
    }
}
int main()
{
    int choice;
    printf("***PROGRAM OF BINARY SEARCH TREE***\n");
    do
    {
        printf("\n press 1 to insert a new element on tree :");
        printf("\n press 2 to delete a element from tree :");
        printf("\n press 3 to search  a element in tree :");
        printf("\n press 4 for inOrder traversal : ");
        printf("\n press 5 for preOrder traversal :");
        printf("\n press 6 for postOrder traversal :");
        printf("\n press 7 for exit : ");
        printf("\n Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :insert();
                    break;
            case 2 :printf("\n Enter value of node to be deleted :");
                    scanf("%d",&data);
                    delet(root,data);
                    break;
            case 3 :search();
                    break;
            case 4 :inOrder(root);
                    break;
            case 5 :preOrder(root);
                    break;
            case 6 :postOrder(root);
                    break;
            case 7 :exit(0);
            default : printf("\nOOOPS....Wrong choice.Renter your choice :");
                        break;
        }//end of switch
    }while(1);
    return 0;
}
