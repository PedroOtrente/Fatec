#============================================#
### Controle de medicamento de uma clinica ###
#============================================#

#Sistema de controle de medicamentos para uma clínica, 
#com o objetivo de gerenciar o estoque de medicamentos 
#e as reservas realizadas pelos usuários.
#Dois arquivos serão utilizados para a implementação:
# medicamentos.txt (medicamento:quantidade:validade)
# reservas.txt (medicamento:quantidade:usuario:data_reserva)


## Funcionalidades do Programa  ##
#================================#

#1. Adicionar Medicamentos #
#Permitir adicionar novos medicamentos.

#2. Listar Medicamentos #
#Exibir todos os medicamentos e suas respectivas quantidades 
#disponíveis no estoque e validades.

'''
======= Inventário de Medicamentos ========
Medicamento        Quantidade      Validade
'''

#3. Atualizar Medicamentos #
#Alterar a quantidade de um medicamento no estoque.

#4. Remover Medicamentos #
#Excluir um medicamento do cadastro.

#5. Buscar Medicamento #
#Verificar se um medicamento específico está no estoque.

#6. Reservar Medicamento #
#Permitir reservar um medicamento para um usuário, incluindo 
#o nome do usuário, verificando a disponibilidade no estoque 
#e registrando a data da reserva.

#7. Listar Reservas #
#Exibir todas as reservas realizadas, com o nome do medicamento, 
#a quantidade reservada, o nome do usuário e a data da reserva.

'''
============ Relatório de reservas medicamentos ============
Usuário          Medicamento        Quantidade         Data           
'''

#8. Sair do Programa #
# Encerrar a execução do sistema.

## Importação das bibliotecas ##
##============================##

import os
limpa_tela = lambda: os.system('cls')
limpa_tela()

from entrada_dados import garantir_arquivo_existe,ler_arquivo,escrever_arquivo,pega_inteiro_positivo,pega_string_nao_vazia

## Variaveis Globais ##
##===================##

nome_arquivo = 'medicamentos.txt'
reservas_arquivo = 'reservas.txt'

## Implementação das funções ##
#=============================#

# Menu #
#======#

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

# Adicionar medicamentos #
#========================#

def adicionar_medicamentos(nome_m, quantidade_m):
    conteudo = f"{nome_m}:{quantidade_m}\n"
    escrever_arquivo(nome_arquivo, conteudo, modo='a')
    print(f"Medicamento {nome_m} com a quantidade de {quantidade_m} adicionado com sucesso!")

# Listar medicamentos #
#=====================#

def listar_medicamentos():
    limpa_tela()
    linhas = ler_arquivo(nome_arquivo) 
    print("=========== Inventário de Medicamentos ============")
    print(f"{'Medicamento': <30} {'Quantidade': <10}")
    for linha in linhas:
        medicamento, quantidade = linha.strip().split(":")
        print(f"{medicamento: <30} {quantidade: <10}")


# Atualizar medicamentos #
#========================#

def atualizar_medicamentos(nome_m):
    linhas = ler_arquivo(nome_arquivo)
    conteudo_atualizado = ""
    atualizado = False
    for linha in linhas:
        medicamento, quantidade = linha.strip().split(":")
        if medicamento == nome_m:
            nova_quantidade = pega_inteiro_positivo("Digite a nova quantidade: ")
            conteudo_atualizado += f"{medicamento}:{nova_quantidade}\n"
            atualizado = True
        else:
            conteudo_atualizado += linha
    escrever_arquivo(nome_arquivo, conteudo_atualizado)
    if atualizado:
        print(f"Medicamento {nome_m} atualizado com sucesso!")
    else:
        print(f"Medicamento {nome_m} não encontrado.")

# Remover medicamentos #
#======================#

def remover_medicamentos(nome_m):
    linhas = ler_arquivo(nome_arquivo)
    conteudo_atualizado = ""
    removido = False

    for linha in linhas:
        medicamento, quantidade = linha.strip().split(":")
        if medicamento != nome_m:
            conteudo_atualizado += linha
        else:
            removido = True
    escrever_arquivo(nome_arquivo, conteudo_atualizado)
    if removido:
        print(f"Medicamento {nome_m} removido com sucesso!")
    else:
        print(f"Medicamento {nome_m} não encontrado.")


# Buscar medicamentos #
#=====================#

def buscar_medicamento(nome_m):
    linhas = ler_arquivo(nome_arquivo)
    for linha in linhas:
        medicamento, quantidade = linha.strip().split(":")
        if medicamento == nome_m:
            print(f"Medicamento encontrado: {medicamento}, Quantidade: {quantidade}")
            return quantidade,True
    print(f"Medicamento {nome_m} não encontrado.")


# Reservar medicamentos #
#=======================#

