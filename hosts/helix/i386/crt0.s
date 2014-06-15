extern main
extern _exit

global _start
_start:
    mov eax, [esp]
    mov ebx, [esp + 4]
    mov ecx, [esp + 8]

    push ecx
    push ebx
    push eax

    call main
    push eax
    call _exit

.hang:
    jmp .hang
