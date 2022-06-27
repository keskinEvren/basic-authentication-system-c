#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ENTER 13
#define TAB 9
#define BACKSPACE 8

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

void takePassword(char pw[25]){
	int i;
	char ch;
	while(1){
		ch=getch();
		if(ch == ENTER || ch == TAB){
			pw[i] = '\0';
			break;
		}else if(ch == BACKSPACE){
			if(i>0){
				i--;
				printf("");
			}
		}else{
			pw[i++] = ch;
			printf("* ");
			
		}
	}
}

char makeUsername(char email[25], char username[25]){
	for(int i = 0; i<strlen(email); i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}


int main() {
	int action, userFound = 0;
	struct user user;
	char passwordBackup[25];
	FILE *fp;
	
	printf("\t\t\t **** Welcome to Authentication System ****");
	printf("\n Choose you action");
	printf("\n (1)Login");
	printf("\n (2)Signup");
	printf("\n (3)Exit");
	
	printf("\n\n Your Choice : ");
	scanf("%d", &action);
	fgetc(stdin);
	
	char username[50];
	char psword[25];
	struct user userr;
	
	
	switch(action){
		case 2:
			printf("\nEnter your name: ");
			takeInput(user.name);
			printf("\nEnter your email: ");
			takeInput(user.email);
			printf("\nEnter your phone number: ");
			takeInput(user.phoneNumber);
			printf("\nEnter your password: ");
			takePassword(user.password);
			printf("\nEnter your password: ");
			takePassword(passwordBackup);
			
			if(!strcmp(user.password,passwordBackup)){
				printf("\n\t Passwords Matched");
				makeUsername(user.email, user.username);
				printf("\n Your generated username is %s", user.username);
				fp = fopen("user.dat","a+");
				fwrite(&user,sizeof(struct user),1,fp);
				if(fwrite != 0) printf("\n Your registration is success, ");
				else printf("\n Something Went Wrong !!!");
				fclose(fp);
			}else{
				printf("\n\t Passwords Not Matched !!!");
			}
		break;
		
		case 1:
			
			printf("\n Enter your username: ");
			takeInput(username);
			printf("\n Enter your password: ");
			takeInput(psword);
			
			fp = fopen("user.dat","r");
			while(fread(&userr, sizeof(struct user),1,fp)){
				if(!strcmp(userr.username, username)){
					if(!strcmp(userr.password,psword)){
						printf("\n\n Login is Successfull ");
						printf("\n\t\t Profile Informations");
						printf("\n %s",userr.name);
						printf("\n %s",userr.email);
						printf("\n %s",userr.phoneNumber);
					}else{
						Beep(1000,500);
						printf("\n Login is Unsuccessfull !!!");
						printf("\n Check Your Informations");
					}
					userFound = 1;
				}
			}
			if(!userFound){
				printf("\n\n User is not Found Please Singup Before Login");
				Beep(1000,500);
			}
			fclose(fp);
			break;
		
		case 3:
			printf("\t\t Good Bye :)");
			return 0;
	}
	
	return 0;
}
