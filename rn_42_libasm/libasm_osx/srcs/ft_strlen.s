section .text
    global _ft_strlen           ; set entry point

_ft_strlen:                     ; size_t    strlen(const char *s);
    push rbp                    ; function's prologue https://beta.hackndo.com/stack-introduction/#prologue---%C3%A9pilogue
    mov rbp, rsp                ; https://stackoverflow.com/questions/42208087/are-the-prologue-and-epilogue-mandatory-when-writing-assembly-functions
    xor rcx, rcx                ; set the counter to 0 https://stackoverflow.com/questions/4749585/what-is-the-meaning-of-xor-in-x86-assembly
 
_loop:
    cmp [rdi], byte 0           ; compare [rdi] (contained 1st arg, [] pointer, ptr on the 1st byte, the 1st char of the str) is this bye 0?
    jz _end                     ; if 0, jmp to _end
    inc rcx                     ; increment rcx value (like i++ in C)
    inc rdi                     ; move to next char
    jmp _loop                   ; redo the loop

_end:   
    mov rax, rcx                ; put rcx value in rax (contained the return  value)
    pop rbp                     ; function's epilogue
    ret