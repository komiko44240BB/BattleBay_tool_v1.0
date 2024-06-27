import csv

header = ["LEVEL", "BASE_STAT", "COOL_DOWN", "RANGE", "PROJECTILE_SPEED","CRITICAL_HIT_CHANCE", "RADIUS", "SPREAD", "AMOUNT_OF_PROJECTILES", "DURATION"]

cool_down = [5.6,11.1,11.1,14.4,10,8.5,11.1,11,10,10,15.6,6.1,13.3,10,15,22.2,12.8,12.8,15,11.1,13.3,16.5,0,0,0,0,0,12,12,20,20,11.1,13.3,11.1,14.7,17,15,17,18,20,20,20]
range_ = [25,22,40,22,25,12,12,25,35,25,25,0,0,0,0,0,30,30,7,22,22,27,0,0,0,0,0,0,0,0,0,0,30,7,0,0,0,22,0,0,0,0]
projectile_speed = [34.7,17.8,39.6,14.9,38.5,33,0,0,0,0,0,4,3.3,5,3.7,39.6,0,0,0,19.3,0,0,0,0,0,0,0,0,0,14.9,0,55,0,0,0,0,16.5,0,0,0,0,0]
critical_hit_chance = [1.0,1.0,5.0,1.0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
radius = [0,0,0,2,0,0,2.2,3,3,4.2,3.3,3,3.5,3,2,0,1.5,1.5,2,0,4,3.6,0,0,0,0,0,0,0,0.3,1,0,6,1,5,0,0.3,4,0,7,0,7]
spread = [0,0,0,0,3,8,0,0,0,0,0,0,0,0,15,0,10,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,140,0,0,0]
amount_of_projectiles = [1,1,1,1,15,7,1,1,1,1,1,1,1,1,3,1,5,9,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
duration = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,20,13,0,0,0,0,0,6,1,0,5,7,7,0,8.5,10,0,15,8,8,6,0]
item_name = ['standard_cannon','blast_cannon','sniper_cannon','explosive_canon','galting_gun','carronade','grenade_launcher','standard_mortar','long_range_mortar','ballpark_mortar','big_berta','standard_torpedo','big_torpedo','swift_torpedo','triple_torpedo','railgun','missile_launcher',
             'multi_missile','mine','flare_gun','napalm_launcher','fire_bomb','standard_shield','big_shield','turbo','bandage','big_bandage','overboost','nitro','tesla_bolt','tesla_shield','frost_blaster','frsot_launcher','repair_box_launcher','repair_pulse','duct_tape','repair_bolt',
             'repair_plasma','defence_wall','defence_aura','bloster_armor','cleanse_pulse']
rarity = ['common','uncommon','rare','epic','legendary']
base_stat_tab = [
    [[138,150,161,172,184],[147,170,192,215,238],[155,188,220,252,285],[170,212,255,298,341],[319,347,376,404,433]],#standard_cannon
    [[248,268,288,308,328],[265,305,346,387,428],[281,339,397,455,513],[307,385,463,541,619],[576,627,679,730,781]],#blast_cannon
    [[171,185,198,211,225],[183,211,240,268,297],[194,234,274,314,354],[212,266,319,372,425],[398,433,468,503,538]],#sniper_cannon
    [[300,323,347,371,395],[319,367,416,464,513],[338,407,476,546,615],[369,462,555,648,741],[694,756,817,879,941]],#explosive_canon
    [[21,32,36,39,43],[27,34,40,47,54],[32,39,47,55,62],[38,46,55,63,72],[65,72,78,85,92]],#galting_gun
    [[29,35,40,46,52],[38,45,52,58,65],[43,52,60,69,77],[48,59,71,82,94],[83,92,100,109,117]],#carronade
    [[300,323,347,371,395],[319,368,418,467,516],[339,408,477,547,616],[369,462,555,648,741],[694,756,817,879,941]],#grenade_launcher
    [[316,342,367,393,418],[337,388,439,491,542],[357,430,503,576,649],[390,489,588,686,785],[732,798,863,929,994]],#standard_mortar
    [[253,273,293,313,333],[270,312,354,396,437],[286,345,404,463,522],[313,392,471,550,628],[588,640,692,744,797]],#long_range_mortar
    [[249,269,289,309,329],[266,306,347,388,429],[282,340,398,456,513],[307,385,463,541,619],[578,629,681,732,783]],#ballpark_mortar
    [[475,513,551,589,627],[505,583,661,739,817],[536,646,757,867,977],[586,734,882,1030,1178],[1101,1199,1298,1397,1496]],#big_berta
    [[281,303,325,347,369],[300,346,392,438,484],[317,382,447,512,577],[347,453,523,611,699],[651,709,767,825,884]],#standard_torpedo
    [[523,565,607,648,690],[556,642,727,813,898],[590,712,834,955,1077],[645,808,971,1135,1298],[1213,1321,1429,1538,1646]],#big_torpedo
    [[322,347,373,399,424],[342,395,447,499,551],[363,438,513,589,664],[397,497,598,699,799],[744,811,877,944,1010]],#swift_torpedo
    [[314,339,363,388,413],[335,386,437,489,540],[355,428,501,574,647],[387,485,583,681,779],[728,794,859,925,990]],#triple_torpedo
    [[469,506,543,580,617],[499,576,653,730,807],[530,639,748,857,967],[578,724,871,1017,1163],[1086,1183,1280,1377,1474]],#railgun
    [[125,134,144,153,163],[133,153,173,193,213],[141,171,200,229,259],[154,193,232,271,310],[289,315,341,366,392]],#missile_launcher
    [[72,77,83,89,95],[76,88,99,111,122],[81,97,114,130,146],[88,110,132,153,175],[165,179,193,208,222]],#multi_missile
    [[662,715,768,821,874],[705,814,922,1030,1139],[748,902,1056,1210,1364],[817,1024,1231,1438,1645],[1536,1673,1811,1949,2087]],#mine
    [[20,22,24,26,28],[22,26,30,34,38],[24,29,39,38,43],[26,33,39,46,53],[46,51,56,60,65]],#flare_gun
    [[37,40,44,48,52],[40,47,54,60,67],[44,53,61,70,78],[48,59,71,82,94],[89,96,104,112,119]],#napalm_launcher
    [[24,26,28,30,32],[25,29,33,37,40],[27,33,38,44,50],[30,38,45,53,60],[55,59,64,69,74]],#fire_bomb
    [[357,386,415,444,473],[381,440,499,558,617],[404,487,570,653,736],[441,553,665,777,889],[829,903,977,1051,1125]],#standard_shield
    [[476,514,552,590,628],[507,585,663,741,819],[538,649,760,871,982],[588,737,886,1035,1184],[1105,1204,1303,1402,1501]],#big_shield
    [[0.05,0.082,0.114,0.145,0.177],[0.1,0.144,0.188,0.232,0.276],[0.16,0.207,0.255,0.302,0.35],[0.23,0.281,0.331,0.382,0.432],[0.405,0.438,0.471,0.504,0.537]],#turbo
    [[38,41,44,48,51],[40,47,53,60,66],[43,52,61,70,79],[47,59,71,83,94],[87,95,103,110,118]],#bandage
    [[68,73,78,83,89],[72,82,93,103,114],[76,92,108,123,139],[83,104,125,146,167],[156,170,183,197,210]],#big_bandage
    [[0.2,0.26,0.32,0.38,0.44],[0.3,0.374,0.448,0.522,0.596],[0.4,0.482,0.564,0.646,0.728],[0.52,0.608,0.696,0.784,0.872],[0.824,0.883,0.942,1.002,1.061]],#overboost
    [[1.552,1.815,2.079,2.343,2.606],[2.07,2.378,2.686,2.994,3.302],[2.59,2.906,3.222,3.538,3.854],[3.1,3.426,3.752,4.078,4.404],[4.225,4.436,4.647,4.858,5.069]],#nitro
    [[2.5,2.99,3.48,3.97,4.46],[3.1,3.634,4.168,4.702,5.236],[3.8,4.366,4.932,5.498,6.064],[4.6,5.188,5.776,6.364,6.952],[6.62,6.994,7.368,7.742,8.116]],#tesla_bolt
    [[203,235,267,299,331],[225,279,333,387,441],[248,343,438,533,628],[405,531,657,783,909],[810,900,990,1080,1170]],#tesla_shield
    [[-0.2,-0.238,-0.276,-0.314,-0.352],[-0.26,-0.298,-0.336,-0.374,-0.412],[-0.3,-0.342,-0.384,-0.426,-0.468],[-0.36,-0.4,-0.44,-0.48,-0.52],[-0.498,-0.5224,-0.5468,-0.5712,-0.5956]],#frost_blaster
    [[-0.2,-0.2232,-0.2464,-0.2696,-0.2928],[-0.25,-0.2764,-0.3028,-0.3292,-0.3556],[-0.29,-0.3202,-0.3504,-0.3806,-0.4108],[-0.32,-0.355,-0.39,-0.425,-0.46],[-0.423,-0.4514,-0.4798,-0.5082,-0.5366]],#frsot_launcher
    [[220,238,256,274,292],[234,270,306,342,378],[248,299,350,401,452],[271,340,409,478,547],[509,555,601,647,693]],#repair_box_launcher
    [[20,25,30,35,40],[22,28,34,40,46],[29,35,41,47,53],[32,40,48,56,64],[60,65,70,75,80]],#repair_pulse
    [[42,45,48,51,54],[44,51,58,65,72],[47,57,67,77,87],[51,64,77,90,103],[96,105,114,123,132]],#duct_tape
    [[346,374,402,430,458],[368,425,482,539,596],[391,472,553,634,715],[427,535,643,751,859],[802,874,946,1018,1090]],#repair_bolt
    [[29,31,33,35,37],[31,36,40,45,50],[33,39,46,53,59],[36,44,53,61,70],[67,73,78,84,90]],#repair_plasma
    [[893,964,1035,1106,1177],[951,1097,1243,1389,1535],[1009,1217,1425,1633,1841],[1101,1380,1659,1938,2217],[2072,2258,2444,2630,2816]],#defence_wall
    [[0.119,0.1285,0.138,0.1475,0.157],[0.1267,0.1462,0.1657,0.1852,0.2047],[0.1344,0.1622,0.1899,0.2176,0.2454],[0.1468,0.184,0.2213,0.2585,0.2958],[0.2762,0.3009,0.3257,0.3505,0.3752]],#defence_aura
    [[0.119,0.1285,0.138,0.1475,0.157],[0.1267,0.1462,0.1657,0.1852,0.2047],[0.1344,0.1622,0.1899,0.2176,0.2454],[0.1468,0.184,0.2213,0.2585,0.2958],[0.2762,0.3009,0.3257,0.3505,0.3752]],#bloster_armor
    [[4.461,4.8176,5.1742,5.5308,5.8874],[4.7509,5.4823,6.2136,6.945,7.6763],[5.0408,6.081,7.1211,8.1612,9.2014],[5.5047,6.9015,8.2982,9.695,11.0917],[10.3563,11.285,12.2138,13.1425,14.0713]]#cleanse_pulse
]


ration_tab = [
    [[1.22,1.11,1.11,1.22,0.88],[2.33,2.22,2.33,2.33,2.33],[3.33,3.22,3.22,3.33,3.44],[4.33,4.33,4.33,4.33,4.77],[2.77,2.88,2.77,2.88,3.11]],#standard_cannon
    [[2,2,2,2,2.22],[4.11,4.11,4.11,4.11,4.44],[5.77,5.77,5.77,5.77,6.33],[7.88,7.88,7.77,7.77,8.44],[5.22,5.22,5.11,5.22,6]],#blast_cannon
    [[1.44,1.33,1.33,1.44,1.66],[2.88,3,2.88,3,2.88],[4,4,4,4,4.44],[5.44,5.33,5.33,5.33,6],[3.55,3.55,3.55,3.55,4.22]],#sniper_cannon
    [[2.44,2.44,2.44,2.44,2.55],[4.77,4.88,4.77,4.88,5.55],[6.88,7,7,6.88,7.88],[9.44,9.44,9.44,9.44,10.55],[6.22,6.22,6.33,6.22,7]],#explosive_canon
    [[1,0.44,0.33,0.44,0.55],[0.77,0.66,0.77,0.77,0.44],[0.77,0.88,0.88,0.77,0.77],[0.88,1,0.88,1,0.77],[0.77,0.66,0.77,0.77,0.44]],#galting_gun
    [[0.66,0.55,0.66,0.66,0.55],[0.77,0.77,0.66,0.77,0.77],[1,0.88,1,0.88,1],[1.22,1.33,1.22,1.33,1.22],[1,0.88,1,0.88,1]],#carronade
    [[2.44,2.44,2.44,2.44,2.55],[4.88,5,4.88,5,5.33],[6.88,7,7,6.88,7.77],[9.44,9.44,9.44,9.44,10.66],[6.22,6.22,6.33,6.22,7.11]],#grenade_launcher
    [[2.66,2.55,2.66,2.66,2.66],[5.11,5.22,5.22,5.11,5.77],[7.33,7.33,7.44,7.44,8.33],[9.88,9.88,9.88,10,10.88],[6.66,6.55,6.66,6.55,7.33]],#standard_mortar
    [[2,2,2,2,2.44],[4.22,4.22,4.22,4.22,4.44],[6,6,5.88,5.88,6.55],[7.88,7.88,7.88,7.88,8.88],[5.22,5.22,5.33,5.33,6]],#long_range_mortar
    [[2,2,2,2,2.22],[4.11,4.11,4.11,4.11,4.55],[5.77,5.77,5.77,5.77,6.44],[7.88,7.88,7.77,7.77,8.66],[5.22,5.22,5.11,5.22,5.88]],#ballpark_mortar
    [[3.88,3.88,3.88,3.88,4.11],[7.77,7.77,7.77,7.77,8.44],[11.11,11.11,11,11.11,12.33],[14.88,14.88,14.88,14.88,16.55],[9.88,10,9.88,9.88,10.88]],#big_berta
    [[2.22,2.22,2.22,2.22,2.66],[4.55,4.66,4.66,4.66,4.88],[6.66,6.66,6.55,6.55,7.44],[8.88,8.88,8.88,8.88,9.55],[5.77,5.88,5.88,5.88,6.44]],#standard_torpedo
    [[4.22,4.22,4.22,4.22,4.55],[8.55,8.55,8.55,8.55,9.66],[12.33,12.22,12.22,12.22,13.55],[16.33,16.33,16.44,16.33,18.22],[10.88,10.88,10.88,10.77,12.11]],#big_torpedo
    [[2.55,2.66,2.66,2.55,2.88],[5.33,5.22,5.22,5.33,6],[7.66,7.66,7.66,7.55,8.11],[10.11,10.22,10.11,10.11,11],[6.66,6.66,6.66,6.66,7.55]],#swift_torpedo
    [[2.55,2.44,2.55,2.55,2.88],[5.11,5.22,5.22,5.11,5.66],[7.33,7.33,7.44,7.44,8.11],[9.77,9.77,9.77,9.77,10.88],[6.66,6.66,6.66,6.66,7.11]],#triple_torpedo
    [[3.77,3.77,3.77,3.77,4.22],[7.77,7.77,7.66,7.66,8.33],[10.88,11,11,11,11.88],[14.66,14.66,14.66,14.66,16.33],[9.77,9.77,9.77,9.66,11]],#railgun
    [[0.88,1,0.88,1,1.33],[2.11,2,2,2,2.44],[3,2.88,3,3,3],[4,3.88,3.88,3.88,4.33],[2.66,2.66,2.55,2.66,2.88]],#missile_launcher
    [[0.55,0.66,0.66,0.66,0.55],[1.22,1.11,1.22,1.11,1.33],[1.66,1.77,1.66,1.66,1.88],[2.22,2.22,2.22,2.22,2.66],[1.44,1.44,1.55,1.44,1.77]],#multi_missile
    [[5.33,5.33,5.44,5.44,5.88],[10.88,10.88,10.88,10.88,12],[15.44,15.44,15.44,15.44,17.22],[20.77,20.77,20.77,20.77,23],[13.77,13.88,13.88,13.77,15.11]],#mine
    [[0.22,0.22,0.22,0.22,0.22],[0.44,0.44,0.44,0.44,0.33],[0.55,0.55,0.44,0.55,0.55],[0.77,0.66,0.77,0.77,0.66],[0.55,0.55,0.44,0.55,0.44]],#flare_gun
    [[0.33,0.44,0.44,0.44,0.44],[0.77,0.77,0.66,0.77,0.77],[1,0.88,1,0.88,1],[1.22,1.33,1.22,1.33,1.22],[0.77,0.88,0.88,0.77,0.88]],#napalm_launcher
    [[0.22,0.22,0.22,0.22,0.22],[0.44,0.44,0.44,0.33,0.44],[0.66,0.55,0.66,0.66,0.44],[0.88,0.77,0.88,0.77,0.66],[0.44,0.55,0.55,0.55,0.44]],#fire_bomb
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#standard_shield
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#big_shield
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#turbo
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#bandage
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#big_bandage
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#overboost
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#nitro
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#tesla_bolt
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#tesla_shield
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#frost_blaster
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#frsot_launcher
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#repair_box_launcher
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#repair_pulse
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#duct_tape
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#repair_bolt
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#repair_plasma
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#defence_wall
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#defence_aura
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]],#bloster_armor
    [[,,,,],[,,,,],[,,,,],[,,,,],[,,,,]]#cleanse_pulse
]

file_name = []

def create_file():
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
