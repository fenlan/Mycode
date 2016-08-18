import curses
from random import choice

def transpose(matrix):
    return list(map(list, zip(*matrix)))

def invert(matrix):
    return list(map(lambda row: row[::-1], matrix))

class GameMatrix(object):
    def __init__(self, win=2048):
        self.height = 4
        self.width = 4
        self.win_number = win
        self.score = 0
        self.maxscore = 0
        self.start()
        
    def start(self):
        self.maxscore = self.score if self.score > self.maxscore else self.maxscore
        self.score = 0
        self.matrix = [[0 for i in range(self.width)] for j in range(self.height)]
        self.new_unit()
        self.new_unit()

    def new_unit(self):
        new_number = choice([4,4]+[2]*8)
        (i, j) = choice([(i,j) for i in range(self.width) for j in range(self.height) if self.matrix[i][j]==0])
        self.matrix[i][j] = new_number
        
    def movable(self, direction):
        def left_movable_row(row):
            def left_movable_unit(u):
                if row[u]==0 and row[u+1]!=0:
                    return True
                if row[u]!=0 and row[u]==row[u+1]:
                    return True
                return False
            return any(left_movable_unit(u) for u in  range(self.width-1))
            
        check = {}
        check[ord('a')] = check[ord('A')] = lambda matrix: any(map(left_movable_row, matrix))
        check[ord('d')] = check[ord('D')] = lambda matrix: check[97](invert(matrix))
        check[ord('w')] = check[ord('W')] = lambda matrix: check[97](transpose(matrix))
# ########## wrong:        check[ord('s')] = check[ord('S')] = lambda matrix: check[119](invert(matrix))
        check[ord('s')] = check[ord('S')] = lambda matrix: check[100](transpose(matrix))
        
        return check[direction](self.matrix)
                
    def move(self, direction):
        def left_move_row(row):
            # wrong: row = [i for i in row if i != 0] + [0]*(self.width-len(row))            
            short_row = [i for i in row if i != 0]
            new_row, i = [], 0
            while i < len(short_row)-1:
                if short_row[i] != short_row[i+1]:
                    new_row.append(short_row[i])
                    i += 1
                else:
                    new_row.append(short_row[i]*2)
                    self.score += short_row[i]*2
                    i += 2
            if i == len(short_row)-1:
                new_row.append(short_row[i])
            return new_row + [0]*(len(row)-len(new_row))
                            
        moves = {}
        moves[ord('a')] = moves[ord('A')] = lambda matrix: list(map(left_move_row, matrix))
        moves[ord('d')] = moves[ord('D')] = lambda matrix: invert(moves[97](invert(matrix)))
        moves[ord('w')] = moves[ord('W')] = lambda matrix: transpose(moves[97](transpose(matrix)))
# ######### wrong:       moves[ord('s')] = moves[ord('S')] = lambda matrix: invert(moves[119](invert(matrix)))
        moves[ord('s')] = moves[ord('S')] = lambda matrix: transpose(moves[100](transpose(matrix)))
        
        if self.movable(direction):
            self.matrix = moves[direction](self.matrix)
            self.new_unit()
            return True
        else:
            return False
    
    def is_win(self):
        return any(any(i >= self.win_number for i in row) for row in self.matrix)
    
    def is_lose(self):
        return not any(self.movable(ord(dir)) for dir in 'wasd')
    
    def draw(self, screen):
        title = '-=**** 2048 ****=-\n'
        menu1 = '(W)Up (S)Down (A)Left (D)Right'
        menu2 = '(R)Restart (Q)Exit'
        win_string = '** YOU WIN **'
        gameover_string = '** GAME OVER **'        
        line = ('+' + '-'*6) * self.width + '+'
        sc = 'YOUR SCORE : ' + str(self.score) + ('\nBEST : '+str(self.maxscore) if self.maxscore else '')
        
        def cast(string):
            screen.addstr(string + '\n')
            
        def middle_cast(string):
            string = '{:^29}'.format(string)
            cast(string)

        def draw_row(row):
            cast(''.join('|{:^5} '.format(num) if num > 0 else '|      ' for num in row) + '|')
            
        screen.clear()

        middle_cast(title)        
        if self.is_win():
            middle_cast(win_string)
        elif self.is_lose():
            middle_cast(gameover_string)
        else:
            middle_cast(menu1)
        middle_cast(menu2)
        
        for row in self.matrix:
            cast(line)
            draw_row(row)
        cast(line)
        
        cast(sc)

        
valid_actions=[ord(a) for a in 'wasdqrWASDQR']

def get_valid_action(keyboard):
    c = 0
    while c not in valid_actions:
        c = keyboard.getch()
    return c

def main(stdscr):
    def start():
        game_matrix.start()
        return 'Game'
        
    def not_game(state):
        game_matrix.draw(stdscr)
        action = get_valid_action(stdscr)
        if action in [ord('r'), ord('R')]:
            return 'Start'
        if action in [ord('q'), ord('Q')]:
            return 'Quit'
        return state
        
    def game():
        game_matrix.draw(stdscr)
        action = get_valid_action(stdscr)
        if action in [ord('r'), ord('R')]:
            return 'Start'
        if action in [ord('q'), ord('Q')]:
            return 'Quit'
        if game_matrix.move(action):
            if game_matrix.is_win():
                return 'Win'
            if game_matrix.is_lose():
                return 'GameOver'
        return 'Game'
        
    state_func={
            'Start': start,
            'Game': game,
            'Win': lambda: not_game('Win'),
            'GameOver': lambda: not_game('GameOver')
            }
    
    game_matrix = GameMatrix()
    
    state = 'Start'
    
    while state != 'Quit':
        state = state_func[state]()
        
curses.wrapper(main)
