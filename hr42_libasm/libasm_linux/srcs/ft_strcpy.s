section .text
	global ft_strcpy

ft_strcpy:                     ; char *     stpcpy(char * dst, const char * src);
	push rbp                    ; function's prologue https://beta.hackndo.com/stack-introduction/#prologue---%C3%A9pilogue
	mov rbp, rsp                ; https://stackoverflow.com/questions/42208087/are-the-prologue-and-epilogue-mandatory-when-writing-assembly-functions
	mov rax, rdi                ; set return value to rdi, 1st arg, return value of strcpy (return value is in rax)

_loop:
	cmp [rsi], byte 0           ; is rsi pnt on \0?
	jz _loop_end                ; if \0, jump to the end
	movsb                       ; copy on byte of rsi in rdi and inc or dec https://www.gladir.com/LEXIQUE/ASM/movsb.htm on DF https://stackoverflow.com/questions/41090297/default-state-of-direction-flag-df-during-x86-program-execution https://en.wikipedia.org/wiki/Direction_flag
	jmp _loop                   ; redo the loop

_loop_end:
	mov byte [rdi], 0           ; set the last byte to \0
	pop rbp                     ; function's epilogue
	ret
