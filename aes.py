import sys
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad
from os import urandom
import hashlib

def encriptar(textoPlano, clave):
    k = hashlib.sha256(CLAVE).digest()
    iv = 16 * b'\x00'
    textoPlano = pad(textoPlano, AES.block_size)
    cifrado = AES.new(k, AES.MODE_CBC, iv)
    textoCifrado = cifrado.encrypt(textoPlano)
    return textoCifrado,clave
  
def escribirArchivo(clave, textoCifrado):
  with open("cifrado.bin", "wb") as archivoCifrado:
    archivoCifrado.write(textoCifrado)
  with open("clave.bin", "wb") as archivoClave:
    archivoClave.write(clave)

try:
    archivo = open(sys.argv[1], "rb")
    contenido = archivo.read()
except:
    print("Uso: .\aes.py Archivo.bin")
    sys.exit()


CLAVE = urandom(16)
textoCifrado, clave = encriptar(contenido, CLAVE)

escribirArchivo(CLAVE,textoCifrado)