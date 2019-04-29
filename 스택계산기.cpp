#include <stdio.h>
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

void push(precedence item)
{
/* 전역 stack에 item을 삽입 */
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack[++top] = item;
}
void push2(int item)
{
/* 전역 stack에 item을 삽입 */
	if (top >= MAX_STACK_SIZE - 1)
		stackFull();
	stack2[++top] = item;
}

precedence pop(void)
{/* stack의 최상위 원소를 삭제하고 반환 */
	if (top == -1)
		stackEmpty();	/* returns an error key */

	return stack[top--];
}
int pop2(void)
{
/* stack의 최상위 원소를 삭제하고 반환 */
	if (top == -1)
	stackEmpty();	/* returns an error key */

	return stack2[top--];
}

void printToken(precedence token)
{
	switch (token)
	{
	case lparen: postfix_expr[j++] = '(';	break;
	case rparen: postfix_expr[j++] = '(';	break;
	case plus: postfix_expr[j++] = +'+';	break;
	case minus: postfix_expr[j++] = -'-';	break;
	case divide: postfix_expr[j++] = '/';	break;
	case times: postfix_expr[j++] = '*';	break;
	case mod: postfix_expr[j++] = '%';		break;
	case eos: postfix_expr[j++] = ' ';		return;
	}
	postfix_expr[j++] = ' ';
}

//중위 표기식을 후위 표기식으로 변환
void postfix(void)
{
/* 수식을 후위 표기식으로 출력한다. 수식 스트링, 스택, top은 전역적이다. */
	char symbol;
	precedence token;
	int n = 0;
	j = 0;
	top = 0; /* eos를 스택에 삽입한다. */
	stack[0] = eos;

	for (token = getToken(&symbol, &n, infix_expr); token != '\0'; token = getToken(&symbol, &n, infix_expr))
	{
		if (token == eos)
			continue;

		if (token == operand)
		{
			postfix_expr[j++] = symbol;
			while ((token = getToken(&symbol, &n, infix_expr)) == operand)
				postfix_expr[j++] = symbol;
			postfix_expr[j++] = ' ';
			n--;
		}
		else if (token == rparen)
		{
		/* 왼쪽 괄호가 나올 때까지 토큰들을 제거해서 출력시킴 */
			while (stack[top] != lparen)
				printToken(pop());
			pop(); /*왼쪽 괄호를 버린다 */
		}
		else 
		{
		/* symbol의 isp가 token의 icp보다 크거나 같으면 symbol을 제거하고 출력시킴 */
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
	}
	while ((token = pop()) != eos)
		printToken(token);
}

precedence getToken(char *symbol, int *n, char *infix_expr)
{
	/* 다음 토큰을 취한다.
	symbol은 문자 표현이며, token은 그것의 열거된 값으로 표현되고, 명칭으로 반환된다. */
	*symbol = infix_expr[(*n)++];

	switch (*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case ' ': return eos;
	default: return operand;	/* 에러 검사는 하지 않고 기본 값은 피연산자 */
	}
}

int eval(void)
{
	/* 전역 변수로 되어있는 후위 표기식 expr을 연산한다. ' \0' 은 수식의 끝을 나타낸다.
	stack과 top은 전역 변수이다. 함수 getToken은 토큰의 타입과 문자 심벌을 반환한다.
	피연산자는 한 문자로 된 숫자임을 가정한다. */

	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;/* 수식 스트링을 위한 카운터 */
	int num;
	top = -1;
	token = getToken(&symbol, &n, postfix_expr);

	while (token != '\0')
	{
		if (token == eos)
		{
			token = getToken(&symbol, &n, postfix_expr);
			continue;
		}
		if (token == operand)
		{
			num = symbol - '0'; /*스택 삽입 */
			while ((token = getToken(&symbol, &n, postfix_expr)) == operand)
				num = num * 10 + (symbol - '0');
			n--;
			push2(num);
		}
		else
		{
			/* 두 피연산자를 삭제하여 연산을 수행한 후, 그 결과를 스택에 삽입함 */
			op2 = pop2();	/* 스택 삭제 */
			op1 = pop2();
			switch (token)
			{
			case plus: push2(op1 + op2);	break;
			case minus: push2(op1 - op2);	break;
			case times: push2(op1*op2);		break;
			case divide: push2(op1 / op2);	break;
			case mod: push2(op1%op2);
			}
		}
		token = getToken(&symbol, &n, postfix_expr);
	}
	return pop2();	/* 결과를 반환 */
}