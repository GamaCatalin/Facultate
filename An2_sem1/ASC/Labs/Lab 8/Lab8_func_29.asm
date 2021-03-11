bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
extern scanf
import scanf msvcrt.dll
extern printf
import printf msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...

    control1 db "a after: "
    a dw 0
    x dw 0
    control2 db "m after: "
    m dd 0
    control3 db "n after: "
    n dd 0
    control4 db "output after: "
    output dd 0
    control5 db "format after: "
    format dw 0
    control6 db "etc after: "
    scanFormat db "%d",0
    printFormat db "%d",0
    messageA db "a= ",0
    messageM db "m= ",0
    messageN db "n= ",0
    errorMsg db "n can't be greater than m!",0

    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;Read three numbers a, m and n (a: word, 0 <= m, n <= 15, m > n) from the keyboard. Isolate the bits m-n of a and display the integer represented by those bits in base 16
        
        
        push dword messageA                 ;print the a message
        call [printf]
        add ESP, 4*1
        
        push dword a                        ;scan for a
        push dword scanFormat   
        call [scanf]
        add ESP, 4*2
        
        
        
        push dword messageM                 ;print the m message
        call [printf]
        add ESP, 4*1
        
        push dword m                        ;scan for m
        push dword scanFormat
        call [scanf]
        add ESP, 4*2
        
        
        
        push dword messageN                 ;print the n message
        call [printf]
        add ESP, 4*1
            
        push dword n                        ;scan for n
        push dword scanFormat
        call [scanf]
        add ESP, 4*2
        
        
        
        mov EAX, [m]                        ;check if n is greater than m
        cmp EAX, [n]
        jg  noError
        
        push dword errorMsg                 ;print an error and end the program if n>=m
        call [printf]
        add ESP,4*1
        jmp endProgram
        
        noError:
        
        mov ESI, 0                          ;clear ESI
        
        
        mov ECX, 15                         ;move into ECX the number of times we have to do the loop
        
        
        mainLoop:
            mov AX, [format]                ;move into AX the current format
            cmp ESI, [n]                    ;check if the current index is between n and m
            jb isUnderN
            
            cmp ESI, [m]
            jg isOverM
            
            
            or AX, 10000000_00000000b       ;place a 1 at the begining of AX
            
            
            isUnderN:
            isOverM:
        
            shr AX, 1                       ;shift AX 1 to the right
            mov [format], AX                ;save the current format
            inc ESI                         ;increment the index
        
        loop mainLoop                       ;loop to find the format
        
        
        
        mov AX, [a]                         ;move into AX the read word
        and AX, [format]                    ;isolate the bits determined by m and n
        cwde
        
        mov [output],EAX                    ;save the output
        
        
        push dword [output]                 ;print the output
        push dword printFormat
        call [printf]
        
        
        endProgram:
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
