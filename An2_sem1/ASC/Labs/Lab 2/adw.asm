bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    	a db 10 ; a->Al, AH-= 8biti,1byte; BL, BH. CL.CH. DH,DL

        b dw 40 ; 28h; AX = AH |AL -2bytes BX, CX, EAX (high part), DX

        d dw 0B113h;

        e dw 0C321h;

        f dd 12345678h; -> 12 34 56 78 -> 78 56 34 12

        ;;0A 28 00 12 13 B1 2A C3 78 56 34 12

    
; our code starts here
segment code use32 class=code
    start:
        ; ...
    
    
       
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
