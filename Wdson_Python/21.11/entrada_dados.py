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
