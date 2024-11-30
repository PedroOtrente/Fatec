import os
limpa_tela = lambda: os.system('cls')
limpa_tela()

from entrada_dados import pega_inteiro_positivo, pega_string_nao_vazia

nome_arquivo = "C:/Users/2880482411004.LABFATECAQA/Desktop/Ex Python/inventario.txt"

def menu():
    print("===== Menu de Opções =====")
    print("1. Adicionar um produto")
    print("2. Listar o inventário")
    print("3. Atualizar um produto")
    print("4. Remover um produto")
    print("5. Buscar um produto")
    print("6. Sair") 


def adicionar_produto(nome_p, quantidade_p):
    try:
        with open(nome_arquivo,'a') as arquivo:
            arquivo.write(f"{nome_p}: {quantidade_p}\n")
            print(f"Produto {nome_p} inserido com sucesso!")
     
    except IOError:
        print("Erro no acesso da abertura do arquivo")
    except PermissionError:
        print("Erro de permissão de acesso ao arquivo")
    except Exception as e:
        print(f"Erro inesperado {e}")
    except FileNotFoundError:
        print("Arquivo não encontrado")
    
def listar_produtos():
    with open(nome_arquivo, 'r') as arquivo:
        print("======== Inventário de produtos ========")
        print(f"{'Produto': <30}{'Quantidade': <10}")
        for linha in arquivo:
            produto, quantidade = linha.strip().split(":")
            print(f"{produto: <30}{quantidade: <10}")

def atualizar_produtos(nome_p):
    try:
        with open(nome_arquivo,'r') as arquivo:
            linhas = arquivo.readlines()

    except IOError:
        print("Erro no acesso da abertura do arquivo")
    except PermissionError:
        print("Erro de permissão de acesso ao arquivo")
    except Exception as e:
        print(f"Erro inesperado {e}")
    except FileNotFoundError:
        print("Arquivo não encontrado")

    try:
        achou_produto = False
        with open(nome_arquivo, 'w') as arquivo:
            for linha in linhas:
                if linha.startswith(f"{nome_p}"):
                    quantidade_p = pega_inteiro_positivo("Digite a quantidade: ")
                    arquivo.write(f"{nome_p}:{quantidade_p}\n")
                    achou_produto = True
                else:
                    arquivo.write(linha)
                
            if achou_produto:
                print(f"Produto {nome_p} alterado com sucesso!")
            else:
                print(f"Produto {nome_p} não encontrado!")

    except IOError:
        print("Erro no acesso da abertura do arquivo")
    except PermissionError:
        print("Erro de permissão de acesso ao arquivo")
    except Exception as e:
        print(f"Erro inesperado {e}")


def remover_produto():
    try:
        with open(nome_arquivo,'r') as arquivo:
            linhas = arquivo.readlines()
            
    except IOError:
        print("Erro no acesso da abertura do arquivo")
    except PermissionError:
        print("Erro de permissão de acesso ao arquivo")
    except Exception as e:
        print(f"Erro inesperado {e}")
    except FileNotFoundError:
        print("Arquivo não encontrado")

    try:
        with open(nome_arquivo,'w') as arquivo:
            achou_produto = False
            for linha in linhas:
                if linha.startswith(f"{nome_p}:"):
                    achou_produto = False
                else:
                    arquivo.write(linha)
            if achou_produto:
                print(f"Produto {nome_p} removido com sucesso")
            else:
                print(f"Produto {nome_p} não encontrado")
     
    except IOError:
        print("Erro no acesso da abertura do arquivo")
    except PermissionError:
        print("Erro de permissão de acesso ao arquivo")
    except Exception as e:
        print(f"Erro inesperado {e}")
    except FileNotFoundError:
        print("Arquivo não encontrado")


def buscar_produto(nome_p):
    try:
        with open(nome_arquivo, 'r') as arquivo:
            achou_produto = False
            for linha in arquivo:
                produto, quantidade = linha.strip().split(":")
                if produto == nome_p:
                    print("===== Inventário do Produto =====")
                    print(f"{'Produto': <30} {'Quantidade':<10}")
                    print(f"{produto:<30} {quantidade:<10}")
                    return
            print(f"Produto {nome_p} não encontrado")

    except IOError:
        print("Erro no acesso da abertura do arquivo")
    except PermissionError:
        print("Erro de permissão de acesso ao arquivo")
    except Exception as e:
        print(f"Erro inesperado {e}")
    except FileNotFoundError:
        print("Arquivo não encontrado")


while True:
    limpa_tela()
    menu()
    op = input("Digite a opção desejada:\n")
    match op:
        case '1':
            nome_p = pega_string_nao_vazia("Digite o nome do produto: ")
            quantidade_p = pega_inteiro_positivo("Digite a quantidade: ")
            adicionar_produto(nome_p, quantidade_p)
            input("Enter parta continuar...")
        case '2':
            try:
                if os.path.getsize(nome_arquivo) > 0:
                    listar_produtos()
                else:
                    print("Inventário de produtos vazio!")
            except FileNotFoundError:
                print("Arquivo não encontrado")
            input("Enter para continuar...")
        case '3':
            if os.path.getsize(nome_arquivo) > 0:
                atualizar_produtos(nome_p)
            input("Enter para continuar...")
        case '4':
            try:
                if os.path.getsize(nome_arquivo) > 0:
                    listar_produtos()
                else:
                    print("Inventário de produtos vazio!")
            except FileNotFoundError:
                print("Arquivo não encontrado")
            input("Enter para continuar...")
        case '5':
            input("Enter para continuar...")
        case '6':
            limpa_tela()
            break
        case _:
            print("Opção inválida, tente novamente!")