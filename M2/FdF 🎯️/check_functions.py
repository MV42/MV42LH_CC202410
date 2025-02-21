import os
import re

# Liste des fonctions autorisées
allowed_functions = [
    'open', 'close', 'read', 'write', 'malloc', 'free', 'perror', 'strerror', 'exit',
    'sin', 'cos', 'tan', 'sqrt', 'pow', 'log', 'exp', 'ceil', 'floor', 'fabs', 'atan',
    'asin', 'acos', 'atan2', 'sinh', 'cosh', 'tanh', 'log10', 'fmod',
    'mlx_init', 'mlx_new_window', 'mlx_loop', 'mlx_string_put', 'mlx_pixel_put',
    'mlx_new_image', 'mlx_get_data_addr', 'mlx_put_image_to_window', 'mlx_destroy_window',
    'mlx_key_hook', 'mlx_mouse_hook', 'mlx_hook', 'mlx_expose_hook', 'mlx_loop_hook',
]

# Liste des mots-clés à ignorer
keywords_to_ignore = [
    'if', 'while', 'return', 'break', 'else'
]

# Fonction pour extraire les déclarations de fonctions des fichiers .c
def extract_functions_from_c_file(file_path):
    functions = []
    with open(file_path, 'r') as file:
        content = file.read()
        matches = re.findall(r'\b\w+\s+\w+\s*\([^)]*\)\s*{', content)
        for match in matches:
            func_name = re.match(r'\b\w+\s+(\w+)', match).group(1)
            functions.append(func_name)
    return functions

# Fonction pour vérifier les appels de fonctions dans un fichier
def check_functions_in_file(file_path, allowed_functions):
    with open(file_path, 'r') as file:
        content = file.read()
        
        # Trouver tous les appels de fonctions
        functions = re.findall(r'\b\w+\s*\(', content)
        functions = [f[:-1].strip() for f in functions]  # Remove '(' and strip spaces
        
        for func in functions:
            if func not in allowed_functions and func not in keywords_to_ignore:
                print(f"Function '{func}' in file '{file_path}' is not allowed.")

# Parcourir les fichiers du projet
project_dir = 'C'  # Répertoire contenant les fichiers source
c_files = []

# Extraire les déclarations de fonctions des fichiers .c
for root, _, files in os.walk(project_dir):
    for file in files:
        if file.endswith('.c'):
            c_files.append(os.path.join(root, file))

for c_file in c_files:
    allowed_functions.extend(extract_functions_from_c_file(c_file))

# Vérifier les appels de fonctions dans les fichiers .c
for c_file in c_files:
    check_functions_in_file(c_file, allowed_functions)