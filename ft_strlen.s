section .text
    global _ft_strlen

_ft_strlen:
    mov rax, 0
    jmp cycle

cycle:
    cmp BYTE [rdi + rax], 0
    je return
    inc rax
    jmp cycle

return:
    ret