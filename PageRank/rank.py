import json
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
def equal(A,B, epsilon):
    m = len(A)                                           
    for i in range(m):           
        if (abs(A[i][0] - B[i][0]) > epsilon):
            return False
    return True

def findI(I,H):
    I2 = H.dot(I)
    if (equal(I,I2, 0.0000001)):
        return I
    else:
        return findI(I2, H)

def draw_graph():
    with open("result.json") as file:
        sorted_res = json.load(file)
    G = nx.Graph()
    for i in range(15):
        G.add_node(sorted_res[i][0])
        for j in range(15):
            if(sorted_res[j][0] in heroes[sorted_res[i][0]]):
                G.add_edge(sorted_res[i][0], sorted_res[j][0])
            else:
                print(sorted_res[j][0], sorted_res[i][0])

    nx.draw_circular(G,
            node_color='red',
            node_size=1000,
            with_labels=True)
    plt.savefig('graph.png')
    plt.close()

def find_pagerank():
    with open("datasets\heroes_network_6426a.json") as file:
        heroes = json.load(file)
    alpha = 0.85
    count = len(heroes)

    h = np.zeros((count,count))
    a = np.zeros((count,count))
    e = np.ones((count,count)) 

    i = 0
    j = 0
    for hero in heroes:
        j = 0
        for colum in heroes:
            if len(heroes[colum]) == 0:
                a[i][j] = 1/count
            if hero in heroes[colum] and len(heroes[colum]) != 0:
                h[i][j] = 1/len(heroes[colum])
            j += 1
        i += 1

    i = np.zeros((count,1))
    i[0][0] = 1

    g = h.dot(alpha) + a.dot(alpha) + e.dot((1 - alpha)/count)
    i = findI(i, g)
    G = g.dot(i)

    res = {}
    i = 0
    for hero in heroes:
        res[hero] = G[i][0]
        i += 1

    sorted_res = sorted(res.items(), key=lambda x: x[1], reverse=True)
    with open("result.json", 'w') as file:
        json.dump(sorted_res,file)


