#include <assert.h>

/* Enumerated type creates set of constants numbered 0 and upward */
typedef enum { MODE_A, MODE_B, MODE_C, MODE_D, MODE_E } mode_t;

int switch3(int* p1, int* p2, mode_t action)
{
	int result = 0;
	switch (action)
	{
	case MODE_A:
		result = *p1;
		*p1 = *p2;
		p2 = p1;
		break;
	case MODE_B:
		result = *p2;
		result += *p1;
		*p2 = result;
		break;
	case MODE_C:
		*p2 = 15;
		result = *p1;
		break;
	case MODE_D:
		result = *p1;
		*p2 = result;
		result = 17;
		break;
	case MODE_E:
		result = 17;
		break;
	default:
		result = -1;
	}
	return result;
}

//Intel syntax
int switch3_asm(int* p1, int* p2, mode_t action)
{
	int result = 0;

	switch (action)
	{
	case MODE_A:
		goto L13;
	case MODE_B:
		goto L14;
	case MODE_C:
		goto L15;
	case MODE_D:
		goto L16;
	case MODE_E:
		goto L17;
	default:
		break;
	}

L17:	//MODE_E
	__asm {
		mov edx, 17
		jmp L19
	}
L13:	//MODE_A
	__asm {
		mov eax, p1
		mov edx, [eax]
		mov ecx, p2
		mov eax, [ecx]
		mov ecx, p1
		mov [ecx], eax
		jmp L19
	}
L14:	//MODE_B
	__asm {
		mov edx, p2
		mov eax, [edx]
		mov edx, eax
		mov ecx, p1
		add edx, [ecx]
		mov eax, p2
		mov [eax], edx
		jmp L19
	}
L15:	//MODE_C
	__asm {
		mov edx, p2
		mov [edx], 15
		mov ecx, p1
		mov edx, [ecx]
		jmp L19
	}
L16:	//MODE_D
	__asm {
		mov edx, p1
		mov eax, [edx]
		mov ecx, p2
		mov [ecx], eax
		mov edx, 17
		jmp L19
	}
L19:	//default
	__asm {
		mov result, edx
	}
	return result;
}

int main() {

	int p1, p2, p3, p4;
	int result = 0, result2 = 0;
	
	p1 = p3 = 5;
	p2 = p4 = 8;
	result = switch3_asm(&p1, &p2, MODE_A);
	result2 = switch3(&p3, &p4, MODE_A);
	assert(result == result2);
	assert(p1 == p3);
	assert(p2 == p4);

	p1 = p3 = 18;
	p2 = p4 = 44;
	result = switch3_asm(&p1, &p2, MODE_B);
	result2 = switch3(&p3, &p4, MODE_B);
	assert(result == result2);
	assert(p1 == p3);
	assert(p2 == p4);

	p1 = p3 = 60;
	p2 = p4 = 26;
	result = switch3_asm(&p1, &p2, MODE_C);
	result2 = switch3(&p3, &p4, MODE_C);
	assert(result == result2);
	assert(p1 == p3);
	assert(p2 == p4);

	p1 = p3 = 14;
	p2 = p4 = 5;
	result = switch3_asm(&p1, &p2, MODE_D);
	result2 = switch3(&p3, &p4, MODE_D);
	assert(result == result2);
	assert(p1 == p3);
	assert(p2 == p4);

	p1 = p3 = 62;
	p2 = p4 = 58;
	result = switch3_asm(&p1, &p2, MODE_E);
	result2 = switch3(&p3, &p4, MODE_E);
	assert(result == result2);
	assert(p1 == p3);
	assert(p2 == p4);

    return 0;
}