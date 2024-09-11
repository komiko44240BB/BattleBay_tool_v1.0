import os
import tkinter as tk
from tkinter import filedialog

def choisir_dossier():
    root = tk.Tk()
    root.withdraw()  # Cache la fenêtre principale de Tkinter
    dossier = filedialog.askdirectory(title="Choisissez un dossier")
    return dossier

def changer_extension_en_csv(dossier):
    if not os.path.exists(dossier):
        print(f"Le dossier {dossier} n'existe pas.")
        return

    for filename in os.listdir(dossier):
        chemin_complet = os.path.join(dossier, filename)
        if os.path.isfile(chemin_complet):
            nouveau_nom = os.path.splitext(chemin_complet)[0] + ".csv"
            os.rename(chemin_complet, nouveau_nom)
            print(f"Renommé: {chemin_complet} -> {nouveau_nom}")

if __name__ == "__main__":
    dossier_choisi = choisir_dossier()
    if dossier_choisi:
        changer_extension_en_csv(dossier_choisi)
    else:
        print("Aucun dossier sélectionné.")
