import os
import pandas as pd
import tkinter as tk
from tkinter import filedialog
import re

def select_output_folder():
    """Open a dialog to select the output folder."""
    root = tk.Tk()
    root.withdraw()  # Hide the root window
    folder_selected = filedialog.askdirectory(title="Select Output Folder")
    return folder_selected

def process_bonus(bonus):
    """Split bonus into value and type and convert percentage to decimal where applicable."""
    if pd.isna(bonus):
        return None, None  # Return None for empty cells
    parts = bonus.split(' ', 1)
    if len(parts) == 2:
        value, boost_type = parts
        # Convert percentage to decimal
        if '%' in value:
            value = str(float(value.strip('%')) / 100)
        return value, boost_type
    return None, None  # If not properly split

def process_xlsx_file(file_path, output_folder):
    """Process a single xlsx file and create csv files based on Rarity and Item."""
    df = pd.read_excel(file_path, engine='openpyxl')

    # Process each row to split the 1st and 2nd bonus into value and type
    df['1st Boost Value'], df['1st Boost Type'] = zip(*df['1st Bonus'].apply(process_bonus))
    df['2nd Boost Value'], df['2nd Boost Type'] = zip(*df['2nd Bonus'].apply(process_bonus))

    # For each unique combination of Rarity and Item, create a new csv file
    for (rarity, item), group in df.groupby(['Rarity', 'Item']):
        # Define the output CSV filename
        output_filename = f"event_{rarity}_{item}.csv"
        output_filepath = os.path.join(output_folder, output_filename)
        
        # Select and reorder the columns for the CSV
        group_csv = group[['1st Boost Value', '1st Boost Type', '2nd Boost Value', '2nd Boost Type']]
        
        # Save to CSV without index
        temp_filepath = output_filepath + '.tmp'
        group_csv.to_csv(temp_filepath, index=False)
        
        # Post-process to remove any extra newlines
        with open(temp_filepath, 'r') as f_in, open(output_filepath, 'w', newline='\r') as f_out:
            for line in f_in:
                if line.strip():  # Avoid writing empty lines
                    f_out.write(line)

        os.remove(temp_filepath)  # Clean up temporary file



def process_all_files(input_folder, output_folder):
    """Process all xlsx files in the input folder."""
    for filename in os.listdir(input_folder):
        if filename.endswith('.xlsx'):
            file_path = os.path.join(input_folder, filename)
            print(f"Processing file: {filename}")
            process_xlsx_file(file_path, output_folder)

if __name__ == "__main__":
    # Prompt the user to select the input folder
    input_folder = filedialog.askdirectory(title="Select Input Folder Containing Excel Files")
    
    if input_folder:
        # Prompt the user to select the output folder
        output_folder = select_output_folder()
        if output_folder:
            # Process all xlsx files in the input folder
            process_all_files(input_folder, output_folder)
            print("Processing complete.")
        else:
            print("No output folder selected. Exiting.")
    else:
        print("No input folder selected. Exiting.")