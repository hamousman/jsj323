
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ShoppingItem 
{
	char name[50]; // ��Ʒ����
	int quantity; // ��Ʒ����
	struct ShoppingItem* next; // ָ����һ���ڵ��ָ��
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL;

//�����Ʒ�������嵥��
void addItem(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	strcpy(newItem->name, itemName);
	
	if (shoppingList == NULL) {
		shoppingList = newItem;
	} else {
		struct ShoppingItem* current = shoppingList;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newItem;
	}
}

void addItem2(char itemName[], int itemQuantity) {
	struct ShoppingItem* newItem = (struct ShoppingItem*)malloc(sizeof(struct ShoppingItem));
	
	newItem->quantity = itemQuantity;
	newItem->next = NULL;
	strcpy(newItem->name, itemName);
	
	if (shoppingList2 == NULL) {
		shoppingList2 = newItem;
	} else {
		struct ShoppingItem* current = shoppingList2;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newItem;
	}
}

//�ӹ����嵥���Ƴ���Ʒ��
void removeItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* previous = NULL;
	
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (previous != NULL) {
				previous->next = current->next;
			} else {
				shoppingList = current->next;
			}
			free(current);
			break;
		}
		
		previous = current;
		current = current->next;
	}
}

//�鿴�����嵥
void displayList() {
	struct ShoppingItem* current = shoppingList;
	printf("�����嵥:\n");
	while (current != NULL) {
		printf("%s - ������%d\n", current->name, current->quantity);
		
		current=current->next;
		
	}
}
//�޸Ĺ����嵥
void updateQuantity(char itemName[], int newItemQuantity) {
	struct ShoppingItem* current = shoppingList;
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			
			current->quantity = newItemQuantity;
			
			break;
		}
		current = current->next;
	}
}

//��չ����嵥��
void clearList() {
	while (shoppingList != NULL) {
		
		struct ShoppingItem* temp = shoppingList;
		shoppingList = shoppingList->next;
		
		free(temp);
	}
	printf("�����������Ʒ\n");
}

//���㹺���嵥����Ʒ����������
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		
		total =total+ current->quantity;
		current = current->next;
		
	}
	return total;
}

//���ҹ����嵥�е���Ʒ��
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	
	printf("������Ʒ %s ��\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - ������%d\n", current->name, current->quantity);
			return;
		}
		
		current = current->next;
		
	}
	printf("δ�ҵ���Ʒ %s��\n", itemName);
} 

//�������嵥��
void sortList() {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* nextItem = NULL;
	char tempName[50];
	int tempQuantity;
	
	while (current != NULL) {
		nextItem = current->next;
		
		while (nextItem != NULL) {
			if (strcmp(current->name, nextItem->name) > 0) {
				
				strcpy(tempName, current->name);
				strcpy(current->name, nextItem->name);
				strcpy(nextItem->name, tempName);
				
				tempQuantity = current->quantity;
				current->quantity = nextItem->quantity;
				nextItem->quantity = tempQuantity;
			}
			nextItem = nextItem->next;
		}
		current = current->next;
	}
}

//�ϲ������嵥��
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	
	while (current->next != NULL) {
		current = current->next;
	}
	
	current->next = *list2;
	*list2 = NULL;
}

//ɾ�������嵥�е���Ʒ��
void deleteItem(char itemName[], int deleteAll) {
	struct ShoppingItem* current = shoppingList;
	struct ShoppingItem* prev = NULL;
	
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			if (prev == NULL) {
				struct ShoppingItem* temp = shoppingList;
				
				shoppingList = shoppingList->next;
				
				free(temp);
				if (!deleteAll) break;
			} else {
				
				prev->next = current->next;
				
				free(current);
				current = prev->next;
				if (!deleteAll) break;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}

int main() {
	
	addItem("�ֻ�", 2000);
	addItem("����", 3000);        
	addItem("ˮ��", 15);
	addItem("ë��", 10);
	
	
	displayList(); 
	
	printf("\n");
	removeItem("ˮ��"); 
	 
	displayList(); 
	
	printf("\n");
	
	updateQuantity("�ֻ�", 250); 
	
	displayList(); 
	
	
	printf("\n");
	
	
	printf("%d\n",totalQuantity());
	
	printf("\n");
	
	findItem("�ֻ�");
	
	printf("\n");
	
	sortList();
	
	displayList();
	
	printf("\n");  
	
	
	addItem2("ƻ��", 20);
	addItem2("����", 510);
	addItem2("����", 150);
	
	mergeLists(&shoppingList,&shoppingList2);
	
	displayList();
	
	printf("\n");
	
	deleteItem("�ֻ�",1 );
	
	displayList();
	
	printf("\n");
	
	clearList();
	
	printf("\n");
	
	

	
	return 0;
}

