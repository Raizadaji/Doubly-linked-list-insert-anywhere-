#include<iostream>
using namespace std;
struct node{
int data;
node *prev;
node *next;
};
node * eol(node *,node *);
node * fol(node *,node *);

char mol(node *,node *,int);
main(){
node *temp, *head=NULL,*tail=NULL;
char ch;
int o;
cout<<"where to add next nodes \n1. Front\n2. Back\t";
cin>>o;
o==1?(cout<<"node will be inserted in the front."<<endl):(cout<<"node will be inserted at the end."<<endl);
do{
    temp=new node();
    cout<<"enter data : ";
    cin>>temp->data;
if(head==NULL){
    temp->prev=NULL;
    temp->next=NULL;
    head=tail=temp;
}
else
    {
    if(o==1){
        head=fol(head,temp);
    }
    else
    {
        tail=eol(tail,temp);
    }
}
    cout<<"do you want to add more data : ";
    cin>>ch;

}while(ch=='y'||ch=='Y');

temp=head;
while(temp!=NULL)
{
    cout<<temp->data<<endl;
    temp=temp->next;
}

cout<<"do you want to add a element in middle [Y/N] : ";
cin>>ch;
if(ch=='y'||ch=='Y'){
    cout<<"where do u want to add node : ";
    cin>>o;
    temp=new node;
    cout<<"enter new data : ";
    cin>>temp->data;
    if(o==0){
        fol(head,temp);
    }
    else {
    o=o-1;
    if((mol(head,temp,o)))
    {
        eol(tail,temp);
    }
    }

}

temp=head;
while(temp!=NULL)
{
    cout<<temp->data<<endl;
    temp=temp->next;
}
}
char mol(node *h,node *t,int n)
{   node *temp;
    temp=h;
    while(n>0){
        temp=temp->next;
        n--;
    }
    if(temp->next==NULL){
            return 'l';
    }
	temp->next->prev=t;
    t->next=temp->next;
	t->prev=temp;
    temp->next=t;

    return NULL;
}

node * eol(node *t,node *temp){
    t->next=temp;
    temp->prev=t;
    t=temp;
    return t;
}
node * fol(node *h,node *temp){
    temp->next=h;
    h->prev=temp;
    h=temp;
    return h;
}
