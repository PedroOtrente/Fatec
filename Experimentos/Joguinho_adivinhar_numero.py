import os, random, sys
clear = lambda: os.system('cls' if os.name == 'nt' else 'clear')

def cabecalho():
    print(f'{"Joguinho de acertar número, ebaaa":^60}')
    print(f"{'Tente acertar o número secreto. Ele está entre 1 e 100':^60}")
    print('-'*60)

def escolha():
    while True:
        try:
            opt = int(input("Qual você escolhe?\n"))
            if opt <= 0 or opt >100:
                print("O número está fora do range, babe\n")
                continue
            else: break
        except: 
            print("Somente números inteiros, sor\n")
            continue
    return opt

def resultado():
    tentativas = 0
    segredo = random.randint(1,100)
    clear()
    cabecalho()
    while True:
        opt = escolha()
        tentativas +=1
        if opt > segredo:
            print("O número é menor, babe\n")
        elif opt < segredo:
            print("O número é maior, querido\n")
        else:
            print(f"Acertou ebaaa! O número era {segredo} e você acertou na {tentativas}° tentativa!")
            break
    return 

def main():
    while True:
        resultado()
        while True:
            denovo = int(input(f"Gostaria de jogar de novo?\n{'\t\t1. Sim\t\t'} {'2. Não\t\t'}"))
            match denovo:
                case 1:
                    break
                case 2:
                    print(f"{'Tchau, paizão':^60}")
                    sys.exit()
                case _:
                    print("Escolha algo válido por favooor")
                    continue



if __name__ == "__main__":
    main()