from random import shuffle

numbers = [str(i) for i in range(1, 14)]
suits = ['C', 'D', 'H', 'S']

deck = [(i, s) for i in numbers for s in suits]
shuffle(deck)

with open('deck.txt', mode='w') as file:
    for card in deck:
        file.write(card[0] + ' ' + card[1] + '\n')
