#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
int main() {
	// your code goes here
	ListNode *head = NULL;
	ListNode *curr = head;
	for(int i=1;i<=5;i++){
	    ListNode *node = new ListNode(i);
	    if(head==NULL){
	        head = node;
	        curr = head;
	    }else{
	        curr->next = node;
	        curr=curr->next;
	    }
	}
	while(head!=NULL){
	    cout<<head->val<<" ";
	    head=head->next;
	}
	return 0;
}
