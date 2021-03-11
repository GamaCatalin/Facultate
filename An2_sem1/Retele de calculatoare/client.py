import socket

import struct

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect( ("192.168.0.121",1234))

array=[]

while(True):
    a=int(input("Number = "))
    if(a==0):
        break
    array.append(a)




res = s.send(struct.pack("!H",len(array)))


for elem in array:
    res = s.send(struct.pack("!H",elem))

Sum = s.recv(2)

Sum = struct.unpack("!H",Sum)

print("Array sum is: "+Sum[0].__format__('d'))

s.close()