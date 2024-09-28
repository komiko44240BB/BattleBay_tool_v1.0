import pandas as pd
import csv
import re

# Load the Excel file
file_name = 'healing_perks'
file_path = 'C:/Users/Pierre-Luc/Documents/GitHub/BattleBay_tool/scriptspy/data/' + file_name + '.xlsx'
df = pd.read_excel(file_path, sheet_name='Sheet1', engine='openpyxl')

# Function to split bonus into value and name
def split_bonus(bonus):
    if isinstance(bonus, str) and ' ' in bonus:
        parts = bonus.split(' ', 1)
        return parts[0], parts[1]
    return None, None

# Function to clean text by removing non-printable characters
def clean_text(text):
    if isinstance(text, str):
        # Remove non-printable characters
        return re.sub(r'[^\x20-\x7E]+', '', text)
    return text

# Clean the DataFrame by applying the clean_text function to all cells
df = df.applymap(clean_text)

# Create new columns for 1st bonus and 2nd bonus values and names
df['1STBONUS_VALUE'], df['1STBONUS_NAME'] = zip(*df['1st Bonus'].map(split_bonus))
df['2NDBONUS_VALUE'], df['2NDBONUS_NAME'] = zip(*df['2nd Bonus'].map(split_bonus))

# Rename columns to match the specified format
df.rename(columns={
    'Rarity': 'RARITY',
    'Perk': 'PERK_NAME',
    'Item': 'COMPATIBLE_ITEMS'
}, inplace=True)

# Select and reorder columns
output_df = df[['RARITY', '1STBONUS_VALUE', '1STBONUS_NAME', '2NDBONUS_VALUE', '2NDBONUS_NAME', 'PERK_NAME', 'COMPATIBLE_ITEMS']]

# Save the DataFrame to a CSV file with proper quoting and escape characters
output_file_path = 'C:/Users/Pierre-Luc/Documents/GitHub/BattleBay_tool/scriptspy/data/' + file_name + '.csv'
output_df.to_csv(output_file_path, index=False, sep=',', quoting=csv.QUOTE_MINIMAL, escapechar='\\', encoding='utf-8')

# Output the path of the saved CSV file
print(f"CSV file saved to: {output_file_path}")
