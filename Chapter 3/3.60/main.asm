; Listing generated by Microsoft (R) Optimizing Compiler Version 19.37.32822.0 

	TITLE	D:\dev\CSAPPExercises\Chapter 3\3.60\main.obj
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

_DATA	SEGMENT
COMM	_A:DWORD:01efH
_DATA	ENDS
PUBLIC	_store_ele
PUBLIC	_main
; Function compile flags: /Odtp
_TEXT	SEGMENT
_main	PROC
; File D:\dev\CSAPPExercises\Chapter 3\3.60\main.c
; Line 13
	push	ebp
	mov	ebp, esp
; Line 14
	xor	eax, eax
; Line 15
	pop	ebp
	ret	0
_main	ENDP
_TEXT	ENDS
; Function compile flags: /Odtp
_TEXT	SEGMENT
_i$ = 8							; size = 4
_j$ = 12						; size = 4
_k$ = 16						; size = 4
_dest$ = 20						; size = 4
_store_ele PROC
; File D:\dev\CSAPPExercises\Chapter 3\3.60\main.c
; Line 8
	push	ebp
	mov	ebp, esp
; Line 9
	imul	eax, DWORD PTR _i$[ebp], 396
	imul	ecx, DWORD PTR _j$[ebp], 44
	lea	edx, DWORD PTR _A[eax+ecx]
	mov	eax, DWORD PTR _dest$[ebp]
	mov	ecx, DWORD PTR _k$[ebp]
	mov	edx, DWORD PTR [edx+ecx*4]
	mov	DWORD PTR [eax], edx
; Line 10
	mov	eax, 1980				; 000007bcH
; Line 11
	pop	ebp
	ret	0
_store_ele ENDP
_TEXT	ENDS
END
