import socket
import os
import sys
import traceback
import random
import time
from Crypto.Cipher import AES
import socketserver
from threading import Thread

PORT = int(os.environ.get("PORT", 6955))

soc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
soc.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
# print('Socket created')

try: 
    host_ip = socket.gethostbyname('chal.zense.co.in') 
except socket.gaierror: 
    # this means could not resolve the host 
    print("there was an error resolving the host")
    sys.exit() 

soc.connect((host_ip,PORT))
# print("the socket has successfully connected to zense on port == " +str(host_ip) )

soc.recv(1024)
soc.send("\n".encode())
soc.recv(1024)

search = "0987654321qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890_.-!%{}"
sofar = "zenseCTF{Bl0ck_c1ph3rs_suck_6"

while(True):
  break_flag = False
  print(sofar)
  for i in search:
    temp_sofar = sofar+i
    print("temp_sofar:"+temp_sofar)
    prefix_len = 16-len(temp_sofar)%16
    prefix = "a"*prefix_len
    final_str_2 = prefix+temp_sofar
    final_str_1 = prefix #Flag gets appended automatically
    # print(final_str_1)
    # print(final_str_2)

    soc.recv(1024) # Choice
    soc.send("1".encode()) #send choice
    soc.recv(1024) #enter message
    soc.send(final_str_1.encode())  #send message
    enc1 = str(soc.recv(1024))[21:-3] #recieve encryption
    # print(enc1)

    soc.recv(1024) # Choice
    soc.send("2".encode()) #send choice
    soc.recv(1024) #enter message
    soc.send(final_str_2.encode())  #send message
    enc2 = str(soc.recv(1024))[21:-3] #recieve encryption
    # print(enc2)

    block_no = int(len(final_str_2)/16)
    if(enc1[:32*(block_no)] == enc2[:32*(block_no)]):
      sofar += i
      if(i == '}'): break_flag = True
      break

  print(sofar)
  if(break_flag): break

print("Success")
print(sofar)