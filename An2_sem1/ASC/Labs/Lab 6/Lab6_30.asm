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

    A dw 3123,4214,634,8562,4214
    lenghtA equ ($-A)
    control1 db 0FFh
    s1 times lenghtA/2 db 0
    control2 db 0FFh
    s2 times lenghtA/2 db 0
    control3 db 0FFh
    
    byteHigh db 0
    control4 db 0FFh
    byteLow db 0
    control5 db 0FFh
    counterHigh db 0
    control6 db 0FFh
    counterLow db 0
    control7 db 0FFh
    loopReminder dd 0
    
    
    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
        
        ;A string of words is given. Build two strings of bytes, s1 and s2, in the following way: for each word,
        ;if the number of bits 1 from the high byte of the word is larger than the number of bits 1 from its low byte, then s1 will contain the high byte and s2 will contain the low byte of the word
        ;if the number of bits 1 from the high byte of the word is equal to the number of bits 1 from its low byte, then s1 will contain the number of bits 1 from the low byte and s2 will contain 0
        ;otherwise, s1 will contain the low byte and s2 will contain the high byte of the word.
    
    
    
    
 
        mov ECX, lenghtA/2                          ;move into ECX the times we have to repeat the loop
        mov ESI, A                                  ;move into ESI the sourse offset
        mov EDI, 0                                  ;clear EDI

        
        mainLoop:                               
            LODSW                                   ;load into AX the word at the source and increment the source offset by 2
            
            mov [byteLow], AL                       ;separate the low and high byte of the word
            mov [byteHigh], AH
            
            mov [loopReminder], ECX                 ;save the remaining number of times we have tt do the main loop
            mov ECX, 8                              ;move into ECX 8
           
            mov [counterLow], byte 0                ;clear the counters for the bits
            mov [counterHigh], byte 0
            
            bitCounterLoop:                         ;start the loop to count the 1 bits
                shr byte [byteLow], 1               ;shift the low byte 1 to the right
                jnc lowIsZero                       ;check if the last bit was a one
                    
                lowIsOne:
                    inc byte [counterLow]           ;increment the low byte counter
            
                lowIsZero:
                
                    
                shr byte [byteHigh], 1              ;shift the high byte 1 to the right
                jnc highIsZero                      ;check if the last bit was a one
                
                hightIsOne:                         
                    inc byte [counterHigh]          ;increment the high byte counter
                    
                highIsZero:
                
            loop bitCounterLoop                     ;loop ECX times


            mov ECX, [loopReminder]                 ;re initialize ECX
    
            mov DL, [counterHigh]                   ;move into DL the number of bits 1 from the high byte
            cmp DL, [counterLow]                    ;compare the number of bits from the high byte with the number of bith 
            
            jg highGreater                         
            je highEqual
            
            highLess:
                mov DL, AL                          ;save AL into DL
                mov AL, AH                          ;move into AL the value from AH
                mov AH, DL                          ;move into AH the value from DL
                jmp endLoop                         ;jump to the end of the loop
                
            highGreater:   
                jmp endLoop                         ;jump to the end of the loop
            
            highEqual:
                mov AH, [counterLow]                ;move into AH the number of bits1 from the low byte
                mov AL, 0                           ;move into AL 0
                jmp endLoop                         ;jump to the end of the loop
                
    
            endLoop:
                mov [s1+EDI], AH                    ;move into [s1+EDI] the value from AH
                mov [s2+EDI], AL                    ;move into [s2+EDI] the value from AL
                inc EDI                             ;increment EDI
    
        loop mainLoop
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
