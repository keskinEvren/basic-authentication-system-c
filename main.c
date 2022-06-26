#include<stdio.h>
#include<conio.h>
#include<windows.h>

struct user{
	char name[25];
	char email[25];
	char password[25];
	char username[25];
	char phoneNumber[25];
};

void takeInput(char ch[25]){
	fgets(ch, 25, stdin);
	ch[strlen(ch)-1] = 0;
}

void makeUsername(char email[25], char username[25]){
	for(int i = 0; i<strlen(email); i++){
		if(email[i] = '@') break;
		else username[i] = email[i];
	}
}


int main() {
	int action;
	
	printf("\t\t\t **** Welcome to Authentication System ****");
	printf("\n Choose you action");
	printf("\n (1)Login");
	printf("\n (2)Signup");
	printf("\n (3)Exit");
	
	printf("\n\n Your Choice : ");
	scanf("%d", action);
	fgetc(stdin);
	
	
	return 0;
}
