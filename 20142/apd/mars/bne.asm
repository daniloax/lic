addi $s0,$s0,0
addi $s1,$s1,2
addi $s2,$s2,3
addi $s3,$s3,1
addi $s4,$s4,1
beq $s3,$s4,Else
add $s0,$s1,$s2
j Exit
Else: sub $s0,$s1,$s2
Exit: