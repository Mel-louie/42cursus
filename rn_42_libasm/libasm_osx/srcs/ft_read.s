section .text
	global _ft_read                 ;   entry point
	extern ___error                 ;   implementation of errno from the definition sys/errno.h

_ft_read:                           ;   ssize_t     read(int fildes, void *buf, size_t nbyte);
	push rbp
	mov rbp, rsp
	mov rax, 0x02000003         ;   put the code of read in rax register
	syscall                     ;   syscall read
	jc _errno                   ;   if carry flag is set, jump to errno label | carry flag is set because an error occures https://forums.freebsd.org/threads/is-apples-osx-based-on-a-standard-fbsd.3790/ | http://beefchunk.com/documentation/sys-programming/os-freebsd/asm_freebsd_fr.html | https://www.freebsd.org/doc/en_US.ISO8859-1/books/developers-handbook/x86-return-values.html
	jmp _end

_errno:
	push rax                    ;   preserve the value of rax, the error code
	call ___error               ;   error is called, which will put its return value in rax (return value here: a non-null pointer to the error number)
	mov rbx, rax                ;   move the previous return value in rbx
	pop rax                     ;   restore original rax (here error code)
	mov [rbx], rax              ;   move error code to errno location (memory adress contain in rbx)
	mov rax, -1                 ;   set return to -1 (rax as the return value)
	jp _end

_end:
	pop rbp
	ret
