import time
import pyautogui


number_of_boosts = [
    32,#standard_cannon
    31,#blast_cannon
    30,#sniper_cannon
    30,#explosive_canon
    22,#galting_gun
    33,#carronade
    30,#grenade_launcher
    27,#standard_mortar
    28,#long_range_mortar
    27,#ballpark_mortar
    32,#big_berta
    31,#standard_torpedo
    27,#big_torpedo
    31,#swift_torpedo
    30,#triple_torpedo
    20,#railgun
    26,#missile_launcher
    26,#multi_missile
    28,#mine
    33,#flare_gun
    29,#napalm_launcher
    24,#fire_bomb
    27,#standard_shield
    30,#big_shield
    4,#turbo
    13,#bandage
    13,#big_bandage
    8,#overboost
    25,#nitro
    18,#tesla_bolt
    23,#tesla_shield
    13,#frost_blaster
    16,#frost_launcher
    29,#repair_box_launcher
    19,#repair_pulse
    15,#duct_tape
    17,#repair_bolt
    29,#repair_plasma
    27,#defence_wall
    13,#defence_aura
    13,#bloster_armor
    4#cleanse_pulse
]

for i in range(0,41):
    time.sleep(5)

    for j in range (0,number_of_boosts[i]):
        pyautogui.press(',')
        time.sleep(0.1)
    