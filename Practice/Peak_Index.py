#n is a peak index if
#( L[n] >= L[n+1] if L[n+1] is exist ) && ( L[n] >= L[n-1] if L[n-1] is exist )

#1 find a peak in a list
'''L = [ ]
Ans = []

def peak(L):
    if len(L) == 0: return
    n = ( len(L) - 1 ) // 2
    if n-1 >= 0 and L[n] < L[n-1]: peak(L[:n])
    elif n+1 < len(L) and L[n] < L[n+1]: peak(L[n+1:])
    else:
        Ans.append(L[n])
    
peak(L)

for c in Ans:
    print(c)'''

#-------------------------------------------------------------------------------
#2 find a peak in matrix(2D)

#L is list of list
L = [[1,2,5,0],
     [5,12,13,16],
     [0,4,5,3],
     [0,1,1,10]]
Ans = []

def peak(L):
    if len(L) == 0: return
    n = ( len(L) - 1 ) // 2
    if n-1 >= 0 and L[n] < L[n-1]: peak(L[:n])
    elif n+1 < len(L) and L[n] < L[n+1]: peak(L[n+1:])
    else:
        Ans.append(L[n])
    
def peak2D(L):
    nrows = len(L)
    ncols = len( L[0] )
    ncol = (ncols + 1) // 2
    max_value = L[0][ncol]
    idx_number_column = 0
    for i in range(nrows):
        if L[i][ncol] > max_value:
            max_value = L[i][ncol]
            idx_number_column = i
    peak([L[idx_number_column][i] for i in range(ncols)])

peak2D(L)    

for c in Ans:
    print(c)

#Time complexity is n*log(m)
# n = number of rows
# m = number of columns

            
        
        
    
    

    

        
    
