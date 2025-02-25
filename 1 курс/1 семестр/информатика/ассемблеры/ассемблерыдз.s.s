.data
bibim: .asciiz "Введите число: "

.text
main:
    li $v0, 4      
    la $a0, bibim
    syscall

    li $v0, 5      
    syscall
    move $t0, $v0  

    li $t1, 10     

loop:
    div $t0, $t1   
    mfhi $a0       

    li $v0, 1      
    syscall

    mflo $t0       
    bnez $t0, loop  

    li $v0, 10     
    syscall