; nasm source
BITS 64

extern _exit
extern main
extern dalibc_linux_enter_program

global _start
_start:
    ; Pop argc off stack
    pop rdi
    ; pop argv[0] off stack
    pop rsi

    ; find the last argument in the list
.args:
    pop rcx
    test rcx, rcx
    jnz .args

    ; pop environment variable off stack
    pop rdx

    call dalibc_linux_enter_program
    mov rdi, rax
    call _exit

.hang:
    jmp .hang
