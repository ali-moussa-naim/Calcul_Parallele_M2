import matplotlib.pyplot as plt

def courbe_Sp():
    plt.figure(figsize=(8, 6))
    plt.xlabel('Proportion (%)')
    plt.ylabel('Facteur d’accélération (Sp)')

    l_pourc = list(range(0, 101, 10))

    for p in range(1, 11):
        l_Sp = []

        for pourc in l_pourc:
            y = pourc / 100 
            Sp = 1 / ((1 - y) + y / p)
            l_Sp.append(Sp)

        plt.plot(l_pourc, l_Sp, marker='o')

    plt.grid(True)
    plt.show()

def courbe_efficacite():
    plt.figure(figsize=(8, 6))
    plt.xlabel('Proportion (%)')
    plt.ylabel('Efficacité (Ep)')

    l_pourc = list(range(0, 101, 10))

    for p in range(1, 11):
        l_Ep = []

        for pourc in l_pourc:
            y = pourc / 100 
            Sp = 1 / ((1 - y) + y / p)
            Ep = Sp / p
            l_Ep.append(Ep)

        plt.plot(l_pourc, l_Ep, marker='o')

    plt.grid(True)
    plt.show()

def main():
    courbe_Sp()
    courbe_efficacite()

if __name__ == "__main__":
    main()
