import subprocess

def run_cpp_with_input(executable_file, input_file):
    """Ejecuta el archivo ejecutable C++ con un archivo de entrada .txt y captura la salida."""
    try:
        # Abrir el archivo de entrada
        with open(input_file, 'r') as file_in:
            # Ejecutar el archivo binario y redirigir el archivo de entrada
            result = subprocess.run([f'./{executable_file}'], stdin=file_in, capture_output=True, text=True)
        
        # Si la ejecución es correcta, imprimir la salida
        if result.returncode == 0:
            print(result.stdout,end="")
        else:
            print("Error al ejecutar el archivo C++:")
            print(result.stderr)
    except FileNotFoundError:
        print(f"No se encontró el archivo {input_file}")

def main():
    executable_file = '1'  # El binario ya compilado de C++
    input_file = 'tests/test1_0_2.txt'     # Archivo .txt con los datos de entrada
    for i in range(10):
        run_cpp_with_input(executable_file, "tests/test0_2_"+str(i)+".txt")
    # Ejecutar el binario C++ con el archivo de entrada
    

if __name__ == '__main__':
    main()
