
#include<iostream>
using namespace std;
       class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };


Node* reverse(Node* head){
	if(head==NULL && head->next==NULL){
		return head;
	}
	Node* pre=NULL;
	Node* curr=head;
	Node* next1=NULL;
	while(curr!=NULL){
		next1=curr->next;
		curr->next=pre;
		
		pre=curr;
		curr=next1;
	}
	return pre;
}
void insertattail(Node* &head,Node*&tail,int val){
	Node* temp=new Node(val);
	if(head==NULL){
       head=temp;
	   tail=temp;
	}
	else{
		tail->next=temp;
		tail=temp;
	}
}
Node* add(Node* head1,Node* head2){
	int carry=0;
	Node* anshead=NULL;
	Node* anstail=NULL;
	while(head1!=NULL ||head2!=NULL || carry!=0){
		int val=0;
		if(head1!=NULL){
			val=head1->data;
		}
		int val2=0;
		if(head2!=NULL){
			val2=head2->data;
		}
		int sum=val+val2+carry;
		int digit=sum%10;
		insertattail(anshead,anstail,digit);
		carry=sum/10;
		if(head1!=NULL)
		head1=head1->next;
		if(head2!=NULL)
		head2=head2->next;
	}
	return anshead;
}
Node *addLL(Node *head1, Node *head2)
{
    // Write your code here
	//reverse
	//find digit
	////create node for digit
	//find carry
	head1=reverse(head1);
	head2=reverse(head2);
	Node* ans=add(head1,head2);
	ans=reverse(ans);
	while(ans->data==0 && ans->next!=NULL){
		ans=ans->next;
	}
    
	return ans;
}
int main(){
    cout<<"everthing is okk print it later on";
    return 0;
}
