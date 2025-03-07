#=============================#
## Análise de Vendas Mensais ##
##===========================##

#Suponha que as vendas mensais de uma loja ficam armazenadas  
#em um arquivo de texto. O objetivo do programa é processar 
#esses dados, salvá-los em uma estrutura de dados apropriada 
#e gerar um gráfico para análise.

#1.Arquivo de entrada:
#Um arquivo de texto chamado vendas.txt contém os dados no 
#seguinte formato: mes, valor, meta

#2.Tarefas a serem realizadas:

#Leia o arquivo vendas.txt e armazene os dados em três listas: 
#uma para os meses, uma para os valores de vendas e outra para
#as metas de vendas.
#Plote um gráfico de linha para visualizar as vendas ao longo 
#do ano X metas de cada mês.
#Adicione títulos e rótulos ao gráfico para torná-lo mais 
#informativo.

## Importação das bibliotecas ##
#==============================#

import os
import matplotlib.pyplot as plt

limpa_tela = lambda: os.system('cls')
limpa_tela()

from entrada_dados import garantir_arquivo_existe,ler_arquivo, escrever_arquivo, pega_inteiro_positivo, pega_string_nao_vazia

## Variáveis Globais ##
#=====================#

arquivov = 'vendas_mes.txt'

## Funções do Programa ##
#=======================#

### menu ###

def menu():
    print("======= Menu de Opções ========")
    print("1. Adicionar Venda")
    print("2. Listar Vendas")
    print("3. Remover Venda")
    print("4. Alterar Venda")
    print("5. Buscar Venda")
    print("6. Plotar Gráfico")
    print("7. Sair")
    print("===============================")

### adicionar informações de venda do mês ###

def adicionar_venda(mes_v, valor_v, meta_v):
    escrever_arquivo(arquivov, f"{mes_v},{valor_v},{meta_v}\n", 'a')
    print(f"Venda adicionada: {mes_v} - Venda: R$ {valor_v}, Meta: R$ {meta_v} com sucesso")

### listar as venda do mês ###

def listar_vendas():
    vendas = ler_arquivo(arquivov)
    print("========== Vendas Registradas ==========")
    print(f"{'Mês':<10} {'Venda (R$)':<15} {'Meta (R$)':<15}")
    for venda in vendas:
        mes, valor, meta = venda.strip().split(',')
        print(f"{mes:<10} {valor:<15} {meta:<15}")
    print("========================================")

### remover um mês de venda ###

def remover_venda(mes_v):
    vendas = ler_arquivo(arquivov)
    vendas_atualizadas = [venda for venda in vendas if not venda.startswith(mes_v)]
    ''' expressão geradora de lista = compressão de lista
    vendas_atualizadas = []
    for venda in vendas:
        if not venda.startswith(mes_v):
            vendas_atualizadas.append(venda)
    '''
    if len(vendas) != len(vendas_atualizadas):
        ''' junta todos os elementos da lista em uma unica string sem separador
        conteudo = ""
        for venda in vendas_atualizadas:
            conteudo += venda
        escrever_arquivo(arquivov,conteudo, modo='w')
        '''
        escrever_arquivo(arquivov, ''.join(vendas_atualizadas), modo='w')
        print(f"Venda do mês {mes_v} removida com sucesso.")
    else:
        print(f"Nenhuma venda encontrada para o mês {mes_v}.")

### alterar informações de um mês de venda ###

def alterar_venda(mes_v):
    vendas = ler_arquivo(arquivov)
    vendas_atualizadas = []
    alterada = False

    for venda in vendas:
        mes, valor, meta = venda.strip().split(',')
        if mes == mes_v:
            novo_valor = pega_inteiro_positivo(f"Digite o novo valor para o mês {mes}: ")
            nova_meta = pega_inteiro_positivo(f"Digite a nova meta para o mês {mes}: ")
            vendas_atualizadas.append(f"{mes},{novo_valor},{nova_meta}\n")
            alterada = True
        else:
            vendas_atualizadas.append(venda)

    if alterada:
        escrever_arquivo(arquivov, ''.join(vendas_atualizadas), modo='w')
        print(f"Venda do mês {mes_v} alterada com sucesso.")
    else:
        print(f"Nenhuma venda encontrada para o mês {mes_v}.")

### buscar um mês de venda ###

def buscar_venda(mes_v):
    vendas = ler_arquivo(arquivov)
    for venda in vendas:
        mes, valor, meta = venda.strip().split(',')
        if mes == mes_v:
            print(f"Venda encontrada: Mês: {mes}, Venda: R$ {valor}, Meta: R$ {meta}")
            return
    print(f"Nenhuma venda encontrada para o mês {mes_v}.")

