import os

def pega_string_nao_vazia(texto):
    while True:
        valor = input(texto).strip()
        if valor:
            return valor
        else:
            print("Erro: campo não pode ser vazio")

def pega_inteiro_positivo(texto):
    while True:
        try:
            valor = int(input(texto))
            if valor > 0:
                return valor
            else:
                print("Erro: campo não pode ser negativo")  
        except ValueError:
            print("Erro: campo deve ser um numero inteiro")


def ler_arquivo(nome_arquivo):
    #Lê o conteúdo de um arquivo e retorna como uma lista.
    try:
        with open(nome_arquivo, 'r', encoding='utf-8') as arquivo:
            return arquivo.readlines()
        
    except FileNotFoundError:
        print(f"Arquivo '{nome_arquivo}' não encontrado.")
    except IOError:
        print("Erro : no acesso de abertura do arquivo")
    except PermissionError:
        print("Erro : permissão de acesso ao arquivo")
    except Exception as e:
        print(f"Erro ao ler o arquivo '{nome_arquivo}': {e}")
    return []

def escrever_arquivo(nome_arquivo, conteudo, modo='w'):
    #Escreve conteúdo no arquivo especificado.
    try:
        with open(nome_arquivo, modo) as arquivo:
            arquivo.write(conteudo)

    except IOError:
        print("Erro : no acesso de abertura do arquivo")
    except PermissionError:
        print(f"Erro : permissão de acesso ao arquivo {nome_arquivo}")
    except Exception as e:
        print(f"Erro inesperado no arquivo '{nome_arquivo}': {e}")


### verificar se o arquivo existe, senão cria o mesmo ###
def garantir_arquivo_existe(arquivov):
    if not os.path.exists(arquivov):
        open(arquivov, 'a').close()