section .text
    global _ft_strcmp

_ft_strcmp:
    mov rax, 0

cycle:
    mov dl, byte [rdi + rax]
    mov cl, byte [rsi + rax]
    cmp dl, 0
    je end
    cmp cl, 0
    je end
    cmp dl, cl
    je iteration
    jmp end

iteration:
    inc rax
    jmp cycle

end:
    movzx rax, dl
    movzx r8, cl
    sub rax, r8
    ret