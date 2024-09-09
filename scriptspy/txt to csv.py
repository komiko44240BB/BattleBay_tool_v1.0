import os
from tkinter import Tk
from tkinter.filedialog import askdirectory

def replace_commas_in_txt_files(directory):
    # Parcours des fichiers dans le répertoire
    for filename in os.listdir(directory):
        if filename.endswith(".txt"):
            file_path = os.path.join(directory, filename)
            
            # Lecture du contenu du fichier
            with open(file_path, 'r', encoding='utf-8') as file:
                content = file.read()
            
            # Remplacement des virgules par des points-virgules
            new_content = content.replace(";", ",")
            
            # Écriture du nouveau contenu dans le fichier .txt
            with open(file_path, 'w', encoding='utf-8') as file:
                file.write(new_content)
            
            print(f"Fichier modifié : {filename}")
            
            # Création d'un fichier CSV avec le même contenu
            csv_filename = filename.replace(".txt", ".csv")
            csv_path = os.path.join(directory, csv_filename)
            
            with open(csv_path, 'w', encoding='utf-8') as csv_file:
                csv_file.write(new_content)
            
            print(f"Fichier CSV créé : {csv_filename}")

if __name__ == "__main__":
    # Création d'une fenêtre Tkinter pour la sélection du dossier
    Tk().withdraw()  # Masquer la fenêtre principale
    folder_selected = askdirectory(title="Sélectionnez un dossier contenant les fichiers .txt")
    
    if folder_selected:
        replace_commas_in_txt_files(folder_selected)
        print("Tous les fichiers ont été traités et des fichiers CSV ont été créés.")
    else:
        print("Aucun dossier sélectionné.")
