import random
import os
import time

def clear_screen():
    os.system('cls' if os.name == 'nt' else 'clear')

class Character:

    def __init__(self, name, max_hp, attack, defense):
        self.name = name
        self.max_hp = max_hp
        self.current_hp = max_hp
        self.attack = attack
        self.defense = defense

    def is_alive(self):
        return self.current_hp > 0

    def take_damage(self, damage):
        actual_damage = max(0, damage - self.defense)
        self.current_hp = max(0, self.current_hp - actual_damage)
        return actual_damage

class Player(Character):
    def choose_action(self):
        while True:
            print("\n\n                                                    @")   
            print("                                     DRAGON           #%@")
            print("                                     ###@@%%         ##%#%@")
            print("                                   ###%@@@@%%       ##$$%%%##@")
            print("                                  %@%#%*==+%@%%     #%%###%%%#$$%@")
            print("                                   ###*    +%@%*   ###%%%$$$$+++&&%@")
            print("                                   #+-     %%%%    ###++==###$$##==%@")
            print("                                  #       *%%%-    %%%%##=$$$######+=%@")
            print("                                         -#@@+     ##%###=#%%%%$####--+@@")
            print("                                         +@@%      ##%%##+===%%%%####++=%=@")
            print("           HUMAN                        +%%#=     ##%##++==###%%###%$$####=%@")
            print("                                      #%*#%@#     *##*#%%##*#####%%%%%$$**%@")
            print("@@#+++++====+%%#-:::::+*#+-          +##@%@@*+%***###%%%%%%%######%%%###+@")
            print("@@*::::--=---####:.:=**:.            *##%%%@@@%%#*##%%#%@@@@%%%%%##*%@")
            print("@@+.::----:::-&&#:-=-==              +%%%%@%%%#%%%#%%%*%%%@@@%%%%%@#=%@")
            print("@@*:-------:=*###*+++:.              =#%%@@@@%*#%@@@%@%@@@@%#*#%%%@@%%#*")
            print("@@*-==--==-##=%%%%*.                 -#@@@@@@@##*%@@@@%****##%%%@@@@@@%%#")
            print("@@*-==-===##:*%%%%=.                  -*#%*#****#%*+**%%###%@@@@@@@@@@@%%#")
            print("@@#==--==##=-=#####=                 -+###**#-%@@@##%#%%%%%%@%%*++==+#@@@@%%#")
            print("@@#==---##=--:-%%%%+                 +##-      :+%@@@@@@@@@@@@@@%###%    *@@@%%*")
            print("@@#==---===---#%@@@#-                *#*              +%@@@%**####%@*      +@%%%*")
            print("@@#==-----==-+%%@@@%=                                      *#*#@@#=           ***%")
            print("@@*--::------=#%#=%%=                                         @@              -=#@*")
            print("@@*:::::::::-+#%*=*#+==                                                     #@@@@@%")
            print("@@*::::::::-=*##**##*                                                       @@@@@")
            print("@@*::::::--=+#%#%%*=\n\n\n\n")
            print("==================")
            print("   Pilih aksi")
            print("  Hero VS Dragon")
            print("==================")
            print("1. Serang Dragon!")
            print("2. Bertahan Dari Serangan Dragon")
            print("3. Minum Potion (Pulihkan 30 HP)")
            print("4. Skill ")
            print("==================")
            try:
                choice = int(input("Masukkan pilihan (1/2/3/4): "))
                if choice in [1, 2, 3, 4]:
                    return choice
                else:
                    print("Pilihan tidak valid. Coba lagi.")
            except ValueError:
                print("Input tidak valid. Masukkan angka.")

class EnemyAI(Character):
    def choose_action(self, turn_count):
        if turn_count > 0 and turn_count % 5 == 0:
            return 4  # Gunakan skill spesial jika diizinkan
        if self.current_hp < self.max_hp * 0.3:
            return random.choice([2, 3])  # Bertahan atau sembuh jika HP rendah
        elif random.random() < 0.7:  # Serang dengan probabilitas 70%
            return 1
        else:
            return random.choice([2, 3])

