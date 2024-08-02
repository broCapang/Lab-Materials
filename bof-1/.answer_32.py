from pwn import *

io = process("./chal_32")

rop = ROP("./chal_32")