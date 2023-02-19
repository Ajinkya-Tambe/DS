#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 20

char stack[MAX];
int top=-1;
char infix[MAX],prefix[MAX], item, temp;
int i=0,j=0;

int isFull();
int isEmpty();
void push(char);
int isOperator(char);
char pop();
int pre(char);

void InToPre(char infix[MAX]){

    strrev(infix);

    while(infix[i]!='\0'){
		item=infix[i];
		if(item==')'){
			push(item);
		}else if(item>='A'&&item<='Z'||item>='a'&&item<='z'){
			prefix[j]=item;
			j++;
		}else if(isOperator(item)){
			temp=pop();
			while(isOperator(temp)==1&&pre(temp)>=pre(item)){
				prefix[j]=temp;
				j++;
				temp=pop();
			}
			push(temp);
			push(item);
		}else if(item=='('){
			temp=pop();
			while(temp!=')'){
				prefix[j]=temp;
				j++;
				temp=pop();
			}
		}else{
			printf("Invalid Arithmetix expression!\n");
			exit(0);
		}
		i++;
	}
	while(!isEmpty()){
		prefix[j]=pop();
		j++;
	}
	prefix[j]='\0';
	printf("The prefix expression is: ");
	puts(strrev(prefix));
}

int main()
{
    printf("This program will convert Infix expresstion too Prefix expression");
    char ch;

    printf("\n\nEnter an infix expression: ");
    gets(infix);

    InToPre(infix);
}

void push(char item){
	if(isFull()){
		printf("Stack overflow!\n");
	}else{
		top++;
		stack[top]=item;
	}
}

int isFull(){
	if(top==MAX-1){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(){
	if(top==-1){
		return 1;
	}else{
		return 0;
	}
}

int isOperator(char symbol){
	if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/'||symbol=='^'){
		return 1;
	}else{
		return 0;
	}
}

char pop(){
	if(isEmpty()){
		return '\0';
	}
	char ch;
	ch=stack[top];
	top--;
	return ch;
}

int pre(char symbol){
	if(symbol=='^'){
		return 3;
	}else if(symbol=='*'||symbol=='/'){
		return 2;
	}else if(symbol=='+'||symbol=='-'){
		return 1;
	}else{
		return 0;
	}
}