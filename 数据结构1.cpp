
 #include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ShoppingItem 
{
	char name[50]; // 商品名称
	int quantity; // 商品数量
	struct ShoppingItem* next; // 指向下一个节点的指针
};

struct ShoppingItem* shoppingList = NULL;
struct ShoppingItem* shoppingList2 = NULL;

//添加商品到购物清单：
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

//从购物清单中移除商品：
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

//查看购物清单
void displayList() {
	struct ShoppingItem* current = shoppingList;
	printf("购物清单:\n");
	while (current != NULL) {
		printf("%s - 数量：%d\n", current->name, current->quantity);
		
		current=current->next;
		
	}
}
//修改购物清单
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

//清空购物清单：
void clearList() {
	while (shoppingList != NULL) {
		
		struct ShoppingItem* temp = shoppingList;
		shoppingList = shoppingList->next;
		
		free(temp);
	}
	printf("已清空所有物品\n");
}

//计算购物清单中商品的总数量：
int totalQuantity() {
	struct ShoppingItem* current = shoppingList;
	int total = 0;
	while (current != NULL) {
		
		total =total+ current->quantity;
		current = current->next;
		
	}
	return total;
}

//查找购物清单中的商品：
void findItem(char itemName[]) {
	struct ShoppingItem* current = shoppingList;
	
	printf("查找商品 %s ：\n", itemName);
	while (current != NULL) {
		if (strcmp(current->name, itemName) == 0) {
			printf("%s - 数量：%d\n", current->name, current->quantity);
			return;
		}
		
		current = current->next;
		
	}
	printf("未找到商品 %s。\n", itemName);
} 

//排序购物清单：
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

//合并购物清单：
void mergeLists(struct ShoppingItem** list1, struct ShoppingItem** list2) {
	struct ShoppingItem* current = *list1;
	
	while (current->next != NULL) {
		current = current->next;
	}
	
	current->next = *list2;
	*list2 = NULL;
}

//删除购物清单中的商品：
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
	
	addItem("手机", 2000);
	addItem("电脑", 3000);        
	addItem("水笔", 15);
	addItem("毛巾", 10);
	
	
	displayList(); 
	
	printf("\n");
	removeItem("水笔"); 
	 
	displayList(); 
	
	printf("\n");
	
	updateQuantity("手机", 250); 
	
	displayList(); 
	
	
	printf("\n");
	
	
	printf("%d\n",totalQuantity());
	
	printf("\n");
	
	findItem("手机");
	
	printf("\n");
	
	sortList();
	
	displayList();
	
	printf("\n");  
	
	
	addItem2("苹果", 20);
	addItem2("梨子", 510);
	addItem2("树苗", 150);
	
	mergeLists(&shoppingList,&shoppingList2);
	
	displayList();
	
	printf("\n");
	
	deleteItem("手机",1 );
	
	displayList();
	
	printf("\n");
	
	clearList();
	
	printf("\n");
	
	

	
	return 0;
}