class Game:
    def __init__(self):
        self.player = Player("Hero", max_hp=100, attack=15, defense=5)
        self.enemy = EnemyAI("Dragon", max_hp=100, attack=15, defense=5)
        self.potions = 3
        self.turn_count = 0  # Menghitung jumlah giliran

    def display_status(self):
        print(f"{self.player.name} HP: {self.player.current_hp}/{self.player.max_hp} \t\t{self.enemy.name} HP: {self.enemy.current_hp}/{self.enemy.max_hp}")
        # perulangan angka dari 1 sampai 10
        if self.player.current_hp != 0 and self.enemy.current_hp != 0:
            for i in range(int(self.player.current_hp / 5)):
                print("=", end="")
            print("\t\t",end="")
            for i in range(int(self.enemy.current_hp / 5)):
                print("=", end="")

    def use_skill(self, user, target):
        print(f"\n{user.name} menggunakan SKILL spesial!")
        gamble = random.randint(1, 4)
        if gamble == 4:
            damage = int(target.max_hp * 0.6)
        elif gamble == 3:
            damage = int(target.max_hp * 0.5)
        elif gamble == 2:
            damage = int(target.max_hp * 0.3)
        else:
            damage = int(target.max_hp * 0.15)

        actual_damage = target.take_damage(damage)
        print(f"{user.name} mendapatkan angka {gamble}. {target.name} menerima {actual_damage} damage dari SKILL!")
        time.sleep(2)

    def player_turn(self):
        clear_screen()
        print("\t### GILIRAN ANDA ###")
        self.display_status()
        action = self.player.choose_action()
        print(self.skill_turn)
        self.PlayerDeffTurn += 1
        if self.PlayerDeffTurn > 2:
            self.player.defense = 5
            
        if self.skill_turn >= 5 and self.skill_used == False:
                self.skill_used = True
        
        if action == 4 and self.skill_used == True:
            self.use_skill(self.player, self.enemy)
            self.skill_used = False
            self.skill_turn = 1

        elif action == 1:
            damage = random.randint(5, self.player.attack)
            actual_damage = self.enemy.take_damage(damage)
            print(f"Anda menyerang {self.enemy.name} dan memberikan {actual_damage} damage!")
            self.skill_turn += 1
        elif action == 2:
            self.player.defense *= 3
            self.PlayerDeffTurn = 0
            self.skill_turn += 1
            print(f"{self.player.name} meningkatkan pertahanan selama 2 turn!")
        elif action == 3:
            if self.potions > 0:
                heal_amount = 30
                self.player.current_hp = min(self.player.max_hp, self.player.current_hp + heal_amount)
                self.potions -= 1
                self.skill_turn += 1
                print(f"{self.player.name} meminum potion dan memulihkan {heal_amount} HP!")
                print(f"Sisa potion: {self.potions}")
            else:
                print("Tidak ada potion tersisa!")
        else:
            print("Aksi tidak valid atau skill belum tersedia.")
            time.sleep(2)
            self.player_turn()
        time.sleep(2)

    def enemy_turn(self):
        clear_screen()
        print("=== GILIRAN MUSUH ===")
        self.display_status()
        action = self.enemy.choose_action(self.turn_count)
        self.EnemyDeffTurn += 1
        if self.EnemyDeffTurn > 2:
            self.enemy.defense = 5
        if action == 4:
            self.use_skill(self.enemy, self.player)
        elif action == 1:
            damage = random.randint(3, self.enemy.attack)
            actual_damage = self.player.take_damage(damage)
            print(f"{self.enemy.name} menyerang Anda dan memberikan {actual_damage} damage!")
        elif action == 2:
            self.enemy.defense *= 3
            self.EnemyDeffTurn = 0
            print(f"{self.enemy.name} meningkatkan pertahanan selama 2 turn!")
        elif action == 3:
            heal_amount = 25
            self.enemy.current_hp = min(self.enemy.max_hp, self.enemy.current_hp + heal_amount)
            print(f"{self.enemy.name} meminum potion dan memulihkan {heal_amount} HP!")
        time.sleep(1)

    def play(self):
        clear_screen()
        print("=== Pertarungan Dimulai! ===")
        self.skill_turn = 1
        self.EnemyDeffTurn = 3
        self.PlayerDeffTurn = 3
        self.skill_used = False
        while self.player.is_alive() and self.enemy.is_alive():
            self.turn_count += 1
            self.player_turn()
            if not self.enemy.is_alive():
                clear_screen()
                print(f"\n{self.enemy.name} telah dikalahkan! Anda menang!")
                break
            self.enemy_turn()
            if not self.player.is_alive():
                clear_screen()
                print(f"\n{self.player.name} telah dikalahkan! Game Over!")
                break
        print("\n===========================")
        print("\n=== Pertarungan Selesai ===")
        print("\n===========================")

def main():
    game = Game()
    game.play()

if __name__ == "__main__":
    main()
