import os
import csv
from tkinter import Tk, filedialog

# Fonction pour sélectionner un fichier
def select_file(title="Choisir un fichier"):
    root = Tk()
    root.withdraw()  # Cacher la fenêtre principale
    file_path = filedialog.askopenfilename(title=title, filetypes=[("Text Files", "*.txt")])
    return file_path

# Fonction pour sélectionner un dossier
def select_folder(title="Choisir un dossier"):
    root = Tk()
    root.withdraw()  # Cacher la fenêtre principale
    folder_path = filedialog.askdirectory(title=title)
    return folder_path

# Fonction pour lire le fichier .txt et retourner un dictionnaire
def read_txt_file(file_path):
    mapping = {}
    with open(file_path, 'r') as txt_file:
        for line in txt_file:
            name_clear, name_scrambled = line.strip().split(',')
            mapping[name_scrambled.strip()] = name_clear.strip()  # Assurez-vous de supprimer les espaces
    return mapping

# Fonction pour renommer les fichiers CSV
def rename_csv_files(folder_path, name_mapping):
    for filename in os.listdir(folder_path):
        if filename.endswith(".csv"):
            scrambled_name, ext = os.path.splitext(filename)
            if scrambled_name in name_mapping:
                clear_name = name_mapping[scrambled_name]
                new_filename = clear_name + ext
                old_file_path = os.path.join(folder_path, filename)
                new_file_path = os.path.join(folder_path, new_filename)
                os.rename(old_file_path, new_file_path)
                print(f"Renommé: {filename} -> {new_filename}")
            else:
                print(f"Nom brouillé non trouvé dans le fichier .txt : {filename}")

# Étapes du programme
if __name__ == "__main__":
    # 1. Demander à l'utilisateur de sélectionner le fichier .txt
    txt_file_path = select_file("Choisissez un fichier .txt avec les noms")
    
    if not txt_file_path:
        print("Aucun fichier .txt sélectionné.")
    else:
        # 2. Lire le fichier txt et créer un dictionnaire de correspondances
        name_mapping = read_txt_file(txt_file_path)

        # 3. Demander à l'utilisateur de sélectionner le dossier contenant les fichiers CSV
        csv_folder_path = select_folder("Choisissez un dossier contenant les fichiers CSV")
        
        if not csv_folder_path:
            print("Aucun dossier sélectionné.")
        else:
            # 4. Renommer les fichiers CSV en fonction des correspondances
            rename_csv_files(csv_folder_path, name_mapping)
