#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node * link;
} node;

node * createNode (int val) {
	node * new = (node *) malloc (sizeof(node));
	new->val = val;
	new->link = NULL;
	return new;
}

node * insert(node * head, int val){
	node * t = head;
	node * temp = createNode(val);
	if(head == NULL){
		return temp;
	}
	while(t->link != NULL){
		t = t->link;
	}
	t->link = temp;
}

void display(node* head){
	while(head!=NULL){
		printf("%d -> ", head->val);
		head = head->link;
	}
}

int main(){
	int v, m = 1;

	printf("Enter the number of vertices: ");
	scanf("%d", &v);

	node * head = NULL;

	for (int i = 0; i < v; ++i)
	{
		head = insert(head, i+1);
		do{
			int u;
		printf("Enter the vertex (v): ");
		scanf("%d",  &u);
		insert(head, u);
		printf("Continue? ");
		scanf("%d", &m);
		} while(m!=0);
		display(head);
		printf("\n");
	}

	printf("Displaying List: \n");
	for (int i = 0; i < v; ++i)
	{
		
	}
}