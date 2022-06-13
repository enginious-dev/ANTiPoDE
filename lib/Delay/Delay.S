#include <xc.h>
.text
.set noreorder
.global delay
.ent delay
delay:
    addiu sp, sp, -4   # Move stack pointer
    addiu t0, zero, 20 # Store 20 in t0 (unfortunately some magic number)
    nop                # Infortunately some magic nop
    nop                
count:
    bge t0, a0, end    # If count is done go to end
    addiu t0, t0, 5    # Increment t0 by 5
    j count # (6)      # Continue loop
end:
    nop                # Infortunately some magic nop (part II)
    nop
    addiu sp, sp, 4    # Move stack pointer
    jr ra              # return 
.end delay