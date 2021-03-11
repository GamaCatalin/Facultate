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

    A db 15,4,6,1,54,7
    lenghtA equ ($-A);
    control1 db 0xFF
    B db 9,6,3
    lenghtB equ ($-B);
    control2 db 0xFF
    ;lenghtC equ ([lenghtA]+[lenghtB])
    lenghtC equ 10
    C times lenghtC db 0
    control3 db 0xFF
    minLenght db 0
    maxLenght db 0
    currentIndex dd 0
    zero db 0
    one db 1
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;Two strings of bytes A and B are given. Parse the shortest string of those two and build a third string C as follows:
        ;up to the lenght of the shortest string C contains the largest element of the same rank from the two strings
        ;then, up to the length of the longest string C will be filled with 1 and 0, alternatively.
        
        
        mov AL, lenghtA                                 ;get into AL the lenth of A
        cmp AL, lenghtB                                 ;compare the lenght of A with the lenght of B
        
        jge lenAGreater                                 ;jump if A is greater
        
        
        lenBGreater:                                    ;put into [minLenght] the lenght of A, and into [maxLenght] the lenght of B
            mov [minLenght], AL
            mov AL,lenghtB
            mov [maxLenght], AL
            jmp initLoop
            
        lenAGreater:                                    ;put into [maxLenght] the lenght of A, and into [minLenght] the lenght of B
            mov [maxLenght], AL
            mov AL,lenghtB
            mov [minLenght], AL
            jmp initLoop
        
        
        initLoop:                       
            mov AL, [maxLenght]                         ;get in AL the maximum lenght
            cbw
            cwde                                        ;convert the max lenght to a double word
        
        
            mov ECX, EAX                                ;put into ECX the nr of times the loop needs to go through, i.e. maxLenght
            
            mov EAX, 0                                  ;clear EAX
            
            mov EDI, C                                  ;put into EDI the destination string, i.e C
            
            mainLoop:                                   ;start the main loop
                mov AL, [minLenght]                     ;get into AL the minLenght
                cbw
                cwde
                cmp [currentIndex], EAX                 ;compare the current index with the minimum lenght
                
                jbe lowString                           ;if the index is below or equal to the minLenght jump to the low part of the string
                
                
                highString:
                    mov ESI, [currentIndex]             ;get into ESI the current index and decrement it 
                    dec ESI
                    mov AL, [C+ESI]                     ;mov into AL the last value
                    cmp AL, 0                           ;check if the last value is 0
                   
                    je lastZero                         ;jump if the last value was 0
                    
                    
                    lastOne:
                        mov ESI, zero                   ;move into ESI the offset of the zero value
                        LODSB                           ;load the value from ESI into AL
                        jmp nextLoop                    ;jump to the end of the loop
                        
                    
                    lastZero:
                        mov ESI, one                    ;move into ESi the offset of the one value
                        LODSB                           ;load the value from ESI into AL
                        jmp nextLoop                    ;jump to the end of the loop
                    
        
                lowString:
                    mov ESI, [currentIndex]             ;move into ESI the current index
                    
                    mov AL, [A+ESI]                     ;move into AL the byte from the current index in A
                    mov BL, [B+ESI]                     ;move into BL the byte from the current index in B
                    
                    cmp AL, BL                          ;compare the bytes from A and B
                    
                    jge alGreater                       ;jump if the byte from A is greater
                    
                    
                    blGreater:
                        mov EDX, [currentIndex]         ;move into EDX the current index
                        add EDX, B                      ;add to EDX the offset of B
                        mov ESI, EDX                    ;put into ESI the offset of B+currentIndex
                        LODSB                           ;load the value from ESI into AL
                        
                        jmp nextLoop                    ;jump to the end of the loop
                        
                    alGreater:
                        mov EDX, [currentIndex]         ;move into EDX the current index
                        add EDX, A                      ;add to EDX the offset of A
                        mov ESI, EDX                    ;put into ESI the offset of A+currentIndex
                        LODSB
                    
                        jmp nextLoop                    ;jump to the end of the loop
                    
                    
                 nextLoop:
                    STOSB                               ;move into the current offset of C the value stored in AL
                    mov EAX, [currentIndex]             ;mov into EAX the current index
                    add EAX, 1                          ;add 1 to EAX
                    mov [currentIndex], EAX             ;move into currentIndex the new value
                    
                    
           loop mainLoop                                ;loop
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
