section .text
    global _ft_strcpy

_ft_strcpy:
    mov rdx, 0
    cmp rsi, 0
    je end
    jmp cycle

cycle:
    mov bl, BYTE [rsi + rdx]
    mov BYTE [rdi + rdx], bl
    cmp bl, 0
    je end
    jmp iteration

iteration:
    inc rdx
    jmp cycle

end:
    mov rax, rdi
    ret