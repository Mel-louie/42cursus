section .text
	global _ft_write					;	entry point
	extern ___error						; 	implement errno from the definition in sys/errno.h

_ft_write:								;	ssize_t		ft_write(int fd, void *buf, size_t count);
	push rbp
	mov rbp, rsp
	mov rax, 0x2000004					;	put code of write in rax register
	syscall								; 	syscall write
	jc _errno							;	if carry flag is set, jump to errno label | carry flag is set because an error occures https://forums.freebsd.org/threads/is-apples-osx-based-on-a-standard-fbsd.3790/ | http://beefchunk.com/documentation/sys-programming/os-freebsd/asm_freebsd_fr.html | https://www.freebsd.org/doc/en_US.ISO8859-1/books/developers-handbook/x86-return-values.html
;	ret									;	if no cf, just okidoki ret
	jmp _end

_errno:
	push rax							; preserve the value of rax, here error code
	call ___error						; error is called, which will put its return value in rax (return value here: a non-null pointer to the error number)
	mov rbx, rax						; move previous return value in rbx
	pop rax								; restore original rax (error code)
	mov [rbx], rax						; move error code to errno location (memory adress contained in rbx)
	mov rax, -1							; set new return to -1 (rax has the return value)
	jp _end

_end:
	pop rbp
	ret
