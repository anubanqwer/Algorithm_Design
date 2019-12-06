
# board parameter need to be in this form [0,1,0,1,-1,0,0,1]
# 0 = 'X' ; 1 = 'O' ; -1 = ' '(Blank)
def print_board(board):
    print('-'*15)
    idx_char = ['X','O',' ']
    s_board = ' 0 | 1 | 2 \n -----------\n 3 | 4 | 5 \n -----------\n 6 | 7 | 8 '
    for i in range(len(board)):
        s_board = s_board.replace(str(i),idx_char[board[i]])
    print(s_board)
    print('-'*15)
    
    return
#--------------------------vvADD_YOUR_CODE_HEREvv------------------------
N = int(input().strip())
aL = [-1 for e in range(9)]
for i in range(N):
    indexx = int(input().strip())
    if i%2 == 0:
        aL[indexx] = 0
    else:
        aL[indexx] = 1

L = [ aL ]
pattern = [[0,3,6],[1,4,7],[2,5,8],[0,1,2],[3,4,5],[6,7,8],[0,4,8],[2,4,6]]


def imp_idx(alist, num ): # -1,0,0  or -1,1,1
    win_alist = []; block_list = []
    blank_set = { i for i in range(9) if alist[i] == -1 }
    X_set = { i  for i in range(9) if alist[i] == 0 }
    O_set = { i  for i in range(9) if alist[i] == 1 }
    for c in pattern:
        alist6 = sorted( [ alist[c[i]] for i in range(3) ] ) #alist6 store value
        if alist6[0] == -1  and alist6[1]==alist6[2] and ( alist6[1] == num ):
            for j in range(3):
                if alist[c[j]] == -1 and c[j] not in win_alist:
                    win_alist.append( c[j] )
                    valid = True
                    break
    if len(win_alist) != 0: return win_alist
    for c in pattern:
        alist6 = sorted( [ alist[c[i]] for i in range(3) ] ) #alist6 store value
        if alist6[0] == -1  and alist6[1]==alist6[2] and  alist6[1] not in  [num , -1]:
            for j in range(3):
                if alist[c[j]] == -1 and c[j] not in block_list:
                    block_list.append( c[j] )
                    valid = True
                    break
    if len(block_list) != 0 : return block_list        
    return sorted ( list( blank_set ) )

#print( imp_idx( [0,1,0,-1,1,-1,0,-1,1] , 0 ))

def fill( alist1,num ): #imp_idx=[0,7] L = [-1,-1,1,0,-1,1,-1,0,0]
                        #new_L = [[num,-1,.....],[......,num,0]
    new_L = []
    for a_list in alist1:
        imp_idx_list = imp_idx( a_list, num )
        for i in range(len(imp_idx_list)):
            new_LL = list(a_list)
            new_LL[imp_idx_list[i]] = num
            new_L.append(new_LL)
    return new_L

#print( fill ( [ [ 0,-1,0,-1,1,-1,0,-1,1 ] ], 1))
#print( fill  ( [[0, -1, 0, 1, 1, -1, 0, -1, 1], [0, 1, 0, -1, 1, -1, 0, -1, 1]]  , 0 ))

def finished( LoL ):
    new_LoL = []
    for a__list in LoL:
        winn = False
        for c in pattern:
            alist8 = [ a__list[c[i]] for i in range(3) ]
            if alist8[0] == alist8[1] == alist8[2]  and alist8[0] == 0:
                winn = True
                if a__list not in Ans_X_WIN:
                    Ans_X_WIN.append( a__list )
            if alist8[0] == alist8[1] == alist8[2]  and alist8[0] == 1:
                winn = True
                if a__list not in Ans_O_WIN:
                    Ans_O_WIN.append( a__list)
        if winn == False:            
            continuee = False            
            for i in range(9):
                if a__list[i] == -1:
                    continuee = True
                    break
                
            if continuee == False:
                if a__list not in Ans_DRAW:
                    Ans_DRAW.append( a__list )
            else:
                new_LoL.append( a__list )          
    
    return new_LoL
    
        
if N%2==0: const = 0  #turn x
else:
    const = 1  #turn o

Ans_O_WIN = []
Ans_X_WIN = []
Ans_DRAW = []

#print(finished([[0,1,0,-1,1,-1,0,-1,1],[0,-1,0,1,1,-1,0,-1,1]]))
#print(finished([[0,0,0,-1,1,-1,0,-1,1],[0,-1,0,0,1,-1,0,-1,1]]))

while True:
    if const % 2 != 0:  #turn O
        L = fill(L, 1)
    else:  #turn x
        L = fill(L,0)      
    L = finished(L)
    if len(L) == 0 : break
    const += 1
    


#print(Ans_O_WIN)
#print(Ans_X_WIN)
#print(Ans_DRAW)

        
      

#------------------------------------------------------------------------
# Output
#--------------------------------DRAW------------------------------------
print('Numbers of Board that Draw :' + str(len(Ans_DRAW)))
for i in sorted(Ans_DRAW):
      print_board(i)
print('-'*34)
#------------------------------------------------------------------------
#--------------------------------X_WIN-----------------------------------
print('Numbers of Board that X Wins :' + str(len(Ans_X_WIN)))
for i in sorted(Ans_X_WIN): #Sort List of board
      print_board(i)
print('-'*34)
#------------------------------------------------------------------------
#--------------------------------O_WIN-----------------------------------
print('Numbers of Board that O Wins :' + str(len(Ans_O_WIN)))   
for i in sorted(Ans_O_WIN): #Sort List of board
      print_board(i)
#------------------------------------------------------------------------
