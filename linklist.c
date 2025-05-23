#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

void AddAtStart(Node **HdN,int val)
{
    Node *NwN = (Node*)malloc(sizeof(Node));
    NwN->data = val;
    NwN->next = NULL;
    NwN->next = *HdN; // link the new node with previous one
    (*HdN) = NwN;    // new head updated
}

void AddAtLast(Node **HdN,int val)
{
    Node *NwN = (Node *)malloc(sizeof(Node));
    NwN->data = val;
    NwN->next = NULL;
    if(*HdN == NULL){ *HdN = NwN; return;}
    Node *tmpN = *HdN;
    while(tmpN->next!=NULL)
    {
        tmpN = tmpN->next;
    }
    tmpN->next = NwN;
}
// 1 2 3 4 5 6
// indx = 4 
void AddAtMiddle(Node **HdN,int val,int indx)
{
    Node *NwN = (Node*)malloc(sizeof(Node));
    NwN->data=val;
    NwN->next=NULL;
    if(*HdN == NULL)
    {
        *HdN = NwN;   // add at head
        return;
    }
    Node *tmpN = *HdN;int Cnt=0;
    while(tmpN!=NULL && Cnt < indx-1)
    {
        tmpN = tmpN->next;
        Cnt++;
    }
    if(tmpN==NULL)
    {
        printf("indx is out of bond");
        free(NwN);
        return;
    }
        NwN->next = tmpN->next;
        tmpN->next = NwN;
}

void ShowList(Node *HdN)
{
    Node *tmpN = HdN;
    if(tmpN==NULL) 
    {
        printf("List is empty");
        return;
    }else
    {
        while(tmpN!=NULL)
        {
            printf("%d\t",tmpN->data);
            tmpN = tmpN->next ;
        }
    }
}

int main(void)
{
   Node *HdN = NULL;
    int c = 0, n = 0, indx = 0;

    while (1)
    {
        printf("\nEnter Choice\n1.First\n2.Last\n3.Middle\n4.Show\n5.Exit\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            printf("Enter value to add at start: ");
            scanf("%d", &n);
            AddAtStart(&HdN, n);
            break;

        case 2:
            printf("Enter value to add at last: ");
            scanf("%d", &n);
            AddAtLast(&HdN, n);
            break;

        case 3:
            printf("Enter value to add: ");
            scanf("%d", &n);
            printf("Enter index to insert at: ");
            scanf("%d", &indx);
            AddAtMiddle(&HdN, n, indx);
            break;

        case 4:
            ShowList(HdN);
            break;

        case 5:
            // Free list before exit (optional)
            while (HdN != NULL)
            {
                Node *tmp = HdN;
                HdN = HdN->next;
                free(tmp);
            }
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;    
}
