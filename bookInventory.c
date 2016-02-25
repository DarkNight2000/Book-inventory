#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


/* setup the node for link list */
struct Node{

	char bookTitle[35];
	char authorName[35];
	int bookStockNumber;
	float wholesalePrice;
	float retailPrice;
	int wholesaleQuantity;
	int retailQuantity;
	
	struct Node *next;

};


/* initialize new node */

struct Node* createNode(){
	
	/* declare a new node */
	struct Node *newNode = (struct Node*)malloc(1 * sizeof(struct Node));
	
	if(newNode == NULL){
		printf("Failed to create a new node !\n");
		return (struct Node*) NULL;
	}else{

		printf("Please enter the book information: \n");


		scanf("%[^\n]", newNode->bookTitle);

		getchar();/* consume the \n character */
		printf("Book Title: %s\n", newNode->bookTitle );


		scanf("%[^\n]", newNode->authorName);
		getchar();/* consume the \n character */
		printf("Author Name: %s\n", newNode->authorName );
		
		scanf("%d", &(newNode->bookStockNumber));
		printf("Book StockNumber: %d\n", newNode->bookStockNumber );

		
		scanf("%f", &(newNode->wholesalePrice));
		printf("Wholesale Price: %.2f\n", newNode->wholesalePrice );

	
		scanf("%f", &(newNode->retailPrice));
		printf("Retail Price: %.2f\n", newNode->retailPrice );

		
		scanf("%d", &(newNode->wholesaleQuantity));
		printf("Wholesale Quantity: %d\n", newNode->wholesaleQuantity );

		
		scanf("%d", &(newNode->retailQuantity));
		printf("Retail Quantity: %d\n", newNode->retailQuantity );
		
		getchar();/* consume the \n character */
		
		
		return newNode;
	}

}

/* read the book list to the inventory */
void createList(struct Node **head){
	/* declare compare string of END_DATA */
	char a[35] = "END_DATA";
	int  i = 0;
	void insertNode(struct Node *, struct Node **);
	
	struct Node *newNode;

	while(TRUE){ /* if reach the END_DATA, break the while loop */
	
		newNode = (struct Node*)malloc(1 * sizeof(struct Node));
		
		if(newNode == NULL){
			printf("Failed to create a new node !\n");
		}else{
			
			printf("\nPlease enter the book information: \n");
			scanf("%[^\n]", newNode->bookTitle);
			getchar();/* consume the \n character */
			
		
			if(strcmp(newNode->bookTitle, a) == 0){
				printf("End of book data\n");
				free(newNode);
				break;
			}else{
			
				printf("\nBook Title: %s\n", newNode->bookTitle );
				
				scanf("%[^\n]", newNode->authorName);
				getchar();/* consume the \n character */
				printf("Author Name: %s\n", newNode->authorName );
		
				scanf("%d", &(newNode->bookStockNumber));
				printf("Book StockNumber: %d\n", newNode->bookStockNumber );

		
				scanf("%f", &(newNode->wholesalePrice));
				printf("Wholesale Price: %.2f\n", newNode->wholesalePrice );

	
				scanf("%f", &(newNode->retailPrice));
				printf("Retail Price: %.2f\n", newNode->retailPrice );

		
				scanf("%d", &(newNode->wholesaleQuantity));
				printf("Wholesale Quantity: %d\n", newNode->wholesaleQuantity );

		
				scanf("%d", &(newNode->retailQuantity));
				printf("Retail Quantity: %d\n", newNode->retailQuantity );
				getchar();/* consume the \n character */
				
				
			}
			
			insertNode(newNode, head);
		}	
	}	
}

/* print out the node in the list */
void printNode(struct Node *item){

	printf("\nBook Title: %s\n", item->bookTitle );
	printf("Author Name: %s\n", item->authorName );
	printf("Book Stock Number: %d\n", item->bookStockNumber );
	printf("Wholesale Price: %.2f\n", item->wholesalePrice );
	printf("Retail Price: %.2f\n", item->retailPrice);
	printf("Wholesale Quantity: %d\n", item->wholesaleQuantity );
	printf("Retail Quantity: %d\n\n", item->retailQuantity );


}

/* print out the list */
void printList(struct Node **headRef){

	struct Node *current = *headRef;
	while(current != NULL){
		printNode(current);
		current = current->next;
	}
}

/* insert new node to the list */
void insertNode(struct Node *item, struct Node **head){
	struct Node *traverse, *prev;
	
	/* if it is an empty list, set head to the insert item */
	if(*head == NULL){
		*head = item;
		item->next = NULL;
		return;

	}
	
	traverse = *head;
	
	/* use book stock number as the standard to locate the position we want to insert */
	while((item->bookStockNumber) > (traverse->bookStockNumber)){
		traverse = traverse->next;
		if(traverse == NULL){	/* stop when pass to the end of list */
			break;
		}
	}	
	
	/* the temp now point to the position we want to insert */
	if( traverse == *head ){	/* if the insert position is at the first node */
		item->next = *head;
		*head = item;
	}else{
		prev = *head;
		/* move the prev node to the node before the one to be deleted */
		while(prev->next != traverse){
			prev = prev->next;
		}
		
		/* insert the node between previous node and next node */
		prev->next = item;
		item->next = traverse;
		
	}
	
}

/* delete node from the list */
void deleteNode(struct Node *item, struct Node **head){
	struct Node *traverse, *prev;
	traverse = item; /* node to be delete */
	prev = *head;
	
	/* if the node we delete is the first node */
	if(traverse == prev){
		*head = (*head)->next; 
		
		free(traverse);
	}else{
		/* move the prev node to the node before the one to be deleted */
		while(prev->next != traverse){
			prev = prev->next;
		}
		prev->next = traverse->next; /* link the previous node to the next node */ 
		
		free(traverse);
	}
	
}

