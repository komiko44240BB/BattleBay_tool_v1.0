import os
import tkinter as tk
from tkinter import filedialog

def choisir_dossier():
    """Affiche un dialogue pour choisir un dossier."""
    root = tk.Tk()
    root.withdraw()  # Cacher la fenêtre principale
    dossier = filedialog.askdirectory()  # Ouvre une boîte de dialogue pour sélectionner un dossier
    return dossier

def renommer_fichiers_txt_en_csv(dossier):
    """Renomme tous les fichiers .txt en .csv dans le dossier donné."""
    for filename in os.listdir(dossier):
        if filename.endswith(".txt"):
            chemin_complet = os.path.join(dossier, filename)
            nouveau_nom = os.path.join(dossier, filename[:-4] + ".csv")
            os.rename(chemin_complet, nouveau_nom)
            print(f"Renommé : {chemin_complet} -> {nouveau_nom}")

if __name__ == "__main__":
    dossier = choisir_dossier()
    if dossier:
        renommer_fichiers_txt_en_csv(dossier)
        print("Renommage terminé.")
    else:
        print("Aucun dossier sélectionné.")
