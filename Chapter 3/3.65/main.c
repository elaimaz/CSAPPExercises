#define A 14
#define B 12

typedef struct
{
	short x[A][B]; /* Unknown constants A and B */
	int y;
} str1;

typedef struct
{
	char array[B];
	int t;
	short s[B];
	int u;
} str2;

void setVal(str1* p, str2* q)
{
	int v1 = q->t;
	int v2 = q->u;
	p->y = v1 + v2;
}

int main() {
    return 0;
}