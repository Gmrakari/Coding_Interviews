#include <iostream>
#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



struct Student {
	int number;
	char* name;
	int age;
};


struct ListNode
{
	Student *info;
	ListNode *next;
	ListNode(Student *info) : info->age = 0, info->name = NULL, info->number = 101, next(NULL) {
	}
	
	//ListNode() : info[0] = 0,info[1] = NULL, info[2] = 0, next(NULL) {}
	//ListNode(Student info[3]) : ListNode->info[0] = 0,ListNode->info[1] = NULL, ListNode->info[2] = 0, next(NULL) {}
	//ListNode(Student info[3], ListNode* next) : info[0] = 0,info[1] = NULL, info[2] = 0, next(next) {}
};

ListNode* add(ListNode* pHead, ListNode* node, int pos) {
	if (pHead == NULL || node == NULL || pos < 0) 
		return NULL;

	ListNode* newhead = pHead;
	ListNode* cur = newhead;
	ListNode* newnode = node;

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	cur->next = newnode;
	newnode->next = cur->next;

	return pHead;
}

ListNode* del(ListNode* pHead, int pos) {
	if (pHead == NULL || pos < 0) 
		return NULL;

	ListNode* temp = NULL;
	ListNode* newhead = pHead;
	ListNode* cur = newhead;

	for (int i = 0; i < pos; ++i) {
		cur = cur->next;
	}

	temp = cur;
	cur->next = temp->next;
	free(temp);
	return newhead;
}

ListNode* init() {
	ListNode *stu5 = new ListNode(105, "dawang", 21, NULL);
	ListNode *stu4 = new ListNode(104, "dayi", 20, std5);	
	ListNode *stu3 = new ListNode(103, "xiaojia", 22, std4);
	ListNode *stu2 = new ListNode(102, "xiaowang", 21, std3);
	ListNode *stu1 = new ListNode(101, "xiaoming", 20, stu2);

	ListNode *head = stu1;

	return head;
}

void traval(ListNode *pHead){
	if (pHead == NULL)
		return ;

	while (pHead) {
		cout << "number: " << pHead->info->number << "name: " << pHead->info->name << "age: " << pHead->info->age << endl;
		pHead = pHead->next;
	}
	
}

int main_92() {
	ListNode *phead = init();
	
	ListNode *addnode = new ListNode(106, "xinzeng", 22, NULL);
	
	traval(phead);
	cout << endl;
	
	
	
}
