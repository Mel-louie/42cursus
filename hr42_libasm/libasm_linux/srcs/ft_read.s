section .text
	global ft_read          ; entry point
	extern __errno_location ; implement errno from the definition in /usr/include/errno.h

ft_read:					; ssize_t read(int fd, void *buf, size_t count);
	push rbp
	mov rbp, rsp
	mov rax, 0				; 0 is the syscall code of read, to obtain easily this code on linux: printf SYS_write | gcc -include sys/syscall.h -E -  | https://unix.stackexchange.com/questions/421750/where-do-you-find-the-syscall-table-for-linux
	syscall                 ; invoke syscall
	cmp rax, 0				; compare the rax value with 0
	jl _errno				; jump after a cmp if the destination operand is less than the source operand | if an error occures, errno return a value inf to 0
	jmp _end	

_errno:                     ; set errno and return -1
	neg rax 				; set rax to a positive error value, cause for now it's negative
	push rax				; preserve the value of rax, here the error code which occures
	call __errno_location	; error is called, which will put its return value in rax (return value here: a non-null pointer to the error number)
	mov rbx, rax			; move previous return value in rbx
	pop rax 				; restore the rax of the begining, the error code
	mov [rbx], rax			; move error code to errno location (memory adress contained in rbx)
	mov rax, -1				; set new return to -1 (rax has the return value)
	jmp _end

_end:
	pop rbp
	ret
