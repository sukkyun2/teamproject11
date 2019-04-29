#include "pch.h"
#include <iostream>

#define plus '+'
#define mult '*'
#define minus '-'

typedef struct polyterm *ptpointer;
typedef struct polyterm
{
	float coef;
	int expon;
	ptpointer link;
};

ptpointer InputPoly();	//다항식 입력받기
ptpointer AddPoly(ptpointer a, ptpointer b);	//덧셈
ptpointer MultPoly(ptpointer a, ptpointer b);	//곱셈
ptpointer MinusPoly(ptpointer a, ptpointer b);	//뺄셈
void attach(float coef, int expon, ptpointer *ptr);	//복사
void PrintPoly(ptpointer ptr);	//출력

void clear_stdin();	//입력 버퍼 비우기


int main()
{
	char p_operator;			//연산
	ptpointer a, b, c, d, f;	//다항식
	a = b = c = d = f = NULL;	//비어있음

	while (1)
	{
		printf("\n ===== 다항식 계산기 =====\n");
		a = InputPoly();
		printf("\n첫번째 다항식:\na(x)= ");
		PrintPoly(a);

		b = InputPoly();
		printf("\n두번째 다항식:\nb(x)= ");
		PrintPoly(b);

		clear_stdin();

		printf("다항식 연산 (+, *, -) : ");
		scanf_s("%c", &p_operator, sizeof(p_operator));

		if (p_operator == plus)
		{
			c = AddPoly(a, b);
			printf("\n다항식의 덧셈:\na(x)+b(x)= ");
			PrintPoly(c);
		}
		else if (p_operator == mult)
		{
			d = MultPoly(a, b);
			printf("\n다항식의 곱셈:\na(x)*b(x)= ");
			PrintPoly(d);
		}
		else if (p_operator == minus)
		{
			f = MinusPoly(a, b);
			printf("\n다항식의 뺄셈:\na(x)-b(x)= ");
			PrintPoly(f);
		}
		else
			;
	}
}

// 다항식 입력받기
ptpointer InputPoly()
{
	ptpointer pn = NULL, temp, trail = NULL;
	float coef; int expon;

	printf("지수 입력에서 -1 입력시 종료\n");
	while (1)
	{
		printf("계수 입력 : ");
		scanf_s("%f", &coef);
		printf("지수 입력 : ");
		scanf_s("%d", &expon);
		
		if (expon == -1)
			break;

		//pn으로 옯기기
		temp = (ptpointer)malloc(sizeof(struct polyterm));
		if (temp != NULL)
		{
			temp->coef = coef;
			temp->expon = expon;
			temp->link = NULL;
			if (pn == NULL)
			{
				pn = temp;
				trail = temp;
			}
			else
				trail->link = temp;
		}
	}
	return pn;
}

ptpointer AddPoly(ptpointer a, ptpointer b)	//덧셈
{ /* a와 b가 합산된 다항식을 반환 */
	ptpointer c, rear, temp;
	float sum;

	rear = (ptpointer)malloc(sizeof(struct polyterm));
	c = rear;
	while ((a != NULL) && (b != NULL))
	{
		if (a->expon < b->expon)
		{ /* a->expon < b->expon */
			attach(b->coef, b->expon, &rear);
			b = b->link;
		}
		else if (a->expon = b->expon)	//지수 같으면 덧셈
		{/* a->expon = b->expon */
			sum = a->coef + b->coef;
			if (sum) attach(sum, a->expon, &rear);
			a = a->link; b = b->link;
		}
		else
		{/* a->expon > b->expon */
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	}

	/* 리스트 a와 리스트 b의 나머지를 복사 */
	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	/* 필요 없는 초기 노드를 삭제 */
	temp = c; c = c->link; free(temp);
	return c;
}

ptpointer MultPoly(ptpointer a, ptpointer b)	//곱셈
{
	ptpointer d, rear, temp;
	float mcoef; int mexpon;

	rear = (ptpointer)malloc(sizeof(struct polyterm));
	d = rear;

	while (a != NULL)
	{
		while (b != NULL)	// 곱셈 계산
		{
			mcoef = a->coef * b->coef;
			mexpon = a->expon + b->expon;
			attach(mcoef, mexpon, &rear);
			b = b->link;
		}
		a = a->link;
	}
	/* 리스트 a와 리스트 b의 나머지를 복사 */
	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	/* 필요 없는 초기 노드를 삭제 */
	temp = d; d = d->link; free(temp);
	return d;
}

ptpointer MinusPoly(ptpointer a, ptpointer b)	//뺄셈
{
	ptpointer f, rear, temp;
	float difference;
	rear = (ptpointer)malloc(sizeof(struct polyterm));
	f = rear;
	while ((a != NULL) && (b != NULL))
	{
		if (a->expon < b->expon)
		{ /* a->expon < b->expon */
			attach(b->coef, b->expon, &rear);
			b = b->link;
		}
		else if (a->expon = b->expon)	//지수 같으면 뺄셈
		{/* a->expon = b->expon */
			difference = a->coef - b->coef;
			if (difference) attach(difference, a->expon, &rear);
			a = a->link; b = b->link;
		}
		else
		{/* a->expon > b->expon */
			attach(a->coef, a->expon, &rear);
			a = a->link;
		}
	}

	/* 리스트 a와 리스트 b의 나머지를 복사 */
	for (; a; a = a->link) attach(a->coef, a->expon, &rear);
	for (; b; b = b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	/* 필요 없는 초기 노드를 삭제 */
	temp = f; f = f->link; free(temp);
	return f;
}


void attach(float coef, int expon, ptpointer *ptr)
{ /* coef=coefficient 이고 expon=exponent인 새로운 노드를 생성하고,
	 그것을 ptr에 의해 참조되는 노드에 첨가한다. ptr을 갱신하여
	 이 새로운 노드를 참조하도록 한다. */
	ptpointer temp;

	temp = (ptpointer)malloc(sizeof(struct polyterm));
	temp->coef = coef;
	temp->expon = expon;
	(*ptr)->link = temp;
	*ptr = temp;
}

void PrintPoly(ptpointer ptr)	//출력
{
	for (; ptr; ptr = ptr->link)	// ptr->link가 null이 될때까지
	{
		printf("%.2fx^%d", ptr->coef, ptr->expon);
		if (ptr->link != NULL)	// null이 아니면
			printf(" + ");		// + 표기
	}
	printf("\n\n");
}

void clear_stdin()	// 입력 버퍼 지우기
{
	int ch;

	while ((ch = getchar()) != EOF && ch != '\n') {};
}