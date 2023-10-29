#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
}NODE;

NODE *create_list(NODE *);
NODE *ins_rear(int ele,NODE *first);
NODE *ins_pos(int ele,int pos, NODE *first);
NODE *ins_node(int ele,int node_ele,NODE *first);
NODE *del_node(int ele,NODE *first);
NODE *concat(NODE *first,NODE *second);
void display(NODE *first);
NODE *get_node();

NODE *get_node()
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    if(temp==NULL)
        printf("No memory available\n");
    
    return temp;
}

void main()
{
    NODE *first=NULL;
    int ch,node_ele,ele,pos;
    while(1) {

    printf("Enter:\n1 to create first list\n2 Insert a node at a given position\n3 Insert a node after a node\n4 Delete a node\n5 Concatenate two lists\n6 for display\n7 for exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: first=create_list(first);
                break;
        case 2: printf("Enter the element\n");
                scanf("%d",&ele);
                printf("Enter the position\n");
                scanf("%d",&pos);
                first=ins_pos(ele,pos,first);
                break;
        case 3: if(first==NULL)
                {
                    printf("List is empty\n");
                    break;
                }
                printf("Enter data field of the node\n");
                scanf("%d",&node_ele);
                printf("Enter the element to add\n");
                scanf("%d",&ele);
                first=ins_node(ele,node_ele,first);
                break;

        case 4: if(first==NULL)
                    printf("List is empty\n");

                else
                {
                    printf("Enter the data of the node you want to delete\n");
                    scanf("%d",&ele);
                    first=del_node(ele,first);
                
                }
                break;
        case 5: if(first==NULL)
                    printf("No list created, create by entering 1\n");
                else
                {
                    NODE *second=create_list(second);
                    printf("Enter the second list contents\n");
                    first=concat(first,second);
                    printf("Concatenated list is\n");
                    display(first);
                }
                break;
        
        case 6: if(first==NULL)
                    printf("List is empty\n");
                else {
                printf("Elements in the list are\n");
                display(first);
                }
                break;
        
        case 7: exit(0);

        default:printf("Enter valid choice between 1 and 7\n");                   
    }
}
}
NODE *create_list(NODE *first)
{
    int ch,ele;
    for(;;) {
    printf("Enter 1 to add a new node in the list or 2 to stop\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: printf("Enter the element\n");
                scanf("%d",&ele);
                first=ins_rear(ele,first);
                break;
                
        case 2: return first;
                
        default:printf("Enter 1 or 2\n");
                

    }

}
}

NODE *ins_rear(int ele,NODE *first)
{
    NODE *new=get_node();
    NODE *temp=NULL;
    new->data=ele;
    new->link=NULL;

    if(first==NULL)
    {
        return new;
    }

    temp=first;
    while(temp->link != NULL)
    {
        temp=temp->link;
    }
    temp->link=new;
    return first;
}

NODE *ins_pos(int ele,int pos,NODE *first)
{
    NODE *new=get_node();
    new->data=ele;
    NODE *cur=first,*prev=NULL;
    if(pos==1)
    {
        new->link=first;
        return new;
    }
    if(pos<1){
        printf("Invalid position\n");
        return first;
    }
    for(int i=1;i<pos;i++)
    {
        prev=cur;
        
        if(cur==NULL)
        {
            printf("Invalid position\n");
            return first;
        }
        cur=cur->link;
    }
    prev->link=new;
    new->link=cur;
    return first;
}

NODE *ins_node(int ele,int node_ele,NODE *first)
{
    NODE *new=(NODE *)malloc(sizeof(NODE));
    NODE *temp=first;
    
    new->data=ele;

    while(temp!=NULL)
    {
        if(temp->data==node_ele)
        {
            new->link=temp->link;
            temp->link=new;
            return first;
        }
        temp=temp->link;
    }
    printf("Node with the entered data is not present\n");
    return first;
}

NODE *del_node(int ele,NODE *first)
{
    if(first->data==ele)
        return first->link;        
    else {

    NODE *cur=first->link,*prev=first,*temp=NULL;
    while(cur!=NULL)
    {
        if(cur->data==ele)
        {
            temp=cur->link;
            prev->link=temp;
            return first;
        }
        
        prev=cur;
        cur=cur->link;
    }

    }   
    printf("Entered node is not present\n");
    return first;
}

NODE *concat(NODE *first,NODE *second)
{
    NODE *temp=first;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=second;
    return first;
}

void display(NODE *first)
{
    NODE *temp=first;
    while(temp->link!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("%d\n",temp->data);
}
