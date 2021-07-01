section .txt
	global ft_strcmp

ft_strcmp:                  ;int     strcmp(const char *s1, const char *s2);
	push rbp                ; function's prologue https://beta.hackndo.com/stack-introduction/#prologue---%C3%A9pilogue
	mov rbp, rsp            ; https://stackoverflow.com/questions/42208087/are-the-prologue-and-epilogue-mandatory-when-writing-assembly-functions
	xor rax, rax            ; return values init to 0
	xor rbx, rbx            ; iterative variable set to 0
	xor cx, cx              ; cx to 0 to manipulate char in rdi
	xor dx, dx              ; dx to 0 to manipulate char in rsi

_loop:
	mov cl, [rdi + rbx]     ; put the char in rdi + rbx (serve as an index) to cl to manipulate the char
	mov dl, [rsi + rbx]
	or cl, cl               ; is cl zero? https://stackoverflow.com/questions/22123863/or-al-al-in-x86-assembly "Afin d’optimiser la taille et les performances du programme, on peut utiliser l’instruction “OR AX, AX” à la place de “CMP AX, 0”. En effet, un OU bit à bit entre deux nombres identiques ne modifie pas Destination et est exécuté « infiniment » plus rapidement qu’une soustraction. Comme les flags sont affectés, les sauts conditionnels sont possibles. " http://www.uqac.ca/rebaine/8INF212/unbonresumeassembleur.pdf
	jz _ret_value           ; if 0, jump to ret 'cause it's the \0 of s1
	or dl, dl
	jz _ret_value
	cmp cl, dl              ; if char in cl and char in dl aren't the same, ret
	jne _ret_value
	inc rbx                 ; increment the iteration variable (i++)
	jmp _loop

_ret_value:
	sub cx, dx              ; *s1 - *s2
	jl _negative            ; jl = if cx < dx jump to _negative
	ja _postive             ; ja = if cx > dx jump to _positive
	jmp _equal              ; else jump to _equal

_negative:
	mov rax, -1
	pop rbp
	ret

_postive:
	mov rax, 1
	pop rbp
	ret

_equal:
	mov rax, 0
	pop rbp
	ret

