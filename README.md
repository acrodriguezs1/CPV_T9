Imagen del PPM funcional
![image](https://github.com/user-attachments/assets/fe4777d1-d1d7-4608-85f9-8dac78d8decc)


##  Pasos para compilar y ejecutar el proyecto 

1. **Abrir la terminal o consola de comandos:**
   - Ve al buscador de tu PC, escribe `cmd` o `Terminal`, y ábrelo.

2. **Ir a la carpeta donde descargaste el proyecto:**

3. **Generar la carpeta de compilación:**
   - Ejecuta este comando para crear una carpeta llamada `build` donde se guardarán los archivos de compilación:
     ```bash
     cmake -B build
     ```

4. **Construir el proyecto:**
   - Compila el proyecto ejecutando el siguiente comando:
     ```bash
     cmake --build build --target inOneWeekend
     ```

5. **Compilar en modo Release (opcional pero recomendado):**
   - Esto genera una versión optimizada del ejecutable:
     ```bash
     cmake --build build --config Release
     ```

6. **Generar la imagen en formato `.ppm`:**
   - Ejecuta el programa para que cree una imagen en la carpeta `build\Release`:
     ```bash
     build\Release\inOneWeekend > image.ppm
     ```
   - Esto creará un archivo llamado `image.ppm`.

7. **Visualizar la imagen `.ppm`:**
   - Si quieres ver cómo quedó la imagen, puedes usar esta página web para visualizarla:
     https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html