/* delete the list and release the allocated memory */
void deleteList(struct Node *item, struct Node **head){
	struct Node *traverse;
		
	if(item == *head){ /* if delete the entire list */
		*head = NULL;
	}else{ /* if delete partial list */
		traverse = *head;
		while(traverse->next != item){
			traverse = traverse -> next;
		}
	}
	while(item != NULL){
		traverse = item-> next;
		free(item);
		item = traverse;
	}
}


/* search function for book stock number */ 
struct Node* searchNode(struct Node *node, int stockNumber){
	
	while(node != NULL){
		if(node->bookStockNumber == stockNumber){
			break;
		}
		node = node->next;
	} 
	return node;
}

/* calculate the total revenue */
float totalRevenue(struct Node **head){
	struct Node *traverse  = *head;
	float result = 0;
	while(traverse  != NULL){
		result = result + (traverse ->retailPrice)*(traverse ->retailQuantity);
		traverse  = traverse ->next;
	} 
	return result;
}

/* calculate the total wholesale cost */
float totalWholesaleCost(struct Node **head){
	struct Node *traverse  = *head;
	float result = 0;
	while(traverse  != NULL){
		result = result + (traverse ->wholesalePrice)*(traverse ->wholesaleQuantity);
		traverse  = traverse ->next;
	} 
	return result;
}

/* calculate the number of book sold for all books */
int totalNumberOfBookSold(struct Node **head){
	struct Node *traverse  = *head;
	int result = 0;
	while(traverse  != NULL){
		result = result + traverse ->retailQuantity;
		traverse  = traverse ->next;
	}
	return result;
}

void processLinkList(struct Node **head){
	/* initialize the variables */
	int bookStockNumber = 0;
	float revenue = 0;
	float wholesaleCost = 0;
	float profit = 0;
	int soldBook = 0;
	float averageProfit = 0;
	
	int option; /* user's option */
	
	struct Node *newNode; /* setup the new node */
	

	while(1){
    
		/* repeatly prompt the user to choose one of the following options  */
		printf("\nPlease choose an option to process book inventory\n\n");
		printf("1.Determine and print total revenue.\n");
		printf("2.Determine and print total wholesale cost.\n");
		printf("3.Determine and print total profit.\n");
		printf("4.Determine and print total number of books sold for all books.\n");
		printf("5.Determine and print average profit per sale.\n");
		printf("6.Print book list.\n");
		printf("7.Add book.\n");
		printf("8.Delete book.\n");
		printf("9.Exit the program.\n");

		/* read and store user's option */
		scanf("%d", &option);
		printf("Your option is %d\n", option);
		
		/* Exit the program */
		if(option == 9){
		    printf("Exit the program\n");

		    /* free the dynamically allocated space for each of the data sets */
		    
		    break;
		}else{

		    switch(option){

		    /* Determine and print total revenue */
		    case 1:
		       	revenue = totalRevenue(head);
		        printf("The total revenue is: %.2f \n", revenue);              
		        break;
		    /* Determine and print total wholesale cost */
		    case 2:
		        wholesaleCost = totalWholesaleCost(head);
		        printf("The total wholesale cost is: %.2f \n", wholesaleCost);
		        break;
		    /* Determine and print total profit */
		    case 3:
		      	revenue =totalRevenue(head);
		      	wholesaleCost = totalWholesaleCost(head);
		      	profit = revenue - wholesaleCost;
		        printf("The total profit is: %.2f \n", profit);
		        break;
		    /* Determine and print total number of books sold for all books */
		    case 4:
		        soldBook = totalNumberOfBookSold(head);
		        printf("The total number of books sold for all books is: %d\n", soldBook);
		        break;
		    /* Determine and print average profit per sale */
		    case 5:
		    	/* calculate the profit */
		    	revenue =totalRevenue(head);
		      	wholesaleCost = totalWholesaleCost(head);
		      	profit = revenue - wholesaleCost;
		      	
		      	/* calculate the number of sold book */
		      	soldBook = totalNumberOfBookSold(head);
		      	
		      	averageProfit = profit / soldBook;
		        printf("The average profit per sale is: %.2f\n", averageProfit);
		        break;

		    /* Print book list */
		    case 6:    
		       	printList(head);
		        break;
		    /* Add book */
		    case 7: 
		    
		    	printf("Enter the book stock number: \n");
		    	scanf("%d", &bookStockNumber);
		    	
		    	newNode = searchNode(*head, bookStockNumber); 
		    	/* make newNode point to the position where it will be placed */

			if(newNode == NULL){
				newNode = createNode();
				
				insertNode(newNode, head);
			}else{
				printf("The book has already existed !\n");
			}

			break;
		    /* Delete book */
		    case 8: 
		    	printf("Enter the book stock number of the book you want to delete: \n");
		    	scanf("%d", &bookStockNumber);
		    	getchar();/* consume the \n character */
		    	newNode = searchNode(*head, bookStockNumber);
		    	
		    	if(newNode == NULL){
		    		printf("The book you want to delete is not in the inventory !\n");
		    	}else{
		    		deleteNode(newNode, head);
		    	}
			break;
		    /* Deal with invalid input */
		    default:
		        printf("Invaild option, please enter available option from 1 to 9\n");
		        break;
		    }
        	}
    	}  
}
/* read user's choice */
int main(){
	struct Node *head = (struct Node*) NULL; /* construct the head node */
	createList(&head);
	processLinkList(&head);
    	deleteList(head, &head);  

	return 0;
}