### plotar o grafico vendas X metas mês a mês ###

def plotar_grafico():
    vendas = ler_arquivo(arquivov)
    meses = []
    valores = []
    metas = []
    for venda in vendas:
        mes, valor, meta = venda.strip().split(',')
        meses.append(mes)
        valores.append(float(valor))
        metas.append(float(meta))
    # Cria uma nova figura para o gráfico.#
    # Define o tamanho da figura em polegadas (largura 10 e altura 6)#
    plt.figure(figsize=(10, 6))

    #plt.plot: Plota os dados no gráfico como uma linha.
    #meses: Valores no eixo x (ex.: ['Jan', 'Feb', 'Mar']).
    #valores: Valores no eixo y (ex.: [1000, 1200, 1100]).
    #marker='o': Usa círculos para marcar os pontos.
    ##linestyle='-': Usa uma linha sólida para conectar os pontos.
    #color='b': Define a cor da linha como azul ('b' para blue).
    #label='Vendas': Define o rótulo para a legenda.
    plt.plot(meses, valores, marker='o', linestyle='-', color='b', label='Vendas')

    ## Idem a linha de anterior ##
    plt.plot(meses, metas, marker='x', linestyle='--', color='r', label='Metas')


    #plt.title: Adiciona um título ao gráfico.
    #fontsize=14: Define o tamanho da fonte do título.
    plt.title("Vendas Mensais x Metas", fontsize=14)

    #plt.xlabel: Adiciona um rótulo ao eixo x (neste caso, "Meses").
    #fontsize=12: Define o tamanho da fonte do rótulo.
    plt.xlabel("Meses", fontsize=12)

    #plt.ylabel: Adiciona um rótulo ao eixo y (neste caso, "Valores (em R$)").
    #fontsize=12: Define o tamanho da fonte do rótulo.
    plt.ylabel("Valores (em R$)", fontsize=12)

    #plt.grid: Adiciona uma grade ao gráfico para facilitar a leitura dos 
    #valores.
    #True: Habilita a grade.
    plt.grid(True)

    #plt.xticks: Define os valores do eixo x.
    #rotation=45: Rotaciona os rótulos do eixo x em 45 graus para melhor 
    #visibilidade.
    plt.xticks(rotation=45)

    #plt.legend: Exibe uma legenda no gráfico com base nos rótulos definidos 
    #nos parâmetros label.
    plt.legend()

    #plt.tight_layout: Ajusta automaticamente os elementos do gráfico para 
    #evitar sobreposição.
    plt.tight_layout()

    #plt.show: Exibe o gráfico na saída.
    plt.show()


## Programa Principal ##
#======================#

garantir_arquivo_existe(arquivov)

while True:
    limpa_tela()
    menu()
    opcao = input("Digite a opção desejada: ")
    if opcao == '1':
        mes_v = pega_string_nao_vazia("Digite o mês da venda: ")
        valor_v = pega_inteiro_positivo("Digite o valor da venda: ")
        meta_v = pega_inteiro_positivo("Digite a meta para o mês: ")
        adicionar_venda(mes_v, valor_v, meta_v)
        input("<enter> para continuar")
    elif opcao == '2':
        if os.path.getsize(arquivov) > 0:
            listar_vendas()
        else:
            print(f"Arquivo de vendas {arquivov} vazio")
        input("Pressione Enter para continuar...")
    elif opcao == '3':
        if os.path.getsize(arquivov) > 0:
            mes_v = pega_string_nao_vazia("Digite o mês da venda: ")
            remover_venda(mes_v)
        else:
            print(f"Arquivo de vendas {arquivov} vazio")
        input("Pressione Enter para continuar...")
    elif opcao == '4':
        if os.path.getsize(arquivov) > 0:
            mes_v = pega_string_nao_vazia("Digite o mês da venda: ")
            alterar_venda(mes_v)
        else:
            print(f"Arquivo de vendas {arquivov} vazio")
        input("Pressione Enter para continuar...")
    elif opcao == '5':
        if os.path.getsize(arquivov) > 0:
            mes_v = pega_string_nao_vazia("Digite o mês da venda: ")
            buscar_venda(mes_v)
        else:
            print(f"Arquivo de vendas {arquivov} vazio")
        input("Pressione Enter para continuar...")
    elif opcao == '6':
        if os.path.getsize(arquivov) > 0:
            plotar_grafico()
        else:
            print(f"Arquivo de vendas {arquivov} vazio")
        input("Pressione Enter para continuar...")
    elif opcao == '7':
        limpa_tela()
        break
    else:
        print("Opção inválida!")
        input("Pressione Enter para continuar...")