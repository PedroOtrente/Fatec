import os
limpa_tela = lambda: os.system('cls')
limpa_tela()

from entrada_dados import garantir_arquivo_existe,ler_arquivo,escrever_arquivo,pega_inteiro_positivo,pega_string_nao_vazia


nome_arquivo = 'medicamentos.txt'
reservas_arquivo = 'reservas.txt'

def menu():
    print("======= Menu de Opções ========")
    print("1. Adicionar Medicamento")
    print("2. Listar Medicamentos")
    print("3. Atualizar Medicamento")
    print("4. Remover Medicamento")
    print("5. Buscar Medicamento")
    print("6. Reservar Medicamento")
    print("7. Listar Reservas")
    print("8. Sair")
    print("===============================")


garantir_arquivo_existe(reservas_arquivo)

garantir_arquivo_existe(nome_arquivo)

while True:
    limpa_tela()
    menu()
    opcao = input("Digite a opção desejada: ")

    if opcao == '1':
         ## Adicionar um medicamento no arquivo ## OK
        nome_m = pega_inteiro_positivo("Digite o nome do medicamento: ")
        quantidade_m = pega_inteiro_positivo("Digite a quantidade: ")
        adicionar_medicamentos(nome_m, quantidade_m)
        input("<enter> para continuar...")

    elif opcao == '2':
        ## Listar todos os medicamentos do arquivo ##
        if os.path.getsize(nome_arquivo > 0):
            listar_medicamentos()
        else:
            print("Arquivo de medicamentos '{nome_arqvuivo}' está vazio")
            input("<enter> para continuar...")
    
    elif opcao == '3':
        ## Atualizar a quantidade de um medicamento especifico ##
        if os.path.getsize(nome_arquivo > 0):
            nome_m = pega_string_nao_vazia("Digite o nome do medicamento: ")
            atualizar_medicamentos(nome_m)
        else:
            print(f"Arquivo de medicamentos {nome_arquivo} está vazio: ")
        input("<enter> para continuar")

    elif opcao == '4':
        ## Remover um medicamento especifico ##
        if os.path.getsize(nome_arquivo > 0):
            