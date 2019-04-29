/**#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100

typedef enum
{
	lparen, rparen, plus, 
	minus, times, divide, 
	mod, eos, operand
} precedence;

precedence stack[MAX_STACK_SIZE];
int stack2[MAX_STACK_SIZE];
int top = -1;

void stackFull(void);
void stackEmpty(void);
void push2(int item);
void push(precedence item);
precedence pop(void);
int pop2(void);
precedence getToken(char *symbol, int *n, char *infix_expr);
int eval(void);
void printToken(precedence token);
void postfix(void);

char infix_expr[MAX_EXPR_SIZE];
char postfix_expr[MAX_EXPR_SIZE];
/*isp와 icp 배열 – 인덱스는 연산자 lparen, rparen, plus, 
minus, times, divide, mod, eos의 우선순위 값 */
/*
static int isp[] = { 0,19,12,12,13,13,13,0 };
static int icp[] = { 20,19,12,12,13,13,13,0 };
int j;

int main(void)
{
	fgets(infix_expr, 100, stdin);
	infix_expr[strlen(infix_expr) - 1] = '\0';
	postfix();
	printf("중위 표기 : %s\n", infix_expr);
	printf("후위 표기 : %s\n", postfix_expr);
	printf("결과값 : ");
	printf("%d", eval());

	return 0;
}

void stackFull(void)
{
	fprintf(stderr, "\nStack is full, cannot add element\n");
	exit(EXIT_FAILURE);
}
void stackEmpty(void)
{
	fprintf(stderr, "\nStack is emoty, cannot delete element\n");
	exit(EXIT_FAILURE);
}