def reservar_medicamento(nome_m, quantidade_r, nome_p, data_r):
    linhas = ler_arquivo(nome_arquivo)
    conteudo_atualizado = ""
    for linha in linhas:
        medicamento, quantidade = linha.strip().split(":")
        if medicamento == nome_m: #verifica cadastro do medicamento
            nova_quantidade = int(quantidade) - quantidade_r
            conteudo_atualizado += f"{medicamento}:{nova_quantidade}\n"
        else:
            conteudo_atualizado += linha

    escrever_arquivo(nome_arquivo, conteudo_atualizado)
    reserva = f"{nome_p}:{nome_m}:{quantidade_r}:{data_r}\n"
    escrever_arquivo(reservas_arquivo, reserva, modo='a')
    print(f"Medicamento {nome_m} reservado com sucesso para {nome_p} na data {data_r}!")


# Função para listar reservas #
#=============================#

def listar_reservas():
    linhas = ler_arquivo(reservas_arquivo)
    if linhas:
        print("=========== Reservas de Medicamentos ============")
        print(f"{'Usuário': <20} {'Medicamento': <25} {'Quantidade': <10} {'Data': <10}")
        for linha in linhas:
            nome, medicamento, quantidade, data = linha.strip().split(":")
            print(f"{nome: <20} {medicamento: <25} {quantidade: <10} {data: <10}")


###### Programa Principal ######
#==============================#

#Se o arquivo de reservas não existir, cria#
garantir_arquivo_existe(reservas_arquivo)

#Se o arquivo de medicamentos não existir, cria#
garantir_arquivo_existe(nome_arquivo)

while True:
    limpa_tela()
    menu()
    opcao = input("Digite a opção desejada: ")
    if opcao == '1':
        ## Adicionar um medicamento no arquivo ## OK
        nome_m = pega_string_nao_vazia("Digite o nome do medicamento: ")
        quantidade_m = pega_inteiro_positivo("Digite a quantidade: ")
        adicionar_medicamentos(nome_m, quantidade_m)
        input("<enter> para continuar...")
    elif opcao == '2':
        ## Listar todos os medicamentos do arquivo ##
        if os.path.getsize(nome_arquivo) > 0:
            listar_medicamentos()
        else:
            print(f"Arquivo de medicamentos {nome_arquivo} está vazio")
        input("<enter> para continuar...")
    elif opcao == '3':
        ## Atualizar a quantidade de um medicamento especifico ##
        if os.path.getsize(nome_arquivo) > 0:
            nome_m = pega_string_nao_vazia("Digite o nome do medicamento: ")
            atualizar_medicamentos(nome_m)
        else:
            print(f"Arquivo de medicamentos {nome_arquivo} está vazio")   
        input("<enter> para continuar...")
    elif opcao == '4':
        ## Remover um medicamento especifico ##
        if os.path.getsize(nome_arquivo) > 0:
            nome_m = pega_string_nao_vazia("Digite o nome do medicamento: ")
            remover_medicamentos(nome_m)
        else:
            print(f"Arquivo de medicamentos {nome_arquivo} está  vazio")   
        input("<enter> para continuar...")
    elif opcao == '5':
        ## Buscar um medicamento especifico ##:
        if os.path.getsize(nome_arquivo) > 0:
            nome_m = pega_string_nao_vazia("Digite o nome do medicamento: ")
            buscar_medicamento(nome_m)
        else:
            print(f"Arquivo de medicamentos {nome_arquivo} está vazio")     
        input("<enter> para continuar...")
    elif opcao == '6':
        ## Reservar um medicamento especifico ##
        if os.path.getsize(nome_arquivo) > 0:
            nome_m = pega_string_nao_vazia("Digite o nome do medicamento: ")
            quantidade_m,status_m = buscar_medicamento(nome_m)
            if status_m == True:
                quantidade_r = pega_inteiro_positivo("Digite a quantidade: ")
                if int(quantidade_m) >= quantidade_r:
                    nome_p = pega_string_nao_vazia("Digite o nome do usuário: ")
                    data_r = pega_string_nao_vazia("Digite a data da reserva (dd/mm/aaaa): ")
                    reservar_medicamento(nome_m, quantidade_r, nome_p, data_r)
                else:
                    print(f"Estoque do medicamento {nome_m} com quantidade {quantidade_m} insuficiente")
        else:
            print(f"Arquivo de medicamentos {nome_arquivo} está vazio")     
        input("<enter> para continuar...")
    elif opcao == '7':
        ## Listar todos os medicamentos reservados ##
        if os.path.getsize(reservas_arquivo) > 0:
            listar_reservas() 
        else:
            print(f"Arquivo de reservas {reservas_arquivo} está vazio") 
        input("<enter> para continuar...")
    elif opcao == '8':
        ## Sair do Programa ##
        limpa_tela()
        break
    else:
        print("Opção inválida!")
