section .text
    global _ft_strdup
    extern _ft_strlen
    extern _ft_strcpy
    extern _malloc

_ft_strdup:
    cmp rdi, 0x0            ; check if str != \0
    jz _err
    push rbp                ; function's prologue https://beta.hackndo.com/stack-introduction/#prologue---%C3%A9pilogue
    mov rbp, rsp            ; https://stackoverflow.com/questions/42208087/are-the-prologue-and-epilogue-mandatory-when-writing-assembly-functions
    mov r12, rdi            ; save str in r12
    call _ft_strlen         ; call ftstrlen to get the number of chars to allocate
    inc rax                 ; inc rax to have the space for \0
    mov rdi, rax            ; move rax in rdi (1st arg) to set the lenght in malloc
    call _malloc
    or rax, rax             ; if rax 0, malloc failed, so error https://stackoverflow.com/questions/22123863/or-al-al-in-x86-assembly "Afin d’optimiser la taille et les performances du programme, on peut utiliser l’instruction “OR AX, AX” à la place de “CMP AX, 0”. En effet, un OU bit à bit entre deux nombres identiques ne modifie pas Destination et est exécuté « infiniment » plus rapidement qu’une soustraction. Comme les flags sont affectés, les sauts conditionnels sont possibles. " http://www.uqac.ca/rebaine/8INF212/unbonresumeassembleur.pdf
    jz _err    
    mov rdi, rax            ; pass malloced string on the 1st arg for strcpy
    mov rsi, r12            ; pass src string previoustly saved on the 2nd arg for strcpy
    call _ft_strcpy         ; calling ftstrcpy to duplicate r12 in rax
    pop rbp                 ; function's epilogue
    ret

_err:
    xor rax, rax            ; set rax to 0, 'cause error occures
    pop rbp                 ; function's epilogue
    ret