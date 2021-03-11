bits 32 

segment code use32 public code 
global sum
  


sum: 
    
    pop eax
    pop ebx
    
    add eax,ebx
    
    ret 4
    