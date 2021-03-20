section .text
    global _ft_strcpy

_ft_strcpy:
    mov rdx, 0
    cmp rsi, 0
    jz end
    jmp cycle

cycle:
    mov dl, BYTE [rsi + rdx]
    mov BYTE [rdi + rdx], dl
    cmp dl, 0
    jnz iteration

iteration:
    inc rdx

end:
    mov rax, rdi
    ret