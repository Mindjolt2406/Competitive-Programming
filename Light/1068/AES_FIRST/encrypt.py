#!usr/bin/python

# from secret import flag
from Crypto.Cipher import AES
import hashlib
import time
import base64


key = hashlib.md5(str(1592566200).encode('utf-8'))
print(key.digest())
# padding = 16 - len(flag) % 16
aes = AES.new(str(key.hexdigest()).encode('utf-8'), AES.MODE_ECB)
print ("\n\n\n\n")
enc = "dd8e9250e270e1008cd5fba4c6dd93581d9e3b9822b5e0764e3cf126e75e6f69a7418a8ba0d0f66f3535e0573884a6468ba13399eca1ecc787413db51b00920e8ba13399eca1ecc787413db51b00920e"
# enc = base64.b64decode(enc)
  # iv = enc[:16]
print(aes.decrypt(enc.encode('utf-8')))
# outData = aes.encrypt(str(flag) + padding* str(padding))
# print(outData.encode('base64'))

# a80182989ba919adbe9b