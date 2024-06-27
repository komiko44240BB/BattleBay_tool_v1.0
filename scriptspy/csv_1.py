import csv

header = [
    "LEVEL", "BASE_STAT", "COOL_DOWN", "RANGE", "PROJECTILE_SPEED",
    "CRITICAL_HIT_CHANCE", "RADIUS", "SPREAD", "AMOUNT_OF_PROJECTILES", "DURATION"
]

cool_down = 5.2
range_ = 14.6
projectile_speed = 14.2
critical_hit_chance = 1.0
radius = 0
spread = 0
amount_of_projectiles = 1
duration = 0
file_name = 'common_railgun.csv'
base_stat_tab = [469,506,543,580,617]
ration_tab = [3.77,3.77,3.77,3.77,4.22]

with open(file_name, 'w', newline='') as file:
    writer = csv.writer(file, delimiter=';')
    writer.writerow(header)

    base_stat = base_stat_tab[0]
    ratio = ration_tab[0]
    for level in range(1, 11):
        rounded_base_stat = round(base_stat)
        writer.writerow([level, rounded_base_stat, cool_down, range_, projectile_speed, critical_hit_chance, radius, spread, amount_of_projectiles, duration])
        base_stat += ratio

    base_stat = base_stat_tab[1]
    ratio = ration_tab[1]
    for level in range(11, 21):
        rounded_base_stat = round(base_stat)
        writer.writerow([level, rounded_base_stat, cool_down, range_, projectile_speed, critical_hit_chance, radius, spread, amount_of_projectiles, duration])
        base_stat += ratio

    base_stat = base_stat_tab[2]
    ratio = ration_tab[2]
    for level in range(21, 31):
        rounded_base_stat = round(base_stat)
        writer.writerow([level, rounded_base_stat, cool_down, range_, projectile_speed, critical_hit_chance, radius, spread, amount_of_projectiles, duration])
        base_stat += ratio

    base_stat = base_stat_tab[3]
    ratio = ration_tab[3]
    for level in range(31, 41):
        rounded_base_stat = round(base_stat)
        writer.writerow([level, rounded_base_stat, cool_down, range_, projectile_speed, critical_hit_chance, radius, spread, amount_of_projectiles, duration])
        base_stat += ratio

    base_stat = base_stat_tab[4]
    ratio = ration_tab[4]
    for level in range(41, 51):
        rounded_base_stat = round(base_stat)
        writer.writerow([level, rounded_base_stat, cool_down, range_, projectile_speed, critical_hit_chance, radius, spread, amount_of_projectiles, duration])
        base_stat += ratio

print("CSV file created successfully.")
