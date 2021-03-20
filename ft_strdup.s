section .text
    extern _malloc
    extern _ft_strlen
    extern _ft_strcpy
    extern ___error
    global _ft_strdup

_ft_strdup:
    cmp rdi, 0
    je end
    call _ft_strlen
    inc rax
    jmp memory

memory:
    push rdi
    mov rdi, rax
    call _malloc
    cmp rax, 0
    jc error
    je end
    pop rsi
    mov rdi, rax
    call _ft_strcpy
    ret

end:
    mov rax, 0
    ret

error:
    push rax
    call ___error
    pop QWORD[rax]
    mov rax, 0
    ret