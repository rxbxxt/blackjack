import os


if __name__ == '__main__':
    QRC_FILE    = './resources.qrc'
    BG_DIR      = './images/backgrounds'
    CARDS_DIR   = './images/cards'

    with open(QRC_FILE, 'w') as resources:
        resources.write('<RCC>\n')

        resources.write('  <qresource prefix="/background">\n')
        for bg_file in os.listdir(BG_DIR):
            alias = os.path.splitext(bg_file)[0] # filename without extension
            resources.write(f'    <file alias="{alias}">{BG_DIR}/{bg_file}</file>\n')
        resources.write('  </qresource>\n\n')

        resources.write('  <qresource prefix="/card">\n')
        for suit in os.listdir(CARDS_DIR):
            if suit == 'unknown.png':
                continue
            resources.write(f'    <!-- {suit} -->\n')
            for card in os.listdir(f'{CARDS_DIR}/{suit}'):
                alias = os.path.splitext(f'{suit}/{card}')[0] # filename without extension
                resources.write(f'    <file alias="{alias}">{CARDS_DIR}/{suit}/{card}</file>\n')
        resources.write('  </qresource>\n')

        resources.write('</RCC>\n')