def toInt(param: str):
    ret = 0
    flag=False
    if param[0] == '-':
        param=param[1:]
        flag=True
        print('chang',param)
    for i in range(len(param)):
        c = param[len(param)-1-i]
        c = ord(c)-ord('A')
        ret += (c*(26**i))

    if flag:
        ret*=-1
    return ret

def to26(Int : int):
    ret = ''
    while Int > 0:
        ret += chr(ord('A')+(Int%26))
        Int //= 26
    return ret

ilist=['RQGHUMEA',
       'GLFDXF',
       'DVSCXGG','-RFNQDUXWF','-LZVSR','-PP','-TGGXRPNR','-ETMWCYS','PQPEVIKEF','-YNIMKKASVW','PNZKYCX','-JLSGYP','YDPOOEF','-YCOEJUVP','-ZO']

res=0
for i in ilist:
    res += toInt(i)
    
if res < 0:
    print('-'+to26(-res)[::-1])
else:
    print(to26(res)[::-1])