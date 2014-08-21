extern main
extern _exit
extern dalibc_helix_enter_program

global _start
_start:
    mov eax, [esp]
    mov ebx, [esp + 4]
    mov ecx, [esp + 8]

    push ecx
    push ebx
    push eax

    call dalibc_helix_enter_program
    push eax
    call _exit

.hang:
    jmp .hang
