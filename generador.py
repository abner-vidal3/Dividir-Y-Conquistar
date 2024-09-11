from random import randint
def escribir(test,t,q):
    archivo = open(test,"w")
    #valor de t
    #0 para caso ordenamiento.
    #1 para caso multiplicación de matriz.
    #2 para caso ordenamiento Selection Sort.
    #3 para caso multiplicación de matriz cuadrada.
    #valor de q
    #0 para peor caso
    #1 para mejor caso
    #2 para caso aleatorio
    if t == 0:
        if q == 0:
            s = randint(1,100000)
            archivo.write(str(s)+"\n")
            for i in range(s+1,1,-1):
                archivo.write(str(i)+" ")
            archivo.write("\n")
        elif q == 1:
            s = randint(1,100000)
            archivo.write(str(s)+"\n")
            for i in range(1,s+1):
                archivo.write(str(i)+" ")
            archivo.write("\n")
        else:
            s = randint(1,100000)
            archivo.write(str(s)+"\n")
            for i in range(1,s+1):
                archivo.write(str(randint(1,1000000000))+" ")
            archivo.write("\n")
    elif t == 1:
        if q == 0:
            n = randint(1,100)
            m = randint(1,100)
            archivo.write(str(n)+" "+str(m)+"\n")
            for i in range(n):
                for j in range(m):
                    r = randint(1,4)
                    if r == 1:
                        archivo.write(str(randint(1,1000))+" ")
                    else:
                        archivo.write(str(0)+" ")
                archivo.write("\n")
            n = m
            m = randint(1,100)
            archivo.write(str(n)+" "+str(m)+"\n")
            for i in range(n):
                for j in range(m):
                    r = randint(1,4)
                    if r == 1:
                        archivo.write(str(0)+" ")
                    else:
                        archivo.write(str(randint(1,1000))+" ")
                archivo.write("\n")
        elif q == 1:
            n = randint(1,100)
            m = randint(1,100)
            archivo.write(str(n)+" "+str(m)+"\n")
            for i in range(n):
                for j in range(m):
                    archivo.write(str(randint(1,1000))+" ")
                archivo.write("\n")
            n = m
            m = randint(1,100)
            archivo.write(str(n)+" "+str(m)+"\n")
            for i in range(n):
                for j in range(m):
                    archivo.write(str(randint(1,1000))+" ")
                archivo.write("\n")
        else:
            n = randint(1,100)
            m = randint(1,100)
            archivo.write(str(n)+" "+str(m)+"\n")
            for i in range(n):
                for j in range(m):
                    archivo.write(str(randint(0,1000))+" ")
                archivo.write("\n")
            n = m
            m = randint(1,100)
            archivo.write(str(n)+" "+str(m)+"\n")
            for i in range(n):
                for j in range(m):
                    archivo.write(str(randint(0,1000))+" ")
                archivo.write("\n")
    elif t == 2:
        if q == 0:
            s = randint(1,1000)
            archivo.write(str(s)+"\n")
            for i in range(s+1,1,-1):
                archivo.write(str(i)+" ")
            archivo.write("\n")
        elif q == 1:
            s = randint(1,1000)
            archivo.write(str(s)+"\n")
            for i in range(1,s+1):
                archivo.write(str(i)+" ")
            archivo.write("\n")
        else:
            s = randint(1,1000)
            archivo.write(str(s)+"\n")
            for i in range(1,s+1):
                archivo.write(str(i)+" ")
            archivo.write("\n")
    else:
        if q == 0:
            n = randint(1,100)
            archivo.write(str(n)+" "+str(n)+"\n")
            for i in range(n):
                for j in range(n):
                    r = randint(1,4)
                    if r == 1:
                        archivo.write(str(randint(1,1000))+" ")
                    else:
                        archivo.write(str(0)+" ")
                archivo.write("\n")
            archivo.write(str(n)+" "+str(n)+"\n")
            for i in range(n):
                for j in range(n):
                    r = randint(1,4)
                    if r == 1:
                        archivo.write(str(randint(1,1000))+" ")
                    else:
                        archivo.write(str(0)+" ")
                archivo.write("\n")
        elif q == 1:
            n = randint(1,100)
            archivo.write(str(n)+" "+str(n)+"\n")
            for i in range(n):
                for j in range(n):
                    archivo.write(str(randint(1,1000))+" ")
                archivo.write("\n")
            archivo.write(str(n)+" "+str(n)+"\n")
            for i in range(n):
                for j in range(n):
                    archivo.write(str(randint(1,1000))+" ")
                archivo.write("\n")
        else:
            n = randint(1,100)
            archivo.write(str(n)+" "+str(n)+"\n")
            for i in range(n):
                for j in range(n):
                    archivo.write(str(randint(0,1000))+" ")
                archivo.write("\n")
            archivo.write(str(n)+" "+str(n)+"\n")
            for i in range(n):
                for j in range(n):
                    archivo.write(str(randint(0,1000))+" ")
                archivo.write("\n")
    archivo.close()
tipos = [[0,0],[0,1],[0,2],[1,0],[1,1],[1,2],[2,0],[2,1],[2,2],[3,0],[3,1],[3,2]]
for tipo in tipos:
    for i in range(10):
        escribir("tests/test"+str(tipo[0])+"_"+str(tipo[1])+"_"+str(i)+".txt",tipo[0],tipo[1])